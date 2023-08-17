/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../inc/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
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
    QByteArrayData data[29];
    char stringdata0[349];
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
QT_MOC_LITERAL(21, 243, 23), // "tableDataChanged_params"
QT_MOC_LITERAL(22, 267, 11), // "QModelIndex"
QT_MOC_LITERAL(23, 279, 7), // "topLeft"
QT_MOC_LITERAL(24, 287, 11), // "bottomRight"
QT_MOC_LITERAL(25, 299, 12), // "QVector<int>"
QT_MOC_LITERAL(26, 312, 5), // "roles"
QT_MOC_LITERAL(27, 318, 16), // "pressed_ackFault"
QT_MOC_LITERAL(28, 335, 13) // "pressed_start"

    },
    "MainWindow\0openSerialPort\0\0closeSerialPort\0"
    "about\0writeData\0data\0readData\0"
    "synchronizeParams\0askToReadParam\0"
    "calc_chksm\0uint8_t*\0serial_tx\0checksum\0"
    "decode_usart_rx\0serial_rx\0uint8_t\0"
    "artifact_bitwise\0handleError\0"
    "QSerialPort::SerialPortError\0error\0"
    "tableDataChanged_params\0QModelIndex\0"
    "topLeft\0bottomRight\0QVector<int>\0roles\0"
    "pressed_ackFault\0pressed_start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    2,   88,    2, 0x08 /* Private */,
      14,    2,   93,    2, 0x08 /* Private */,
      18,    1,   98,    2, 0x08 /* Private */,
      21,    3,  101,    2, 0x08 /* Private */,
      27,    0,  108,    2, 0x08 /* Private */,
      28,    0,  109,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22, 0x80000000 | 25,   23,   24,   26,
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
        case 10: _t->tableDataChanged_params((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2])),(*reinterpret_cast< const QVector<int>(*)>(_a[3]))); break;
        case 11: _t->pressed_ackFault(); break;
        case 12: _t->pressed_start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
