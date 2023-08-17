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
#include <QtWidgets/QVBoxLayout>
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
    QAction *actionAutoTrigger;
    QAction *actionWrite_Param;
    QAction *actionRead_All;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_statoInverter;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_init;
    QLabel *label_freqEst;
    QLabel *label_readyToOp;
    QLabel *label_fault;
    QLabel *label_opEnabled;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_OVER_VOLTAGE;
    QLabel *label_SYNCH_SCR_LOST;
    QLabel *label_FREQ_SCR_UNDEF;
    QLabel *label_UNDER_VOLTAGE;
    QLabel *label_DESAT;
    QLabel *label_PSUPLLY;
    QLabel *label_EXTERNAL_FLT;
    QLabel *label_OVER_CURRENT;
    QLabel *label_UNDER_CURRENT;
    QLabel *label_OH1;
    QLabel *label_OH2;
    QGroupBox *groupBox_controlloInverter;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_start;
    QPushButton *pushButton_ackFault;
    QLabel *label_ImpulsiSpenti;
    QLabel *label_impulsiAttivi;
    QHBoxLayout *horizontalLayout_process;
    QHBoxLayout *horizontalLayout_params;
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
        actionAutoTrigger = new QAction(MainWindow);
        actionAutoTrigger->setObjectName(QString::fromUtf8("actionAutoTrigger"));
        actionAutoTrigger->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons8-agopressione-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAutoTrigger->setIcon(icon6);
        actionWrite_Param = new QAction(MainWindow);
        actionWrite_Param->setObjectName(QString::fromUtf8("actionWrite_Param"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icons8-scaricare-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWrite_Param->setIcon(icon7);
        actionRead_All = new QAction(MainWindow);
        actionRead_All->setObjectName(QString::fromUtf8("actionRead_All"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons8-caricare-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRead_All->setIcon(icon8);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_statoInverter = new QGroupBox(centralWidget);
        groupBox_statoInverter->setObjectName(QString::fromUtf8("groupBox_statoInverter"));
        groupBox_statoInverter->setFlat(false);
        verticalLayout_2 = new QVBoxLayout(groupBox_statoInverter);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_init = new QLabel(groupBox_statoInverter);
        label_init->setObjectName(QString::fromUtf8("label_init"));
        label_init->setFocusPolicy(Qt::NoFocus);
        label_init->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_init->setFrameShape(QFrame::Box);
        label_init->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_init);

        label_freqEst = new QLabel(groupBox_statoInverter);
        label_freqEst->setObjectName(QString::fromUtf8("label_freqEst"));
        label_freqEst->setFocusPolicy(Qt::NoFocus);
        label_freqEst->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_freqEst->setFrameShape(QFrame::Box);
        label_freqEst->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_freqEst);

        label_readyToOp = new QLabel(groupBox_statoInverter);
        label_readyToOp->setObjectName(QString::fromUtf8("label_readyToOp"));
        label_readyToOp->setFocusPolicy(Qt::NoFocus);
        label_readyToOp->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_readyToOp->setFrameShape(QFrame::Box);
        label_readyToOp->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_readyToOp);

        label_fault = new QLabel(groupBox_statoInverter);
        label_fault->setObjectName(QString::fromUtf8("label_fault"));
        label_fault->setFocusPolicy(Qt::NoFocus);
        label_fault->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_fault->setFrameShape(QFrame::Box);
        label_fault->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_fault);

        label_opEnabled = new QLabel(groupBox_statoInverter);
        label_opEnabled->setObjectName(QString::fromUtf8("label_opEnabled"));
        label_opEnabled->setFocusPolicy(Qt::NoFocus);
        label_opEnabled->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_opEnabled->setFrameShape(QFrame::Box);
        label_opEnabled->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_opEnabled);


        gridLayout->addWidget(groupBox_statoInverter, 2, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_OVER_VOLTAGE = new QLabel(groupBox);
        label_OVER_VOLTAGE->setObjectName(QString::fromUtf8("label_OVER_VOLTAGE"));

        verticalLayout->addWidget(label_OVER_VOLTAGE);

        label_SYNCH_SCR_LOST = new QLabel(groupBox);
        label_SYNCH_SCR_LOST->setObjectName(QString::fromUtf8("label_SYNCH_SCR_LOST"));

        verticalLayout->addWidget(label_SYNCH_SCR_LOST);

        label_FREQ_SCR_UNDEF = new QLabel(groupBox);
        label_FREQ_SCR_UNDEF->setObjectName(QString::fromUtf8("label_FREQ_SCR_UNDEF"));

        verticalLayout->addWidget(label_FREQ_SCR_UNDEF);

        label_UNDER_VOLTAGE = new QLabel(groupBox);
        label_UNDER_VOLTAGE->setObjectName(QString::fromUtf8("label_UNDER_VOLTAGE"));

        verticalLayout->addWidget(label_UNDER_VOLTAGE);

        label_DESAT = new QLabel(groupBox);
        label_DESAT->setObjectName(QString::fromUtf8("label_DESAT"));

        verticalLayout->addWidget(label_DESAT);

        label_PSUPLLY = new QLabel(groupBox);
        label_PSUPLLY->setObjectName(QString::fromUtf8("label_PSUPLLY"));

        verticalLayout->addWidget(label_PSUPLLY);

        label_EXTERNAL_FLT = new QLabel(groupBox);
        label_EXTERNAL_FLT->setObjectName(QString::fromUtf8("label_EXTERNAL_FLT"));

        verticalLayout->addWidget(label_EXTERNAL_FLT);

        label_OVER_CURRENT = new QLabel(groupBox);
        label_OVER_CURRENT->setObjectName(QString::fromUtf8("label_OVER_CURRENT"));

        verticalLayout->addWidget(label_OVER_CURRENT);

        label_UNDER_CURRENT = new QLabel(groupBox);
        label_UNDER_CURRENT->setObjectName(QString::fromUtf8("label_UNDER_CURRENT"));

        verticalLayout->addWidget(label_UNDER_CURRENT);

        label_OH1 = new QLabel(groupBox);
        label_OH1->setObjectName(QString::fromUtf8("label_OH1"));

        verticalLayout->addWidget(label_OH1);

        label_OH2 = new QLabel(groupBox);
        label_OH2->setObjectName(QString::fromUtf8("label_OH2"));

        verticalLayout->addWidget(label_OH2);


        verticalLayout_3->addLayout(verticalLayout);


        gridLayout->addWidget(groupBox, 3, 1, 1, 1);

        groupBox_controlloInverter = new QGroupBox(centralWidget);
        groupBox_controlloInverter->setObjectName(QString::fromUtf8("groupBox_controlloInverter"));
        groupBox_controlloInverter->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBox_controlloInverter);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_start = new QPushButton(groupBox_controlloInverter);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setCheckable(true);

        gridLayout_2->addWidget(pushButton_start, 1, 0, 1, 2);

        pushButton_ackFault = new QPushButton(groupBox_controlloInverter);
        pushButton_ackFault->setObjectName(QString::fromUtf8("pushButton_ackFault"));
        pushButton_ackFault->setCheckable(false);

        gridLayout_2->addWidget(pushButton_ackFault, 0, 0, 1, 2);

        label_ImpulsiSpenti = new QLabel(groupBox_controlloInverter);
        label_ImpulsiSpenti->setObjectName(QString::fromUtf8("label_ImpulsiSpenti"));
        label_ImpulsiSpenti->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_ImpulsiSpenti, 2, 0, 1, 1);

        label_impulsiAttivi = new QLabel(groupBox_controlloInverter);
        label_impulsiAttivi->setObjectName(QString::fromUtf8("label_impulsiAttivi"));
        label_impulsiAttivi->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_impulsiAttivi, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_controlloInverter, 0, 1, 2, 1);

        horizontalLayout_process = new QHBoxLayout();
        horizontalLayout_process->setSpacing(6);
        horizontalLayout_process->setObjectName(QString::fromUtf8("horizontalLayout_process"));

        gridLayout->addLayout(horizontalLayout_process, 3, 0, 1, 1);

        horizontalLayout_params = new QHBoxLayout();
        horizontalLayout_params->setSpacing(6);
        horizontalLayout_params->setObjectName(QString::fromUtf8("horizontalLayout_params"));
        horizontalLayout_params->setSizeConstraint(QLayout::SetDefaultConstraint);

        gridLayout->addLayout(horizontalLayout_params, 0, 0, 3, 1);

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
        mainToolBar->addAction(actionAutoTrigger);
        mainToolBar->addAction(actionSynchronizeParams);
        mainToolBar->addAction(actionWrite_Param);
        mainToolBar->addAction(actionRead_All);

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
        actionSynchronizeParams->setText(QCoreApplication::translate("MainWindow", "Synchronize Params", nullptr));
