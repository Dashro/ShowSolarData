
HEADERS += ./Mainwindow.h \
    ./Customplot/qcustomplot.h \
    ./Plotter/Plotter.h \
    ./Plotter/PlotterWindow.h \
    ./Data/Data.h \
    ./WebSocketClient/WebSocketClient.h \
    ./StartPage/StartPage.h \
    ./StartPage/StartPageWindow.h \
    ./EventFilter.h \
    ./Settings/Settings.h
SOURCES += ./main.cpp \
    ./Mainwindow.cpp \
    ./Customplot/qcustomplot.cpp \
    ./Plotter/Plotter.cpp \
    ./Plotter/PlotterWindow.cpp \
    ./Data/Data.cpp \
    ./WebSocketClient/WebSocketClient.cpp \
    ./StartPage/StartPage.cpp \
    ./StartPage/CStartPageWindow.cpp \
    ./EventFilter.cpp \
    ./Settings/Settings.cpp
FORMS += ./Mainwindow.ui \
    ./Plotter/PlotterWindow.ui \
    ./StartPage/StartPageWindow.ui \
    ./Settings/Settings.ui
RESOURCES += ShowSolarData.qrc
