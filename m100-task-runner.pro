#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T23:04:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = m100-task-runner
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


HEADERS  += mainwindow.h \
        QonboardSDK.h \
    tasks/abstracttask.h \
    tasks/taskmanager.h \
    singleton/callonce.h \
    singleton/singleton.h \
    tasks/tasklistmodel.h \
    tasks/sampletask.h

SOURCES += main.cpp\
        mainwindow.cpp \
        QonboardSDK.cpp \
    tasks/taskmanager.cpp \
    tasks/tasklistmodel.cpp \
    tasks/sampletask.cpp

INCLUDEPATH += \
        osdk-core/ \
        osdk-core/inc

FORMS    += mainwindow.ui


# For DJI Onboard SDK

DEPENDENCE += QT\
              DJILIB\
              DEPENDENCE

DEFINES += $$DEPENDENCE

QT += serialport

ONBOARDSDK_SRC += \
    osdk-core/src/DJI_API.cpp \
    osdk-core/src/DJI_App.cpp \
    osdk-core/src/DJI_Camera.cpp \
    osdk-core/src/DJI_Codec.cpp \
    osdk-core/src/DJI_Flight.cpp \
    osdk-core/src/DJI_Follow.cpp \
    osdk-core/src/DJI_HardDriver.cpp \
    osdk-core/src/DJI_HotPoint.cpp \
    osdk-core/src/DJI_Link.cpp \
    osdk-core/src/DJI_Logging.cpp \
    osdk-core/src/DJI_Memory.cpp \
    osdk-core/src/DJI_Mission.cpp \
    osdk-core/src/DJI_VirtualRC.cpp \
    osdk-core/src/DJI_WayPoint.cpp

HEADERS  += \
    osdk-core/inc/DJI_API.h \
    osdk-core/inc/DJI_App.h \
    osdk-core/inc/DJI_Camera.h \
    osdk-core/inc/DJI_Codec.h \
    osdk-core/inc/DJI_Config.h \
    osdk-core/inc/DJI_Flight.h \
    osdk-core/inc/DJI_Follow.h \
    osdk-core/inc/DJI_HardDriver.h \
    osdk-core/inc/DJI_HotPoint.h \
    osdk-core/inc/DJI_Link.h \
    osdk-core/inc/DJI_Logging.h \
    osdk-core/inc/DJI_Memory.h \
    osdk-core/inc/DJI_Mission.h \
    osdk-core/inc/DJI_Type.h \
    osdk-core/inc/DJI_Version.h \
    osdk-core/inc/DJI_VirtualRC.h \
    osdk-core/inc/DJI_WayPoint.h \
    osdk-core/inc/DJICommonType.h

SOURCES += $$ONBOARDSDK_SRC

HEADERS += $$ONBOARDSDK_INC
