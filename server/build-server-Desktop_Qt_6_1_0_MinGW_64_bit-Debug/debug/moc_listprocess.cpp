/****************************************************************************
** Meta object code from reading C++ file 'listprocess.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../listprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListProcess_t {
    const uint offsetsAndSize[30];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ListProcess_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ListProcess_t qt_meta_stringdata_ListProcess = {
    {
QT_MOC_LITERAL(0, 11), // "ListProcess"
QT_MOC_LITERAL(12, 4), // "send"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 5), // "DATA&"
QT_MOC_LITERAL(24, 4), // "data"
QT_MOC_LITERAL(29, 8), // "sendKill"
QT_MOC_LITERAL(38, 8), // "listProc"
QT_MOC_LITERAL(47, 9), // "LISTPROC&"
QT_MOC_LITERAL(57, 7), // "message"
QT_MOC_LITERAL(65, 3), // "msg"
QT_MOC_LITERAL(69, 11), // "contextMenu"
QT_MOC_LITERAL(81, 3), // "pos"
QT_MOC_LITERAL(85, 14), // "getListProcess"
QT_MOC_LITERAL(100, 8), // "killProc"
QT_MOC_LITERAL(109, 13) // "createProcess"

    },
    "ListProcess\0send\0\0DATA&\0data\0sendKill\0"
    "listProc\0LISTPROC&\0message\0msg\0"
    "contextMenu\0pos\0getListProcess\0killProc\0"
    "createProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListProcess[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    0 /* Public */,
       5,    1,   65,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   68,    2, 0x0a,    4 /* Public */,
       8,    1,   71,    2, 0x0a,    6 /* Public */,
      10,    1,   74,    2, 0x08,    8 /* Private */,
      12,    0,   77,    2, 0x08,   10 /* Private */,
      13,    0,   78,    2, 0x08,   11 /* Private */,
      14,    0,   79,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    4,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QPoint,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ListProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListProcess *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 1: _t->sendKill((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 2: _t->listProc((*reinterpret_cast< LISTPROC(*)>(_a[1]))); break;
        case 3: _t->message((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->getListProcess(); break;
        case 6: _t->killProc(); break;
        case 7: _t->createProcess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListProcess::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListProcess::send)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ListProcess::*)(DATA & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListProcess::sendKill)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ListProcess::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ListProcess.offsetsAndSize,
    qt_meta_data_ListProcess,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ListProcess_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTPROC &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPoint, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ListProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListProcess.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ListProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ListProcess::send(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ListProcess::sendKill(DATA & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
