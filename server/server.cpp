#include "server.h"

Server::Server(QObject *parent) : QObject(parent){
    srv = new QTcpServer(this);
    connect(srv, SIGNAL(newConnection()), this, SLOT(clientConnect()));
}

void Server::sendData(DATA &data){
    command = data.cmd;
    if((! currentClient.isEmpty()) && listClients[currentClient]->state() == QAbstractSocket::ConnectedState){
        listClients[currentClient]->write((char*)&data, sizeof(data));
    }
}

void Server::recvData(){
    qint64 len = 0;
    while((len = listClients[currentClient]->bytesAvailable()) > 0){
        switch(command){
            case SYS :
                emit recvSysInfo(listClients[currentClient]->readAll());
                break;
            case SYSNET :
                listClients[currentClient]->read((char*)&net, sizeof(net));
                emit recvNetInfo(net);
                break;
            case DISK :
                listClients[currentClient]->read((char*)&disk, sizeof(disk));
                emit recvListDisk(disk);
                break;
            case LSDIR :
                listClients[currentClient]->read((char*)&dir, sizeof(dir));
                emit recvListDir(dir);
                break;
            case RMDIR :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendFileManager(tr("Removing dirictory success!!!"));
                break;
            case RMFILE :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendFileManager(tr("Removing file success!!!"));
                break;
            case CRFILE :
                break;
            case CRDIR :
                break;
            case RNAME :
                break;
            case ATTR :
                break;
            case LSPROC :                
                listClients[currentClient]->read((char*)&lsproc, sizeof(lsproc));
                emit recvListProc(lsproc);
                break;
            case CRPROC :                
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendProcess(tr("Create process success!!!"));
                break;
            case KILLP :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendProcess(tr("Process kill success!!!"));
                break;
            case SHELL :
                emit recvShell(listClients[currentClient]->readAll());
                break;
            case REBOOT :
                break;
            case POWEROFF :
                break;
            case LOGONOFF :
                break;
            case SCREEN :
                recvScreenShot(listClients[currentClient]->readAll());
                break;
            case CLBUF :
            recvBuffer(listClients[currentClient]->readAll());
                break;
            case DOWNLOAD :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit recvFile(data.data);
                break;
            case UPLOAD :
                break;
            case LSUSR :                
                listClients[currentClient]->read((char*)&users, sizeof(users));
                emit recvListUsers(users);
                break;
            case CRUSR :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendUsers(tr("Create user!!!"));
                break;
            case RMUSR :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendUsers(tr("Remove user!!!"));
                break;
            case BLCKUSR :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendUsers(tr("Success!!!"));
                break;
            case PASSUSR :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendUsers(tr("Passowrd change success!!!"));
                break;
            case LSGRP :
                listClients[currentClient]->read((char*)&grp, sizeof(grp));
                emit recvListGroups(grp);
                break;
            case CRGRP :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendGroup(tr("Create group!!!"));
                break;
            case RMGRP :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendGroup(tr("Remove group!!!"));
                break;
            case ADDUSRGRP :
                listClients[currentClient]->read((char*)&data, sizeof(data));
                if(data.err == 0)
                    emit sendGroup(tr("Add user group!!!"));
                break;
            case LSSRV :
                listClients[currentClient]->read((char*)&lsSrv, sizeof(lsSrv));
                emit recvListService(lsSrv);
                break;
        }
    }
}

void Server::clientConnect(){
    QTcpSocket *client = srv->nextPendingConnection();
    QString ip = client->peerAddress().toString();
    quint16 port = client->peerPort();
    if(! listClients.contains(ip)){
        listClients.insert(ip, client);
        emit statisticClient(ip, port);
        connect(listClients[ip], SIGNAL(disconnected()), this, SLOT(clientDisconnect()));
    }
    else
        client->close();

}

void Server::clientDisconnect(){
    QTcpSocket *sock = qobject_cast<QTcpSocket*>(sender());
    emit clientDisconnected(listClients.key(sock));
    listClients.remove(listClients.key(sock));
}

void Server::stopServer(){
    QMap <QString, QTcpSocket*>::iterator it = listClients.begin();
    for(;  it != listClients.end(); it++){
        if(it.value()->state() == QAbstractSocket::ConnectedState)
            it.value()->close();
    }
    srv->close();
}

void Server::setCurrentClient(const QString &curClient){
    currentClient = curClient;    
    if(! currentClient.isEmpty())
        connect(listClients[currentClient], SIGNAL(readyRead()), this, SLOT(recvData()));
}

void Server::setAddressServer(const QString &ipAddress, const quint16 port){
    if(ipAddress.isEmpty())
        srv->listen(QHostAddress::Any, port);
    else
        srv->listen(QHostAddress(ipAddress), port);
}
