#include "netinfo.h"

NetInfo::NetInfo(QWidget *parent) : QTextEdit(parent){
    setReadOnly(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void NetInfo::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);
    QAction *actUpdate = new QAction(QIcon("://ico/refresh.png"), tr("Update"), this);
    menu->addAction(actUpdate);
    menu->popup(viewport()->mapToGlobal(pos));

    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getNetInfo()));
}

void NetInfo::getNetInfo(){
    memset(&data, '\0', sizeof(data));
    data.cmd = SYSNET;
    clear();
    insertHtml("<center><h1>Network</h1>");
    emit send(data);
}

void NetInfo::netInfoData(NETINFO data){
    insertHtml(QString("<br><h3>Interface: %1</h3><h3>IP address: %2</h3><h3>Netmask: %3</h3><h3>Gateway: %4</h3><h3>DHCP enable: %5</h3><h3>DHCP server: %6</h3><h3>MAC address: %7</h3>").arg(data.device).arg(data.ipaddr).arg(data.mask).arg(data.gateway).arg(data.isDhcp?"true":"false").arg(data.dhcp).arg(data.mac));
}
