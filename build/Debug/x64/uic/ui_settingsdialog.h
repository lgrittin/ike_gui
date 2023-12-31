/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *protocolGroupBox;
    QGridLayout *gridLayout_4;
    QComboBox *protocolListBox;
    QGroupBox *tcpGroupBox;
    QGridLayout *gridLayout_5;
    QLabel *ipPortLabel;
    QLineEdit *ipPortLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *applyButton;
    QGroupBox *selectBox;
    QGridLayout *gridLayout;
    QLabel *manufacturerLabel;
    QLabel *locationLabel;
    QLabel *vidLabel;
    QLabel *pidLabel;
    QComboBox *serialPortInfoListBox;
    QLabel *serialNumberLabel;
    QLabel *descriptionLabel;
    QPushButton *pushButton_rescanSerialPorts;
    QGroupBox *parametersBox;
    QGridLayout *gridLayout_2;
    QComboBox *stopBitsBox;
    QLabel *stopBitsLabel;
    QComboBox *flowControlBox;
    QComboBox *parityBox;
    QLabel *parityLabel;
    QLabel *dataBitsLabel;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QComboBox *dataBitsBox;
    QLabel *flowControlLabel;
    QGroupBox *additionalOptionsGroupBox;
    QGridLayout *gridLayout_6;
    QLabel *label_2;
    QSpinBox *retriesSpinner;
    QLabel *label_4;
    QLabel *label;
    QCheckBox *localEchoCheckBox;
    QSpinBox *timeoutSpinner;
    QLabel *label_3;
    QSpinBox *readIntervalSpinner;
    QSpinBox *modbusServerAddressSpinner;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(593, 486);
        gridLayout_3 = new QGridLayout(SettingsDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        protocolGroupBox = new QGroupBox(SettingsDialog);
        protocolGroupBox->setObjectName(QString::fromUtf8("protocolGroupBox"));
        gridLayout_4 = new QGridLayout(protocolGroupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        protocolListBox = new QComboBox(protocolGroupBox);
        protocolListBox->setObjectName(QString::fromUtf8("protocolListBox"));

        gridLayout_4->addWidget(protocolListBox, 0, 0, 1, 1);


        gridLayout_3->addWidget(protocolGroupBox, 0, 0, 1, 2);

        tcpGroupBox = new QGroupBox(SettingsDialog);
        tcpGroupBox->setObjectName(QString::fromUtf8("tcpGroupBox"));
        gridLayout_5 = new QGridLayout(tcpGroupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        ipPortLabel = new QLabel(tcpGroupBox);
        ipPortLabel->setObjectName(QString::fromUtf8("ipPortLabel"));

        gridLayout_5->addWidget(ipPortLabel, 1, 0, 1, 1);

        ipPortLineEdit = new QLineEdit(tcpGroupBox);
        ipPortLineEdit->setObjectName(QString::fromUtf8("ipPortLineEdit"));

        gridLayout_5->addWidget(ipPortLineEdit, 1, 1, 1, 1);


        gridLayout_3->addWidget(tcpGroupBox, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(96, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        applyButton = new QPushButton(SettingsDialog);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setCheckable(false);

        horizontalLayout->addWidget(applyButton);


        gridLayout_3->addLayout(horizontalLayout, 4, 0, 1, 2);

        selectBox = new QGroupBox(SettingsDialog);
        selectBox->setObjectName(QString::fromUtf8("selectBox"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selectBox->sizePolicy().hasHeightForWidth());
        selectBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(selectBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        manufacturerLabel = new QLabel(selectBox);
        manufacturerLabel->setObjectName(QString::fromUtf8("manufacturerLabel"));

        gridLayout->addWidget(manufacturerLabel, 2, 0, 1, 1);

        locationLabel = new QLabel(selectBox);
        locationLabel->setObjectName(QString::fromUtf8("locationLabel"));

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        vidLabel = new QLabel(selectBox);
        vidLabel->setObjectName(QString::fromUtf8("vidLabel"));

        gridLayout->addWidget(vidLabel, 5, 0, 1, 1);

        pidLabel = new QLabel(selectBox);
        pidLabel->setObjectName(QString::fromUtf8("pidLabel"));

        gridLayout->addWidget(pidLabel, 6, 0, 1, 1);

        serialPortInfoListBox = new QComboBox(selectBox);
        serialPortInfoListBox->setObjectName(QString::fromUtf8("serialPortInfoListBox"));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        serialNumberLabel = new QLabel(selectBox);
        serialNumberLabel->setObjectName(QString::fromUtf8("serialNumberLabel"));

        gridLayout->addWidget(serialNumberLabel, 3, 0, 1, 1);

        descriptionLabel = new QLabel(selectBox);
        descriptionLabel->setObjectName(QString::fromUtf8("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        pushButton_rescanSerialPorts = new QPushButton(selectBox);
        pushButton_rescanSerialPorts->setObjectName(QString::fromUtf8("pushButton_rescanSerialPorts"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_rescanSerialPorts->sizePolicy().hasHeightForWidth());
        pushButton_rescanSerialPorts->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_rescanSerialPorts, 0, 1, 1, 1);


        gridLayout_3->addWidget(selectBox, 1, 0, 1, 1);

        parametersBox = new QGroupBox(SettingsDialog);
        parametersBox->setObjectName(QString::fromUtf8("parametersBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(parametersBox->sizePolicy().hasHeightForWidth());
        parametersBox->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(parametersBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stopBitsBox = new QComboBox(parametersBox);
        stopBitsBox->setObjectName(QString::fromUtf8("stopBitsBox"));

        gridLayout_2->addWidget(stopBitsBox, 4, 1, 1, 1);

        stopBitsLabel = new QLabel(parametersBox);
        stopBitsLabel->setObjectName(QString::fromUtf8("stopBitsLabel"));

        gridLayout_2->addWidget(stopBitsLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(parametersBox);
        flowControlBox->setObjectName(QString::fromUtf8("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 5, 1, 1, 1);

        parityBox = new QComboBox(parametersBox);
        parityBox->setObjectName(QString::fromUtf8("parityBox"));

        gridLayout_2->addWidget(parityBox, 0, 1, 1, 1);

        parityLabel = new QLabel(parametersBox);
        parityLabel->setObjectName(QString::fromUtf8("parityLabel"));

        gridLayout_2->addWidget(parityLabel, 0, 0, 1, 1);

        dataBitsLabel = new QLabel(parametersBox);
        dataBitsLabel->setObjectName(QString::fromUtf8("dataBitsLabel"));

        gridLayout_2->addWidget(dataBitsLabel, 2, 0, 1, 1);

        baudRateLabel = new QLabel(parametersBox);
        baudRateLabel->setObjectName(QString::fromUtf8("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 1, 0, 1, 1);

        baudRateBox = new QComboBox(parametersBox);
        baudRateBox->setObjectName(QString::fromUtf8("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 1, 1, 1, 1);

        dataBitsBox = new QComboBox(parametersBox);
        dataBitsBox->setObjectName(QString::fromUtf8("dataBitsBox"));

        gridLayout_2->addWidget(dataBitsBox, 2, 1, 1, 1);

        flowControlLabel = new QLabel(parametersBox);
        flowControlLabel->setObjectName(QString::fromUtf8("flowControlLabel"));

        gridLayout_2->addWidget(flowControlLabel, 5, 0, 1, 1);


        gridLayout_3->addWidget(parametersBox, 1, 1, 1, 1);

        additionalOptionsGroupBox = new QGroupBox(SettingsDialog);
        additionalOptionsGroupBox->setObjectName(QString::fromUtf8("additionalOptionsGroupBox"));
        gridLayout_6 = new QGridLayout(additionalOptionsGroupBox);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_2 = new QLabel(additionalOptionsGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_2, 2, 0, 1, 1);

        retriesSpinner = new QSpinBox(additionalOptionsGroupBox);
        retriesSpinner->setObjectName(QString::fromUtf8("retriesSpinner"));

        gridLayout_6->addWidget(retriesSpinner, 2, 1, 1, 1);

        label_4 = new QLabel(additionalOptionsGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_4, 2, 2, 1, 1);

        label = new QLabel(additionalOptionsGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label, 1, 0, 1, 1);

        localEchoCheckBox = new QCheckBox(additionalOptionsGroupBox);
        localEchoCheckBox->setObjectName(QString::fromUtf8("localEchoCheckBox"));
        localEchoCheckBox->setChecked(true);

        gridLayout_6->addWidget(localEchoCheckBox, 0, 0, 1, 1);

        timeoutSpinner = new QSpinBox(additionalOptionsGroupBox);
        timeoutSpinner->setObjectName(QString::fromUtf8("timeoutSpinner"));
        timeoutSpinner->setMaximum(10000);

        gridLayout_6->addWidget(timeoutSpinner, 1, 1, 1, 1);

        label_3 = new QLabel(additionalOptionsGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(label_3, 1, 2, 1, 1);

        readIntervalSpinner = new QSpinBox(additionalOptionsGroupBox);
        readIntervalSpinner->setObjectName(QString::fromUtf8("readIntervalSpinner"));
        readIntervalSpinner->setMaximum(10000);

        gridLayout_6->addWidget(readIntervalSpinner, 1, 3, 1, 1);

        modbusServerAddressSpinner = new QSpinBox(additionalOptionsGroupBox);
        modbusServerAddressSpinner->setObjectName(QString::fromUtf8("modbusServerAddressSpinner"));

        gridLayout_6->addWidget(modbusServerAddressSpinner, 2, 3, 1, 1);


        gridLayout_3->addWidget(additionalOptionsGroupBox, 3, 0, 1, 2);


        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Settings", nullptr));
        protocolGroupBox->setTitle(QCoreApplication::translate("SettingsDialog", "Select Protocol", nullptr));
        tcpGroupBox->setTitle(QCoreApplication::translate("SettingsDialog", "Select Ethernet Connection", nullptr));
        ipPortLabel->setText(QCoreApplication::translate("SettingsDialog", "TCP/IP Host Address [IPv4:Port]:", nullptr));
        applyButton->setText(QCoreApplication::translate("SettingsDialog", "Apply", nullptr));
        selectBox->setTitle(QCoreApplication::translate("SettingsDialog", "Select Serial Port", nullptr));
        manufacturerLabel->setText(QCoreApplication::translate("SettingsDialog", "Manufacturer:", nullptr));
        locationLabel->setText(QCoreApplication::translate("SettingsDialog", "Location:", nullptr));
        vidLabel->setText(QCoreApplication::translate("SettingsDialog", "Vendor ID:", nullptr));
        pidLabel->setText(QCoreApplication::translate("SettingsDialog", "Product ID:", nullptr));
        serialNumberLabel->setText(QCoreApplication::translate("SettingsDialog", "Serial number:", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("SettingsDialog", "Description:", nullptr));
        pushButton_rescanSerialPorts->setText(QCoreApplication::translate("SettingsDialog", "Rescan", nullptr));
        parametersBox->setTitle(QCoreApplication::translate("SettingsDialog", "Select Parameters", nullptr));
        stopBitsLabel->setText(QCoreApplication::translate("SettingsDialog", "Stop bits:", nullptr));
        parityLabel->setText(QCoreApplication::translate("SettingsDialog", "Parity:", nullptr));
        dataBitsLabel->setText(QCoreApplication::translate("SettingsDialog", "Data bits:", nullptr));
        baudRateLabel->setText(QCoreApplication::translate("SettingsDialog", "BaudRate:", nullptr));
        flowControlLabel->setText(QCoreApplication::translate("SettingsDialog", "Flow control:", nullptr));
        additionalOptionsGroupBox->setTitle(QCoreApplication::translate("SettingsDialog", "Additional options", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsDialog", "Number of retries:", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsDialog", "Server Address: ", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "Response Timeout [ms]:", nullptr));
        localEchoCheckBox->setText(QCoreApplication::translate("SettingsDialog", "Local echo", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsDialog", "Read Interval [ms]:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
