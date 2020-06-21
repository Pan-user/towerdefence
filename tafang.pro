QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Pos.cpp \
    basetower.cpp \
    bullet.cpp \
    button.cpp \
    chapter.cpp \
    endwindow.cpp \
    enemy.cpp \
    enemy_plus.cpp \
    list.cpp \
    main.cpp \
    mainwindow.cpp \
    tower1.cpp \
    tower2.cpp

HEADERS += \
    Pos.h \
    basetower.h \
    bullet.h \
    button.h \
    chapter.h \
    endwindow.h \
    enemy.h \
    enemy_plus.h \
    list.h \
    mainwindow.h \
    test.h \
    tower1.h \
    tower2.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES +=
