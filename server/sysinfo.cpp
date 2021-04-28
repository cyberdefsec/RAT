#include "sysinfo.h"

SysInfo::SysInfo(QWidget *parent) : QTextEdit(parent){
    setReadOnly(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void SysInfo::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);
    QAction *actUpdate = new QAction(QIcon("://ico/refresh.png"), tr("Update"), this);
    menu->addAction(actUpdate);
    menu->popup(viewport()->mapToGlobal(pos));

    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getSysInfo()));
}

void SysInfo::getSysInfo(){
    memset(&data, '\0', sizeof(data));
    data.cmd = SYS;
    emit send(data);

}

void SysInfo::sysInfoData(QByteArray data){
    SYSINFO *info = reinterpret_cast<SYSINFO*>(data.data());
    clear();
    html.clear();
    html.append(QString("<center><h1> Operation system </h1></center>\r\n<h3>Current user: %1</h3>\r\n<h3>Domain name: %2</h3>\r\n<h3>Hostname: %3</h3>\r\n<hr>\r\n<h3>OS: %4</h3>\r\n<h3>System directory: %5</h3>\r\n<h3>Windows dirictory: %6</h3>\r\n<hr>\r\n<h3>Processor: %7</h3>\r\n<h3>Architecture: %8</h3>\r\n<h3>Screen: %9 x %10</h3>\r\n").arg(info->currUser).arg(info->domainName).arg(info->hostName).arg(info->nameOS).arg(info->sysDir).arg(info->winDir).arg(info->processor).arg(info->architecture).arg(info->w).arg(info->h));
    insertHtml(html);
}
