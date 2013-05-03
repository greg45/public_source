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

#ifndef _USER_H
#define	_USER_H

#include <iostream>
#include <string>

#include <QDir>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>

#include "passwordtype.h"

namespace DummyFTPServer {
namespace AccountManager {

/*! \class User
 *  \brief Třída reprezentující uživatele.
 */
class User {
public:
    /*! \fn User(std::string username, std::string password, PasswordType format, std::string homeDirectory)
     *  \brief Vytváří objekty reprezentující uživatele.
     *  \param username Uživatelské jméno
     *  \param password Heslo
     *  \param format Formát hesla
     *  \param homeDirectory Domovský adresář
     */
    User(std::string username,
         std::string password,
         PasswordType format,
         std::string homeDirectory);

    /*! \fn std::string getUsername() const
     *  \brief Metoda vrací uživatelské jméno.
     */
    std::string getUsername() const;

    /*! \fn std::string getHomeDirectory() const
     *  \brief Metoda vrací cestu k domovskému adresáři.
     */
    std::string getHomeDirectory() const;

    /*! \fn bool checkPassword(std::string password, PasswordType format) const
     *  \brief Metoda provádí porovnání hesel.
     *  \param password Vstupní heslo.
     *  \param format Formát vstupního hesla.
     *  \return Vrací pravdu při shodě hesel, v opačném případě nepravdu.
     */
    bool checkPassword(std::string password, PasswordType format) const;

    /*! \fn bool isValidPath() const
     *  \brief Třídní metoda provádějící kontrolu existence cesty.
     *  \return Vrací pravdu při úspěšné validaci cesty, v opačném případě nepravdu.
     */
    bool isValidPath() const;

    /*! \fn bool operator==(const User &u) const
     *  \brief Přetížený operátor provnání. Slouží k porovnání hesel dvou uživatelských objektů.
     *  \param u Vstupní uživatelský objekt.
     *  \return Vrací pravdu při shodě hesel, v opačném případě nepravdu.
     */
    bool operator==(const User &u) const;

    /*! \fn bool operator!=(const User &u) const
     *  \brief Přetížený operátor porovnání. Slouží k porovnání hesel dvou uživatelských objektů.
     *  \param u Vstupní uživatelský objekt.
     *  \return Vrací nepravdu při shodě hesel, v opačném případě pravdu.
     */
    bool operator!=(const User &u) const;

    /*! \fn bool isValidPath(const QString &path)
     *  \param path Nastaví cestu.
     *  \brief Netřídní metoda provádějící kontrolu existence cesty.
     */
    static bool isValidPath(const QString &path);

private:
    /*! \var m_username
     *  \brief Uživatelské jméno.
     */
    std::string m_username;

    /*! \var m_password
     *  \brief Uživatelské heslo.
     */
    std::string m_password;

    /*! \var m_passwordFormat
     *  \brief Formát hesla.
     */
    PasswordType m_passwordFormat;

    /*! \var m_homeDirectory
     *  \brief Domovský adresář.
     */
    std::string m_homeDirectory;
};
}
}

#endif	/* _USER_H */

