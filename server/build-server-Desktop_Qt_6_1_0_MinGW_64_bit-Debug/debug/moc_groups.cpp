/****************************************************************************
** Meta object code from reading C++ file 'groups.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../groups.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groups.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    const uint offsetsAndSize[12];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 6), // "Dialog"
QT_MOC_LITERAL(7, 9), // "sendApply"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 5), // "DATA&"
QT_MOC_LITERAL(24, 4), // "data"
QT_MOC_LITERAL(29, 5) // "apply"

    },
    "Dialog\0sendApply\0\0DATA&\0data\0apply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

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

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendApply((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->apply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::sendApply)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.offsetsAndSize,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Dialog_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Dialog::sendApply(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Groups_t {
    const uint offsetsAndSize[30];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Groups_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Groups_t qt_meta_stringdata_Groups = {
    {
QT_MOC_LITERAL(0, 6), // "Groups"
QT_MOC_LITERAL(7, 4), // "send"
QT_MOC_LITERAL(12, 0), // ""
QT_MOC_LITERAL(13, 5), // "DATA&"
QT_MOC_LITERAL(19, 4), // "data"
QT_MOC_LITERAL(24, 10), // "listGroups"
QT_MOC_LITERAL(35, 10), // "INFOGROUP&"
QT_MOC_LITERAL(46, 11), // "createGroup"
QT_MOC_LITERAL(58, 11), // "removeGroup"
QT_MOC_LITERAL(70, 14), // "addUserInGroup"
QT_MOC_LITERAL(85, 7), // "message"
QT_MOC_LITERAL(93, 3), // "msg"
QT_MOC_LITERAL(97, 11), // "contextMenu"
QT_MOC_LITERAL(109, 3), // "pos"
QT_MOC_LITERAL(113, 13) // "getListGroups"

    },
    "Groups\0send\0\0DATA&\0data\0listGroups\0"
    "INFOGROUP&\0createGroup\0removeGroup\0"
    "addUserInGroup\0message\0msg\0contextMenu\0"
    "pos\0getListGroups"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Groups[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   65,    2, 0x0a,    2 /* Public */,
       7,    0,   68,    2, 0x0a,    4 /* Public */,
       8,    0,   69,    2, 0x0a,    5 /* Public */,
       9,    0,   70,    2, 0x0a,    6 /* Public */,
      10,    1,   71,    2, 0x0a,    7 /* Public */,
      12,    1,   74,    2, 0x08,    9 /* Private */,
      14,    0,   77,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QPoint,   13,
    QMetaType::Void,

       0        // eod
};

void Groups::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Groups *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->listGroups((*reinterpret_cast< INFOGROUP(*)>(_a[1]))); break;
        case 2: _t->createGroup(); break;
        case 3: _t->removeGroup(); break;
        case 4: _t->addUserInGroup(); break;
        case 5: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 7: _t->getListGroups(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Groups::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Groups::send)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Groups::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Groups.offsetsAndSize,
    qt_meta_data_Groups,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Groups_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<INFOGROUP &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Groups::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Groups::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Groups.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Groups::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Groups::send(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
