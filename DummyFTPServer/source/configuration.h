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

#ifndef _CONFIGURATION_H
#define	_CONFIGURATION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "config.h"
#include "confsection.h"

using DummyFTPServer::ConfSection;

namespace DummyFTPServer {

/*! \class Configuration
 *  \brief Třída sloužící jako databáze nastavení v paměti.
 */
class Configuration {

public:
    /*! \fn Configuration(std::string configFile = DEFAULT_CONF_PATH)
     *  \brief Uživatelský konstruktor, který provede otevření konfiguračního souboru pro čtení.
     *  \param configFile Nastaví cestu konfiguračního souboru.
     */
    Configuration(std::string configFile = DEFAULT_CONF_PATH);
    ~Configuration();

    /*! \fn bool appendToSection(std::string key, std::string value, std::string sectionName = "global")
     *  \brief Metoda sloužící k přidávání hodnot do sekcí. Pokud není vybrána žádná sekce je automaticky zvolena globální sekce "global".
     *  \param key Nastaví klíč pomocí, kterého bude hodnota přístupná.
     *  \param value Nastaví hodnotu.
     *  \param sectionName Vybere příslušnou sekci.
     *  \return Vrací pravdu při úspěšném vložení, v opačném případě nepravdu.
     */
    bool appendToSection(std::string key, std::string value,
                         std::string sectionName = "global");

    /*! \fn bool clean()
     *  \brief Provede vyprázdnění databáze.
     *  \return Vrací pravdu při úspěšném vyprázdnění, v opačném případě nepravdu.
     */
    bool clean();

    /*! \fn bool loadConfiguration()
     *  \brief Provede načtení konfiguračního souboru.
     *  \return Vrací pravdu při úspěšném načtení, v opačném případě nepravdu.
     */
    bool loadConfiguration();

    /*! \fn ConfSection *getSection(std::string name)
     *  \brief Slouží k získání ukazatele na sekci.
     *  \param name Nastaví jméno hledané sekce.
     *  \return Vrací ukazatel na sekci. Pokud sekce neexistuje bude vrácen NULL pointer.
     */
    ConfSection *getSection(std::string name);

private:
    /*! \fn bool parseSection(std::string input, std::string *section)
     *  \brief Metoda sloužící k získání názvu sekce, s textového řetězce.
     *  \param input Vstupní textový řetězec.
     *  \param section Ukazatel na řetězec do, kterého bude uložen získaný název sekce.
     *  \return Vrací pravdu při úspěšném získání sekce, v opačném případě nepravdu.
     */
    bool parseSection(std::string input, std::string *section);

    /*! \fn bool parseValue(std::string sectionName, std::string input)
     *  \brief Metoda sloužící k získání klíče a hodnoty, s textového řetězce.
     *  \param sectionName Ukazatel na řetězec do, kterého bude uložen získaný název sekce.
     *  \param input Vstupní textový řetězec.
     *  \return Vrací pravdu při úspěšném získání klíče a hodnoty. V opačném případě nepravdu.
     */
    bool parseValue(std::string sectionName, std::string input);

    /*! \var configPath
     *  \brief Proměnná obsahující cestu ke konfiguračnímu souboru.
     */
    std::string configPath;

    /*! \var configFile
     *  \brief Proměnná obsahující instanci fstreamu.
     */
    std::fstream configFile;

    /*! \var sections
     *  \brief Mapa obsahující ukazatele na objekty, které reprezentují sekce.
     */
    std::map<std::string, ConfSection *> sections;
};
}

#endif	/* _CONFIGURATION_H */

