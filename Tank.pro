#-------------------------------------------------
#
# Project created by QtCreator 2018-07-21T22:33:39
#
#-------------------------------------------------

QT       += core gui concurrent
CONFIG   += console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    EntityFu.cpp \
    weaponcomponent.cpp \
    healthcomponent.cpp \
    movecomponent.cpp \
    aicomponent.cpp \
    healthsystem.cpp \
    collisioncomponent.cpp \
    positioncomponent.cpp \
    movesystem.cpp \
    inputcomponent.cpp \
    inputsystem.cpp \
    globalapplication.cpp \
    rendercomponent.cpp \
    shellcomponent.cpp \
    tankcomponent.cpp \
    collisionsystem.cpp \
    damagesystem.cpp \
    destroysystem.cpp \
    fuelcomponent.cpp \
    fuelsystem.cpp \
    weaponsystem.cpp \
    firesystem.cpp \
    hitcomponent.cpp \
    hitsystem.cpp

HEADERS  += mainwindow.h \
    EntityFu.h \
    weaponcomponent.h \
    healthcomponent.h \
    movecomponent.h \
    aicomponent.h \
    healthsystem.h \
    collisioncomponent.h \
    positioncomponent.h \
    movesystem.h \
    inputcomponent.h \
    inputsystem.h \
    globalapplication.h \
    rendercomponent.h \
    tankcomponent.h \
    collisionsystem.h \
    damagesystem.h \
    destroysystem.h \
    util/vector2.h \
    matrix/AxisAngle.hpp \
    matrix/Dcm.hpp \
    matrix/Euler.hpp \
    matrix/filter.hpp \
    matrix/helper_functions.hpp \
    matrix/integration.hpp \
    matrix/math.hpp \
    matrix/Matrix.hpp \
    matrix/Quaternion.hpp \
    matrix/Scalar.hpp \
    matrix/SquareMatrix.hpp \
    matrix/stdlib_imports.hpp \
    matrix/Vector.hpp \
    matrix/Vector2.hpp \
    matrix/Vector3.hpp \
    const_value.h \
    fuelcomponent.h \
    fuelsystem.h \
    weaponsystem.h \
    firesystem.h \
    hitcomponent.h \
    hitsystem.h \
    ammunitioncomponent.h

