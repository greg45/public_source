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

#ifndef FTPCOMMANDRETR_H
#define FTPCOMMANDRETR_H

#include <QObject>
#include "ftpcommand.h"

namespace DummyFTPServer {

/*! \class FTPCommandRETR
 *  \brief Zajišťuje obsluhu FTP příkazu RETR.
 */
class FTPCommandRETR : public FTPCommand {

    Q_OBJECT

public:
    /*! \fn FTPCommandRETR(const QString &fileName, ServerThread *parent)
     *  \brief Vytváří objekt pro zpracování FTP příkaz RETR.
     *  \param fileName Nastaví cestu k souboru.
     *  \param parent Ukazatel na předka.
     */
    FTPCommandRETR(const QString &fileName, ServerThread *parent);

public slots:
    /*! \fn void sendData()
     *  \brief Slot, který při zavolání naplní socket daty.
     */
    void sendData();

    /*! \fn void error(bool stop = true)
     *  \brief Slot, který obsluhuje chybové stavy.
     */
    void error(bool stop = true);
};
}

#endif // FTPCOMMANDRETR_H
