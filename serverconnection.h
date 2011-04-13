#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include "servermessages.h"
#include "serverconnectiontyps.h"
#include "user.h"

class ServerConnection : public QTcpServer
{
    Q_OBJECT

public:
    ServerConnection(quint16 port, QHostAddress host = QHostAddress::Any, QObject* parent = 0);
    void serverStatus(){ emit message(_serverStatus, _serverStatusTyp); };

private:
    QHostAddress               _hostAddress;
    quint16                    _port;
    QString                    _serverStatus;
    ServerMessages::MessageTyp _serverStatusTyp;

    QHash<QTcpSocket*, User*>  _users;

private:
    void incomingConnection ( int socketDescriptor );
    bool isNameExistent(QString name);
    qint32 connectionTyp(ServerConnectionTyps::ConnectionTyp t){ return (qint32)t; }

private slots:
    void socketReadyRead();
    void socketDisconnected();

signals:
    void message(QString text, ServerMessages::MessageTyp typ);
};

#endif // TCPSERVER_H
