#include "service.h"

Service::Service(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);

    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(3);
    treeWidget->setHeaderLabels(headerName);
    treeWidget->setSortingEnabled(true);
    treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    vlayout->addWidget(treeWidget);

    labTotalService = new QLabel(tr("Total service: 0"));
    vlayout->addWidget(labTotalService);

    connect(treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
}

void Service::listService(LISTSERVICE &data){    
     addRoot(data);
     labTotalService->setText(QString(tr("Total service: %1")).arg(treeWidget->topLevelItemCount()));
}

void Service::contextMenu(QPoint pos){
    QMenu *menu = new QMenu(this);

    QAction *actUpdate = new QAction(QIcon(":/ico/refresh.png"), tr("Refresh"), this);
    actUpdate->setShortcut(QKeySequence("F5"));
    menu->addAction(actUpdate);

    menu->popup(treeWidget->viewport()->mapToGlobal(pos));
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(getListService()));    
}

void Service::getListService(){
    data.cmd = LSSRV;    
    emit send(data);
    treeWidget->clear();
}

void Service::addRoot(LISTSERVICE lsService){    
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setText(0, QString::fromLocal8Bit(lsService.name));
    root->setText(1, QString::fromLocal8Bit(lsService.serviceName));
    switch(lsService.currentState){
        case SERVICE_STOPPED :
            root->setText(2, tr("STOPPED"));
            break;
        case SERVICE_START_PENDING :
            root->setText(2, tr("START"));
            break;
        case SERVICE_STOP_PENDING :
             root->setText(2, tr("STOP"));
             break;
        case SERVICE_RUNNING :
             root->setText(2, tr("RUNNING"));
             break;
        case SERVICE_CONTINUE_PENDING :
             root->setText(2, tr("CONTINUE"));
             break;
        case SERVICE_PAUSE_PENDING :
             root->setText(2, tr("PAUSE"));
             break;
        case SERVICE_PAUSED :
             root->setText(2, tr("PAUSED"));
             break;
    }

}

void Service::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F5)
        getListService();
}
