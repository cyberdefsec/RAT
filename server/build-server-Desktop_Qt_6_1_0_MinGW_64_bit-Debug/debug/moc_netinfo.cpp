/****************************************************************************
** Meta object code from reading C++ file 'netinfo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../netinfo.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'netinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetInfo_t {
    const uint offsetsAndSize[20];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_NetInfo_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_NetInfo_t qt_meta_stringdata_NetInfo = {
    {
QT_MOC_LITERAL(0, 7), // "NetInfo"
QT_MOC_LITERAL(8, 4), // "send"
QT_MOC_LITERAL(13, 0), // ""
QT_MOC_LITERAL(14, 5), // "DATA&"
QT_MOC_LITERAL(20, 4), // "data"
QT_MOC_LITERAL(25, 11), // "contextMenu"
QT_MOC_LITERAL(37, 3), // "pos"
QT_MOC_LITERAL(41, 10), // "getNetInfo"
QT_MOC_LITERAL(52, 11), // "netInfoData"
QT_MOC_LITERAL(64, 7) // "NETINFO"

    },
    "NetInfo\0send\0\0DATA&\0data\0contextMenu\0"
    "pos\0getNetInfo\0netInfoData\0NETINFO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetInfo[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    0 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   41,    2, 0x08,    2 /* Private */,
       7,    0,   44,    2, 0x08,    4 /* Private */,
       8,    1,   45,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    4,

       0        // eod
};

void NetInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetInfo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->getNetInfo(); break;
        case 3: _t->netInfoData((*reinterpret_cast< NETINFO(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetInfo::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetInfo::send)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NetInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QTextEdit::staticMetaObject>(),
    qt_meta_stringdata_NetInfo.offsetsAndSize,
    qt_meta_data_NetInfo,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_NetInfo_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NETINFO, std::false_type>


>,
    nullptr
} };


const QMetaObject *NetInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetInfo.stringdata0))
        return static_cast<void*>(this);
    return QTextEdit::qt_metacast(_clname);
}

int NetInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void NetInfo::send(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
