#ifndef USERS_H
#define USERS_H

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

class DialogUsers : public QDialog{

    Q_OBJECT

public:
    DialogUsers(const QString &title, QWidget *parent = nullptr);
    virtual ~DialogUsers(){}
    QLineEdit *lineName = nullptr;
    QLineEdit *linePass = nullptr;
    QPushButton *btnOk = nullptr;
    QPushButton *btnCancel = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;
    void setCommand(COMMANDS cmd);
    void setNameUser(const QString &nameUser);
    void setPlaceholder(const QString &str1, const QString &str2);

private:
    DATA data;
    QString name;

private slots:
    void apply();

signals:
    void sendApply(DATA &data);
};

class Users : public QWidget{

    Q_OBJECT

public:
    Users(QWidget *parent = nullptr);
    virtual ~Users(){}

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QTreeWidget *treeWidget = nullptr;
    QLabel *labTotalUsr = nullptr;
    QVBoxLayout *vlayout = nullptr;

    QStringList headerName = {"Name", "Comment", "SID"};
    DATA data;
    void addRoot(INFOUSER lsService);

public slots:
    void listUsers(INFOUSER &data);
    void message(const QString &msg);

private slots:
    void contextMenu(QPoint pos);
    void getListUsers();
    void createUser();
    void removeUser();
    void changePassowrd();
    void blockUser();

signals:
    void send(DATA &data);
};
#endif
