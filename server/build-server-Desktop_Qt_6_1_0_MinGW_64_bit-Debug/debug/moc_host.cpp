/****************************************************************************
** Meta object code from reading C++ file 'host.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../host.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'host.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClipBoard_t {
    const uint offsetsAndSize[16];
    char stringdata0[56];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ClipBoard_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ClipBoard_t qt_meta_stringdata_ClipBoard = {
    {
QT_MOC_LITERAL(0, 9), // "ClipBoard"
QT_MOC_LITERAL(10, 7), // "sendBuf"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 5), // "DATA&"
QT_MOC_LITERAL(25, 4), // "data"
QT_MOC_LITERAL(30, 11), // "contextMenu"
QT_MOC_LITERAL(42, 3), // "pos"
QT_MOC_LITERAL(46, 9) // "getBuffer"

    },
    "ClipBoard\0sendBuf\0\0DATA&\0data\0contextMenu\0"
    "pos\0getBuffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClipBoard[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   35,    2, 0x08,    2 /* Private */,
       7,    0,   38,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,

       0        // eod
};

void ClipBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClipBoard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendBuf((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->getBuffer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClipBoard::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClipBoard::sendBuf)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ClipBoard::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_meta_stringdata_ClipBoard.offsetsAndSize,
    qt_meta_data_ClipBoard,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClipBoard_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ClipBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClipBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClipBoard.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int ClipBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ClipBoard::sendBuf(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Host_t {
    const uint offsetsAndSize[20];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Host_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Host_t qt_meta_stringdata_Host = {
    {
QT_MOC_LITERAL(0, 4), // "Host"
QT_MOC_LITERAL(5, 4), // "send"
QT_MOC_LITERAL(10, 0), // ""
QT_MOC_LITERAL(11, 5), // "DATA&"
QT_MOC_LITERAL(17, 4), // "data"
QT_MOC_LITERAL(22, 13), // "screenDesktop"
QT_MOC_LITERAL(36, 9), // "setBuffer"
QT_MOC_LITERAL(46, 11), // "contextMenu"
QT_MOC_LITERAL(58, 3), // "pos"
QT_MOC_LITERAL(62, 13) // "getScreenShot"

    },
    "Host\0send\0\0DATA&\0data\0screenDesktop\0"
    "setBuffer\0contextMenu\0pos\0getScreenShot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Host[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   47,    2, 0x0a,    2 /* Public */,
       6,    1,   50,    2, 0x0a,    4 /* Public */,
       7,    1,   53,    2, 0x08,    6 /* Private */,
       9,    0,   56,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QByteArray,    4,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,

       0        // eod
};

void Host::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Host *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->screenDesktop((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->setBuffer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->getScreenShot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Host::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Host::send)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Host::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Host.offsetsAndSize,
    qt_meta_data_Host,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Host_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Host::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Host::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Host.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Host::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Host::send(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
