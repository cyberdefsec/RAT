/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../server.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    const uint offsetsAndSize[82];
    char stringdata0[455];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 6), // "Server"
QT_MOC_LITERAL(7, 15), // "statisticClient"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 9), // "ipAddress"
QT_MOC_LITERAL(34, 4), // "port"
QT_MOC_LITERAL(39, 18), // "clientDisconnected"
QT_MOC_LITERAL(58, 6), // "client"
QT_MOC_LITERAL(65, 9), // "recvShell"
QT_MOC_LITERAL(75, 4), // "data"
QT_MOC_LITERAL(80, 11), // "recvSysInfo"
QT_MOC_LITERAL(92, 11), // "recvListDir"
QT_MOC_LITERAL(104, 8), // "LISTDIR&"
QT_MOC_LITERAL(113, 12), // "recvListProc"
QT_MOC_LITERAL(126, 9), // "LISTPROC&"
QT_MOC_LITERAL(136, 12), // "recvListDisk"
QT_MOC_LITERAL(149, 9), // "LISTDISK&"
QT_MOC_LITERAL(159, 13), // "recvListUsers"
QT_MOC_LITERAL(173, 9), // "INFOUSER&"
QT_MOC_LITERAL(183, 14), // "recvListGroups"
QT_MOC_LITERAL(198, 10), // "INFOGROUP&"
QT_MOC_LITERAL(209, 11), // "recvNetInfo"
QT_MOC_LITERAL(221, 7), // "NETINFO"
QT_MOC_LITERAL(229, 15), // "recvListService"
QT_MOC_LITERAL(245, 12), // "LISTSERVICE&"
QT_MOC_LITERAL(258, 14), // "recvScreenShot"
QT_MOC_LITERAL(273, 15), // "sendFileManager"
QT_MOC_LITERAL(289, 3), // "msg"
QT_MOC_LITERAL(293, 11), // "sendProcess"
QT_MOC_LITERAL(305, 9), // "sendGroup"
QT_MOC_LITERAL(315, 9), // "sendUsers"
QT_MOC_LITERAL(325, 8), // "recvFile"
QT_MOC_LITERAL(334, 10), // "recvBuffer"
QT_MOC_LITERAL(345, 16), // "setAddressServer"
QT_MOC_LITERAL(362, 16), // "clientDisconnect"
QT_MOC_LITERAL(379, 10), // "stopServer"
QT_MOC_LITERAL(390, 16), // "setCurrentClient"
QT_MOC_LITERAL(407, 9), // "curClient"
QT_MOC_LITERAL(417, 8), // "sendData"
QT_MOC_LITERAL(426, 5), // "DATA&"
QT_MOC_LITERAL(432, 8), // "recvData"
QT_MOC_LITERAL(441, 13) // "clientConnect"

    },
    "Server\0statisticClient\0\0ipAddress\0"
    "port\0clientDisconnected\0client\0recvShell\0"
    "data\0recvSysInfo\0recvListDir\0LISTDIR&\0"
    "recvListProc\0LISTPROC&\0recvListDisk\0"
    "LISTDISK&\0recvListUsers\0INFOUSER&\0"
    "recvListGroups\0INFOGROUP&\0recvNetInfo\0"
    "NETINFO\0recvListService\0LISTSERVICE&\0"
    "recvScreenShot\0sendFileManager\0msg\0"
    "sendProcess\0sendGroup\0sendUsers\0"
    "recvFile\0recvBuffer\0setAddressServer\0"
    "clientDisconnect\0stopServer\0"
    "setCurrentClient\0curClient\0sendData\0"
    "DATA&\0recvData\0clientConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  164,    2, 0x06,    0 /* Public */,
       5,    1,  169,    2, 0x06,    3 /* Public */,
       7,    1,  172,    2, 0x06,    5 /* Public */,
       9,    1,  175,    2, 0x06,    7 /* Public */,
      10,    1,  178,    2, 0x06,    9 /* Public */,
      12,    1,  181,    2, 0x06,   11 /* Public */,
      14,    1,  184,    2, 0x06,   13 /* Public */,
      16,    1,  187,    2, 0x06,   15 /* Public */,
      18,    1,  190,    2, 0x06,   17 /* Public */,
      20,    1,  193,    2, 0x06,   19 /* Public */,
      22,    1,  196,    2, 0x06,   21 /* Public */,
      24,    1,  199,    2, 0x06,   23 /* Public */,
      25,    1,  202,    2, 0x06,   25 /* Public */,
      27,    1,  205,    2, 0x06,   27 /* Public */,
      28,    1,  208,    2, 0x06,   29 /* Public */,
      29,    1,  211,    2, 0x06,   31 /* Public */,
      30,    1,  214,    2, 0x06,   33 /* Public */,
      31,    1,  217,    2, 0x06,   35 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      32,    2,  220,    2, 0x0a,   37 /* Public */,
      33,    0,  225,    2, 0x0a,   40 /* Public */,
      34,    0,  226,    2, 0x0a,   41 /* Public */,
      35,    1,  227,    2, 0x0a,   42 /* Public */,
      37,    1,  230,    2, 0x0a,   44 /* Public */,
      39,    0,  233,    2, 0x0a,   46 /* Public */,
      40,    0,  234,    2, 0x08,   47 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, 0x80000000 | 11,    8,
    QMetaType::Void, 0x80000000 | 13,    8,
    QMetaType::Void, 0x80000000 | 15,    8,
    QMetaType::Void, 0x80000000 | 17,    8,
    QMetaType::Void, 0x80000000 | 19,    8,
    QMetaType::Void, 0x80000000 | 21,    8,
    QMetaType::Void, 0x80000000 | 23,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   36,
    QMetaType::Void, 0x80000000 | 38,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->statisticClient((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 1: _t->clientDisconnected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->recvShell((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->recvSysInfo((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->recvListDir((*reinterpret_cast< LISTDIR(*)>(_a[1]))); break;
        case 5: _t->recvListProc((*reinterpret_cast< LISTPROC(*)>(_a[1]))); break;
        case 6: _t->recvListDisk((*reinterpret_cast< LISTDISK(*)>(_a[1]))); break;
        case 7: _t->recvListUsers((*reinterpret_cast< INFOUSER(*)>(_a[1]))); break;
        case 8: _t->recvListGroups((*reinterpret_cast< INFOGROUP(*)>(_a[1]))); break;
        case 9: _t->recvNetInfo((*reinterpret_cast< NETINFO(*)>(_a[1]))); break;
        case 10: _t->recvListService((*reinterpret_cast< LISTSERVICE(*)>(_a[1]))); break;
        case 11: _t->recvScreenShot((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 12: _t->sendFileManager((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->sendProcess((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->sendGroup((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->sendUsers((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->recvFile((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 17: _t->recvBuffer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 18: _t->setAddressServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const quint16(*)>(_a[2]))); break;
        case 19: _t->clientDisconnect(); break;
        case 20: _t->stopServer(); break;
        case 21: _t->setCurrentClient((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->sendData((*reinterpret_cast< DATA(*)>(_a[1]))); break;
        case 23: _t->recvData(); break;
        case 24: _t->clientConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)(const QString & , const quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::statisticClient)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::clientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvShell)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Server::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvSysInfo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Server::*)(LISTDIR & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvListDir)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Server::*)(LISTPROC & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvListProc)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Server::*)(LISTDISK & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvListDisk)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Server::*)(INFOUSER & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvListUsers)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Server::*)(INFOGROUP & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvListGroups)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Server::*)(NETINFO );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvNetInfo)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Server::*)(LISTSERVICE & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvListService)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Server::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvScreenShot)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::sendFileManager)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::sendProcess)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::sendGroup)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::sendUsers)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Server::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvFile)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Server::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::recvBuffer)) {
                *result = 17;
                return;
            }
        }
    }
}

const QMetaObject Server::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Server.offsetsAndSize,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Server_t
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTDIR &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTPROC &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTDISK &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<INFOUSER &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<INFOGROUP &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<NETINFO, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<LISTSERVICE &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const quint16, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<DATA &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void Server::statisticClient(const QString & _t1, const quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Server::clientDisconnected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::recvShell(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Server::recvSysInfo(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Server::recvListDir(LISTDIR & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Server::recvListProc(LISTPROC & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Server::recvListDisk(LISTDISK & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Server::recvListUsers(INFOUSER & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Server::recvListGroups(INFOGROUP & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Server::recvNetInfo(NETINFO _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Server::recvListService(LISTSERVICE & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Server::recvScreenShot(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Server::sendFileManager(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Server::sendProcess(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Server::sendGroup(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Server::sendUsers(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Server::recvFile(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Server::recvBuffer(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
