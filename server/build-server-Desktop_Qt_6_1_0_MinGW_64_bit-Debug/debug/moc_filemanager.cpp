/****************************************************************************
** Meta object code from reading C++ file 'filemanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../filemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChangeAttribute_t {
    const uint offsetsAndSize[14];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ChangeAttribute_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ChangeAttribute_t qt_meta_stringdata_ChangeAttribute = {
    {
QT_MOC_LITERAL(0, 15), // "ChangeAttribute"
QT_MOC_LITERAL(16, 10), // "attributes"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 8), // "nameFile"
QT_MOC_LITERAL(37, 5), // "DWORD"
QT_MOC_LITERAL(43, 4), // "attr"
QT_MOC_LITERAL(48, 9) // "attribute"

    },
    "ChangeAttribute\0attributes\0\0nameFile\0"
    "DWORD\0attr\0attribute"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChangeAttribute[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   31,    2, 0x08,    3 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ChangeAttribute::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChangeAttribute *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->attributes((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< DWORD(*)>(_a[2]))); break;
        case 1: _t->attribute(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChangeAttribute::*)(const QString & , DWORD );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChangeAttribute::attributes)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ChangeAttribute::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ChangeAttribute.offsetsAndSize,
    qt_meta_data_ChangeAttribute,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ChangeAttribute_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<DWORD, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ChangeAttribute::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChangeAttribute::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChangeAttribute.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ChangeAttribute::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ChangeAttribute::attributes(const QString & _t1, DWORD _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Create_t {
    const uint offsetsAndSize[12];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Create_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Create_t qt_meta_stringdata_Create = {
    {
QT_MOC_LITERAL(0, 6), // "Create"
QT_MOC_LITERAL(7, 7), // "getName"
QT_MOC_LITERAL(15, 0), // ""
QT_MOC_LITERAL(16, 5), // "DATA&"
QT_MOC_LITERAL(22, 4), // "data"
QT_MOC_LITERAL(27, 7) // "setName"

    },
    "Create\0getName\0\0DATA&\0data\0setName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Create[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   29,    2, 0x08,    2 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Create::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Create *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->getName((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->setName(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Create::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Create::getName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Create::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Create.offsetsAndSize,
    qt_meta_data_Create,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Create_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Create::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Create::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Create.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Create::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Create::getName(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FileManager_t {
    const uint offsetsAndSize[66];
    char stringdata0[286];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FileManager_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FileManager_t qt_meta_stringdata_FileManager = {
    {
QT_MOC_LITERAL(0, 11), // "FileManager"
QT_MOC_LITERAL(12, 8), // "sendDisk"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 5), // "DATA&"
QT_MOC_LITERAL(28, 4), // "data"
QT_MOC_LITERAL(33, 7), // "sendDir"
QT_MOC_LITERAL(41, 4), // "send"
QT_MOC_LITERAL(46, 11), // "setListDisk"
QT_MOC_LITERAL(58, 9), // "LISTDISK&"
QT_MOC_LITERAL(68, 4), // "disk"
QT_MOC_LITERAL(73, 10), // "setListDir"
QT_MOC_LITERAL(84, 8), // "LISTDIR&"
QT_MOC_LITERAL(93, 7), // "message"
QT_MOC_LITERAL(101, 3), // "msg"
QT_MOC_LITERAL(105, 11), // "contextMenu"
QT_MOC_LITERAL(117, 3), // "pos"
QT_MOC_LITERAL(121, 13), // "openAttribute"
QT_MOC_LITERAL(135, 11), // "getListDisk"
QT_MOC_LITERAL(147, 10), // "getListDir"
QT_MOC_LITERAL(158, 4), // "path"
QT_MOC_LITERAL(163, 7), // "openDir"
QT_MOC_LITERAL(171, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(188, 4), // "item"
QT_MOC_LITERAL(193, 7), // "removes"
QT_MOC_LITERAL(201, 9), // "createDir"
QT_MOC_LITERAL(211, 10), // "createFile"
QT_MOC_LITERAL(222, 6), // "rename"
QT_MOC_LITERAL(229, 13), // "currentUpdate"
QT_MOC_LITERAL(243, 8), // "backHome"
QT_MOC_LITERAL(252, 13), // "setAttributes"
QT_MOC_LITERAL(266, 8), // "nameFile"
QT_MOC_LITERAL(275, 5), // "DWORD"
QT_MOC_LITERAL(281, 4) // "attr"

    },
    "FileManager\0sendDisk\0\0DATA&\0data\0"
    "sendDir\0send\0setListDisk\0LISTDISK&\0"
    "disk\0setListDir\0LISTDIR&\0message\0msg\0"
    "contextMenu\0pos\0openAttribute\0getListDisk\0"
    "getListDir\0path\0openDir\0QTreeWidgetItem*\0"
    "item\0removes\0createDir\0createFile\0"
    "rename\0currentUpdate\0backHome\0"
    "setAttributes\0nameFile\0DWORD\0attr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileManager[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    0 /* Public */,
       5,    1,  125,    2, 0x06,    2 /* Public */,
       6,    1,  128,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,  131,    2, 0x0a,    6 /* Public */,
      10,    1,  134,    2, 0x0a,    8 /* Public */,
      12,    1,  137,    2, 0x0a,   10 /* Public */,
      14,    1,  140,    2, 0x08,   12 /* Private */,
      16,    0,  143,    2, 0x08,   14 /* Private */,
      17,    0,  144,    2, 0x08,   15 /* Private */,
      18,    1,  145,    2, 0x08,   16 /* Private */,
      20,    1,  148,    2, 0x08,   18 /* Private */,
      23,    0,  151,    2, 0x08,   20 /* Private */,
      24,    0,  152,    2, 0x08,   21 /* Private */,
      25,    0,  153,    2, 0x08,   22 /* Private */,
      26,    0,  154,    2, 0x08,   23 /* Private */,
      27,    0,  155,    2, 0x08,   24 /* Private */,
      28,    0,  156,    2, 0x08,   25 /* Private */,
      29,    2,  157,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    4,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 31,   30,   32,

       0        // eod
};

void FileManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendDisk((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->sendDir((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 2: _t->send((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 3: _t->setListDisk((*reinterpret_cast< LISTDISK(*)>(_a[1]))); break;
        case 4: _t->setListDir((*reinterpret_cast< LISTDIR(*)>(_a[1]))); break;
        case 5: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->contextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->openAttribute(); break;
        case 8: _t->getListDisk(); break;
        case 9: _t->getListDir((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->openDir((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->removes(); break;
        case 12: _t->createDir(); break;
        case 13: _t->createFile(); break;
        case 14: _t->rename(); break;
        case 15: _t->currentUpdate(); break;
        case 16: _t->backHome(); break;
        case 17: _t->setAttributes((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< DWORD(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileManager::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileManager::sendDisk)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileManager::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileManager::sendDir)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileManager::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileManager::send)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FileManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FileManager.offsetsAndSize,
    qt_meta_data_FileManager,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FileManager_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTDISK &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTDIR &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<DWORD, std::false_type>


>,
    nullptr
} };


const QMetaObject *FileManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FileManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void FileManager::sendDisk(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileManager::sendDir(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileManager::send(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
