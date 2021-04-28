#ifndef SERVICE_H
#define SERVICE_H

#include <QWidget>
#include <QTreeWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QHeaderView>
#include <QKeyEvent>

#include "common.h"

class Service : public QWidget{

    Q_OBJECT

public:
    Service(QWidget *parent = nullptr);
    virtual ~Service(){}

private:
    QVBoxLayout *vlayout = nullptr;
    QTreeWidget *treeWidget = nullptr;
    QLabel *labTotalService = nullptr;
    QTreeWidgetItem *root = nullptr;

    QStringList headerName = {"Name", "ServiceName", "State"};
    DATA data;
    void addRoot(LISTSERVICE lsService);

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void listService(LISTSERVICE &data);

private slots:
    void contextMenu(QPoint pos);
    void getListService();

signals:
    void send(DATA &data);
};
#endif
