QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appcontroller.cpp \
    ballmodel.cpp \
    ballview.cpp \
    brickmodel.cpp \
    brickview.cpp \
    gamecontroller.cpp \
    gamemodel.cpp \
    gameovercontroler.cpp \
    gameoverview.cpp \
    gameview.cpp \
    main.cpp \
    mainwindow.cpp \
    menucontroler.cpp \
    menumodel.cpp \
    menuview.cpp \
    raquettemodel.cpp \
    raquetteview.cpp

HEADERS += \
    appcontroller.h \
    ballmodel.h \
    ballview.h \
    brickmodel.h \
    brickview.h \
    config.h \
    gamecontroller.h \
    gamemodel.h \
    gameovercontroler.h \
    gameoverview.h \
    gameview.h \
    mainwindow.h \
    menucontroler.h \
    menumodel.h \
    menuview.h \
    raquettemodel.h \
    raquetteview.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_CFLAGS += -Wno-implicit-function-declaration
QMAKE_CXXFLAGS += -Wno-implicit-function-declaration
