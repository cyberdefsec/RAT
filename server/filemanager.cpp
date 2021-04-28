#include "filemanager.h"

ChangeAttribute::ChangeAttribute(QWidget *parent) : QDialog(parent){
    setFixedSize(0, 0);
    setWindowFlags(windowFlags() &= ~Qt::WindowMaximizeButtonHint);
    vlayout = new QVBoxLayout(this);

    nameFile = new QLabel(this);    
    nameFile->setAlignment(Qt::AlignCenter);
    vlayout->addWidget(nameFile);

    gridLayout = new QGridLayout();
    vlayout->addLayout(gridLayout);

    hideAttr = new QCheckBox(tr("Hide"), this);
    gridLayout->addWidget(hideAttr, 0, 0);

    readAttr = new QCheckBox(tr("Read"), this);
    gridLayout->addWidget(readAttr, 0, 1);

    normAttr = new QCheckBox(tr("Normal"), this);
    gridLayout->addWidget(normAttr, 1, 0);

    sysAttr = new QCheckBox(tr("System"), this);
    gridLayout->addWidget(sysAttr, 1, 1);

    btnApply = new QPushButton(tr("Apply"), this);
    btnApply->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    gridLayout->addWidget(btnApply, 2, 0);

    btnCancel = new QPushButton(tr("Cancel"), this);
    btnCancel->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    gridLayout->addWidget(btnCancel, 2, 1);

    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(btnApply, SIGNAL(clicked()), this, SLOT(attribute()));
}

void ChangeAttribute::setName(const QString &name, QString attr){
    if(attr.lastIndexOf('R') != EOF)
        readAttr->setCheckState(Qt::Checked);
    if(attr.lastIndexOf('H') != EOF)
        hideAttr->setCheckState(Qt::Checked);
    if(attr.lastIndexOf('S') != EOF)
        sysAttr->setCheckState(Qt::Checked);
    if(attr.lastIndexOf('N') != EOF)
        normAttr->setCheckState(Qt::Checked);
    this->name = name;
    nameFile->setText(name);
}

void ChangeAttribute::attribute(){
    if(readAttr->isChecked() == true)
        attr |= FILE_ATTRIBUTE_READONLY;

    if(hideAttr->isChecked() == true)
        attr |= FILE_ATTRIBUTE_HIDDEN;

    if(sysAttr->isChecked() == true)
        attr |= FILE_ATTRIBUTE_SYSTEM;

    if(normAttr->isChecked() == true)
        attr |= FILE_ATTRIBUTE_NORMAL;

    emit attributes(name, attr);
    close();
}

Create::Create(const QString &title, QWidget *parent) : QDialog(parent){
    QDialog::setWindowTitle(title);
    vlayout = new QVBoxLayout(this);
    hlayout = new QHBoxLayout();

    lineName = new QLineEdit(this);
    vlayout->addWidget(lineName);

    btnCreate = new QPushButton(tr("OK"), this);
    hlayout->addWidget(btnCreate);

    btnCancel = new QPushButton(tr("Cancel"), this);
    hlayout->addWidget(btnCancel);
    vlayout->addLayout(hlayout);

    connect(btnCreate, SIGNAL(clicked()), this, SLOT(setName()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));
}

void Create::setName(){
    if(! lineName->text().isEmpty()){
        if(data.cmd == RNAME){
            QString dt;
            QFileInfo d(name);
            dt.append(QString("%1 %2\\%3").arg(name).arg(d.canonicalPath()).arg(lineName->text()));
            qstrcpy(data.data, dt.toLocal8Bit());
        }
        else{
            if(name[name.length() - 1] != '\\')
                name += "\\";
            name += lineName->text();
            qstrcpy(data.data, name.toLocal8Bit());
        }
        emit getName(data);
        close();
    }
    else
        QMessageBox::warning(this, nullptr, tr("Enter name %1").arg(QDialog::windowTitle()), QMessageBox::Ok);
}