#if QT_CONFIG(tooltip)
        actionSynchronizeParams->setToolTip(QCoreApplication::translate("MainWindow", "Write Params And Read All", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAutoTrigger->setText(QCoreApplication::translate("MainWindow", "AutoTrigger", nullptr));
#if QT_CONFIG(tooltip)
        actionAutoTrigger->setToolTip(QCoreApplication::translate("MainWindow", "Istantaneous Write Params", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWrite_Param->setText(QCoreApplication::translate("MainWindow", "Write Param", nullptr));
#if QT_CONFIG(tooltip)
        actionWrite_Param->setToolTip(QCoreApplication::translate("MainWindow", "Write Selected Parameter", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRead_All->setText(QCoreApplication::translate("MainWindow", "Read All", nullptr));
#if QT_CONFIG(tooltip)
        actionRead_All->setToolTip(QCoreApplication::translate("MainWindow", "Read Parameters and Process Data", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_statoInverter->setTitle(QCoreApplication::translate("MainWindow", "Stato Inverter", nullptr));
        label_init->setText(QCoreApplication::translate("MainWindow", "INIT", nullptr));
        label_freqEst->setText(QCoreApplication::translate("MainWindow", "FREQ ESTIM.", nullptr));
        label_readyToOp->setText(QCoreApplication::translate("MainWindow", "READY TO OP", nullptr));
        label_fault->setText(QCoreApplication::translate("MainWindow", "FAULT", nullptr));
        label_opEnabled->setText(QCoreApplication::translate("MainWindow", "OP. ENABLED", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Active Faults:", nullptr));
        label_OVER_VOLTAGE->setText(QCoreApplication::translate("MainWindow", "OVER_VOLTAGE", nullptr));
        label_SYNCH_SCR_LOST->setText(QCoreApplication::translate("MainWindow", "SYNCH_SCR_LOST", nullptr));
        label_FREQ_SCR_UNDEF->setText(QCoreApplication::translate("MainWindow", "FREQ_SCR_UNDEF", nullptr));
        label_UNDER_VOLTAGE->setText(QCoreApplication::translate("MainWindow", "UNDER_VOLTAGE", nullptr));
        label_DESAT->setText(QCoreApplication::translate("MainWindow", "DESAT", nullptr));
        label_PSUPLLY->setText(QCoreApplication::translate("MainWindow", "PSUPLLY", nullptr));
        label_EXTERNAL_FLT->setText(QCoreApplication::translate("MainWindow", "EXTERNAL_FLT", nullptr));
        label_OVER_CURRENT->setText(QCoreApplication::translate("MainWindow", "OVER_CURRENT", nullptr));
        label_UNDER_CURRENT->setText(QCoreApplication::translate("MainWindow", "UNDER_CURRENT", nullptr));
        label_OH1->setText(QCoreApplication::translate("MainWindow", "OH1", nullptr));
        label_OH2->setText(QCoreApplication::translate("MainWindow", "OH2", nullptr));
        groupBox_controlloInverter->setTitle(QCoreApplication::translate("MainWindow", "Controllo Inverter", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start / Off", nullptr));
        pushButton_ackFault->setText(QCoreApplication::translate("MainWindow", "Ack Fault", nullptr));
        label_ImpulsiSpenti->setText(QCoreApplication::translate("MainWindow", "Impulsi\n"
"Spenti", nullptr));
        label_impulsiAttivi->setText(QCoreApplication::translate("MainWindow", "Impulsi\n"
"Abilitati", nullptr));
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
