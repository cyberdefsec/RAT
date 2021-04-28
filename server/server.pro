TEMPLATE = app
TARGET = administration

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 exception warning_on

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    listprocess.cpp \
    main.cpp \
    application.cpp \
    filemanager.cpp \
    groups.cpp \
    host.cpp \
    mainwindow.cpp \
    netinfo.cpp \
    server.cpp \
    serversettings.cpp \
    service.cpp \
    shell.cpp \
    sysinfo.cpp \
    users.cpp



HEADERS += \
    application.h \
    common.h \
    filemanager.h \
    groups.h \
    host.h \
    listprocess.h \
    mainwindow.h \
    netinfo.h \
    server.h \
    serversettings.h \
    service.h \
    shell.h \
    sysinfo.h \
    users.h



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
