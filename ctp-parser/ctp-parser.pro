TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#QMAKE_CXXFLAGS += `llvm-config --cxxflags --ldflags --system-libs --libs core`
#LIBS += `llvm-config --cxxflags --ldflags --system-libs --libs core`

SOURCES += \
    ctp-parser.cpp \
    main.cpp

HEADERS += \
    ctp-parser.h
