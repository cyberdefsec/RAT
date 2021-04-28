#ifndef SERVERSETTINGS_H
#define SERVERSETTINGS_H

#include <QWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QValidator>
#include <QMessageBox>
#include <QDateTime>


class ServerSettings : public QWidget{

    Q_OBJECT

public:
    ServerSettings(QWidget *parent = nullptr);
    virtual ~ServerSettings(){}

private:
    QComboBox *listClient = nullptr;
    QLineEdit *ipAddr = nullptr;
    QLineEdit *port = nullptr;
    QPushButton *btnListen = nullptr;
    QPushButton *btnDisconnect = nullptr;
    QGroupBox *groupClient = nullptr;
    QHBoxLayout *clientHlayout = nullptr;
    QGroupBox *groupSetting = nullptr;
    QVBoxLayout *settingVlayout = nullptr;
    QHBoxLayout *settingHlayout = nullptr;
    QGroupBox *groupstat = nullptr;
    QTextEdit *statClient = nullptr;
    QVBoxLayout *statVlayout = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;

public slots:
    void setStatisticClient(const QString &ipAddress, const quint16 port);
    void clientDisconnect(const QString &client);

private slots:
    void setSettingsServer();
    void disconnectServer();

signals:
    void settingsServer(const QString &ipAddress, const quint16 port);
    void stopServer();
    void currentClient(const QString &client);
};

#endif
