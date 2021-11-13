TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    exception.cpp \
    object.cpp

HEADERS += \
    smartpointer.h \
    exception.h \
    object.h \
    list.h \
    staticlist.h \
    seqlist.h \
    dynamiclist.h \
    array.h \
    staticarray.h \
    dynamicarray.h \
    linklist.h \
    staticlinklist.h \
    pointer.h \
    sharepointer.h
