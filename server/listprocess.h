#ifndef LISTPROCESS_H
#define LISTPROCESS_H

#include <QWidget>
#include <QTreeWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QMenu>
#include <QHeaderView>
#include <QMessageBox>
#include <QKeyEvent>

#include "common.h"

class ListProcess : public QWidget{

    Q_OBJECT

public:
    ListProcess(QWidget *parent = nullptr);
    virtual ~ListProcess(){}

private:
    QGroupBox *groupBox = nullptr;
    QLineEdit *lineEdit = nullptr;
    QPushButton *btnCreateProc = nullptr;    
    QCheckBox *procHide = nullptr;
    QTreeWidget *treeWidget = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QVBoxLayout *vvlayout = nullptr;
    QHBoxLayout *createHlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;
    QLabel *labTotalProc = nullptr;

    QStringList headerName = {"Name", "PID", "PPID", "Path"};

    DATA data;
    void addRoot(LISTPROC lsService);

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void listProc(LISTPROC &data);
    void message(const QString &msg);

private slots:
    void contextMenu(QPoint pos);
    void getListProcess();
    void killProc();
    void createProcess();

signals:
    void send(DATA &data);
    void sendKill(DATA &data);
};
#endif // LISTPROCESS_H
