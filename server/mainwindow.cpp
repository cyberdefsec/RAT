#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    resize(WIDTH, HIEGHT);

    centerWidget = new QWidget(this);
    setCentralWidget(centerWidget);

    hlayout = new QHBoxLayout();
    centerWidget->setLayout(hlayout);

    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderHidden(true);
    treeWidget->setRootIsDecorated(false);
    treeWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    hlayout->addWidget(treeWidget);
    addRoot("Computer");

    stackWidget = new QStackedWidget(this);
    stackWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    hlayout->addWidget(stackWidget);

    serverSettings = new ServerSettings(this);
    stackWidget->addWidget(serverSettings);

    fileManager = new FileManager(this);
    stackWidget->addWidget(fileManager);

    service = new Service(this);
    stackWidget->addWidget(service);

    listProcess = new ListProcess(this);
    stackWidget->addWidget(listProcess);

    users = new Users(this);
    stackWidget->addWidget(users);

    groups = new Groups(this);
    stackWidget->addWidget(groups);

    sysInfo = new SysInfo(this);
    stackWidget->addWidget(sysInfo);

    netInfo = new NetInfo(this);
    stackWidget->addWidget(netInfo);

    remoteShell = new RemoteShell(this);
    stackWidget->addWidget(remoteShell);

    host = new Host(this);
    stackWidget->addWidget(host);

    thread = new QThread(this);

    srv = new Server();
    srv->moveToThread(thread);
    thread->start();

    connect(serverSettings, SIGNAL(settingsServer(const QString &, const quint16)), srv, SLOT(setAddressServer(const QString&, const quint16)));
    connect(srv, SIGNAL(statisticClient(const QString&, const quint16)), serverSettings, SLOT(setStatisticClient(const QString&, const quint16)));
    connect(srv, SIGNAL(clientDisconnected(const QString&)), serverSettings, SLOT(clientDisconnect(const QString&)));
    connect(serverSettings, SIGNAL(stopServer()), srv, SLOT(stopServer()));
    connect(serverSettings, SIGNAL(currentClient(const QString&)), srv, SLOT(setCurrentClient(const QString&)));

    connect(fileManager, SIGNAL(sendDisk(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvListDisk(LISTDISK&)), fileManager, SLOT(setListDisk(LISTDISK&)));
    connect(fileManager, SIGNAL(sendDir(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvListDir(LISTDIR&)), fileManager, SLOT(setListDir(LISTDIR&)));
    connect(fileManager, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(sendFileManager(const QString&)), fileManager, SLOT(message(const QString&)));

    connect(remoteShell, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvShell(QByteArray)), remoteShell, SLOT(shellData(QByteArray)));

    connect(sysInfo, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvSysInfo(QByteArray)), sysInfo, SLOT(sysInfoData(QByteArray)));

    connect(netInfo, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvNetInfo(NETINFO)), netInfo, SLOT(netInfoData(NETINFO)));

    connect(service, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvListService(LISTSERVICE&)), service, SLOT(listService(LISTSERVICE&)));

    connect(listProcess, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvListProc(LISTPROC&)), listProcess, SLOT(listProc(LISTPROC&)));
    connect(srv, SIGNAL(sendProcess(const QString&)), listProcess, SLOT(message(const QString&)));

    connect(users, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvListUsers(INFOUSER&)), users, SLOT(listUsers(INFOUSER&)));
    connect(srv, SIGNAL(sendUsers(const QString&)), users, SLOT(message(const QString&)));

    connect(groups, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvListGroups(INFOGROUP&)), groups, SLOT(listGroups(INFOGROUP&)));
    connect(srv, SIGNAL(sendGroup(const QString&)), groups, SLOT(message(const QString&)));

    connect(host, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvScreenShot(QByteArray)), host, SLOT(screenDesktop(QByteArray)));

    connect(host, SIGNAL(send(DATA&)), srv, SLOT(sendData(DATA&)));
    connect(srv, SIGNAL(recvBuffer(QByteArray)), host, SLOT(setBuffer(QByteArray)));

    connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(getChild(QTreeWidgetItem *)));
}

MainWindow::~MainWindow(){
    if(thread->isRunning()){
        thread->terminate();
        thread->quit();
    }
}

void MainWindow::addRoot(const QString &nameRoot){
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setText(0, nameRoot);
    root->setIcon(0, QIcon(":/ico/computer.png"));
    root->setExpanded(true);
    for(int count = 0; count < listName.size(); count++)
        addChild(root, listName[count], listIco[count]);
}

void MainWindow::addChild(QTreeWidgetItem *parent, const QString &nameChild, const QString &icoChild){
    QTreeWidgetItem *child = new QTreeWidgetItem();
    child->setText(0, nameChild);
    child->setIcon(0, QIcon(icoChild));
    parent->addChild(child);
}

void MainWindow::getChild(QTreeWidgetItem *item){
    if(item->parent())
        stackWidget->setCurrentIndex(treeWidget->currentIndex().row());
}
