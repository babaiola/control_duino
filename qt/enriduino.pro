#-------------------------------------------------
#
# Project created by QtCreator 2012-06-12T11:52:23
#
#-------------------------------------------------

QT       -= core gui

TARGET = enriduino
TEMPLATE = lib

DEFINES += ENRIDUINO_LIBRARY

SOURCES += enriduino.cpp

HEADERS += enriduino.h\
        enriduino_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE9A6246C
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = enriduino.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

include(/usr/include/qextserialport/src/qextserialport.pri)
