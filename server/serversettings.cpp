#include "serversettings.h"

ServerSettings::ServerSettings(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);
    groupClient = new QGroupBox();
    vlayout->addWidget(groupClient);
    groupClient->setTitle(tr("List clients"));
    clientHlayout = new QHBoxLayout();
    groupClient->setLayout(clientHlayout);
    listClient = new QComboBox(this);
    clientHlayout->addWidget(listClient);

    groupSetting = new QGroupBox(this);
    groupSetting->setTitle(tr("Server settings"));
    vlayout->addWidget(groupSetting);
    settingVlayout = new QVBoxLayout();
    settingHlayout = new QHBoxLayout();
    hlayout = new QHBoxLayout();
    hlayout->addLayout(settingVlayout);
    groupSetting->setLayout(hlayout);
    ipAddr = new QLineEdit(this);
    ipAddr->setText("127.0.0.1");
    ipAddr->setPlaceholderText(tr("Input ip address"));
    settingVlayout->addWidget(ipAddr);
    port = new QLineEdit(this);
    port->setText("2035");
    port->setMaxLength(5);
    port->setValidator(new QIntValidator(0, 99999, this));
    port->setPlaceholderText(tr("Input port"));
    settingVlayout->addWidget(port);
    settingVlayout->addLayout(settingHlayout);

    btnListen = new QPushButton(tr("Listen"), this);
    btnListen->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    settingHlayout->addWidget(btnListen);
    btnDisconnect = new QPushButton(tr("Disconnect"), this);
    btnDisconnect->setEnabled(false);
    btnDisconnect->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    settingHlayout->addWidget(btnDisconnect);

    groupstat = new QGroupBox(this);
    groupstat->setTitle((tr("Logging")));
    vlayout->addWidget(groupstat);
    statVlayout = new QVBoxLayout();
    statClient = new QTextEdit(this);
    statClient->setReadOnly(true);
    statVlayout->addWidget(statClient);
    groupstat->setLayout(statVlayout);

    connect(btnListen, SIGNAL(clicked()), this, SLOT(setSettingsServer()));
    connect(btnDisconnect, SIGNAL(clicked()), this, SLOT(disconnectServer()));
    connect(listClient, SIGNAL(currentTextChanged(const QString &)), this, SIGNAL(currentClient(const QString &)));
}

void ServerSettings::clientDisconnect(const QString &client){
    listClient->removeItem(listClient->findText(client));
}

void ServerSettings::setStatisticClient(const QString &ipAddress, const uint16_t port){
    listClient->addItem(ipAddress);
    statClient->insertPlainText(QString("\r\nConnected...\r\nIP address: %1\r\nPort: %2\r\nDate: %3\r\n").arg(ipAddress).arg(port).arg(QDateTime::currentDateTime().toString("dd.MM.yyyy hh.mm.ss")));
}

void ServerSettings::setSettingsServer(){
    if(! port->text().isEmpty()){
        ipAddr->setEnabled(false);
        port->setEnabled(false);
        btnListen->setEnabled(false);
        btnDisconnect->setEnabled(true);
        emit settingsServer(ipAddr->text(), port->text().toUShort());
    }
    else
        QMessageBox::warning(this, tr("Server settings"), tr("Enter ip address and port"), QMessageBox::Ok);
}

void ServerSettings::disconnectServer(){
    ipAddr->setEnabled(true);
    ipAddr->clear();
    port->setEnabled(true);
    port->clear();
    btnListen->setEnabled(true);
    btnDisconnect->setEnabled(false);
    emit stopServer();
}
