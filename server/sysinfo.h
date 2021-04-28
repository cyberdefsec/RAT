#ifndef SYSINFO_H
#define SYSINFO_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QAction>
#include <QMenu>

#include "common.h"

class SysInfo : public QTextEdit{

    Q_OBJECT

public:
    SysInfo(QWidget *parent = nullptr);
    virtual ~SysInfo(){}

protected:
    virtual void contextMenuEvent(QContextMenuEvent *) override{}
private:    
    QString html;
    DATA data;

private slots:
    void contextMenu(QPoint pos);
    void getSysInfo();

public slots:
    void sysInfoData(QByteArray data);

signals:
    void send(DATA &data);
};
#endif
