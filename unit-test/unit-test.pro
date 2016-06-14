TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lgtest -lgtest_main -lpthread

INCLUDEPATH += ../ctp-parser

SOURCES += \
    test-case.cpp \
    ../ctp-parser/ctp-parser.cpp

HEADERS += \
    ../ctp-parser/ctp-parser.h
