
TEMPLATE = app
TARGET = ShowSolarData
DESTDIR = ../Win32/Debug
QT += core network widgets gui printsupport websockets
CONFIG += debug
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug \
    ./Neuer Ordner \
    ./Ploter \
    ./Plotter \
    ./SolarData \
    ./StartPage \
    ./FolderChoose \
    ./ConsumptionData \
    ./Data \
    ./WebSocketClient \
    ./Settings
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(ShowSolarData.pri)
