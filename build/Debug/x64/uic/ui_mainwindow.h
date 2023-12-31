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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QAction *actionResetDeafult_Param;
    QAction *actionQuit;
    QAction *actionOpen_Log;
    QAction *actionReadAll;
    QAction *actionAutoTrigger;
    QAction *actionRead_Param;
    QAction *actionWrite_Param;
    QAction *actionLoadDatabase;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_faults;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_UNDER_VOLTAGE;
    QLabel *label_OVER_VOLTAGE;
    QLabel *label_DESAT;
    QLabel *label_PSUPLLY;
    QLabel *label_FREQ_SCR_UNDEF;
    QLabel *label_SYNCH_SCR_LOST;
    QLabel *label_UNDER_CURRENT;
    QLabel *label_OVER_CURRENT;
    QLabel *label_OH1;
    QLabel *label_OH2;
    QLabel *label_EXTERNAL_FLT;
    QGroupBox *groupBox_statoInverter;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_date;
    QLabel *label_time;
    QLabel *label_fmwvers;
    QLabel *label_dbvers;
    QLabel *label_sdCard;
    QLabel *label_rtc;
    QSpacerItem *verticalSpacer;
    QLabel *label_init;
    QLabel *label_freqEst;
    QLabel *label_readyToOp;
    QLabel *label_fault;
    QLabel *label_opEnabled;
    QGroupBox *groupBox_controlloInverter;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_start;
    QPushButton *pushButton_ackFault;
    QPushButton *pushButton_stop;
    QLabel *label_impulsiAttivi;
    QLabel *label_ImpulsiSpenti;
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
        MainWindow->resize(1164, 574);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
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
        actionResetDeafult_Param = new QAction(MainWindow);
        actionResetDeafult_Param->setObjectName(QString::fromUtf8("actionResetDeafult_Param"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/icons8-broom-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetDeafult_Param->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon4);
        actionOpen_Log = new QAction(MainWindow);
        actionOpen_Log->setObjectName(QString::fromUtf8("actionOpen_Log"));
        actionReadAll = new QAction(MainWindow);
        actionReadAll->setObjectName(QString::fromUtf8("actionReadAll"));
        actionReadAll->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/icons8-riproduci-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReadAll->setIcon(icon5);
        actionAutoTrigger = new QAction(MainWindow);
        actionAutoTrigger->setObjectName(QString::fromUtf8("actionAutoTrigger"));
        actionAutoTrigger->setCheckable(true);
        actionAutoTrigger->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/icons8-agopressione-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAutoTrigger->setIcon(icon6);
        actionRead_Param = new QAction(MainWindow);
        actionRead_Param->setObjectName(QString::fromUtf8("actionRead_Param"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/icons8-upload-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRead_Param->setIcon(icon7);
        actionWrite_Param = new QAction(MainWindow);
        actionWrite_Param->setObjectName(QString::fromUtf8("actionWrite_Param"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/icons8-scaricare-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWrite_Param->setIcon(icon8);
        actionLoadDatabase = new QAction(MainWindow);
        actionLoadDatabase->setObjectName(QString::fromUtf8("actionLoadDatabase"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/icons8-apri-cartella-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoadDatabase->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_faults = new QGroupBox(centralWidget);
        groupBox_faults->setObjectName(QString::fromUtf8("groupBox_faults"));
        verticalLayout_3 = new QVBoxLayout(groupBox_faults);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_UNDER_VOLTAGE = new QLabel(groupBox_faults);
        label_UNDER_VOLTAGE->setObjectName(QString::fromUtf8("label_UNDER_VOLTAGE"));
        label_UNDER_VOLTAGE->setFrameShape(QFrame::Box);
        label_UNDER_VOLTAGE->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_UNDER_VOLTAGE, 0, 0, 1, 1);

        label_OVER_VOLTAGE = new QLabel(groupBox_faults);
        label_OVER_VOLTAGE->setObjectName(QString::fromUtf8("label_OVER_VOLTAGE"));
        label_OVER_VOLTAGE->setFrameShape(QFrame::Box);
        label_OVER_VOLTAGE->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_OVER_VOLTAGE, 0, 1, 1, 1);

        label_DESAT = new QLabel(groupBox_faults);
        label_DESAT->setObjectName(QString::fromUtf8("label_DESAT"));
        label_DESAT->setFrameShape(QFrame::Box);
        label_DESAT->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_DESAT, 1, 0, 1, 1);

        label_PSUPLLY = new QLabel(groupBox_faults);
        label_PSUPLLY->setObjectName(QString::fromUtf8("label_PSUPLLY"));
        label_PSUPLLY->setFrameShape(QFrame::Box);
        label_PSUPLLY->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_PSUPLLY, 1, 1, 1, 1);

        label_FREQ_SCR_UNDEF = new QLabel(groupBox_faults);
        label_FREQ_SCR_UNDEF->setObjectName(QString::fromUtf8("label_FREQ_SCR_UNDEF"));
        label_FREQ_SCR_UNDEF->setFrameShape(QFrame::Box);
        label_FREQ_SCR_UNDEF->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_FREQ_SCR_UNDEF, 2, 0, 1, 1);

        label_SYNCH_SCR_LOST = new QLabel(groupBox_faults);
        label_SYNCH_SCR_LOST->setObjectName(QString::fromUtf8("label_SYNCH_SCR_LOST"));
        label_SYNCH_SCR_LOST->setFrameShape(QFrame::Box);
        label_SYNCH_SCR_LOST->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_SYNCH_SCR_LOST, 2, 1, 1, 1);

        label_UNDER_CURRENT = new QLabel(groupBox_faults);
        label_UNDER_CURRENT->setObjectName(QString::fromUtf8("label_UNDER_CURRENT"));
        label_UNDER_CURRENT->setFrameShape(QFrame::Box);
        label_UNDER_CURRENT->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_UNDER_CURRENT, 3, 0, 1, 1);

        label_OVER_CURRENT = new QLabel(groupBox_faults);
        label_OVER_CURRENT->setObjectName(QString::fromUtf8("label_OVER_CURRENT"));
        label_OVER_CURRENT->setFrameShape(QFrame::Box);
        label_OVER_CURRENT->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_OVER_CURRENT, 3, 1, 1, 1);

        label_OH1 = new QLabel(groupBox_faults);
        label_OH1->setObjectName(QString::fromUtf8("label_OH1"));
        label_OH1->setFrameShape(QFrame::Box);
        label_OH1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_OH1, 5, 0, 1, 1);

        label_OH2 = new QLabel(groupBox_faults);
        label_OH2->setObjectName(QString::fromUtf8("label_OH2"));
        label_OH2->setFrameShape(QFrame::Box);
        label_OH2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_OH2, 5, 1, 1, 1);

        label_EXTERNAL_FLT = new QLabel(groupBox_faults);
        label_EXTERNAL_FLT->setObjectName(QString::fromUtf8("label_EXTERNAL_FLT"));
        label_EXTERNAL_FLT->setFrameShape(QFrame::Box);
        label_EXTERNAL_FLT->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_EXTERNAL_FLT, 4, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);


        gridLayout->addWidget(groupBox_faults, 6, 0, 1, 1);

        groupBox_statoInverter = new QGroupBox(centralWidget);
        groupBox_statoInverter->setObjectName(QString::fromUtf8("groupBox_statoInverter"));
        groupBox_statoInverter->setFlat(false);
        verticalLayout_2 = new QVBoxLayout(groupBox_statoInverter);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_date = new QLabel(groupBox_statoInverter);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_date);

        label_time = new QLabel(groupBox_statoInverter);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_time);

        label_fmwvers = new QLabel(groupBox_statoInverter);
        label_fmwvers->setObjectName(QString::fromUtf8("label_fmwvers"));
        label_fmwvers->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_fmwvers);

        label_dbvers = new QLabel(groupBox_statoInverter);
        label_dbvers->setObjectName(QString::fromUtf8("label_dbvers"));
        label_dbvers->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_dbvers);

        label_sdCard = new QLabel(groupBox_statoInverter);
        label_sdCard->setObjectName(QString::fromUtf8("label_sdCard"));
        label_sdCard->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_sdCard);

        label_rtc = new QLabel(groupBox_statoInverter);
        label_rtc->setObjectName(QString::fromUtf8("label_rtc"));
        label_rtc->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_rtc);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

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


        gridLayout->addWidget(groupBox_statoInverter, 4, 0, 2, 1);

        groupBox_controlloInverter = new QGroupBox(centralWidget);
        groupBox_controlloInverter->setObjectName(QString::fromUtf8("groupBox_controlloInverter"));
        groupBox_controlloInverter->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBox_controlloInverter);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_start = new QPushButton(groupBox_controlloInverter);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setCheckable(false);

        gridLayout_2->addWidget(pushButton_start, 1, 1, 1, 1);

        pushButton_ackFault = new QPushButton(groupBox_controlloInverter);
        pushButton_ackFault->setObjectName(QString::fromUtf8("pushButton_ackFault"));
        pushButton_ackFault->setCheckable(false);

        gridLayout_2->addWidget(pushButton_ackFault, 0, 1, 1, 2);

        pushButton_stop = new QPushButton(groupBox_controlloInverter);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout_2->addWidget(pushButton_stop, 1, 2, 1, 1);

        label_impulsiAttivi = new QLabel(groupBox_controlloInverter);
        label_impulsiAttivi->setObjectName(QString::fromUtf8("label_impulsiAttivi"));
        label_impulsiAttivi->setFrameShape(QFrame::Box);
        label_impulsiAttivi->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_impulsiAttivi, 3, 2, 1, 1);

        label_ImpulsiSpenti = new QLabel(groupBox_controlloInverter);
        label_ImpulsiSpenti->setObjectName(QString::fromUtf8("label_ImpulsiSpenti"));
        label_ImpulsiSpenti->setFrameShape(QFrame::Box);
        label_ImpulsiSpenti->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_ImpulsiSpenti, 3, 1, 1, 1);


        gridLayout->addWidget(groupBox_controlloInverter, 2, 0, 2, 1);

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
        menuTools->addAction(actionLoadDatabase);
        menuTools->addAction(actionResetDeafult_Param);
        menuTools->addAction(actionReadAll);
        menuTools->addAction(actionAutoTrigger);
        menuTools->addAction(actionRead_Param);
        menuTools->addAction(actionWrite_Param);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);
        mainToolBar->addAction(actionLoadDatabase);
        mainToolBar->addAction(actionResetDeafult_Param);
        mainToolBar->addAction(actionAutoTrigger);
        mainToolBar->addAction(actionReadAll);
        mainToolBar->addAction(actionRead_Param);
        mainToolBar->addAction(actionWrite_Param);

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
        actionConnect->setText(QCoreApplication::translate("MainWindow", "C&onnect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "Connect", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionConnect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "&Disconnect", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
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
        actionResetDeafult_Param->setText(QCoreApplication::translate("MainWindow", "Default Params", nullptr));
#if QT_CONFIG(tooltip)
        actionResetDeafult_Param->setToolTip(QCoreApplication::translate("MainWindow", "Reset to Default Params", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionResetDeafult_Param->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Log->setText(QCoreApplication::translate("MainWindow", "Open Log", nullptr));
        actionReadAll->setText(QCoreApplication::translate("MainWindow", "Read All", nullptr));
#if QT_CONFIG(tooltip)
        actionReadAll->setToolTip(QCoreApplication::translate("MainWindow", "Read Parameters and Process Data", nullptr));
#endif // QT_CONFIG(tooltip)
        actionAutoTrigger->setText(QCoreApplication::translate("MainWindow", "AutoTrigger", nullptr));
#if QT_CONFIG(tooltip)
        actionAutoTrigger->setToolTip(QCoreApplication::translate("MainWindow", "Istantaneous Write Params", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRead_Param->setText(QCoreApplication::translate("MainWindow", "Read Param", nullptr));
#if QT_CONFIG(tooltip)
        actionRead_Param->setToolTip(QCoreApplication::translate("MainWindow", "Get Parameter Value(s)", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWrite_Param->setText(QCoreApplication::translate("MainWindow", "Write Param", nullptr));
#if QT_CONFIG(tooltip)
        actionWrite_Param->setToolTip(QCoreApplication::translate("MainWindow", "Set Parameter Value(s)", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLoadDatabase->setText(QCoreApplication::translate("MainWindow", "Load Database", nullptr));
#if QT_CONFIG(tooltip)
        actionLoadDatabase->setToolTip(QCoreApplication::translate("MainWindow", "Load New Database", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLoadDatabase->setShortcut(QCoreApplication::translate("MainWindow", "Alt+L", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_faults->setTitle(QString());
        label_UNDER_VOLTAGE->setText(QCoreApplication::translate("MainWindow", "LOW VOLT", nullptr));
        label_OVER_VOLTAGE->setText(QCoreApplication::translate("MainWindow", "HIGH VOLT", nullptr));
        label_DESAT->setText(QCoreApplication::translate("MainWindow", "DESAT", nullptr));
        label_PSUPLLY->setText(QCoreApplication::translate("MainWindow", "PSUPLLY", nullptr));
        label_FREQ_SCR_UNDEF->setText(QCoreApplication::translate("MainWindow", "FREQ UNDEF", nullptr));
        label_SYNCH_SCR_LOST->setText(QCoreApplication::translate("MainWindow", "PLL LOST", nullptr));
        label_UNDER_CURRENT->setText(QCoreApplication::translate("MainWindow", "LOW CURR", nullptr));
        label_OVER_CURRENT->setText(QCoreApplication::translate("MainWindow", "HIGH CURR", nullptr));
        label_OH1->setText(QCoreApplication::translate("MainWindow", "OH1", nullptr));
        label_OH2->setText(QCoreApplication::translate("MainWindow", "OH2", nullptr));
        label_EXTERNAL_FLT->setText(QCoreApplication::translate("MainWindow", "EXT FLT", nullptr));
        groupBox_statoInverter->setTitle(QString());
        label_date->setText(QCoreApplication::translate("MainWindow", "DayOfWeek, DD/MM/YYYY", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "HH:MM:SS", nullptr));
        label_fmwvers->setText(QCoreApplication::translate("MainWindow", "Fmw Version:", nullptr));
        label_dbvers->setText(QCoreApplication::translate("MainWindow", "DB Version:", nullptr));
        label_sdCard->setText(QCoreApplication::translate("MainWindow", "SD Card Enabled: ?", nullptr));
        label_rtc->setText(QCoreApplication::translate("MainWindow", "RTC Enabled: ?", nullptr));
        label_init->setText(QCoreApplication::translate("MainWindow", "INIT", nullptr));
        label_freqEst->setText(QCoreApplication::translate("MainWindow", "FREQ ESTIM.", nullptr));
        label_readyToOp->setText(QCoreApplication::translate("MainWindow", "READY TO OP", nullptr));
        label_fault->setText(QCoreApplication::translate("MainWindow", "FAULT", nullptr));
        label_opEnabled->setText(QCoreApplication::translate("MainWindow", "OP. ENABLED", nullptr));
        groupBox_controlloInverter->setTitle(QString());
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_ackFault->setText(QCoreApplication::translate("MainWindow", "Ack Fault", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_impulsiAttivi->setText(QCoreApplication::translate("MainWindow", "PULSES ON", nullptr));
        label_ImpulsiSpenti->setText(QCoreApplication::translate("MainWindow", "PULSES OFF", nullptr));
        menuCalls->setTitle(QCoreApplication::translate("MainWindow", "Communication", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
