#include "listprocess.h"

ListProcess::ListProcess(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);
    groupBox = new QGroupBox();
    groupBox->setTitle(tr("Create process"));
    vlayout->addWidget(groupBox);
    createHlayout = new QHBoxLayout();
    groupBox->setLayout(createHlayout);

    vvlayout = new QVBoxLayout();
    createHlayout->addLayout(vvlayout);
    hlayout = new QHBoxLayout();
    vvlayout->addLayout(hlayout);

    lineEdit = new QLineEdit(this);
    hlayout->addWidget(lineEdit);   

    btnCreateProc = new QPushButton(tr("Create"), this);
    hlayout->addWidget(btnCreateProc);

    procHide = new QCheckBox(this);
    procHide->setText(tr("Hide process"));
    vvlayout->addWidget(procHide);

    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(4);
    treeWidget->setHeaderLabels(headerName);
    treeWidget->setSortingEnabled(true);   
    treeWidget->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    vlayout->addWidget(treeWidget);

    labTotalProc = new QLabel(tr("Total process: 0"), this);
    vlayout->addWidget(labTotalProc);

    connect(treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    connect(btnCreateProc, SIGNAL(clicked()), this, SLOT(createProcess()));
}

void ListProcess::addRoot(LISTPROC proc){
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setText(0, QString::fromLocal8Bit(proc.name));
    root->setText(1, QString::number(proc.pid));
    root->setText(2, QString::number(proc.ppid));
    root->setText(3, QString::fromLocal8Bit(proc.path));
}

void ListProcess::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F5)
        getListProcess();
    if(event->key() == Qt::Key_Delete)
        killProc();
}

void ListProcess::listProc(LISTPROC &data){
    addRoot(data);
    labTotalProc->setText(QString("Total process: %1").arg(treeWidget->topLevelItemCount()));
}

void ListProcess::message(const QString &msg){
    QMessageBox::information(this, nullptr, msg);
    getListProcess();
}

void ListProcess::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);

    QAction *actUpdate = new QAction(QIcon(":/ico/refresh.png"), tr("Refresh"), this);
    actUpdate->setShortcut(QKeySequence("F5"));
    menu->addAction(actUpdate);

    QAction *actKill = new QAction(QIcon(":/ico/kill.png"), tr("Kill"), this);
    actKill->setShortcut(QKeySequence("Delete"));
    menu->addAction(actKill);

    menu->popup(treeWidget->viewport()->mapToGlobal(pos));
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getListProcess()));
    connect(actKill, SIGNAL(triggered()), this, SLOT(killProc()));
}

void ListProcess::getListProcess(){
    data.cmd = LSPROC;
    emit send(data);
    treeWidget->clear();
}

void ListProcess::killProc(){
    QString nameProc = treeWidget->currentItem()->text(0);
    if(! nameProc.isEmpty()){
        data.cmd = KILLP;
        qstrcpy(data.data, nameProc.toStdString().c_str());
        emit send(data);        
    }
}

void ListProcess::createProcess(){
    QString nameProcess = lineEdit->text();
    if(! nameProcess.isEmpty()){
        data.cmd = CRPROC;
        if(procHide->isChecked())
            data.other = true;
        else
            data.other = false;
        qstrcpy(data.data, nameProcess.toStdString().c_str());
        emit send(data);
        lineEdit->clear();
    }
    else
        QMessageBox::warning(this, nullptr, tr("Enter process name"), QMessageBox::Ok);
}
