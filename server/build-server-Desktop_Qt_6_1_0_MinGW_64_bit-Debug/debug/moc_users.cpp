/****************************************************************************
** Meta object code from reading C++ file 'users.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../users.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'users.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogUsers_t {
    const uint offsetsAndSize[12];
    char stringdata0[40];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_DialogUsers_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_DialogUsers_t qt_meta_stringdata_DialogUsers = {
    {
QT_MOC_LITERAL(0, 11), // "DialogUsers"
QT_MOC_LITERAL(12, 9), // "sendApply"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 5), // "DATA&"
QT_MOC_LITERAL(29, 4), // "data"
QT_MOC_LITERAL(34, 5) // "apply"

    },
    "DialogUsers\0sendApply\0\0DATA&\0data\0"
    "apply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogUsers[] = {

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

void DialogUsers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogUsers *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendApply((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->apply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogUsers::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogUsers::sendApply)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DialogUsers::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogUsers.offsetsAndSize,
    qt_meta_data_DialogUsers,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_DialogUsers_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *DialogUsers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogUsers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogUsers.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogUsers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DialogUsers::sendApply(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Users_t {
    const uint offsetsAndSize[32];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Users_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Users_t qt_meta_stringdata_Users = {
    {
QT_MOC_LITERAL(0, 5), // "Users"
QT_MOC_LITERAL(6, 4), // "send"
QT_MOC_LITERAL(11, 0), // ""
QT_MOC_LITERAL(12, 5), // "DATA&"
QT_MOC_LITERAL(18, 4), // "data"
QT_MOC_LITERAL(23, 9), // "listUsers"
QT_MOC_LITERAL(33, 9), // "INFOUSER&"
QT_MOC_LITERAL(43, 7), // "message"
QT_MOC_LITERAL(51, 3), // "msg"
QT_MOC_LITERAL(55, 11), // "contextMenu"
QT_MOC_LITERAL(67, 3), // "pos"
QT_MOC_LITERAL(71, 12), // "getListUsers"
QT_MOC_LITERAL(84, 10), // "createUser"
QT_MOC_LITERAL(95, 10), // "removeUser"
QT_MOC_LITERAL(106, 14), // "changePassowrd"
QT_MOC_LITERAL(121, 9) // "blockUser"

    },
    "Users\0send\0\0DATA&\0data\0listUsers\0"
    "INFOUSER&\0message\0msg\0contextMenu\0pos\0"
    "getListUsers\0createUser\0removeUser\0"
    "changePassowrd\0blockUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Users[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   68,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   71,    2, 0x0a,    2 /* Public */,
       7,    1,   74,    2, 0x0a,    4 /* Public */,
       9,    1,   77,    2, 0x08,    6 /* Private */,
      11,    0,   80,    2, 0x08,    8 /* Private */,
      12,    0,   81,    2, 0x08,    9 /* Private */,
      13,    0,   82,    2, 0x08,   10 /* Private */,
      14,    0,   83,    2, 0x08,   11 /* Private */,
      15,    0,   84,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Users::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Users *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->listUsers((*reinterpret_cast< INFOUSER(*)>(_a[1]))); break;
        case 2: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->getListUsers(); break;
        case 5: _t->createUser(); break;
        case 6: _t->removeUser(); break;
        case 7: _t->changePassowrd(); break;
        case 8: _t->blockUser(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Users::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Users::send)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Users::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Users.offsetsAndSize,
    qt_meta_data_Users,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Users_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<INFOUSER &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Users::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Users::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Users.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Users::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Users::send(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