FileManager::FileManager(QWidget *parent) : QWidget(parent){
    vlayout = new QVBoxLayout(this);

    hlayout = new QHBoxLayout();
    vlayout->addLayout(hlayout);

    listDisk = new QComboBox(this);
    hlayout->addWidget(listDisk);

    btnRefresh = new QPushButton(this);
    btnRefresh->setIcon(QIcon(":/ico/refresh.png"));
    btnRefresh->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addWidget(btnRefresh);   

    btnHome = new QPushButton(this);
    btnHome->setIcon(QIcon(":/ico/home.png"));
    btnHome->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    hlayout->addWidget(btnHome);

    linePath = new QLineEdit(this);
    vlayout->addWidget(linePath);

    treeWidget = new QTreeWidget(this);
    treeWidget->setRootIsDecorated(false);
    treeWidget->setColumnCount(3);
    treeWidget->setSortingEnabled(true);   
    treeWidget->sortByColumn(2, Qt::DescendingOrder);
    treeWidget->setHeaderLabels(headerName);
    treeWidget->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    vlayout->addWidget(treeWidget);

    hlayout2 = new QHBoxLayout();
    vlayout->addLayout(hlayout2);

    labSizeTotal = new QLabel(tr("Total size: 0 Bytes"), this);
    hlayout2->addWidget(labSizeTotal);

    hlayout2->addStretch();
    labCountDir = new QLabel(tr("Dirs: 0"), this);
    hlayout2->addWidget(labCountDir);

    labCountFile = new QLabel(tr("Files: 0"), this);
    hlayout2->addWidget(labCountFile);

    connect(btnRefresh, SIGNAL(clicked()), this, SLOT(getListDisk()));
    connect(btnHome, SIGNAL(clicked()), this, SLOT(backHome()));
    connect(treeWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(contextMenu(const QPoint&)));
    connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(openDir(QTreeWidgetItem*)));
    connect(listDisk, SIGNAL(currentTextChanged(const QString&)), this, SLOT(getListDir(const QString&)));
    connect(linePath, SIGNAL(textEdited(const QString&)), this, SLOT(getListDir(const QString&)));
}

void FileManager::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_F5)
        getListDisk();
    if(event->key() == Qt::Key_Return && treeWidget->topLevelItemCount() > 0 && treeWidget->currentItem() != nullptr)
        openDir(treeWidget->currentItem());

}


void FileManager::setListDisk(LISTDISK &disk){    
    totalSize.append(disk.totalSpace.QuadPart);
    switch(disk.type){
        case DRIVE_NO_ROOT_DIR :
            listDisk->addItem(disk.disk);
            break;
        case DRIVE_REMOVABLE :
            listDisk->addItem(QIcon(":/ico/usb.png"), disk.disk);
            break;
        case DRIVE_FIXED :
            listDisk->addItem(QIcon(":/ico/hdd.png"), disk.disk);
            break;
        case DRIVE_REMOTE :
            listDisk->addItem(QIcon(":/ico/remotedisk.png"), disk.disk);
            break;
        case DRIVE_CDROM :
            listDisk->addItem(QIcon(":/ico/cdrom.png"), disk.disk);
            break;
        case DRIVE_RAMDISK :
            listDisk->addItem(disk.disk);
            break;
    }
}

void FileManager::setListDir(LISTDIR &data){
    QString attr;
    QTreeWidgetItem *root = new QTreeWidgetItem(treeWidget);
    root->setFlags(root->flags() | Qt::ItemIsEditable);
    root->setText(0, QString::fromLocal8Bit(data.name));
    root->setText(1, QString::number(data.size));
    root->setText(3, data.date);
    if(data.attr & FILE_ATTRIBUTE_ARCHIVE)
        attr += "A";
    if(data.attr & FILE_ATTRIBUTE_DIRECTORY){
        attr += "D";
        countDir++;
        root->setIcon(0, QIcon(":/ico/dir.png"));
    }
    else{
        countFile++;
        root->setIcon(0, QIcon(":/ico/file.png"));;
    }
    if(data.attr & FILE_ATTRIBUTE_HIDDEN)
        attr += "H";
    if(data.attr & FILE_ATTRIBUTE_NORMAL)
        attr += "N";
    if(data.attr & FILE_ATTRIBUTE_SYSTEM)
        attr += "S";
    if(data.attr & FILE_ATTRIBUTE_READONLY)
        attr += "R";
    root->setText(2, attr);
    labCountDir->setText(tr("Dirs: %1").arg(countDir));
    labCountFile->setText(tr("Files: %1").arg(countFile));

}

void FileManager::message(const QString &msg){
    QMessageBox::information(this, nullptr, msg);
    getListDir(linePath->text());
}


