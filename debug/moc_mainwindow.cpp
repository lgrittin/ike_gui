/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[46];
    char stringdata0[861];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "openSerialPort"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "closeSerialPort"
QT_MOC_LITERAL(4, 43, 5), // "about"
QT_MOC_LITERAL(5, 49, 9), // "writeData"
QT_MOC_LITERAL(6, 59, 4), // "data"
QT_MOC_LITERAL(7, 64, 8), // "readData"
QT_MOC_LITERAL(8, 73, 17), // "synchronizeParams"
QT_MOC_LITERAL(9, 91, 14), // "askToReadParam"
QT_MOC_LITERAL(10, 106, 10), // "calc_chksm"
QT_MOC_LITERAL(11, 117, 8), // "uint8_t*"
QT_MOC_LITERAL(12, 126, 9), // "serial_tx"
QT_MOC_LITERAL(13, 136, 8), // "checksum"
QT_MOC_LITERAL(14, 145, 15), // "decode_usart_rx"
QT_MOC_LITERAL(15, 161, 9), // "serial_rx"
QT_MOC_LITERAL(16, 171, 7), // "uint8_t"
QT_MOC_LITERAL(17, 179, 16), // "artifact_bitwise"
QT_MOC_LITERAL(18, 196, 11), // "handleError"
QT_MOC_LITERAL(19, 208, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(20, 237, 5), // "error"
QT_MOC_LITERAL(21, 243, 16), // "pressed_ackFault"
QT_MOC_LITERAL(22, 260, 13), // "pressed_start"
QT_MOC_LITERAL(23, 274, 19), // "pressed_aperturaMan"
QT_MOC_LITERAL(24, 294, 24), // "valueChanged_valApertura"
QT_MOC_LITERAL(25, 319, 30), // "valueChanged_valAperturaFinale"
QT_MOC_LITERAL(26, 350, 33), // "valueChanged_valAperturaRidot..."
QT_MOC_LITERAL(27, 384, 33), // "valueChanged_valAperturaRidot..."
QT_MOC_LITERAL(28, 418, 33), // "valueChanged_durataApRidottaC..."
QT_MOC_LITERAL(29, 452, 21), // "valueChanged_velRampa"
QT_MOC_LITERAL(30, 474, 15), // "pressed_enSweep"
QT_MOC_LITERAL(31, 490, 27), // "valueChanged_freqPrincipale"
QT_MOC_LITERAL(32, 518, 24), // "valueChanged_ampModSweep"
QT_MOC_LITERAL(33, 543, 25), // "valueChanged_freqModSweep"
QT_MOC_LITERAL(34, 569, 25), // "valueChanged_vInvRectGain"
QT_MOC_LITERAL(35, 595, 27), // "valueChanged_vInvRectOffset"
QT_MOC_LITERAL(36, 623, 25), // "valueChanged_iInvRectGain"
QT_MOC_LITERAL(37, 649, 27), // "valueChanged_iInvRectOffset"
QT_MOC_LITERAL(38, 677, 21), // "valueChanged_ntc1Gain"
QT_MOC_LITERAL(39, 699, 23), // "valueChanged_ntc1Offset"
QT_MOC_LITERAL(40, 723, 21), // "valueChanged_ntc2Gain"
QT_MOC_LITERAL(41, 745, 23), // "valueChanged_ntc2Offset"
QT_MOC_LITERAL(42, 769, 20), // "valueChanged_potGain"
QT_MOC_LITERAL(43, 790, 22), // "valueChanged_potOffset"
QT_MOC_LITERAL(44, 813, 22), // "pressed_enProtOvercurr"
QT_MOC_LITERAL(45, 836, 24) // "valueChanged_valOvercurr"

    },
    "MainWindow\0openSerialPort\0\0closeSerialPort\0"
    "about\0writeData\0data\0readData\0"
    "synchronizeParams\0askToReadParam\0"
    "calc_chksm\0uint8_t*\0serial_tx\0checksum\0"
    "decode_usart_rx\0serial_rx\0uint8_t\0"
    "artifact_bitwise\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "pressed_ackFault\0pressed_start\0"
    "pressed_aperturaMan\0valueChanged_valApertura\0"
    "valueChanged_valAperturaFinale\0"
    "valueChanged_valAperturaRidotta50\0"
    "valueChanged_valAperturaRidotta60\0"
    "valueChanged_durataApRidottaCheck\0"
    "valueChanged_velRampa\0pressed_enSweep\0"
    "valueChanged_freqPrincipale\0"
    "valueChanged_ampModSweep\0"
    "valueChanged_freqModSweep\0"
    "valueChanged_vInvRectGain\0"
    "valueChanged_vInvRectOffset\0"
    "valueChanged_iInvRectGain\0"
    "valueChanged_iInvRectOffset\0"
    "valueChanged_ntc1Gain\0valueChanged_ntc1Offset\0"
    "valueChanged_ntc2Gain\0valueChanged_ntc2Offset\0"
    "valueChanged_potGain\0valueChanged_potOffset\0"
    "pressed_enProtOvercurr\0valueChanged_valOvercurr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x08 /* Private */,
       3,    0,  190,    2, 0x08 /* Private */,
       4,    0,  191,    2, 0x08 /* Private */,
       5,    1,  192,    2, 0x08 /* Private */,
       7,    0,  195,    2, 0x08 /* Private */,
       8,    0,  196,    2, 0x08 /* Private */,
       9,    0,  197,    2, 0x08 /* Private */,
      10,    2,  198,    2, 0x08 /* Private */,
      14,    2,  203,    2, 0x08 /* Private */,
      18,    1,  208,    2, 0x08 /* Private */,
      21,    0,  211,    2, 0x08 /* Private */,
      22,    0,  212,    2, 0x08 /* Private */,
      23,    0,  213,    2, 0x08 /* Private */,
      24,    0,  214,    2, 0x08 /* Private */,
      25,    0,  215,    2, 0x08 /* Private */,
      26,    0,  216,    2, 0x08 /* Private */,
      27,    0,  217,    2, 0x08 /* Private */,
      28,    0,  218,    2, 0x08 /* Private */,
      29,    0,  219,    2, 0x08 /* Private */,
      30,    0,  220,    2, 0x08 /* Private */,
      31,    0,  221,    2, 0x08 /* Private */,
      32,    0,  222,    2, 0x08 /* Private */,
      33,    0,  223,    2, 0x08 /* Private */,
      34,    0,  224,    2, 0x08 /* Private */,
      35,    0,  225,    2, 0x08 /* Private */,
      36,    0,  226,    2, 0x08 /* Private */,
      37,    0,  227,    2, 0x08 /* Private */,
      38,    0,  228,    2, 0x08 /* Private */,
      39,    0,  229,    2, 0x08 /* Private */,
      40,    0,  230,    2, 0x08 /* Private */,
      41,    0,  231,    2, 0x08 /* Private */,
      42,    0,  232,    2, 0x08 /* Private */,
      43,    0,  233,    2, 0x08 /* Private */,
      44,    0,  234,    2, 0x08 /* Private */,
      45,    0,  235,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 16,   15,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openSerialPort(); break;
        case 1: _t->closeSerialPort(); break;
        case 2: _t->about(); break;
        case 3: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->readData(); break;
        case 5: _t->synchronizeParams(); break;
        case 6: _t->askToReadParam(); break;
        case 7: _t->calc_chksm((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t*(*)>(_a[2]))); break;
        case 8: _t->decode_usart_rx((*reinterpret_cast< uint8_t*(*)>(_a[1])),(*reinterpret_cast< uint8_t(*)>(_a[2]))); break;
        case 9: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 10: _t->pressed_ackFault(); break;
        case 11: _t->pressed_start(); break;
        case 12: _t->pressed_aperturaMan(); break;
        case 13: _t->valueChanged_valApertura(); break;
        case 14: _t->valueChanged_valAperturaFinale(); break;
        case 15: _t->valueChanged_valAperturaRidotta50(); break;
        case 16: _t->valueChanged_valAperturaRidotta60(); break;
        case 17: _t->valueChanged_durataApRidottaCheck(); break;
        case 18: _t->valueChanged_velRampa(); break;
        case 19: _t->pressed_enSweep(); break;
        case 20: _t->valueChanged_freqPrincipale(); break;
        case 21: _t->valueChanged_ampModSweep(); break;
        case 22: _t->valueChanged_freqModSweep(); break;
        case 23: _t->valueChanged_vInvRectGain(); break;
        case 24: _t->valueChanged_vInvRectOffset(); break;
        case 25: _t->valueChanged_iInvRectGain(); break;
        case 26: _t->valueChanged_iInvRectOffset(); break;
        case 27: _t->valueChanged_ntc1Gain(); break;
        case 28: _t->valueChanged_ntc1Offset(); break;
        case 29: _t->valueChanged_ntc2Gain(); break;
        case 30: _t->valueChanged_ntc2Offset(); break;
        case 31: _t->valueChanged_potGain(); break;
        case 32: _t->valueChanged_potOffset(); break;
        case 33: _t->pressed_enProtOvercurr(); break;
        case 34: _t->valueChanged_valOvercurr(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE