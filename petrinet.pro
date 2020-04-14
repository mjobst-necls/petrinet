#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T15:38:31
#
#-------------------------------------------------

QT -= core gui

TARGET = PetriNet
TEMPLATE = lib

DEFINES += PETRINET_LIBRARY

DESTDIR = $$top_builddir/bin
LIBS += -L$$top_builddir/bin

QMAKE_CXXFLAGS += -std=c++11

OBJECTS_DIR = $$PWD/obj

SOURCES += \
    src/AbstractPetriNetQuery.cpp \
    src/AbstractTransitionHelper.cpp \
    src/Arc.cpp \
    src/ConnectableElement.cpp \
    src/NamedElement.cpp \
    src/PetriNetObject.cpp \
    src/Place.cpp \
    src/PlaceAction.cpp \
    src/TimestampedElement.cpp \
    src/Token.cpp \
    src/TokenData.cpp \
    src/Transition.cpp \
    src/TransitionAction.cpp \
    src/PetriNet.cpp \
    src/AbstractTransitionCondition.cpp

HEADERS +=\
        src/petrinet_global.h \
    src/AbstractPetriNetQuery.h \
    src/AbstractTransitionHelper.h \
    src/Arc.h \
    src/ConnectableElement.h \
    src/NamedElement.h \
    src/PetriNetObject.h \
    src/Place.h \
    src/PlaceAction.h \
    src/TimestampedElement.h \
    src/Token.h \
    src/TokenData.h \
    src/Transition.h \
    src/TransitionAction.h \
    src/PetriNet.h \
    src/AbstractTransitionCondition.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
