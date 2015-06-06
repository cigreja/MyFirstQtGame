#-------------------------------------------------
#
# Project created by QtCreator 2015-06-06T09:17:41
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyFirstQtGame
TEMPLATE = app


SOURCES += main.cpp \
    Player.cpp \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp

HEADERS  += \
    Bullet.h \
    Player.h \
    Enemy.h \
    Game.h \
    Score.h \
    Health.h

FORMS    +=

RESOURCES += \
    res.qrc
