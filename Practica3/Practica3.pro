TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        crypto.cpp \
        gestorArchivos.cpp \
        lz78.cpp \
        main.cpp \
        rle.cpp

HEADERS += \
    crypto.h \
    gestorArchivos.h \
    lz78.h \
    rle.h
