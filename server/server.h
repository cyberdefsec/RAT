#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QThread>

#include "common.h"
#include "serversettings.h"

class Server : public QObject{

    Q_OBJECT

public:
    Server(QObject *parent = nullptr);
    virtual ~Server(){}
    QTcpServer *srv = nullptr;
    QMap <QString, QTcpSocket*> listClients;

private:
    QString currentClient;
    COMMANDS command;
    QVector<LISTSERVICE> tmp;
    QThread *thread = nullptr;
    NETINFO net;
    LISTSERVICE lsSrv;
    LISTPROC lsproc;
    LISTDISK disk;
    LISTDIR dir;
    INFOUSER users;
    INFOGROUP grp;
    DATA data;

public slots:
    void setAddressServer(const QString &ipAddress, const quint16 port);
    void clientDisconnect();
    void stopServer();
    void setCurrentClient(const QString &curClient);
    void sendData(DATA &data);
    void recvData();

private slots:
    void clientConnect();

signals:
    void statisticClient(const QString &ipAddress, const quint16 port);
    void clientDisconnected(const QString &client);
    void recvShell(QByteArray data);
    void recvSysInfo(QByteArray data);    
    void recvListDir(LISTDIR &data);
    void recvListProc(LISTPROC &data);
    void recvListDisk(LISTDISK &data);
    void recvListUsers(INFOUSER &data);
    void recvListGroups(INFOGROUP &data);
    void recvNetInfo(NETINFO data);
    void recvListService(LISTSERVICE &data);
    void recvScreenShot(QByteArray data);
    void sendFileManager(const QString &msg);
    void sendProcess(const QString &msg);
    void sendGroup(const QString &msg);
    void sendUsers(const QString &msg);
    void recvFile(const QByteArray &data);
    void recvBuffer(QByteArray data);
};
#endif
