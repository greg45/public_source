/***************************************************************************
 *   Copyright (C) 2010 by Marek Hakala   *
 *   marek@hakala.cz   *
 *
 *   Semestrální práce PA2 - ČVUT FIT
 *   Téma : Implementace FTP serveru
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _CORE_H
#define	_CORE_H

#include <QObject>
#include <QPointer>

#include <string>
#include <exception>

#include "ftpserver.h"
#include "configuration.h"
#include "userlist.h"

#include "errorexception.h"

using DummyFTPServer::Configuration;
using DummyFTPServer::AccountManager::User;
using DummyFTPServer::AccountManager::UserList;

namespace DummyFTPServer {

/*! \class Core
 *  \brief Tato třída je jádrem celé aplikace. Zajišťuje spolupráci mezi nastavením, uživatelskou databází a serverovou částí.
 */
class Core : public QObject {
    Q_OBJECT

public:
    /*! \fn bool loadConfiguration(std::string configurationPath, std::string userListPath)
     *  \brief Metoda sloužící k načítání konfigurace a uživatelské databáze.
     *  \param configurationPath Nastaví cestu ke konfiguračnímu souboru.
     *  \param userListPath Nastaví cestu.
     *  \return Vrací pravdu při úspěšném načtení, v opačném případě nepravdu.
     */
    bool loadConfiguration(std::string configurationPath, std::string userListPath);

    /*! \fn bool startServer()
     *  \brief Metoda sloužící k zapnutí serverové části do listen režimu.
     *  \return Vrací pravdu při úspěšném startu v opačném případě nepravdu.
     */
    bool startServer();

    /*! \fn QString getAnonymousHome()
     *  \brief Metoda slouží k získaní domovského adresáře uživatele anonymous.
     *  \return Vrací cestu k domovskému adresáři uživatele anonymous.
     */
    QString getAnonymousHome();

    /*! \fn bool getSettingsValue(std::string sectionAndKey, std::string *value)
     *  \brief Metoda vrací hodnotu z nastavení podle zadaného klíče.
     *  \param sectionAndKey Nastaví cestu k požadované hodnotě.
     *  \param value Vstupní ukazatel pomocí, kterého nám bude navrácena získaná hodnota.
     *  \return Vrací pravdu při nalezení hodnoty, v opačném případě nepravdu.
     */
    bool getSettingsValue(std::string sectionAndKey, std::string *value);

    /*! \fn bool getSettingsValue(std::string section, std::string key, std::string *value)
     *  \brief Metoda vrací hodnotu z nastavení podle zadaného klíče.
     *  \param section Nastaví sekci.
     *  \param key Nastaví klíč.
     *  \param value Vstupní ukazatel pomocí, kterého nám bude navrácena získaná hodnota.
     *  \return Vrací pravdu při nalezení hodnoty, v opačném případě nepravdu.
     */
    bool getSettingsValue(std::string section, std::string key, std::string *value);

    /*! \fn User *getUser(std::string username)
     *  \brief Metoda vrací ukazatel na uživatele podle zadaného jména.
     *  \param username Jméno hledaného uživatele.
     *  \return Vrací ukazatel na objekt uživatele, v případě neexistujícího uživatele vrátí null pointer.
     */
    User *getUser(std::string username);

    /*! \fn int getUserCount() const
     *  \brief Metoda pro získání počtu uživatelů v databázi.
     *  \return Vrací počet uživatelů, v uživatelské databázi.
     */
    int getUserCount() const;

    /*! \fn bool isEnabledAnonymousAccess()
     *  \brief Metoda sloužící k získání příznaku, který indikuje povolení anonymního přístupu.
     */
    inline bool isEnabledAnonymousAccess() {
        return enableAnonymous;
    }

    /*! \fn Core *Instance()
     *  \brief Metoda pro vytvoření/získání instance třídy Core. Dle návrhového vzoru Singleton.
     *  \return Vrací instanci třídy Core.
     */
    inline static Core *Instance() {
        if (!pInstance)
            pInstance = new Core();

        return pInstance;
    }

    /*! \fn bool validatePortRange(unsigned int port)
     *  \brief Metoda provádějící validaci TCP portu.
     *  \param port Nastaví číslo kontrolovaného portu.
     *  \return Vrací pravdu při správně nastaveném portu v opačném případě nepravdu.
     */
    static bool validatePortRange(unsigned int port);

    /*! \fn bool split(std::stringstream &ss, std::string *output, char delimiter = ':')
     *  \brief Netřídní metoda sloužící k rozdělení textového řetězce podle zvoleného oddělovače.
     *  \param ss Vstupní textový proud.
     *  \param output Výstupní textový řetězec.
     *  \param delimiter Nastaví oddělovač.
     *  \return Vrací pravdu při úspěšném rozdělení, v opačném případě nepravdu.
     */
    static bool split(std::stringstream &ss, std::string *output, char delimiter = DEFAULT_DELIMITER);

    /*! \fn stringToBool(std::string str)
     *  \brief Netřídní metoda sloužící k převodu textového řetězce na boolovskou hodnotu podle zvoleného oddělovače.
     *  \param str Vstupní textový řetězec.
     *  \return Vrací pravdu při úspěšném převodu textu na boolovskou hodnotu, v opačném případě nepravdu.
     */
    static bool stringToBool(std::string str);

private:

    /*!  \fn Core()
     *   \brief Soukromý konstruktor, který vytváří instanci jádra.
     */
    Core() : QObject(0) {
        configuration = NULL;
        userList = NULL;
        enableAnonymous = false;
    }

    /*! \var enableAnonymous
     *  \brief Příznak povolující anonymní přístup.
     */
    bool enableAnonymous;

    /*! \var userList
     *  \brief Uživatelská databáze.
     */
    UserList *userList;

    /*! \var configuration
     *  \brief Ukazatel na instanci nastavení.
     */
    Configuration *configuration;

    /*! \var pInstance
     *  \brief Ukazatel na instanci třídy Core.
     */
    static QPointer<Core> pInstance;

    ~Core();
};
}

#endif	/* _CORE_H */

