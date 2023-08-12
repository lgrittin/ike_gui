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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_feedbackInverter;
    QGridLayout *gridLayout_6;
    QLabel *label_vInv;
    QLabel *label_vInvVal;
    QLabel *label_vInvUM;
    QLabel *label_ntc1;
    QLabel *label_ntc1Val;
    QLabel *label_ntc1UM;
    QLabel *label_iInv;
    QLabel *label_iInvVal;
    QLabel *label_iInvUM;
    QLabel *label_ntc2;
    QLabel *label_ntc2Val;
    QLabel *label_ntc2UM;
    QLabel *label_vInvRect;
    QLabel *label_vInvRectVal;
    QLabel *label_vInvRectUM;
    QLabel *label_pot;
    QLabel *label_potVal;
    QLabel *label_potUM;
    QLabel *label_iInvRect;
    QLabel *label_iInvRectVal;
    QLabel *label_iInvRectUM;
    QLabel *label_lineFreq;
    QLabel *label_lineFreqVal;
    QLabel *label_lineFreqUM;
    QLabel *label_apScr;
    QLabel *label_apScrVal;
    QLabel *label_apScrUM;
    QLabel *label_timer0Cnt;
    QLabel *label_timer0CntVal;
    QLabel *label_freqIgbt;
    QLabel *label_freqIgbtVal;
    QLabel *label_freqIgbtUM;
    QLabel *label_freqInvalidCnt;
    QLabel *label_freqInvalidCntVal;
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
    QGroupBox *groupBox_parametriInverter;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_scr;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_aperturaMan;
    QLabel *label_valApertura;
    QDoubleSpinBox *doubleSpinBox_valApertura;
    QLabel *label_valAperturaUM;
    QLabel *label_valAperturaRidotta50;
    QLabel *label_p1;
    QDoubleSpinBox *doubleSpinBox_valAperturaRidotta50;
    QLabel *label_valAperturaRidotta50UM;
    QLabel *label_valAperturaRidotta60;
    QLabel *label_p2;
    QDoubleSpinBox *doubleSpinBox_valAperturaRidotta60;
    QLabel *label_valAperturaRidotta60UM;
    QLabel *label_durataApRidottaCheck;
    QLabel *label_p3;
    QDoubleSpinBox *doubleSpinBox_durataApRidottaCheck;
    QLabel *label_durataApRidottaCheckUM;
    QLabel *label_velRampa;
    QLabel *label_p4;
    QDoubleSpinBox *doubleSpinBox_velRampa;
    QLabel *label_ImpulsiSpenti_velRampaUM;
    QLabel *label_valAperturaFinale;
    QLabel *label_p5_3;
    QDoubleSpinBox *doubleSpinBox_valAperturaFinale;
    QLabel *label_valAperturaFinaleUM;
    QGroupBox *groupBox_adc;
    QGridLayout *gridLayout;
    QLabel *label_p7_6;
    QDoubleSpinBox *doubleSpinBox_ntc2Offset;
    QLabel *label_potGainUM;
    QDoubleSpinBox *doubleSpinBox_iInvRectOffset;
    QLabel *label_ntc2OffsetUM;
    QLabel *label_potOffset;
    QDoubleSpinBox *doubleSpinBox_potGain;
    QLabel *label_vInvRectGainUM;
    QLabel *label_ntc1OffsetUM;
    QLabel *label_ntc2GainUM;
    QLabel *label_p7_2;
    QDoubleSpinBox *doubleSpinBox_ntc2Gain;
    QLabel *label_iInvRectGainUM;
    QLabel *label_p6_2;
    QLabel *label_iInvRectGain;
    QLabel *label_ntc1GainUM;
    QDoubleSpinBox *doubleSpinBox_potOffset;
    QLabel *label_p7_5;
    QLabel *label_potOffsetUM;
    QDoubleSpinBox *doubleSpinBox_ntc1Offset;
    QLabel *label_vInvRectOffsetUM;
    QDoubleSpinBox *doubleSpinBox_vInvRectGain;
    QLabel *label_ntc2Offset;
    QLabel *label_iInvRectOffset;
    QLabel *label_ntc1Gain;
    QLabel *label_vInvRectOffset;
    QLabel *label_p7_8;
    QLabel *label_p7_3;
    QLabel *label_ntc1Offset;
    QLabel *label_p5_2;
    QLabel *label_vInvRectGain;
    QDoubleSpinBox *doubleSpinBox_iInvRectGain;
    QLabel *label_p7_9;
    QDoubleSpinBox *doubleSpinBox_ntc1Gain;
    QLabel *label_p7_4;
    QLabel *label_ntc2Gain;
    QLabel *label_potGain;
    QLabel *label_iInvRectOffsetUM;
    QDoubleSpinBox *doubleSpinBox_vInvRectOffset;
    QLabel *label_p7_7;
    QGroupBox *groupBox_protection;
    QGridLayout *gridLayout_4;
    QCheckBox *checkBox_enProtOvercurr;
    QLabel *label_valOverCurr;
    QDoubleSpinBox *doubleSpinBox_valOvercurr;
    QLabel *label_valOverCurrUM;
    QGroupBox *groupBox_miscellaneous;
    QGridLayout *gridLayout_5;
    QLabel *label_durataInit;
    QDoubleSpinBox *doubleSpinBox_durataInit;
    QLabel *label_durataInitUM;
    QLabel *label_durataFreqEst;
    QDoubleSpinBox *doubleSpinBox_durataFreqEst;
    QLabel *label_durataFreqEstUM;
    QGroupBox *groupBox_igbt;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_enSweep;
    QLabel *label_freqPrincipale;
    QLabel *label_p5;
    QDoubleSpinBox *doubleSpinBox_freqPrincipale;
    QLabel *label_freqPrincipaleUM;
    QLabel *label_ampModSweep;
    QLabel *label_p6;
    QDoubleSpinBox *doubleSpinBox_ampModSweep;
    QLabel *label_ampModSweep_2;
    QLabel *label_freqModSweep;
    QLabel *label_p7;
    QDoubleSpinBox *doubleSpinBox_freqModSweep;
    QLabel *label_freqModSweepUM;
    QGroupBox *groupBox_controlloInverter;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_ackFault;
    QPushButton *pushButton_start;
    QLabel *label_ImpulsiSpenti;
    QLabel *label_impulsiAttivi;
    QVBoxLayout *verticalLayout_2;
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
        MainWindow->resize(1000, 974);
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
        groupBox_feedbackInverter = new QGroupBox(centralWidget);
        groupBox_feedbackInverter->setObjectName(QString::fromUtf8("groupBox_feedbackInverter"));
        groupBox_feedbackInverter->setFlat(false);
        gridLayout_6 = new QGridLayout(groupBox_feedbackInverter);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_vInv = new QLabel(groupBox_feedbackInverter);
        label_vInv->setObjectName(QString::fromUtf8("label_vInv"));
        label_vInv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_vInv, 0, 0, 1, 1);

        label_vInvVal = new QLabel(groupBox_feedbackInverter);
        label_vInvVal->setObjectName(QString::fromUtf8("label_vInvVal"));
        label_vInvVal->setFocusPolicy(Qt::NoFocus);
        label_vInvVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_vInvVal->setFrameShape(QFrame::Box);
        label_vInvVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_vInvVal, 0, 1, 1, 1);

        label_vInvUM = new QLabel(groupBox_feedbackInverter);
        label_vInvUM->setObjectName(QString::fromUtf8("label_vInvUM"));
        label_vInvUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_vInvUM, 0, 2, 1, 1);

        label_ntc1 = new QLabel(groupBox_feedbackInverter);
        label_ntc1->setObjectName(QString::fromUtf8("label_ntc1"));
        label_ntc1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_ntc1, 0, 3, 1, 1);

        label_ntc1Val = new QLabel(groupBox_feedbackInverter);
        label_ntc1Val->setObjectName(QString::fromUtf8("label_ntc1Val"));
        label_ntc1Val->setFocusPolicy(Qt::NoFocus);
        label_ntc1Val->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_ntc1Val->setFrameShape(QFrame::Box);
        label_ntc1Val->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_ntc1Val, 0, 4, 1, 2);

        label_ntc1UM = new QLabel(groupBox_feedbackInverter);
        label_ntc1UM->setObjectName(QString::fromUtf8("label_ntc1UM"));
        label_ntc1UM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_ntc1UM, 0, 6, 1, 1);

        label_iInv = new QLabel(groupBox_feedbackInverter);
        label_iInv->setObjectName(QString::fromUtf8("label_iInv"));
        label_iInv->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_iInv, 1, 0, 1, 1);

        label_iInvVal = new QLabel(groupBox_feedbackInverter);
        label_iInvVal->setObjectName(QString::fromUtf8("label_iInvVal"));
        label_iInvVal->setFocusPolicy(Qt::NoFocus);
        label_iInvVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_iInvVal->setFrameShape(QFrame::Box);
        label_iInvVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_iInvVal, 1, 1, 1, 1);

        label_iInvUM = new QLabel(groupBox_feedbackInverter);
        label_iInvUM->setObjectName(QString::fromUtf8("label_iInvUM"));
        label_iInvUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_iInvUM, 1, 2, 1, 1);

        label_ntc2 = new QLabel(groupBox_feedbackInverter);
        label_ntc2->setObjectName(QString::fromUtf8("label_ntc2"));
        label_ntc2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_ntc2, 1, 3, 1, 1);

        label_ntc2Val = new QLabel(groupBox_feedbackInverter);
        label_ntc2Val->setObjectName(QString::fromUtf8("label_ntc2Val"));
        label_ntc2Val->setFocusPolicy(Qt::NoFocus);
        label_ntc2Val->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_ntc2Val->setFrameShape(QFrame::Box);
        label_ntc2Val->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_ntc2Val, 1, 4, 1, 2);

        label_ntc2UM = new QLabel(groupBox_feedbackInverter);
        label_ntc2UM->setObjectName(QString::fromUtf8("label_ntc2UM"));
        label_ntc2UM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_ntc2UM, 1, 6, 1, 1);

        label_vInvRect = new QLabel(groupBox_feedbackInverter);
        label_vInvRect->setObjectName(QString::fromUtf8("label_vInvRect"));
        label_vInvRect->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_vInvRect, 2, 0, 1, 1);

        label_vInvRectVal = new QLabel(groupBox_feedbackInverter);
        label_vInvRectVal->setObjectName(QString::fromUtf8("label_vInvRectVal"));
        label_vInvRectVal->setFocusPolicy(Qt::NoFocus);
        label_vInvRectVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_vInvRectVal->setFrameShape(QFrame::Box);
        label_vInvRectVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_vInvRectVal, 2, 1, 1, 1);

        label_vInvRectUM = new QLabel(groupBox_feedbackInverter);
        label_vInvRectUM->setObjectName(QString::fromUtf8("label_vInvRectUM"));
        label_vInvRectUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_vInvRectUM, 2, 2, 1, 1);

        label_pot = new QLabel(groupBox_feedbackInverter);
        label_pot->setObjectName(QString::fromUtf8("label_pot"));
        label_pot->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_pot, 2, 3, 1, 1);

        label_potVal = new QLabel(groupBox_feedbackInverter);
        label_potVal->setObjectName(QString::fromUtf8("label_potVal"));
        label_potVal->setFocusPolicy(Qt::NoFocus);
        label_potVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_potVal->setFrameShape(QFrame::Box);
        label_potVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_potVal, 2, 4, 1, 2);

        label_potUM = new QLabel(groupBox_feedbackInverter);
        label_potUM->setObjectName(QString::fromUtf8("label_potUM"));
        label_potUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_potUM, 2, 6, 1, 1);

        label_iInvRect = new QLabel(groupBox_feedbackInverter);
        label_iInvRect->setObjectName(QString::fromUtf8("label_iInvRect"));
        label_iInvRect->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_iInvRect, 3, 0, 1, 1);

        label_iInvRectVal = new QLabel(groupBox_feedbackInverter);
        label_iInvRectVal->setObjectName(QString::fromUtf8("label_iInvRectVal"));
        label_iInvRectVal->setFocusPolicy(Qt::NoFocus);
        label_iInvRectVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_iInvRectVal->setFrameShape(QFrame::Box);
        label_iInvRectVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_iInvRectVal, 3, 1, 1, 1);

        label_iInvRectUM = new QLabel(groupBox_feedbackInverter);
        label_iInvRectUM->setObjectName(QString::fromUtf8("label_iInvRectUM"));
        label_iInvRectUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_iInvRectUM, 3, 2, 1, 1);

        label_lineFreq = new QLabel(groupBox_feedbackInverter);
        label_lineFreq->setObjectName(QString::fromUtf8("label_lineFreq"));
        label_lineFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_lineFreq, 3, 3, 1, 1);

        label_lineFreqVal = new QLabel(groupBox_feedbackInverter);
        label_lineFreqVal->setObjectName(QString::fromUtf8("label_lineFreqVal"));
        label_lineFreqVal->setFocusPolicy(Qt::NoFocus);
        label_lineFreqVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_lineFreqVal->setFrameShape(QFrame::Box);
        label_lineFreqVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_lineFreqVal, 3, 4, 1, 2);

        label_lineFreqUM = new QLabel(groupBox_feedbackInverter);
        label_lineFreqUM->setObjectName(QString::fromUtf8("label_lineFreqUM"));
        label_lineFreqUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_lineFreqUM, 3, 6, 1, 1);

        label_apScr = new QLabel(groupBox_feedbackInverter);
        label_apScr->setObjectName(QString::fromUtf8("label_apScr"));
        label_apScr->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_apScr, 4, 0, 1, 1);

        label_apScrVal = new QLabel(groupBox_feedbackInverter);
        label_apScrVal->setObjectName(QString::fromUtf8("label_apScrVal"));
        label_apScrVal->setFocusPolicy(Qt::NoFocus);
        label_apScrVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_apScrVal->setFrameShape(QFrame::Box);
        label_apScrVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_apScrVal, 4, 1, 1, 1);

        label_apScrUM = new QLabel(groupBox_feedbackInverter);
        label_apScrUM->setObjectName(QString::fromUtf8("label_apScrUM"));
        label_apScrUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_apScrUM, 4, 2, 1, 1);

        label_timer0Cnt = new QLabel(groupBox_feedbackInverter);
        label_timer0Cnt->setObjectName(QString::fromUtf8("label_timer0Cnt"));
        label_timer0Cnt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_timer0Cnt, 4, 3, 1, 2);

        label_timer0CntVal = new QLabel(groupBox_feedbackInverter);
        label_timer0CntVal->setObjectName(QString::fromUtf8("label_timer0CntVal"));
        label_timer0CntVal->setFocusPolicy(Qt::NoFocus);
        label_timer0CntVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_timer0CntVal->setFrameShape(QFrame::Box);
        label_timer0CntVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_timer0CntVal, 4, 5, 1, 2);

        label_freqIgbt = new QLabel(groupBox_feedbackInverter);
        label_freqIgbt->setObjectName(QString::fromUtf8("label_freqIgbt"));
        label_freqIgbt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_freqIgbt, 5, 0, 1, 1);

        label_freqIgbtVal = new QLabel(groupBox_feedbackInverter);
        label_freqIgbtVal->setObjectName(QString::fromUtf8("label_freqIgbtVal"));
        label_freqIgbtVal->setFocusPolicy(Qt::NoFocus);
        label_freqIgbtVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_freqIgbtVal->setFrameShape(QFrame::Box);
        label_freqIgbtVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_freqIgbtVal, 5, 1, 1, 1);

        label_freqIgbtUM = new QLabel(groupBox_feedbackInverter);
        label_freqIgbtUM->setObjectName(QString::fromUtf8("label_freqIgbtUM"));
        label_freqIgbtUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_freqIgbtUM, 5, 2, 1, 1);

        label_freqInvalidCnt = new QLabel(groupBox_feedbackInverter);
        label_freqInvalidCnt->setObjectName(QString::fromUtf8("label_freqInvalidCnt"));
        label_freqInvalidCnt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_freqInvalidCnt, 5, 3, 1, 2);

        label_freqInvalidCntVal = new QLabel(groupBox_feedbackInverter);
        label_freqInvalidCntVal->setObjectName(QString::fromUtf8("label_freqInvalidCntVal"));
        label_freqInvalidCntVal->setFocusPolicy(Qt::NoFocus);
        label_freqInvalidCntVal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_freqInvalidCntVal->setFrameShape(QFrame::Box);
        label_freqInvalidCntVal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_freqInvalidCntVal, 5, 5, 1, 2);


        gridLayout_9->addWidget(groupBox_feedbackInverter, 0, 2, 1, 1);

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

        gridLayout_9->addWidget(groupBox_statoInverter, 0, 1, 1, 1);

        groupBox_parametriInverter = new QGroupBox(centralWidget);
        groupBox_parametriInverter->setObjectName(QString::fromUtf8("groupBox_parametriInverter"));
        groupBox_parametriInverter->setFlat(false);
        gridLayout_8 = new QGridLayout(groupBox_parametriInverter);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        groupBox_scr = new QGroupBox(groupBox_parametriInverter);
        groupBox_scr->setObjectName(QString::fromUtf8("groupBox_scr"));
        groupBox_scr->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBox_scr);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox_aperturaMan = new QCheckBox(groupBox_scr);
        checkBox_aperturaMan->setObjectName(QString::fromUtf8("checkBox_aperturaMan"));
        checkBox_aperturaMan->setContextMenuPolicy(Qt::NoContextMenu);
        checkBox_aperturaMan->setLayoutDirection(Qt::RightToLeft);
        checkBox_aperturaMan->setCheckable(true);

        gridLayout_2->addWidget(checkBox_aperturaMan, 0, 0, 1, 1);

        label_valApertura = new QLabel(groupBox_scr);
        label_valApertura->setObjectName(QString::fromUtf8("label_valApertura"));
        label_valApertura->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valApertura, 0, 1, 1, 2);

        doubleSpinBox_valApertura = new QDoubleSpinBox(groupBox_scr);
        doubleSpinBox_valApertura->setObjectName(QString::fromUtf8("doubleSpinBox_valApertura"));
        doubleSpinBox_valApertura->setWrapping(false);
        doubleSpinBox_valApertura->setFrame(true);
        doubleSpinBox_valApertura->setMaximum(99.000000000000000);
        doubleSpinBox_valApertura->setSingleStep(0.010000000000000);

        gridLayout_2->addWidget(doubleSpinBox_valApertura, 0, 3, 1, 1);

        label_valAperturaUM = new QLabel(groupBox_scr);
        label_valAperturaUM->setObjectName(QString::fromUtf8("label_valAperturaUM"));
        label_valAperturaUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaUM, 0, 4, 1, 1);

        label_valAperturaRidotta50 = new QLabel(groupBox_scr);
        label_valAperturaRidotta50->setObjectName(QString::fromUtf8("label_valAperturaRidotta50"));
        label_valAperturaRidotta50->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaRidotta50, 1, 0, 1, 2);

        label_p1 = new QLabel(groupBox_scr);
        label_p1->setObjectName(QString::fromUtf8("label_p1"));
        label_p1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_p1, 1, 2, 1, 1);

        doubleSpinBox_valAperturaRidotta50 = new QDoubleSpinBox(groupBox_scr);
        doubleSpinBox_valAperturaRidotta50->setObjectName(QString::fromUtf8("doubleSpinBox_valAperturaRidotta50"));
        doubleSpinBox_valAperturaRidotta50->setWrapping(false);
        doubleSpinBox_valAperturaRidotta50->setFrame(true);

        gridLayout_2->addWidget(doubleSpinBox_valAperturaRidotta50, 1, 3, 1, 1);

        label_valAperturaRidotta50UM = new QLabel(groupBox_scr);
        label_valAperturaRidotta50UM->setObjectName(QString::fromUtf8("label_valAperturaRidotta50UM"));
        label_valAperturaRidotta50UM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaRidotta50UM, 1, 4, 1, 1);

        label_valAperturaRidotta60 = new QLabel(groupBox_scr);
        label_valAperturaRidotta60->setObjectName(QString::fromUtf8("label_valAperturaRidotta60"));
        label_valAperturaRidotta60->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaRidotta60, 2, 0, 1, 2);

        label_p2 = new QLabel(groupBox_scr);
        label_p2->setObjectName(QString::fromUtf8("label_p2"));
        label_p2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_p2, 2, 2, 1, 1);

        doubleSpinBox_valAperturaRidotta60 = new QDoubleSpinBox(groupBox_scr);
        doubleSpinBox_valAperturaRidotta60->setObjectName(QString::fromUtf8("doubleSpinBox_valAperturaRidotta60"));
        doubleSpinBox_valAperturaRidotta60->setWrapping(false);
        doubleSpinBox_valAperturaRidotta60->setFrame(true);

        gridLayout_2->addWidget(doubleSpinBox_valAperturaRidotta60, 2, 3, 1, 1);

        label_valAperturaRidotta60UM = new QLabel(groupBox_scr);
        label_valAperturaRidotta60UM->setObjectName(QString::fromUtf8("label_valAperturaRidotta60UM"));
        label_valAperturaRidotta60UM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaRidotta60UM, 2, 4, 1, 1);

        label_durataApRidottaCheck = new QLabel(groupBox_scr);
        label_durataApRidottaCheck->setObjectName(QString::fromUtf8("label_durataApRidottaCheck"));
        label_durataApRidottaCheck->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_durataApRidottaCheck, 3, 0, 1, 2);

        label_p3 = new QLabel(groupBox_scr);
        label_p3->setObjectName(QString::fromUtf8("label_p3"));
        label_p3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_p3, 3, 2, 1, 1);

        doubleSpinBox_durataApRidottaCheck = new QDoubleSpinBox(groupBox_scr);
        doubleSpinBox_durataApRidottaCheck->setObjectName(QString::fromUtf8("doubleSpinBox_durataApRidottaCheck"));
        doubleSpinBox_durataApRidottaCheck->setWrapping(false);
        doubleSpinBox_durataApRidottaCheck->setFrame(true);
        doubleSpinBox_durataApRidottaCheck->setDecimals(0);
        doubleSpinBox_durataApRidottaCheck->setMaximum(20000.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_durataApRidottaCheck, 3, 3, 1, 1);

        label_durataApRidottaCheckUM = new QLabel(groupBox_scr);
        label_durataApRidottaCheckUM->setObjectName(QString::fromUtf8("label_durataApRidottaCheckUM"));
        label_durataApRidottaCheckUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_durataApRidottaCheckUM, 3, 4, 1, 1);

        label_velRampa = new QLabel(groupBox_scr);
        label_velRampa->setObjectName(QString::fromUtf8("label_velRampa"));
        label_velRampa->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_velRampa, 4, 0, 1, 2);

        label_p4 = new QLabel(groupBox_scr);
        label_p4->setObjectName(QString::fromUtf8("label_p4"));
        label_p4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_p4, 4, 2, 1, 1);

        doubleSpinBox_velRampa = new QDoubleSpinBox(groupBox_scr);
        doubleSpinBox_velRampa->setObjectName(QString::fromUtf8("doubleSpinBox_velRampa"));
        doubleSpinBox_velRampa->setWrapping(false);
        doubleSpinBox_velRampa->setFrame(true);
        doubleSpinBox_velRampa->setDecimals(2);

        gridLayout_2->addWidget(doubleSpinBox_velRampa, 4, 3, 1, 1);

        label_ImpulsiSpenti_velRampaUM = new QLabel(groupBox_scr);
        label_ImpulsiSpenti_velRampaUM->setObjectName(QString::fromUtf8("label_ImpulsiSpenti_velRampaUM"));
        label_ImpulsiSpenti_velRampaUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_ImpulsiSpenti_velRampaUM, 4, 4, 1, 1);

        label_valAperturaFinale = new QLabel(groupBox_scr);
        label_valAperturaFinale->setObjectName(QString::fromUtf8("label_valAperturaFinale"));
        label_valAperturaFinale->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaFinale, 5, 0, 1, 2);

        label_p5_3 = new QLabel(groupBox_scr);
        label_p5_3->setObjectName(QString::fromUtf8("label_p5_3"));
        label_p5_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_p5_3, 5, 2, 1, 1);

        doubleSpinBox_valAperturaFinale = new QDoubleSpinBox(groupBox_scr);
        doubleSpinBox_valAperturaFinale->setObjectName(QString::fromUtf8("doubleSpinBox_valAperturaFinale"));
        doubleSpinBox_valAperturaFinale->setWrapping(false);
        doubleSpinBox_valAperturaFinale->setFrame(true);
        doubleSpinBox_valAperturaFinale->setDecimals(3);
        doubleSpinBox_valAperturaFinale->setMaximum(1.000000000000000);
        doubleSpinBox_valAperturaFinale->setSingleStep(0.010000000000000);

        gridLayout_2->addWidget(doubleSpinBox_valAperturaFinale, 5, 3, 1, 1);

        label_valAperturaFinaleUM = new QLabel(groupBox_scr);
        label_valAperturaFinaleUM->setObjectName(QString::fromUtf8("label_valAperturaFinaleUM"));
        label_valAperturaFinaleUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_valAperturaFinaleUM, 5, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_scr, 0, 0, 2, 1);

        groupBox_adc = new QGroupBox(groupBox_parametriInverter);
        groupBox_adc->setObjectName(QString::fromUtf8("groupBox_adc"));
        groupBox_adc->setFlat(false);
        gridLayout = new QGridLayout(groupBox_adc);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_p7_6 = new QLabel(groupBox_adc);
        label_p7_6->setObjectName(QString::fromUtf8("label_p7_6"));
        label_p7_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_6, 6, 1, 1, 1);

        doubleSpinBox_ntc2Offset = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_ntc2Offset->setObjectName(QString::fromUtf8("doubleSpinBox_ntc2Offset"));
        doubleSpinBox_ntc2Offset->setWrapping(false);
        doubleSpinBox_ntc2Offset->setFrame(true);
        doubleSpinBox_ntc2Offset->setDecimals(0);
        doubleSpinBox_ntc2Offset->setMinimum(-4095.000000000000000);
        doubleSpinBox_ntc2Offset->setMaximum(4095.000000000000000);
        doubleSpinBox_ntc2Offset->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_ntc2Offset, 7, 2, 1, 1);

        label_potGainUM = new QLabel(groupBox_adc);
        label_potGainUM->setObjectName(QString::fromUtf8("label_potGainUM"));
        label_potGainUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_potGainUM, 8, 3, 1, 1);

        doubleSpinBox_iInvRectOffset = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_iInvRectOffset->setObjectName(QString::fromUtf8("doubleSpinBox_iInvRectOffset"));
        doubleSpinBox_iInvRectOffset->setWrapping(false);
        doubleSpinBox_iInvRectOffset->setFrame(true);
        doubleSpinBox_iInvRectOffset->setDecimals(0);
        doubleSpinBox_iInvRectOffset->setMinimum(-4095.000000000000000);
        doubleSpinBox_iInvRectOffset->setMaximum(4095.000000000000000);
        doubleSpinBox_iInvRectOffset->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_iInvRectOffset, 3, 2, 1, 1);

        label_ntc2OffsetUM = new QLabel(groupBox_adc);
        label_ntc2OffsetUM->setObjectName(QString::fromUtf8("label_ntc2OffsetUM"));
        label_ntc2OffsetUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc2OffsetUM, 7, 3, 1, 1);

        label_potOffset = new QLabel(groupBox_adc);
        label_potOffset->setObjectName(QString::fromUtf8("label_potOffset"));
        label_potOffset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_potOffset, 9, 0, 1, 1);

        doubleSpinBox_potGain = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_potGain->setObjectName(QString::fromUtf8("doubleSpinBox_potGain"));
        doubleSpinBox_potGain->setWrapping(false);
        doubleSpinBox_potGain->setFrame(true);
        doubleSpinBox_potGain->setDecimals(5);
        doubleSpinBox_potGain->setSingleStep(0.001000000000000);

        gridLayout->addWidget(doubleSpinBox_potGain, 8, 2, 1, 1);

        label_vInvRectGainUM = new QLabel(groupBox_adc);
        label_vInvRectGainUM->setObjectName(QString::fromUtf8("label_vInvRectGainUM"));
        label_vInvRectGainUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_vInvRectGainUM, 0, 3, 1, 1);

        label_ntc1OffsetUM = new QLabel(groupBox_adc);
        label_ntc1OffsetUM->setObjectName(QString::fromUtf8("label_ntc1OffsetUM"));
        label_ntc1OffsetUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc1OffsetUM, 5, 3, 1, 1);

        label_ntc2GainUM = new QLabel(groupBox_adc);
        label_ntc2GainUM->setObjectName(QString::fromUtf8("label_ntc2GainUM"));
        label_ntc2GainUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc2GainUM, 6, 3, 1, 1);

        label_p7_2 = new QLabel(groupBox_adc);
        label_p7_2->setObjectName(QString::fromUtf8("label_p7_2"));
        label_p7_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_2, 2, 1, 1, 1);

        doubleSpinBox_ntc2Gain = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_ntc2Gain->setObjectName(QString::fromUtf8("doubleSpinBox_ntc2Gain"));
        doubleSpinBox_ntc2Gain->setWrapping(false);
        doubleSpinBox_ntc2Gain->setFrame(true);
        doubleSpinBox_ntc2Gain->setDecimals(5);
        doubleSpinBox_ntc2Gain->setSingleStep(0.001000000000000);

        gridLayout->addWidget(doubleSpinBox_ntc2Gain, 6, 2, 1, 1);

        label_iInvRectGainUM = new QLabel(groupBox_adc);
        label_iInvRectGainUM->setObjectName(QString::fromUtf8("label_iInvRectGainUM"));
        label_iInvRectGainUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_iInvRectGainUM, 2, 3, 1, 1);

        label_p6_2 = new QLabel(groupBox_adc);
        label_p6_2->setObjectName(QString::fromUtf8("label_p6_2"));
        label_p6_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p6_2, 1, 1, 1, 1);

        label_iInvRectGain = new QLabel(groupBox_adc);
        label_iInvRectGain->setObjectName(QString::fromUtf8("label_iInvRectGain"));
        label_iInvRectGain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_iInvRectGain, 2, 0, 1, 1);

        label_ntc1GainUM = new QLabel(groupBox_adc);
        label_ntc1GainUM->setObjectName(QString::fromUtf8("label_ntc1GainUM"));
        label_ntc1GainUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc1GainUM, 4, 3, 1, 1);

        doubleSpinBox_potOffset = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_potOffset->setObjectName(QString::fromUtf8("doubleSpinBox_potOffset"));
        doubleSpinBox_potOffset->setWrapping(false);
        doubleSpinBox_potOffset->setFrame(true);
        doubleSpinBox_potOffset->setDecimals(0);
        doubleSpinBox_potOffset->setMinimum(-4095.000000000000000);
        doubleSpinBox_potOffset->setMaximum(4095.000000000000000);
        doubleSpinBox_potOffset->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_potOffset, 9, 2, 1, 1);

        label_p7_5 = new QLabel(groupBox_adc);
        label_p7_5->setObjectName(QString::fromUtf8("label_p7_5"));
        label_p7_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_5, 5, 1, 1, 1);

        label_potOffsetUM = new QLabel(groupBox_adc);
        label_potOffsetUM->setObjectName(QString::fromUtf8("label_potOffsetUM"));
        label_potOffsetUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_potOffsetUM, 9, 3, 1, 1);

        doubleSpinBox_ntc1Offset = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_ntc1Offset->setObjectName(QString::fromUtf8("doubleSpinBox_ntc1Offset"));
        doubleSpinBox_ntc1Offset->setWrapping(false);
        doubleSpinBox_ntc1Offset->setFrame(true);
        doubleSpinBox_ntc1Offset->setDecimals(0);
        doubleSpinBox_ntc1Offset->setMinimum(-4095.000000000000000);
        doubleSpinBox_ntc1Offset->setMaximum(4095.000000000000000);
        doubleSpinBox_ntc1Offset->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_ntc1Offset, 5, 2, 1, 1);

        label_vInvRectOffsetUM = new QLabel(groupBox_adc);
        label_vInvRectOffsetUM->setObjectName(QString::fromUtf8("label_vInvRectOffsetUM"));
        label_vInvRectOffsetUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_vInvRectOffsetUM, 1, 3, 1, 1);

        doubleSpinBox_vInvRectGain = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_vInvRectGain->setObjectName(QString::fromUtf8("doubleSpinBox_vInvRectGain"));
        doubleSpinBox_vInvRectGain->setWrapping(false);
        doubleSpinBox_vInvRectGain->setFrame(true);
        doubleSpinBox_vInvRectGain->setDecimals(5);
        doubleSpinBox_vInvRectGain->setSingleStep(0.001000000000000);

        gridLayout->addWidget(doubleSpinBox_vInvRectGain, 0, 2, 1, 1);

        label_ntc2Offset = new QLabel(groupBox_adc);
        label_ntc2Offset->setObjectName(QString::fromUtf8("label_ntc2Offset"));
        label_ntc2Offset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc2Offset, 7, 0, 1, 1);

        label_iInvRectOffset = new QLabel(groupBox_adc);
        label_iInvRectOffset->setObjectName(QString::fromUtf8("label_iInvRectOffset"));
        label_iInvRectOffset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_iInvRectOffset, 3, 0, 1, 1);

        label_ntc1Gain = new QLabel(groupBox_adc);
        label_ntc1Gain->setObjectName(QString::fromUtf8("label_ntc1Gain"));
        label_ntc1Gain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc1Gain, 4, 0, 1, 1);

        label_vInvRectOffset = new QLabel(groupBox_adc);
        label_vInvRectOffset->setObjectName(QString::fromUtf8("label_vInvRectOffset"));
        label_vInvRectOffset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_vInvRectOffset, 1, 0, 1, 1);

        label_p7_8 = new QLabel(groupBox_adc);
        label_p7_8->setObjectName(QString::fromUtf8("label_p7_8"));
        label_p7_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_8, 8, 1, 1, 1);

        label_p7_3 = new QLabel(groupBox_adc);
        label_p7_3->setObjectName(QString::fromUtf8("label_p7_3"));
        label_p7_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_3, 3, 1, 1, 1);

        label_ntc1Offset = new QLabel(groupBox_adc);
        label_ntc1Offset->setObjectName(QString::fromUtf8("label_ntc1Offset"));
        label_ntc1Offset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc1Offset, 5, 0, 1, 1);

        label_p5_2 = new QLabel(groupBox_adc);
        label_p5_2->setObjectName(QString::fromUtf8("label_p5_2"));
        label_p5_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p5_2, 0, 1, 1, 1);

        label_vInvRectGain = new QLabel(groupBox_adc);
        label_vInvRectGain->setObjectName(QString::fromUtf8("label_vInvRectGain"));
        label_vInvRectGain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_vInvRectGain, 0, 0, 1, 1);

        doubleSpinBox_iInvRectGain = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_iInvRectGain->setObjectName(QString::fromUtf8("doubleSpinBox_iInvRectGain"));
        doubleSpinBox_iInvRectGain->setWrapping(false);
        doubleSpinBox_iInvRectGain->setFrame(true);
        doubleSpinBox_iInvRectGain->setDecimals(5);
        doubleSpinBox_iInvRectGain->setSingleStep(0.001000000000000);

        gridLayout->addWidget(doubleSpinBox_iInvRectGain, 2, 2, 1, 1);

        label_p7_9 = new QLabel(groupBox_adc);
        label_p7_9->setObjectName(QString::fromUtf8("label_p7_9"));
        label_p7_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_9, 9, 1, 1, 1);

        doubleSpinBox_ntc1Gain = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_ntc1Gain->setObjectName(QString::fromUtf8("doubleSpinBox_ntc1Gain"));
        doubleSpinBox_ntc1Gain->setWrapping(false);
        doubleSpinBox_ntc1Gain->setFrame(true);
        doubleSpinBox_ntc1Gain->setDecimals(5);
        doubleSpinBox_ntc1Gain->setSingleStep(0.001000000000000);

        gridLayout->addWidget(doubleSpinBox_ntc1Gain, 4, 2, 1, 1);

        label_p7_4 = new QLabel(groupBox_adc);
        label_p7_4->setObjectName(QString::fromUtf8("label_p7_4"));
        label_p7_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_4, 4, 1, 1, 1);

        label_ntc2Gain = new QLabel(groupBox_adc);
        label_ntc2Gain->setObjectName(QString::fromUtf8("label_ntc2Gain"));
        label_ntc2Gain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_ntc2Gain, 6, 0, 1, 1);

        label_potGain = new QLabel(groupBox_adc);
        label_potGain->setObjectName(QString::fromUtf8("label_potGain"));
        label_potGain->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_potGain, 8, 0, 1, 1);

        label_iInvRectOffsetUM = new QLabel(groupBox_adc);
        label_iInvRectOffsetUM->setObjectName(QString::fromUtf8("label_iInvRectOffsetUM"));
        label_iInvRectOffsetUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_iInvRectOffsetUM, 3, 3, 1, 1);

        doubleSpinBox_vInvRectOffset = new QDoubleSpinBox(groupBox_adc);
        doubleSpinBox_vInvRectOffset->setObjectName(QString::fromUtf8("doubleSpinBox_vInvRectOffset"));
        doubleSpinBox_vInvRectOffset->setWrapping(false);
        doubleSpinBox_vInvRectOffset->setFrame(true);
        doubleSpinBox_vInvRectOffset->setDecimals(0);
        doubleSpinBox_vInvRectOffset->setMinimum(-4095.000000000000000);
        doubleSpinBox_vInvRectOffset->setMaximum(4095.000000000000000);
        doubleSpinBox_vInvRectOffset->setSingleStep(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_vInvRectOffset, 1, 2, 1, 1);

        label_p7_7 = new QLabel(groupBox_adc);
        label_p7_7->setObjectName(QString::fromUtf8("label_p7_7"));
        label_p7_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_p7_7, 7, 1, 1, 1);


        gridLayout_8->addWidget(groupBox_adc, 0, 1, 3, 1);

        groupBox_protection = new QGroupBox(groupBox_parametriInverter);
        groupBox_protection->setObjectName(QString::fromUtf8("groupBox_protection"));
        groupBox_protection->setFlat(false);
        gridLayout_4 = new QGridLayout(groupBox_protection);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkBox_enProtOvercurr = new QCheckBox(groupBox_protection);
        checkBox_enProtOvercurr->setObjectName(QString::fromUtf8("checkBox_enProtOvercurr"));
        checkBox_enProtOvercurr->setContextMenuPolicy(Qt::NoContextMenu);
        checkBox_enProtOvercurr->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(checkBox_enProtOvercurr, 0, 0, 1, 2);

        label_valOverCurr = new QLabel(groupBox_protection);
        label_valOverCurr->setObjectName(QString::fromUtf8("label_valOverCurr"));
        label_valOverCurr->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_valOverCurr, 1, 0, 1, 1);

        doubleSpinBox_valOvercurr = new QDoubleSpinBox(groupBox_protection);
        doubleSpinBox_valOvercurr->setObjectName(QString::fromUtf8("doubleSpinBox_valOvercurr"));
        doubleSpinBox_valOvercurr->setWrapping(false);
        doubleSpinBox_valOvercurr->setFrame(true);
        doubleSpinBox_valOvercurr->setMaximum(1.000000000000000);
        doubleSpinBox_valOvercurr->setSingleStep(0.010000000000000);

        gridLayout_4->addWidget(doubleSpinBox_valOvercurr, 1, 1, 1, 1);

        label_valOverCurrUM = new QLabel(groupBox_protection);
        label_valOverCurrUM->setObjectName(QString::fromUtf8("label_valOverCurrUM"));
        label_valOverCurrUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_valOverCurrUM, 1, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_protection, 0, 2, 1, 1);

        groupBox_miscellaneous = new QGroupBox(groupBox_parametriInverter);
        groupBox_miscellaneous->setObjectName(QString::fromUtf8("groupBox_miscellaneous"));
        groupBox_miscellaneous->setFlat(false);
        gridLayout_5 = new QGridLayout(groupBox_miscellaneous);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_durataInit = new QLabel(groupBox_miscellaneous);
        label_durataInit->setObjectName(QString::fromUtf8("label_durataInit"));
        label_durataInit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_durataInit, 0, 0, 1, 1);

        doubleSpinBox_durataInit = new QDoubleSpinBox(groupBox_miscellaneous);
        doubleSpinBox_durataInit->setObjectName(QString::fromUtf8("doubleSpinBox_durataInit"));
        doubleSpinBox_durataInit->setWrapping(false);
        doubleSpinBox_durataInit->setFrame(true);
        doubleSpinBox_durataInit->setDecimals(0);
        doubleSpinBox_durataInit->setMaximum(20000.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_durataInit, 0, 1, 1, 1);

        label_durataInitUM = new QLabel(groupBox_miscellaneous);
        label_durataInitUM->setObjectName(QString::fromUtf8("label_durataInitUM"));
        label_durataInitUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_durataInitUM, 0, 2, 1, 1);

        label_durataFreqEst = new QLabel(groupBox_miscellaneous);
        label_durataFreqEst->setObjectName(QString::fromUtf8("label_durataFreqEst"));
        label_durataFreqEst->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_durataFreqEst, 1, 0, 1, 1);

        doubleSpinBox_durataFreqEst = new QDoubleSpinBox(groupBox_miscellaneous);
        doubleSpinBox_durataFreqEst->setObjectName(QString::fromUtf8("doubleSpinBox_durataFreqEst"));
        doubleSpinBox_durataFreqEst->setWrapping(false);
        doubleSpinBox_durataFreqEst->setFrame(true);
        doubleSpinBox_durataFreqEst->setDecimals(0);
        doubleSpinBox_durataFreqEst->setMaximum(20000.000000000000000);

        gridLayout_5->addWidget(doubleSpinBox_durataFreqEst, 1, 1, 1, 1);

        label_durataFreqEstUM = new QLabel(groupBox_miscellaneous);
        label_durataFreqEstUM->setObjectName(QString::fromUtf8("label_durataFreqEstUM"));
        label_durataFreqEstUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_durataFreqEstUM, 1, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_miscellaneous, 1, 2, 1, 1);

        groupBox_igbt = new QGroupBox(groupBox_parametriInverter);
        groupBox_igbt->setObjectName(QString::fromUtf8("groupBox_igbt"));
        groupBox_igbt->setFlat(false);
        gridLayout_3 = new QGridLayout(groupBox_igbt);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBox_enSweep = new QCheckBox(groupBox_igbt);
        checkBox_enSweep->setObjectName(QString::fromUtf8("checkBox_enSweep"));
        checkBox_enSweep->setContextMenuPolicy(Qt::NoContextMenu);
        checkBox_enSweep->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(checkBox_enSweep, 0, 0, 1, 1);

        label_freqPrincipale = new QLabel(groupBox_igbt);
        label_freqPrincipale->setObjectName(QString::fromUtf8("label_freqPrincipale"));
        label_freqPrincipale->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_freqPrincipale, 1, 0, 1, 1);

        label_p5 = new QLabel(groupBox_igbt);
        label_p5->setObjectName(QString::fromUtf8("label_p5"));
        label_p5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_p5, 1, 1, 1, 1);

        doubleSpinBox_freqPrincipale = new QDoubleSpinBox(groupBox_igbt);
        doubleSpinBox_freqPrincipale->setObjectName(QString::fromUtf8("doubleSpinBox_freqPrincipale"));
        doubleSpinBox_freqPrincipale->setWrapping(false);
        doubleSpinBox_freqPrincipale->setFrame(true);
        doubleSpinBox_freqPrincipale->setDecimals(1);
        doubleSpinBox_freqPrincipale->setMaximum(30000.000000000000000);
        doubleSpinBox_freqPrincipale->setSingleStep(5.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_freqPrincipale, 1, 2, 1, 1);

        label_freqPrincipaleUM = new QLabel(groupBox_igbt);
        label_freqPrincipaleUM->setObjectName(QString::fromUtf8("label_freqPrincipaleUM"));
        label_freqPrincipaleUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_freqPrincipaleUM, 1, 3, 1, 1);

        label_ampModSweep = new QLabel(groupBox_igbt);
        label_ampModSweep->setObjectName(QString::fromUtf8("label_ampModSweep"));
        label_ampModSweep->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_ampModSweep, 2, 0, 1, 1);

        label_p6 = new QLabel(groupBox_igbt);
        label_p6->setObjectName(QString::fromUtf8("label_p6"));
        label_p6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_p6, 2, 1, 1, 1);

        doubleSpinBox_ampModSweep = new QDoubleSpinBox(groupBox_igbt);
        doubleSpinBox_ampModSweep->setObjectName(QString::fromUtf8("doubleSpinBox_ampModSweep"));
        doubleSpinBox_ampModSweep->setWrapping(false);
        doubleSpinBox_ampModSweep->setFrame(true);
        doubleSpinBox_ampModSweep->setMaximum(5000.000000000000000);
        doubleSpinBox_ampModSweep->setSingleStep(0.010000000000000);

        gridLayout_3->addWidget(doubleSpinBox_ampModSweep, 2, 2, 1, 1);

        label_ampModSweep_2 = new QLabel(groupBox_igbt);
        label_ampModSweep_2->setObjectName(QString::fromUtf8("label_ampModSweep_2"));
        label_ampModSweep_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_ampModSweep_2, 2, 3, 1, 1);

        label_freqModSweep = new QLabel(groupBox_igbt);
        label_freqModSweep->setObjectName(QString::fromUtf8("label_freqModSweep"));
        label_freqModSweep->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_freqModSweep, 3, 0, 1, 1);

        label_p7 = new QLabel(groupBox_igbt);
        label_p7->setObjectName(QString::fromUtf8("label_p7"));
        label_p7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_p7, 3, 1, 1, 1);

        doubleSpinBox_freqModSweep = new QDoubleSpinBox(groupBox_igbt);
        doubleSpinBox_freqModSweep->setObjectName(QString::fromUtf8("doubleSpinBox_freqModSweep"));
        doubleSpinBox_freqModSweep->setWrapping(false);
        doubleSpinBox_freqModSweep->setFrame(true);
        doubleSpinBox_freqModSweep->setSingleStep(0.010000000000000);

        gridLayout_3->addWidget(doubleSpinBox_freqModSweep, 3, 2, 1, 1);

        label_freqModSweepUM = new QLabel(groupBox_igbt);
        label_freqModSweepUM->setObjectName(QString::fromUtf8("label_freqModSweepUM"));
        label_freqModSweepUM->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_freqModSweepUM, 3, 3, 1, 1);


        gridLayout_8->addWidget(groupBox_igbt, 2, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_parametriInverter, 1, 0, 1, 3);

        groupBox_controlloInverter = new QGroupBox(centralWidget);
        groupBox_controlloInverter->setObjectName(QString::fromUtf8("groupBox_controlloInverter"));
        groupBox_controlloInverter->setFlat(false);
        gridLayout_7 = new QGridLayout(groupBox_controlloInverter);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pushButton_ackFault = new QPushButton(groupBox_controlloInverter);
        pushButton_ackFault->setObjectName(QString::fromUtf8("pushButton_ackFault"));
        pushButton_ackFault->setCheckable(false);

        gridLayout_7->addWidget(pushButton_ackFault, 0, 0, 1, 2);

        pushButton_start = new QPushButton(groupBox_controlloInverter);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setCheckable(true);

        gridLayout_7->addWidget(pushButton_start, 1, 0, 1, 2);

        label_ImpulsiSpenti = new QLabel(groupBox_controlloInverter);
        label_ImpulsiSpenti->setObjectName(QString::fromUtf8("label_ImpulsiSpenti"));
        label_ImpulsiSpenti->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_ImpulsiSpenti, 2, 0, 1, 1);

        label_impulsiAttivi = new QLabel(groupBox_controlloInverter);
        label_impulsiAttivi->setObjectName(QString::fromUtf8("label_impulsiAttivi"));
        label_impulsiAttivi->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_impulsiAttivi, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_controlloInverter, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        gridLayout_9->addLayout(verticalLayout_2, 2, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
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
        groupBox_feedbackInverter->setTitle(QCoreApplication::translate("MainWindow", "Feedback Inverter", nullptr));
        label_vInv->setText(QCoreApplication::translate("MainWindow", "V inv :", nullptr));
        label_vInvVal->setText(QString());
        label_vInvUM->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_ntc1->setText(QCoreApplication::translate("MainWindow", "Ntc 1 :", nullptr));
        label_ntc1Val->setText(QString());
        label_ntc1UM->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_iInv->setText(QCoreApplication::translate("MainWindow", "I inv :", nullptr));
        label_iInvVal->setText(QString());
        label_iInvUM->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_ntc2->setText(QCoreApplication::translate("MainWindow", "Ntc 2 :", nullptr));
        label_ntc2Val->setText(QString());
        label_ntc2UM->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_vInvRect->setText(QCoreApplication::translate("MainWindow", "V inv rect :", nullptr));
        label_vInvRectVal->setText(QString());
        label_vInvRectUM->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_pot->setText(QCoreApplication::translate("MainWindow", "Pot :", nullptr));
        label_potVal->setText(QString());
        label_potUM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        label_iInvRect->setText(QCoreApplication::translate("MainWindow", "I inv rect :", nullptr));
        label_iInvRectVal->setText(QString());
        label_iInvRectUM->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_lineFreq->setText(QCoreApplication::translate("MainWindow", "Line Freq. :", nullptr));
        label_lineFreqVal->setText(QString());
        label_lineFreqUM->setText(QCoreApplication::translate("MainWindow", "Hz", nullptr));
        label_apScr->setText(QCoreApplication::translate("MainWindow", "Ap SCR :", nullptr));
        label_apScrVal->setText(QString());
        label_apScrUM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        label_timer0Cnt->setText(QCoreApplication::translate("MainWindow", "Timer0 Cnt :", nullptr));
        label_timer0CntVal->setText(QString());
        label_freqIgbt->setText(QCoreApplication::translate("MainWindow", "Freq IGBT :", nullptr));
        label_freqIgbtVal->setText(QString());
        label_freqIgbtUM->setText(QCoreApplication::translate("MainWindow", "Hz", nullptr));
        label_freqInvalidCnt->setText(QCoreApplication::translate("MainWindow", "Freq. Invalida Cnt :", nullptr));
        label_freqInvalidCntVal->setText(QString());
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
        groupBox_parametriInverter->setTitle(QCoreApplication::translate("MainWindow", "Parametri Inverter", nullptr));
        groupBox_scr->setTitle(QCoreApplication::translate("MainWindow", "SCR", nullptr));
        checkBox_aperturaMan->setText(QCoreApplication::translate("MainWindow", "En Apertura Manuale :", nullptr));
        label_valApertura->setText(QCoreApplication::translate("MainWindow", "Valore Apertura :", nullptr));
        label_valAperturaUM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        label_valAperturaRidotta50->setText(QCoreApplication::translate("MainWindow", "Valore Apertura Ridotta per Check (50Hz)", nullptr));
        label_p1->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_valAperturaRidotta50UM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        label_valAperturaRidotta60->setText(QCoreApplication::translate("MainWindow", "Valore Apertura Ridotta per Check (60Hz)", nullptr));
        label_p2->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_valAperturaRidotta60UM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        label_durataApRidottaCheck->setText(QCoreApplication::translate("MainWindow", "Durata Apertura Ridotta per Check", nullptr));
        label_p3->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_durataApRidottaCheckUM->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_velRampa->setText(QCoreApplication::translate("MainWindow", "Velocit\303\240 Rampa", nullptr));
        label_p4->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_ImpulsiSpenti_velRampaUM->setText(QCoreApplication::translate("MainWindow", "pu/s", nullptr));
        label_valAperturaFinale->setText(QCoreApplication::translate("MainWindow", "Valore Finale Apertura", nullptr));
        label_p5_3->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_valAperturaFinaleUM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        groupBox_adc->setTitle(QCoreApplication::translate("MainWindow", "ADC", nullptr));
        label_p7_6->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_potGainUM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        label_ntc2OffsetUM->setText(QCoreApplication::translate("MainWindow", "s16", nullptr));
        label_potOffset->setText(QCoreApplication::translate("MainWindow", "Pot OFFSET", nullptr));
        label_vInvRectGainUM->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_ntc1OffsetUM->setText(QCoreApplication::translate("MainWindow", "s16", nullptr));
        label_ntc2GainUM->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_p7_2->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_iInvRectGainUM->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_p6_2->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_iInvRectGain->setText(QCoreApplication::translate("MainWindow", "I inv Rect GAIN", nullptr));
        label_ntc1GainUM->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_p7_5->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_potOffsetUM->setText(QCoreApplication::translate("MainWindow", "s16", nullptr));
        label_vInvRectOffsetUM->setText(QCoreApplication::translate("MainWindow", "s16", nullptr));
        label_ntc2Offset->setText(QCoreApplication::translate("MainWindow", "Ntc2 OFFSET", nullptr));
        label_iInvRectOffset->setText(QCoreApplication::translate("MainWindow", "I inv Rect OFFSET", nullptr));
        label_ntc1Gain->setText(QCoreApplication::translate("MainWindow", "Ntc1 GAIN", nullptr));
        label_vInvRectOffset->setText(QCoreApplication::translate("MainWindow", "V inv Rect OFFSET", nullptr));
        label_p7_8->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_p7_3->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_ntc1Offset->setText(QCoreApplication::translate("MainWindow", "Ntc1 OFFSET", nullptr));
        label_p5_2->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_vInvRectGain->setText(QCoreApplication::translate("MainWindow", "V inv Rect GAIN", nullptr));
        label_p7_9->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_p7_4->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_ntc2Gain->setText(QCoreApplication::translate("MainWindow", "Ntc2 GAIN", nullptr));
        label_potGain->setText(QCoreApplication::translate("MainWindow", "Pot GAIN", nullptr));
        label_iInvRectOffsetUM->setText(QCoreApplication::translate("MainWindow", "s16", nullptr));
        label_p7_7->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        groupBox_protection->setTitle(QCoreApplication::translate("MainWindow", "PROTECTION", nullptr));
        checkBox_enProtOvercurr->setText(QCoreApplication::translate("MainWindow", "En Protezione OverCurr :", nullptr));
        label_valOverCurr->setText(QCoreApplication::translate("MainWindow", "Valore Scatto OverCurr  :", nullptr));
        label_valOverCurrUM->setText(QCoreApplication::translate("MainWindow", "pu", nullptr));
        groupBox_miscellaneous->setTitle(QCoreApplication::translate("MainWindow", "MISCELLANEOUS", nullptr));
        label_durataInit->setText(QCoreApplication::translate("MainWindow", "Durata \"INIT\"", nullptr));
        label_durataInitUM->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_durataFreqEst->setText(QCoreApplication::translate("MainWindow", "Durata \"FREQ. ESTIM.\"", nullptr));
        label_durataFreqEstUM->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        groupBox_igbt->setTitle(QCoreApplication::translate("MainWindow", "IGBT", nullptr));
        checkBox_enSweep->setText(QCoreApplication::translate("MainWindow", "En Sweep :", nullptr));
        label_freqPrincipale->setText(QCoreApplication::translate("MainWindow", "Frequenza Principale", nullptr));
        label_p5->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_freqPrincipaleUM->setText(QCoreApplication::translate("MainWindow", "Hz", nullptr));
        label_ampModSweep->setText(QCoreApplication::translate("MainWindow", "Ampiezza Modulante Sweep", nullptr));
        label_p6->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_ampModSweep_2->setText(QCoreApplication::translate("MainWindow", "Hz", nullptr));
        label_freqModSweep->setText(QCoreApplication::translate("MainWindow", "Frequenza Modulante Sweep", nullptr));
        label_p7->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
        label_freqModSweepUM->setText(QCoreApplication::translate("MainWindow", "Hz", nullptr));
        groupBox_controlloInverter->setTitle(QCoreApplication::translate("MainWindow", "Controllo Inverter", nullptr));
        pushButton_ackFault->setText(QCoreApplication::translate("MainWindow", "Ack Fault", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start / Off", nullptr));
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