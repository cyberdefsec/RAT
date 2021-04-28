#include "groups.h"

Groups::Groups(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);

    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(2);
    treeWidget->setHeaderLabels(headerName);
    vlayout->addWidget(treeWidget);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    labTotalGrp = new QLabel(tr("Total groups: 0"), this);
    vlayout->addWidget(labTotalGrp);

    connect(treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void Groups::listGroups(INFOGROUP &data){
    addRoot(data);
    labTotalGrp->setText(QString(tr("Total groups: %1")).arg(treeWidget->topLevelItemCount()));
}

void Groups::createGroup(){
    Dialog *create = new Dialog(tr("Create group"), this);
    create->setCommand(CRGRP);
    connect(create, SIGNAL(sendApply(DATA&)), this, SIGNAL(send(DATA&)));
    create->exec();
}

void Groups::removeGroup(){
    if(treeWidget->currentItem() != nullptr){
        data.cmd = RMGRP;
        qstrcpy(data.data, treeWidget->currentItem()->text(0).toLocal8Bit());
        emit send(data);
    }
}

void Groups::addUserInGroup(){
    if(treeWidget->currentItem() != nullptr){
        Dialog *create = new Dialog(tr("Add user in group"), this);
        create->setCommand(ADDUSRGRP);
        create->setNameGroup(treeWidget->currentItem()->text(0));
        connect(create, SIGNAL(sendApply(DATA&)), this, SIGNAL(send(DATA&)));
        create->exec();
    }
}

void Groups::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);

    QAction *actUpdate = new QAction(QIcon(":/ico/refresh.png"), tr("Refresh"), this);
    actUpdate->setShortcut(QKeySequence("F5"));
    menu->addAction(actUpdate);

    QAction *actCreate = new QAction(tr("Create group"), this);
    menu->addAction(actCreate);

    QAction *actRemove = new QAction(tr("Remove group"), this);
    actRemove->setShortcut(QKeySequence("DELETE"));
    menu->addAction(actRemove);

    QAction *actAdd = new QAction(tr("Add user..."), this);
    menu->addAction(actAdd);

    menu->popup(treeWidget->viewport()->mapToGlobal(pos));
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getListGroups()));
    connect(actCreate, SIGNAL(triggered()), this, SLOT(createGroup()));
    connect(actRemove, SIGNAL(triggered()), this, SLOT(removeGroup()));
    connect(actAdd, SIGNAL(triggered()), this, SLOT(addUserInGroup()));
}

void Groups::getListGroups(){
    data.cmd = LSGRP;
    emit send(data);
    treeWidget->clear();
}

void Groups::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F5)
        getListGroups();
}

void Groups::addRoot(INFOGROUP lsGroups){
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setText(0, QString::fromLocal8Bit(lsGroups.nameGroup));
    root->setText(1, QString::fromLocal8Bit(lsGroups.comment));
}

void Groups::message(const QString &msg){
    QMessageBox::information(this, nullptr, msg);
    getListGroups();
}

Dialog::Dialog(const QString &title, QWidget *parent) : QDialog(parent){
    QDialog::setWindowTitle(title);

    vlayout = new QVBoxLayout(this);
    hlayout = new QHBoxLayout();

    lineName = new QLineEdit(this);
    vlayout->addWidget(lineName);

    btnOk = new QPushButton(tr("OK"), this);
    hlayout->addWidget(btnOk);

    btnCancel = new QPushButton(tr("Cancel"), this);
    hlayout->addWidget(btnCancel);

    vlayout->addLayout(hlayout);
    connect(btnOk, SIGNAL(clicked()), this, SLOT(apply()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void Dialog::setCommand(COMMANDS cmd){
    data.cmd = cmd;
}

void Dialog::setNameGroup(const QString &nameGroup){
    grp = nameGroup;
}

void Dialog::apply(){
    QString name = lineName->text();
    if(! name.isEmpty()){
        if(data.cmd == CRGRP)
            qstrcpy(data.data, name.toLocal8Bit());
        else if(data.cmd == ADDUSRGRP){
            qstrcpy(data.data, name.toLocal8Bit());
            strncat(data.data, " ", sizeof(data.data));
            strncat(data.data, grp.toLocal8Bit(), sizeof(data.data));
        }
        emit sendApply(data);
        close();
    }
    else
        QMessageBox::warning(this, nullptr, tr("Enter name"), QMessageBox::Ok);
}
