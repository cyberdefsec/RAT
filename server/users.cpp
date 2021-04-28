#include "users.h"

Users::Users(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);

    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(3);
    treeWidget->setHeaderLabels(headerName);
    vlayout->addWidget(treeWidget);
    treeWidget->setSortingEnabled(true);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    labTotalUsr = new QLabel(tr("Total users: 0"), this);
    vlayout->addWidget(labTotalUsr);

    connect(treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void Users::listUsers(INFOUSER &data){
    addRoot(data);
    labTotalUsr->setText(QString(tr("Total users: %1")).arg(treeWidget->topLevelItemCount()));
}

void Users::message(const QString &msg){
    QMessageBox::information(this, nullptr, msg);
    getListUsers();
}

void Users::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);

    QAction *actUpdate = new QAction(QIcon(":/ico/refresh.png"), tr("Refresh"), this);
    actUpdate->setShortcut(QKeySequence("F5"));
    menu->addAction(actUpdate);

    QAction *actCreate = new QAction(tr("Create"), this);
    menu->addAction(actCreate);

    QAction *actRemove = new QAction(tr("Remove"), this);
    menu->addAction(actRemove);

    QAction *actBlockUser = new QAction(QIcon(":/ico/block_user.png"), tr("Block user"), this);
    menu->addAction(actBlockUser);

    QAction *actPassChange = new QAction(QIcon(":/ico/password.png"), tr("Pass change"), this);
    menu->addAction(actPassChange);

    menu->popup(treeWidget->viewport()->mapToGlobal(pos));
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getListUsers()));
    connect(actCreate, SIGNAL(triggered()), this, SLOT(createUser()));
    connect(actRemove, SIGNAL(triggered()), this, SLOT(removeUser()));
    connect(actPassChange, SIGNAL(triggered()), this, SLOT(changePassowrd()));
    connect(actBlockUser, SIGNAL(triggered()), this, SLOT(blockUser()));
}

void Users::getListUsers(){
    data.cmd = LSUSR;    
    emit send(data);
    treeWidget->clear();
}

void Users::createUser(){
    DialogUsers *dlg = new DialogUsers(tr("Create user"), this);
    dlg->setCommand(CRUSR);
    dlg->setPlaceholder(tr("Name user"), tr("Password"));
    connect(dlg, SIGNAL(sendApply(DATA&)), this, SIGNAL(send(DATA&)));
    dlg->exec();
}

void Users::removeUser(){
    if(treeWidget->currentItem() != nullptr){
        data.cmd = RMUSR;
        qstrcpy(data.data, treeWidget->currentItem()->text(0).toLocal8Bit());
        emit send(data);
    }
}

void Users::changePassowrd(){
    DialogUsers *dlg = new DialogUsers(tr("Change password"), this);
    dlg->setPlaceholder(tr("Old password"), tr("New password"));
    dlg->setCommand(PASSUSR);
    dlg->setNameUser(treeWidget->currentItem()->text(0));
    connect(dlg, SIGNAL(sendApply(DATA&)), this, SIGNAL(send(DATA&)));
    dlg->exec();
}

void Users::blockUser(){
    if(treeWidget->currentItem() != nullptr){
        data.cmd = BLCKUSR;
        qstrcpy(data.data, treeWidget->currentItem()->text(0).toLocal8Bit());
        emit send(data);
    }
}

void Users::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F5)
        getListUsers();
}

void Users::addRoot(INFOUSER lsUsers){
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setText(0, QString::fromLocal8Bit(lsUsers.nameUser));
    if(lsUsers.block)
        root->setIcon(0, QIcon(":/ico/block_user.png"));
    else
        root->setIcon(0, QIcon(":/ico/users.png"));
    root->setText(1, QString::fromLocal8Bit(lsUsers.comment));
    root->setText(2, QString::fromLocal8Bit(lsUsers.sid));
}

DialogUsers::DialogUsers(const QString &title, QWidget *parent) : QDialog(parent){
    QDialog::setWindowTitle(title);

    vlayout = new QVBoxLayout(this);
    hlayout = new QHBoxLayout();

    lineName = new QLineEdit(this);
    vlayout->addWidget(lineName);

    linePass = new QLineEdit(this);
    vlayout->addWidget(linePass);


    btnOk = new QPushButton(tr("OK"), this);
    hlayout->addWidget(btnOk);

    btnCancel = new QPushButton(tr("Cancel"), this);
    hlayout->addWidget(btnCancel);

    vlayout->addLayout(hlayout);
    connect(btnOk, SIGNAL(clicked()), this, SLOT(apply()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void DialogUsers::setPlaceholder(const QString &str1, const QString &str2){
    lineName->setPlaceholderText(str1);
    linePass->setPlaceholderText(str2);
}

void DialogUsers::setCommand(COMMANDS cmd){
    data.cmd = cmd;
}

void DialogUsers::setNameUser(const QString &nameUser){
    name = nameUser;
}

void DialogUsers::apply(){
    QString nameUsr = lineName->text();
    QString passwd = linePass->text();
    if(data.cmd == CRUSR && ! nameUsr.isEmpty()){
        qstrcpy(data.data, nameUsr.toLocal8Bit());
        strcat(data.data, " ");
        strcat(data.data, passwd.toLocal8Bit());
        sendApply(data);
        close();
    }
    else if(data.cmd == PASSUSR && (!nameUsr.isEmpty() && !passwd.isEmpty())){
            qstrcpy(data.data, name.toLocal8Bit());
            strcat(data.data, " ");
            strcat(data.data, nameUsr.toLocal8Bit());
            strcat(data.data, " ");
            strcat(data.data, passwd.toLocal8Bit());
            sendApply(data);
            close();
        }
        else
            QMessageBox::warning(this, nullptr, tr("Enter old password and new password"), QMessageBox::Ok);

}
