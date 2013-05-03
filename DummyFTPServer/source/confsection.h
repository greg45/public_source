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

#ifndef _CONFSECTION_H
#define	_CONFSECTION_H

#include <iostream>
#include <string>
#include <map>

namespace DummyFTPServer {

/*! \class ConfSection
 *  \brief Objekt reprezentující jednu sekci databáze nastavení.
 */
class ConfSection {
public:
    /*! \fn ConfSection(std::string name)
     *  \brief Vytváří objekty, které reprezentují sekce.
     *  \param name Nastavuje název sekce.
     */
    ConfSection(std::string name);

    /*! \fn std::string getName() const;
     *  \brief Slouží k získání jména sekce.
     *  \return Vrací název sekce.
     */
    std::string getName() const;

    /*! \fn int getCount() const
     *  \brief Slouží k získání počtu položek.
     *  \return Vrací počet položek v sekci.
     */
    int getCount() const;

    /*! \fn std::string getValue(std::string key)
     *  \brief Slouží k získání hodnoty.
     *  \return Vrací hodnotu podle hledaného klíče.
     */
    std::string getValue(std::string key);

    /*! \fn bool append(std::string key, std::string value)
     *  \brief Slouží k přidání položky.
     *  \param key Nastaví klíč.
     *  \param value Nastaví hodnotu.
     *  \return Vrací pravdu při úspěšném přidání, v opačném případě nepravdu.
     */
    bool append(std::string key, std::string value);

    /*! \fn bool remove(std::string key)
     *  \param key Nastaví klíč.
     *  \brief Slouží k smazání položky podle klíče.
     *  \return Vrací pravdu při úspěšném smazání, v opačném případě nepravdu.
     */
    bool remove(std::string key);

private:
    /*! \var name
     *  \brief Název sekce.
     */
    std::string name;

    /*! \var items
     *  \brief Mapa položek.
     */
    std::map<std::string, std::string> items;
};
}

#endif	/* _CONFSECTION_H */

