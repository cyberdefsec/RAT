#ifndef GROUPS_H
#define GROUPS_H

#include <QWidget>
#include <QTreeWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QKeyEvent>
#include <QHeaderView>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

#include "common.h"

class Dialog : public QDialog{

    Q_OBJECT

public:
    Dialog(const QString &title, QWidget *parent = nullptr);
    virtual ~Dialog(){}
    QLineEdit *lineName = nullptr;
    QPushButton *btnOk = nullptr;
    QPushButton *btnCancel = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;
    void setCommand(COMMANDS cmd);
    void setNameGroup(const QString &nameGroup);

private:
    DATA data;
    QString grp;

private slots:
    void apply();
signals:
    void sendApply(DATA &data);
};

class Groups : public QWidget{

    Q_OBJECT

public:
    Groups(QWidget *parent = nullptr);
    virtual ~Groups(){}

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QTreeWidget *treeWidget = nullptr;
    QLabel *labTotalGrp = nullptr;
    QVBoxLayout *vlayout = nullptr;

    QStringList headerName = {"Name", "comment"};
    DATA data;
    void addRoot(INFOGROUP lsGroups);

public slots:
    void listGroups(INFOGROUP &data);
    void createGroup();
    void removeGroup();
    void addUserInGroup();
    void message(const QString &msg);

private slots:
    void contextMenu(QPoint pos);
    void getListGroups();

signals:
    void send(DATA &data);
};
#endif
