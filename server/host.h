#ifndef HOST_H
#define HOST_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QScrollArea>
#include <QMenu>
#include <QAction>
#include <QFile>
#include <QDateTime>
#include <QCoreApplication>
#include <QTabWidget>
#include <QTextEdit>

#include "common.h"

class ClipBoard : public QTextEdit{

    Q_OBJECT

public:
    ClipBoard(QWidget *parent = nullptr);
    virtual ~ClipBoard(){}

protected:
    virtual void contextMenuEvent(QContextMenuEvent *) override{}

private:
    DATA data;

private slots:
    void contextMenu(QPoint pos);
    void getBuffer();

signals:
    void sendBuf(DATA &data);
};

class Host : public QWidget{

    Q_OBJECT

public:
    Host(QWidget *parent = nullptr);
    virtual ~Host(){}

private:
    QPushButton *btnReboot = nullptr;
    QPushButton *btnPoweroff = nullptr;
    QPushButton *btnLogonOff = nullptr;
    QGroupBox *grpControl = nullptr;
    QTabWidget *tabWidget = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;    
    QScrollArea *scrollArea = nullptr;
    QLabel *screenShot = nullptr;
    ClipBoard *clip = nullptr;

public slots:
    void screenDesktop(QByteArray data);
    void setBuffer(QByteArray data);

private slots:
    void contextMenu(QPoint pos);
    void getScreenShot();

signals:
    void send(DATA &data);
};

#endif
