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
    AbstractPetriNetQuery.cpp \
    AbstractTransitionHelper.cpp \
    Arc.cpp \
    ConnectableElement.cpp \
    NamedElement.cpp \
    PetriNetObject.cpp \
    Place.cpp \
    PlaceAction.cpp \
    TimestampedElement.cpp \
    Token.cpp \
    TokenData.cpp \
    Transition.cpp \
    TransitionAction.cpp \
    PetriNet.cpp \
    AbstractTransitionCondition.cpp

HEADERS +=\
        petrinet_global.h \
    AbstractPetriNetQuery.h \
    AbstractTransitionHelper.h \
    Arc.h \
    ConnectableElement.h \
    NamedElement.h \
    PetriNetObject.h \
    Place.h \
    PlaceAction.h \
    TimestampedElement.h \
    Token.h \
    TokenData.h \
    Transition.h \
    TransitionAction.h \
    PetriNet.h \
    AbstractTransitionCondition.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
