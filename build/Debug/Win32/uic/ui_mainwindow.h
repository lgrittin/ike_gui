/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionOpen_Log;
    QAction *actionSynchronizeParams;
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_controlloInverter;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_start;
    QLabel *label_impulsiAttivi;
    QPushButton *pushButton_ackFault;
    QLabel *label_ImpulsiSpenti;
    QGroupBox *groupBox_statoInverter;
    QLabel *label_init;
    QLabel *label_freqEst;
    QLabel *label_readyToOp;
    QLabel *label_opEnabled;
    QLabel *label_fault;
    QLabel *label_SYNCH_SCR_LOST;
    QLabel *label_FREQ_SCR_UNDEF;
    QLabel *label_DESAT;
    QLabel *label_OVER_CURRENT;
    QLabel *label_UNDER_CURRENT;
    QLabel *label_OVER_VOLTAGE;
    QLabel *label_UNDER_VOLTAGE;
    QLabel *label_PSUPLLY;
    QLabel *label_EXTERNAL_FLT;
    QLabel *label_OH1;
    QLabel *label_OH2;
    QLabel *label_activeFaults;
    QHBoxLayout *horizontalLayout_params;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menuBar;
    QMenu *menuCalls;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *bottomStatusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1164, 678);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Plugged_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Unplugged_16x.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QString::fromUtf8("actionConfigure"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/icons8-settings-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfigure->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons8-broom-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        actionOpen_Log = new QAction(MainWindow);
        actionOpen_Log->setObjectName(QString::fromUtf8("actionOpen_Log"));
        actionSynchronizeParams = new QAction(MainWindow);
        actionSynchronizeParams->setObjectName(QString::fromUtf8("actionSynchronizeParams"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons8-synchronize-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSynchronizeParams->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_9 = new QGridLayout(centralWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox_controlloInverter = new QGroupBox(centralWidget);
        groupBox_controlloInverter->setObjectName(QString::fromUtf8("groupBox_controlloInverter"));
        groupBox_controlloInverter->setFlat(false);
        gridLayout_7 = new QGridLayout(groupBox_controlloInverter);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton_start = new QPushButton(groupBox_controlloInverter);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setCheckable(true);

        gridLayout_7->addWidget(pushButton_start, 1, 0, 1, 2);

        label_impulsiAttivi = new QLabel(groupBox_controlloInverter);
        label_impulsiAttivi->setObjectName(QString::fromUtf8("label_impulsiAttivi"));
        label_impulsiAttivi->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_impulsiAttivi, 2, 1, 1, 1);

        pushButton_ackFault = new QPushButton(groupBox_controlloInverter);
        pushButton_ackFault->setObjectName(QString::fromUtf8("pushButton_ackFault"));
        pushButton_ackFault->setCheckable(false);

        gridLayout_7->addWidget(pushButton_ackFault, 0, 0, 1, 2);

        label_ImpulsiSpenti = new QLabel(groupBox_controlloInverter);
        label_ImpulsiSpenti->setObjectName(QString::fromUtf8("label_ImpulsiSpenti"));
        label_ImpulsiSpenti->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_ImpulsiSpenti, 2, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_controlloInverter, 1, 1, 1, 1);

        groupBox_statoInverter = new QGroupBox(centralWidget);
        groupBox_statoInverter->setObjectName(QString::fromUtf8("groupBox_statoInverter"));
        groupBox_statoInverter->setFlat(false);
        label_init = new QLabel(groupBox_statoInverter);
        label_init->setObjectName(QString::fromUtf8("label_init"));
        label_init->setGeometry(QRect(20, 20, 91, 16));
        label_init->setFocusPolicy(Qt::NoFocus);
        label_init->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_init->setFrameShape(QFrame::Box);
        label_init->setAlignment(Qt::AlignCenter);
        label_freqEst = new QLabel(groupBox_statoInverter);
        label_freqEst->setObjectName(QString::fromUtf8("label_freqEst"));
        label_freqEst->setGeometry(QRect(20, 50, 91, 16));
        label_freqEst->setFocusPolicy(Qt::NoFocus);
        label_freqEst->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_freqEst->setFrameShape(QFrame::Box);
        label_freqEst->setAlignment(Qt::AlignCenter);
        label_readyToOp = new QLabel(groupBox_statoInverter);
        label_readyToOp->setObjectName(QString::fromUtf8("label_readyToOp"));
        label_readyToOp->setGeometry(QRect(20, 80, 91, 16));
        label_readyToOp->setFocusPolicy(Qt::NoFocus);
        label_readyToOp->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_readyToOp->setFrameShape(QFrame::Box);
        label_readyToOp->setAlignment(Qt::AlignCenter);
        label_opEnabled = new QLabel(groupBox_statoInverter);
        label_opEnabled->setObjectName(QString::fromUtf8("label_opEnabled"));
        label_opEnabled->setGeometry(QRect(20, 110, 91, 16));
        label_opEnabled->setFocusPolicy(Qt::NoFocus);
        label_opEnabled->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_opEnabled->setFrameShape(QFrame::Box);
        label_opEnabled->setAlignment(Qt::AlignCenter);
        label_fault = new QLabel(groupBox_statoInverter);
        label_fault->setObjectName(QString::fromUtf8("label_fault"));
        label_fault->setGeometry(QRect(130, 110, 41, 16));
        label_fault->setFocusPolicy(Qt::NoFocus);
        label_fault->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_fault->setFrameShape(QFrame::Box);
        label_fault->setAlignment(Qt::AlignCenter);
        label_SYNCH_SCR_LOST = new QLabel(groupBox_statoInverter);
        label_SYNCH_SCR_LOST->setObjectName(QString::fromUtf8("label_SYNCH_SCR_LOST"));
        label_SYNCH_SCR_LOST->setGeometry(QRect(210, 30, 101, 16));
        label_FREQ_SCR_UNDEF = new QLabel(groupBox_statoInverter);
        label_FREQ_SCR_UNDEF->setObjectName(QString::fromUtf8("label_FREQ_SCR_UNDEF"));
        label_FREQ_SCR_UNDEF->setGeometry(QRect(210, 50, 101, 16));
        label_DESAT = new QLabel(groupBox_statoInverter);
        label_DESAT->setObjectName(QString::fromUtf8("label_DESAT"));
        label_DESAT->setGeometry(QRect(210, 70, 101, 16));
        label_OVER_CURRENT = new QLabel(groupBox_statoInverter);
        label_OVER_CURRENT->setObjectName(QString::fromUtf8("label_OVER_CURRENT"));
        label_OVER_CURRENT->setGeometry(QRect(210, 90, 101, 16));
        label_UNDER_CURRENT = new QLabel(groupBox_statoInverter);
        label_UNDER_CURRENT->setObjectName(QString::fromUtf8("label_UNDER_CURRENT"));
        label_UNDER_CURRENT->setGeometry(QRect(210, 110, 101, 16));
        label_OVER_VOLTAGE = new QLabel(groupBox_statoInverter);
        label_OVER_VOLTAGE->setObjectName(QString::fromUtf8("label_OVER_VOLTAGE"));
        label_OVER_VOLTAGE->setGeometry(QRect(340, 30, 101, 16));
        label_UNDER_VOLTAGE = new QLabel(groupBox_statoInverter);
        label_UNDER_VOLTAGE->setObjectName(QString::fromUtf8("label_UNDER_VOLTAGE"));
        label_UNDER_VOLTAGE->setGeometry(QRect(340, 50, 101, 16));
        label_PSUPLLY = new QLabel(groupBox_statoInverter);
        label_PSUPLLY->setObjectName(QString::fromUtf8("label_PSUPLLY"));
        label_PSUPLLY->setGeometry(QRect(340, 70, 101, 16));
        label_EXTERNAL_FLT = new QLabel(groupBox_statoInverter);
        label_EXTERNAL_FLT->setObjectName(QString::fromUtf8("label_EXTERNAL_FLT"));
        label_EXTERNAL_FLT->setGeometry(QRect(340, 90, 101, 16));
        label_OH1 = new QLabel(groupBox_statoInverter);
        label_OH1->setObjectName(QString::fromUtf8("label_OH1"));
        label_OH1->setGeometry(QRect(340, 110, 21, 16));
        label_OH2 = new QLabel(groupBox_statoInverter);
        label_OH2->setObjectName(QString::fromUtf8("label_OH2"));
        label_OH2->setGeometry(QRect(400, 110, 21, 16));
        label_activeFaults = new QLabel(groupBox_statoInverter);
        label_activeFaults->setObjectName(QString::fromUtf8("label_activeFaults"));
        label_activeFaults->setGeometry(QRect(210, 10, 101, 16));
        label_activeFaults->setTextFormat(Qt::PlainText);

        gridLayout_9->addWidget(groupBox_statoInverter, 2, 1, 1, 1);

        horizontalLayout_params = new QHBoxLayout();
        horizontalLayout_params->setSpacing(6);
        horizontalLayout_params->setObjectName(QString::fromUtf8("horizontalLayout_params"));
        horizontalLayout_params->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout_9->addLayout(horizontalLayout_params, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout_9->addLayout(horizontalLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1164, 21));
        menuCalls = new QMenu(menuBar);
        menuCalls->setObjectName(QString::fromUtf8("menuCalls"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        bottomStatusBar = new QStatusBar(MainWindow);
        bottomStatusBar->setObjectName(QString::fromUtf8("bottomStatusBar"));
        MainWindow->setStatusBar(bottomStatusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuCalls->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCalls->addAction(actionConnect);
        menuCalls->addAction(actionDisconnect);
        menuCalls->addSeparator();
        menuCalls->addAction(actionQuit);
        menuTools->addAction(actionConfigure);
        menuTools->addAction(actionClear);
        menuTools->addAction(actionOpen_Log);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionClear);
        mainToolBar->addAction(actionSynchronizeParams);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Simple Terminal", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Alt+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutQt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "C&onnect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "Connect to serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "&Disconnect", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "Disconnect from serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDisconnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionConfigure->setText(QCoreApplication::translate("MainWindow", "&Configure", nullptr));
#if QT_CONFIG(tooltip)
        actionConfigure->setToolTip(QCoreApplication::translate("MainWindow", "Configure serial port", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConfigure->setShortcut(QCoreApplication::translate("MainWindow", "Alt+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear->setText(QCoreApplication::translate("MainWindow", "C&lear", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "Clear data", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClear->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Log->setText(QCoreApplication::translate("MainWindow", "Open Log", nullptr));
        actionSynchronizeParams->setText(QCoreApplication::translate("MainWindow", "C&lear", nullptr));
#if QT_CONFIG(tooltip)
        actionSynchronizeParams->setToolTip(QCoreApplication::translate("MainWindow", "Synchronize Parameters", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_controlloInverter->setTitle(QCoreApplication::translate("MainWindow", "Controllo Inverter", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start / Off", nullptr));
        label_impulsiAttivi->setText(QCoreApplication::translate("MainWindow", "Impulsi\n"
"Abilitati", nullptr));
        pushButton_ackFault->setText(QCoreApplication::translate("MainWindow", "Ack Fault", nullptr));
        label_ImpulsiSpenti->setText(QCoreApplication::translate("MainWindow", "Impulsi\n"
"Spenti", nullptr));
        groupBox_statoInverter->setTitle(QCoreApplication::translate("MainWindow", "Stato Inverter", nullptr));
        label_init->setText(QCoreApplication::translate("MainWindow", "INIT", nullptr));
        label_freqEst->setText(QCoreApplication::translate("MainWindow", "FREQ ESTIM.", nullptr));
        label_readyToOp->setText(QCoreApplication::translate("MainWindow", "READY TO OP", nullptr));
        label_opEnabled->setText(QCoreApplication::translate("MainWindow", "OP. ENABLED", nullptr));
        label_fault->setText(QCoreApplication::translate("MainWindow", "FAULT", nullptr));
        label_SYNCH_SCR_LOST->setText(QCoreApplication::translate("MainWindow", "SYNCH_SCR_LOST", nullptr));
        label_FREQ_SCR_UNDEF->setText(QCoreApplication::translate("MainWindow", "FREQ_SCR_UNDEF", nullptr));
        label_DESAT->setText(QCoreApplication::translate("MainWindow", "DESAT", nullptr));
        label_OVER_CURRENT->setText(QCoreApplication::translate("MainWindow", "OVER_CURRENT", nullptr));
        label_UNDER_CURRENT->setText(QCoreApplication::translate("MainWindow", "UNDER_CURRENT", nullptr));
        label_OVER_VOLTAGE->setText(QCoreApplication::translate("MainWindow", "OVER_VOLTAGE", nullptr));
        label_UNDER_VOLTAGE->setText(QCoreApplication::translate("MainWindow", "UNDER_VOLTAGE", nullptr));
        label_PSUPLLY->setText(QCoreApplication::translate("MainWindow", "PSUPLLY", nullptr));
        label_EXTERNAL_FLT->setText(QCoreApplication::translate("MainWindow", "EXTERNAL_FLT", nullptr));
        label_OH1->setText(QCoreApplication::translate("MainWindow", "OH1", nullptr));
        label_OH2->setText(QCoreApplication::translate("MainWindow", "OH2", nullptr));
        label_activeFaults->setText(QCoreApplication::translate("MainWindow", "Active Faults:", nullptr));
        menuCalls->setTitle(QCoreApplication::translate("MainWindow", "Calls", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
