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

#ifndef FTPSERVER_H
#define FTPSERVER_H

#include <QList>
#include <QObject>
#include <QTcpServer>

#include "serverthread.h"

namespace DummyFTPServer {

/*! \class FTPServer
 *  \brief Třída reprezentuje FTP server.
 */
class FTPServer : public QObject {
    Q_OBJECT

public:
    /*! \fn FTPServer(unsigned int tcpPort, QObject *parent = 0)
     *  \brief Vytváří objekt, který reprezentuje FTP server.
     *  \param tcpPort Nastaví port na, kterém bude ftp server poslouchat.
     *  \param parent Ukazatel na předka.
     */
    FTPServer(unsigned int tcpPort, QObject *parent = 0);

    /*! \fn unsigned int getPort()
     *  \brief Slouží k získání nastaveného portu.
     */
    static unsigned int getPort() {
        return port;
    }
    ~FTPServer();

    /*! \fn void start(unsigned int tcpPort)
     *  \brief Zapne server.
     *  \param tcpPort Nastaví port na, kterém bude ftp server poslouchat.
     */
    static void start(unsigned int tcpPort);

    /*! \fn void stop()
     *  \brief Zastaví server.
     */
    static void stop();

    /*! \fn void restart()
     *  \brief Provede restart serveru.
     */
    static void restart();

    /*! \fn bool isRunning()
     *  \brief Zjistí stav serveru.
     */
    static bool isRunning();

public slots:
    /*! \fn void addConnection()
     *  \brief Tento slot obsluhuje nová spojení.
     */
    void addConnection();

signals:
    /*! \fn void closing()
     *  \brief Signalizuje ukončení naslouchání.
     */
    void closing();

private:
    /*! \fn bool clean()
     *  \brief Uvolní paměť.
     */
    bool clean();

    /*! \var pInstance
     *  \brief Instance FTP serveru.
     */
    static FTPServer *pInstance;

    /*! \var socket
     *  \brief Socket FTP Serveru.
     */
    QTcpServer *socket;

    /*! \var threadList
     *  \brief Seznam klientských vláken.
     */
    QList<QObject *> threadList;

    /*! \fn unsigned int port
     *  \brief Port na, kterém bude server poslouchat.
     */
    static unsigned int port;
};
}

#endif // FTPSERVER_H
