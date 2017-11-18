#-------------------------------------------------
#
# Project created by QtCreator 2017-09-19T15:32:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets printsupport

TARGET = main_widget_calendar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calendarwidget.cpp

HEADERS  += mainwindow.h \
    calendarwidget.h

QMAKE_LFLAGS = -static -static-libgcc -enable-stdcall-fixup -Wl,-enable-auto-import -Wl,-enable-runtime-pseudo-reloc
