/****************************************************************************
** Meta object code from reading C++ file 'serversettings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../serversettings.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serversettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerSettings_t {
    const uint offsetsAndSize[24];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ServerSettings_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ServerSettings_t qt_meta_stringdata_ServerSettings = {
    {
QT_MOC_LITERAL(0, 14), // "ServerSettings"
QT_MOC_LITERAL(15, 14), // "settingsServer"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 9), // "ipAddress"
QT_MOC_LITERAL(41, 4), // "port"
QT_MOC_LITERAL(46, 10), // "stopServer"
QT_MOC_LITERAL(57, 13), // "currentClient"
QT_MOC_LITERAL(71, 6), // "client"
QT_MOC_LITERAL(78, 18), // "setStatisticClient"
QT_MOC_LITERAL(97, 16), // "clientDisconnect"
QT_MOC_LITERAL(114, 17), // "setSettingsServer"
QT_MOC_LITERAL(132, 16) // "disconnectServer"

    },
    "ServerSettings\0settingsServer\0\0ipAddress\0"
    "port\0stopServer\0currentClient\0client\0"
    "setStatisticClient\0clientDisconnect\0"
    "setSettingsServer\0disconnectServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerSettings[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   56,    2, 0x06,    0 /* Public */,
       5,    0,   61,    2, 0x06,    3 /* Public */,
       6,    1,   62,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   65,    2, 0x0a,    6 /* Public */,
       9,    1,   70,    2, 0x0a,    9 /* Public */,
      10,    0,   73,    2, 0x08,   11 /* Private */,
      11,    0,   74,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ServerSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerSettings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->settingsServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 1: _t->stopServer(); break;
        case 2: _t->currentClient((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setStatisticClient((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 4: _t->clientDisconnect((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setSettingsServer(); break;
        case 6: _t->disconnectServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ServerSettings::*)(const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerSettings::settingsServer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ServerSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerSettings::stopServer)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ServerSettings::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerSettings::currentClient)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ServerSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ServerSettings.offsetsAndSize,
    qt_meta_data_ServerSettings,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ServerSettings_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ServerSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerSettings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ServerSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ServerSettings::settingsServer(const QString & _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ServerSettings::stopServer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ServerSettings::currentClient(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
