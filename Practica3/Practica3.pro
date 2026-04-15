TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        crypto.cpp \
        main.cpp \
        rle.cpp

HEADERS += \
    crypto.h \
    rle.h
