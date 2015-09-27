/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "Customplot\qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CMainWindowClass
{
public:
    QAction *actionSchlie_en;
    QAction *actionTest;
    QAction *action_nextPage;
    QAction *action_showPlot;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_Start;
    QGridLayout *gridLayout_3;
    QLabel *label_Verbrauch_2;
    QLabel *label_showUsedLast;
    QLabel *label_Produziert_2;
    QLabel *label_showProducedLast;
    QLabel *label_showavAilableNow;
    QLabel *label_showProducedNow;
    QLabel *label_showUsedNow;
    QLabel *label_Verbrauch;
    QLabel *label_Verfgbar;
    QLabel *label_Verfgbar_2;
    QLabel *label;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Produziert;
    QLabel *label_showavAilableLast;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_Plot;
    QGridLayout *gridLayout_2;
    QCustomPlot *widget;
    QMenuBar *menuBar;
    QMenu *menuDatei;
    QMenu *menuAnsicht;
    QMenu *menuAnsicht_Alle;

    void setupUi(QMainWindow *CMainWindowClass)
    {
        if (CMainWindowClass->objectName().isEmpty())
            CMainWindowClass->setObjectName(QStringLiteral("CMainWindowClass"));
        CMainWindowClass->resize(462, 327);
        actionSchlie_en = new QAction(CMainWindowClass);
        actionSchlie_en->setObjectName(QStringLiteral("actionSchlie_en"));
        actionTest = new QAction(CMainWindowClass);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        action_nextPage = new QAction(CMainWindowClass);
        action_nextPage->setObjectName(QStringLiteral("action_nextPage"));
        action_showPlot = new QAction(CMainWindowClass);
        action_showPlot->setObjectName(QStringLiteral("action_showPlot"));
        centralWidget = new QWidget(CMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_Start = new QWidget();
        page_Start->setObjectName(QStringLiteral("page_Start"));
        gridLayout_3 = new QGridLayout(page_Start);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_Verbrauch_2 = new QLabel(page_Start);
        label_Verbrauch_2->setObjectName(QStringLiteral("label_Verbrauch_2"));

        gridLayout_3->addWidget(label_Verbrauch_2, 8, 4, 1, 1);

        label_showUsedLast = new QLabel(page_Start);
        label_showUsedLast->setObjectName(QStringLiteral("label_showUsedLast"));

        gridLayout_3->addWidget(label_showUsedLast, 8, 5, 1, 1);

        label_Produziert_2 = new QLabel(page_Start);
        label_Produziert_2->setObjectName(QStringLiteral("label_Produziert_2"));

        gridLayout_3->addWidget(label_Produziert_2, 8, 1, 1, 1);

        label_showProducedLast = new QLabel(page_Start);
        label_showProducedLast->setObjectName(QStringLiteral("label_showProducedLast"));

        gridLayout_3->addWidget(label_showProducedLast, 8, 2, 1, 1);

        label_showavAilableNow = new QLabel(page_Start);
        label_showavAilableNow->setObjectName(QStringLiteral("label_showavAilableNow"));

        gridLayout_3->addWidget(label_showavAilableNow, 3, 8, 1, 1);

        label_showProducedNow = new QLabel(page_Start);
        label_showProducedNow->setObjectName(QStringLiteral("label_showProducedNow"));

        gridLayout_3->addWidget(label_showProducedNow, 3, 2, 1, 1);

        label_showUsedNow = new QLabel(page_Start);
        label_showUsedNow->setObjectName(QStringLiteral("label_showUsedNow"));

        gridLayout_3->addWidget(label_showUsedNow, 3, 5, 1, 1);

        label_Verbrauch = new QLabel(page_Start);
        label_Verbrauch->setObjectName(QStringLiteral("label_Verbrauch"));

        gridLayout_3->addWidget(label_Verbrauch, 3, 4, 1, 1);

        label_Verfgbar = new QLabel(page_Start);
        label_Verfgbar->setObjectName(QStringLiteral("label_Verfgbar"));

        gridLayout_3->addWidget(label_Verfgbar, 3, 7, 1, 1);

        label_Verfgbar_2 = new QLabel(page_Start);
        label_Verfgbar_2->setObjectName(QStringLiteral("label_Verfgbar_2"));

        gridLayout_3->addWidget(label_Verfgbar_2, 8, 7, 1, 1);

        label = new QLabel(page_Start);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        gridLayout_3->addWidget(label, 1, 1, 1, 8);

        label_6 = new QLabel(page_Start);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 6, 1, 1, 8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 3, 1, 1);

        label_Produziert = new QLabel(page_Start);
        label_Produziert->setObjectName(QStringLiteral("label_Produziert"));

        gridLayout_3->addWidget(label_Produziert, 3, 1, 1, 1);

        label_showavAilableLast = new QLabel(page_Start);
        label_showavAilableLast->setObjectName(QStringLiteral("label_showavAilableLast"));

        gridLayout_3->addWidget(label_showavAilableLast, 8, 8, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 9, 1, 1, 1);

        stackedWidget->addWidget(page_Start);
        page_Plot = new QWidget();
        page_Plot->setObjectName(QStringLiteral("page_Plot"));
        gridLayout_2 = new QGridLayout(page_Plot);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget = new QCustomPlot(page_Plot);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(page_Plot);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        CMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 462, 21));
        menuDatei = new QMenu(menuBar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        menuDatei->setTearOffEnabled(false);
        menuAnsicht = new QMenu(menuBar);
        menuAnsicht->setObjectName(QStringLiteral("menuAnsicht"));
        menuAnsicht->setTearOffEnabled(false);
        menuAnsicht->setSeparatorsCollapsible(false);
        menuAnsicht->setToolTipsVisible(false);
        menuAnsicht_Alle = new QMenu(menuBar);
        menuAnsicht_Alle->setObjectName(QStringLiteral("menuAnsicht_Alle"));
        CMainWindowClass->setMenuBar(menuBar);

        menuBar->addAction(menuDatei->menuAction());
        menuBar->addAction(menuAnsicht->menuAction());
        menuBar->addAction(menuAnsicht_Alle->menuAction());
        menuDatei->addAction(actionSchlie_en);
        menuAnsicht->addAction(action_nextPage);
        menuAnsicht_Alle->addAction(actionTest);

        retranslateUi(CMainWindowClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowClass)
    {
        CMainWindowClass->setWindowTitle(QApplication::translate("CMainWindowClass", "CMainWindow", 0));
        actionSchlie_en->setText(QApplication::translate("CMainWindowClass", "Schlie\303\237en", 0));
        actionTest->setText(QApplication::translate("CMainWindowClass", "test", 0));
        action_nextPage->setText(QApplication::translate("CMainWindowClass", "N\303\244chste Seite", 0));
        action_showPlot->setText(QApplication::translate("CMainWindowClass", "Diagram", 0));
        label_Verbrauch_2->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:14pt;\">Verbrauch:</span></p></body></html>", 0));
        label_showUsedLast->setText(QApplication::translate("CMainWindowClass", "show", 0));
        label_Produziert_2->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:14pt;\">Produziert:</span></p></body></html>", 0));
        label_showProducedLast->setText(QApplication::translate("CMainWindowClass", "show", 0));
        label_showavAilableNow->setText(QApplication::translate("CMainWindowClass", "show", 0));
        label_showProducedNow->setText(QApplication::translate("CMainWindowClass", "show", 0));
        label_showUsedNow->setText(QApplication::translate("CMainWindowClass", "show", 0));
        label_Verbrauch->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:14pt;\">Verbrauch:</span></p></body></html>", 0));
        label_Verfgbar->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:14pt;\">Verf\303\274gbar:</span></p></body></html>", 0));
        label_Verfgbar_2->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:14pt;\">Verf\303\274gbar:</span></p></body></html>", 0));
        label->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:16pt;\">Aktuell</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:16pt;\">Durchschnitt letzte 15min</span></p></body></html>", 0));
        label_Produziert->setText(QApplication::translate("CMainWindowClass", "<html><head/><body><p><span style=\" font-size:14pt;\">Produziert:</span></p></body></html>", 0));
        label_showavAilableLast->setText(QApplication::translate("CMainWindowClass", "show", 0));
        menuDatei->setTitle(QApplication::translate("CMainWindowClass", "Datei", 0));
        menuAnsicht->setTitle(QApplication::translate("CMainWindowClass", "Ansicht", 0));
        menuAnsicht_Alle->setTitle(QApplication::translate("CMainWindowClass", "Ansicht Alle", 0));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowClass: public Ui_CMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
