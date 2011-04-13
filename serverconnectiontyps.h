#ifndef SERVERCONNECTIONTYPS_H
#define SERVERCONNECTIONTYPS_H

#include <QObject>

class ServerConnectionTyps : public QObject
{
    Q_OBJECT
public:
    typedef enum ConnectionTyp
    {
        CONNECTIONACCEPTED,
        USERNAME,
        USERNAMEACCEPTED,
        USERNAMEDENIED,
        USERNAMES,
    }
    ConnectionTyp;

};

#endif // SERVERCONNECTIONTYPS_H