void FileManager::contextMenu(const QPoint &pos){
    QMenu *menu = new QMenu(this);

    actUpdate = new QAction(QIcon(":/ico/refresh.png"), tr("Update"), this);
    menu->addAction(actUpdate);

    actCreateDir = new QAction(QIcon(":/ico/dir.png"), tr("Create dir"), this);
    menu->addAction(actCreateDir);

    actCreateFile = new QAction(QIcon(":/ico/file.png"), tr("Create file"), this);
    menu->addAction(actCreateFile);

    actRemove = new QAction(QIcon(":/ico/remove.png"), tr("Remove"), this);
    menu->addAction(actRemove);

    actRename = new QAction(tr("Rename..."), this);
    menu->addAction(actRename);

    actAttribute = new QAction(tr("Attribute"), this);
    menu->addAction(actAttribute);

    actDownload = new QAction(QIcon(":/ico/download.png"), tr("Download"), this);
    menu->addAction(actDownload);

    actUpload = new QAction(QIcon(":/ico/upload.png"), tr("Upload"), this);
    menu->addAction(actUpload);

    menu->popup(treeWidget->viewport()->mapToGlobal(pos));

    connect(actCreateDir, SIGNAL(triggered()), this, SLOT(createDir()));
    connect(actCreateFile, SIGNAL(triggered()), this, SLOT(createFile()));
    connect(actRename, SIGNAL(triggered()), this, SLOT(rename()));
    connect(actAttribute, SIGNAL(triggered()), this, SLOT(openAttribute()));
    connect(actRemove, SIGNAL(triggered()), this, SLOT(removes()));    
    connect(actUpdate, SIGNAL(triggered()), this, SLOT(currentUpdate()));
}

void FileManager::openAttribute(){
    QString path = linePath->text();
    ChangeAttribute *attr = new ChangeAttribute(this);
    if(! path.isEmpty()){
        if(path[path.length() - 1] != '\\')
            path += "\\";
        path += treeWidget->currentItem()->text(0);
        attr->setName(path, treeWidget->currentItem()->text(2));
    }
    connect(attr, SIGNAL(attributes(const QString&, DWORD)), this, SLOT(setAttributes(const QString&, DWORD)));
    attr->exec();
    currentUpdate();
}

void FileManager::getListDisk(){
    data.cmd = DISK;
    listDisk->clear();
    treeWidget->clear();   
    totalSize.clear();
    countDir = countFile = 0;
    emit sendDisk(data);
}

void FileManager::getListDir(const QString &path){
    treeWidget->clear();
    if(! listDisk->currentText().isEmpty()){
        data.cmd = LSDIR;
        countDir = 0;
        countFile = 0;        
        linePath->setText(path);
        labSizeTotal->setText(tr("Total size: %1 Bytes").arg(totalSize.at(listDisk->currentIndex())));
        qstrcpy(data.data, path.toLocal8Bit());
        if(data.data[strlen(data.data) - 1] == '\\')
            strncat(data.data, "*.*", strlen(data.data));
        else
            strncat(data.data, "\\*.*", strlen(data.data));        
        emit sendDir(data);
    }
}

void FileManager::openDir(QTreeWidgetItem *item){
    QString path = linePath->text();
    if(item->text(2).contains('D')){
        if(item->text(0) == ".."){
            path = path.left(path.lastIndexOf('\\'));
            if(path.length() == 2){
                if(path[path.length() - 1] != '\\')
                    path += "\\";
            }
        }
        else{
            if(path[path.length() - 1] != '\\')
                path += "\\";
            path += item->text(0);
        }
        linePath->setText(path);
        getListDir(path);
    }
}

void FileManager::removes(){
    QString path = linePath->text();
    QString obj = treeWidget->currentItem()->text(0);
    if(path[path.length() - 1] != '\\')
        path += "\\";
    path += obj;
    if(treeWidget->currentItem()->text(2).contains('D'))
        data.cmd = RMDIR;
    else
        data.cmd = RMFILE;
    qstrcpy(data.data, path.toLocal8Bit());
    emit send(data);
}

void FileManager::createDir(){
    Create *dir = new Create(tr("Directory"), this);
    dir->setPath(linePath->text(), CRDIR);
    connect(dir, SIGNAL(getName(DATA&)), this, SIGNAL(send(DATA&)));
    dir->exec();
    currentUpdate();
}

void FileManager::createFile(){
    Create *file = new Create(tr("File"), this);
    file->setPath(linePath->text(), CRFILE);
    connect(file, SIGNAL(getName(DATA&)), this, SIGNAL(send(DATA&)));
    file->exec();
    currentUpdate();
}

void FileManager::rename(){
    QString path;
    Create *ren = new Create(tr("Rename"), this);
    path = linePath->text();
    if(path[path.length() - 1] != '\\')
        path += "\\";
    path += treeWidget->currentItem()->text(0);
    ren->setPath(path, RNAME);
    connect(ren, SIGNAL(getName(DATA&)), this, SIGNAL(send(DATA&)));
    ren->exec();
    currentUpdate();
}

void FileManager::currentUpdate(){
    QString path = linePath->text();
    if(! listDisk->currentText().isEmpty()){
        getListDir(path);
    }
}

void FileManager::backHome(){
    QString path = listDisk->currentText();
    if(! path.isEmpty())
        getListDir(path);
}

void FileManager::setAttributes(const QString& nameFile, DWORD attr){
    data.cmd = ATTR;
    data.other = attr;
    qstrcpy(data.data, nameFile.toLocal8Bit());
    emit send(data);
}
