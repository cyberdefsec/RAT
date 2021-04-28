#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QWidget>
#include <QTreeWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QCheckBox>
#include <QGridLayout>
#include <QHeaderView>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFileInfo>

#include "common.h"

class ChangeAttribute : public QDialog{

    Q_OBJECT

public:
    ChangeAttribute(QWidget *parent = nullptr);
    virtual ~ChangeAttribute(){}
    void setName(const QString &name, QString attr);

private:
    QCheckBox *hideAttr = nullptr;
    QCheckBox *readAttr = nullptr;
    QCheckBox *normAttr = nullptr;
    QCheckBox *sysAttr = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QGridLayout *gridLayout = nullptr;
    QLabel *nameFile = nullptr;
    QPushButton *btnApply = nullptr;
    QPushButton *btnCancel = nullptr;
    DWORD attr = 0;
    QString name;

private slots:
    void attribute();

signals:
    void attributes(const QString &nameFile, DWORD attr);

};

class Create : public QDialog{

    Q_OBJECT

public:
    Create(const QString &title, QWidget *parent = nullptr);
    virtual ~Create(){}
    QPushButton *btnCreate = nullptr;
    QPushButton *btnCancel = nullptr;
    QLineEdit *lineName = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QHBoxLayout *hlayout = nullptr;
    void setPath(const QString &path, COMMANDS cmd){ name = path; data.cmd = cmd; }

private:
    QString name;
    DATA data;

private slots:
   void setName();

signals:
    void getName(DATA &data);
};

class FileManager : public QWidget{

    Q_OBJECT

public:
    FileManager(QWidget *parent = nullptr);
    virtual ~FileManager(){}

private:
    QWidget *wdg = nullptr;
    QPushButton *btnRefresh = nullptr;
    QPushButton *btnHome = nullptr;
    QComboBox *listDisk = nullptr;
    QLineEdit *linePath = nullptr;
    QTreeWidget *treeWidget = nullptr;
    QLabel *labSizeTotal = nullptr;
    QLabel *labCountDir = nullptr;
    QLabel *labCountFile = nullptr;
    QHBoxLayout *hlayout = nullptr;
    QHBoxLayout *hlayout2 = nullptr;
    QVBoxLayout *vlayout = nullptr;
    QAction *actUpdate = nullptr;
    QAction *actCreateDir = nullptr;
    QAction *actCreateFile = nullptr;
    QAction *actRemove = nullptr;
    QAction *actRename = nullptr;
    QAction *actAttribute = nullptr;
    QAction *actDownload = nullptr;
    QAction *actUpload = nullptr;

    QVector<ULONGLONG> totalSize;
    QStringList headerName = {"Name", "Size", "Attribute", "Date Modified"};
    DATA data;
    QString name;
    quint64 countDir;
    quint64 countFile;

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void setListDisk(LISTDISK &disk);
    void setListDir(LISTDIR &data);
    void message(const QString &msg);    

private slots:
    void contextMenu(const QPoint &pos);
    void openAttribute();
    void getListDisk();
    void getListDir(const QString &path);
    void openDir(QTreeWidgetItem *item);
    void removes();
    void createDir();
    void createFile();   
    void rename();
    void currentUpdate();
    void backHome();
    void setAttributes(const QString& nameFile, DWORD attr);

signals:
    void sendDisk(DATA &data);
    void sendDir(DATA &data);
    void send(DATA &data);

};
#endif
