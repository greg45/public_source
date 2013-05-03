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

#include "confsection.h"

namespace DummyFTPServer {

ConfSection::ConfSection(std::string name) {
    this->name = name;
}

std::string ConfSection::getName() const {
    return name;
}

int ConfSection::getCount() const {
    return (int) items.size();
}

std::string ConfSection::getValue(std::string key) {
    std::map<std::string, std::string>::iterator it;

    for (it = items.begin(); it != items.end(); it++) {
        if ((*it).first == key)
            return (*it).second;
    }

    return std::string("");
}

bool ConfSection::append(std::string key, std::string value) {
    this->items.insert(std::pair<std::string, std::string > (key, value));

    return true;
}

bool ConfSection::remove(std::string key) {
    std::map<std::string, std::string>::iterator it = items.find(key);
    items.erase(it);

    return true;
}
}
