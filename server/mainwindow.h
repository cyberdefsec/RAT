#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QThread>

#include "serversettings.h"
#include "filemanager.h"
#include "service.h"
#include "users.h"
#include "groups.h"
#include "sysinfo.h"
#include "netinfo.h"
#include "host.h"
#include "shell.h"
#include "server.h"
#include "listprocess.h"

#define WIDTH 800
#define HIEGHT 600

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget *centerWidget = nullptr;
    QTreeWidget *treeWidget = nullptr;
    QHBoxLayout *hlayout = nullptr;
    void setTextTopLevel(const QString &name);
    QList<QTreeWidgetItem*> rootItem;
    QList<QTreeWidgetItem*> childItem;
    QStackedWidget *stackWidget = nullptr;
    ServerSettings *serverSettings = nullptr;
    FileManager *fileManager = nullptr;    
    Service *service = nullptr;
    ListProcess *listProcess = nullptr;
    Users *users = nullptr;
    Groups *groups = nullptr;
    SysInfo *sysInfo = nullptr;
    NetInfo *netInfo = nullptr;
    RemoteShell *remoteShell = nullptr;
    Host *host = nullptr;
    Server *srv = nullptr;

private:
    QThread *thread = nullptr;
    QStringList listName = {"Server", "FileManager", "Service", "Process", "Users", "Groups", "System information", "Network information", "Remote shell", "Host"};
    QStringList listIco = {":/ico/server.png", ":/ico/filemanager.png", ":/ico/service.png", ":/ico/process.png", ":/ico/users.png",":/ico/groups.png", ":/ico/sysinfo.png", ":/ico/network.png", ":/ico/shell.png", ":/ico/host.png"};

public slots:
    void addRoot(const QString &nameRoot);
    void addChild(QTreeWidgetItem *parent, const QString &nameChild, const QString &icoChild);
    void getChild(QTreeWidgetItem *item);
};
#endif // MAINWINDOW_H
