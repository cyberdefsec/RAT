#ifndef NETINFO_H
#define NETINFO_H

#include <QTabWidget>
#include <QTextEdit>
#include <QAction>
#include <QMenu>

#include "common.h"

class NetInfo : public QTextEdit{

    Q_OBJECT

public:
    NetInfo(QWidget *parent = nullptr);
    virtual ~NetInfo(){}    

protected:
    virtual void contextMenuEvent(QContextMenuEvent *) override{}

private:
    DATA data;

private slots:
    void contextMenu(QPoint pos);
    void getNetInfo();

public slots:
    void netInfoData(NETINFO data);

signals:
    void send(DATA &data);
};

#endif
