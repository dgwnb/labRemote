/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WaferProberGUI/src/backend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MotionWorker_t {
    QByteArrayData data[9];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MotionWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MotionWorker_t qt_meta_stringdata_MotionWorker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MotionWorker"
QT_MOC_LITERAL(1, 13, 15), // "positionChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "axis"
QT_MOC_LITERAL(4, 35, 14), // "commandChanged"
QT_MOC_LITERAL(5, 50, 7), // "command"
QT_MOC_LITERAL(6, 58, 5), // "start"
QT_MOC_LITERAL(7, 64, 4), // "stop"
QT_MOC_LITERAL(8, 69, 3) // "run"

    },
    "MotionWorker\0positionChanged\0\0axis\0"
    "commandChanged\0command\0start\0stop\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MotionWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MotionWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MotionWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->commandChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        case 4: _t->run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MotionWorker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MotionWorker::positionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MotionWorker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MotionWorker::commandChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MotionWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MotionWorker.data,
    qt_meta_data_MotionWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MotionWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MotionWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MotionWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MotionWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MotionWorker::positionChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MotionWorker::commandChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_BackEnd_t {
    QByteArrayData data[36];
    char stringdata0[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BackEnd_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BackEnd_t qt_meta_stringdata_BackEnd = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BackEnd"
QT_MOC_LITERAL(1, 8, 19), // "xyDeviceNameChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "zDeviceNameChanged"
QT_MOC_LITERAL(4, 48, 15), // "deviceConnected"
QT_MOC_LITERAL(5, 64, 15), // "positionChanged"
QT_MOC_LITERAL(6, 80, 4), // "axis"
QT_MOC_LITERAL(7, 85, 11), // "infoUpdated"
QT_MOC_LITERAL(8, 97, 7), // "message"
QT_MOC_LITERAL(9, 105, 11), // "chipArrived"
QT_MOC_LITERAL(10, 117, 15), // "srcImageArrived"
QT_MOC_LITERAL(11, 133, 24), // "chipArrivedForCalibrateZ"
QT_MOC_LITERAL(12, 158, 7), // "posXGot"
QT_MOC_LITERAL(13, 166, 7), // "posYGot"
QT_MOC_LITERAL(14, 174, 7), // "posZGot"
QT_MOC_LITERAL(15, 182, 9), // "speedXSet"
QT_MOC_LITERAL(16, 192, 9), // "speedYSet"
QT_MOC_LITERAL(17, 202, 9), // "speedZSet"
QT_MOC_LITERAL(18, 212, 17), // "checkPositionInfo"
QT_MOC_LITERAL(19, 230, 13), // "receiveUpdate"
QT_MOC_LITERAL(20, 244, 13), // "connectDevice"
QT_MOC_LITERAL(21, 258, 7), // "dismiss"
QT_MOC_LITERAL(22, 266, 7), // "run_cmd"
QT_MOC_LITERAL(23, 274, 3), // "cmd"
QT_MOC_LITERAL(24, 278, 4), // "stop"
QT_MOC_LITERAL(25, 283, 7), // "getPosX"
QT_MOC_LITERAL(26, 291, 7), // "getPosY"
QT_MOC_LITERAL(27, 299, 7), // "getPosZ"
QT_MOC_LITERAL(28, 307, 12), // "xyDeviceName"
QT_MOC_LITERAL(29, 320, 11), // "zDeviceName"
QT_MOC_LITERAL(30, 332, 6), // "speedX"
QT_MOC_LITERAL(31, 339, 6), // "speedY"
QT_MOC_LITERAL(32, 346, 6), // "speedZ"
QT_MOC_LITERAL(33, 353, 8), // "zContact"
QT_MOC_LITERAL(34, 362, 4), // "zSep"
QT_MOC_LITERAL(35, 367, 11) // "IsAtContact"

    },
    "BackEnd\0xyDeviceNameChanged\0\0"
    "zDeviceNameChanged\0deviceConnected\0"
    "positionChanged\0axis\0infoUpdated\0"
    "message\0chipArrived\0srcImageArrived\0"
    "chipArrivedForCalibrateZ\0posXGot\0"
    "posYGot\0posZGot\0speedXSet\0speedYSet\0"
    "speedZSet\0checkPositionInfo\0receiveUpdate\0"
    "connectDevice\0dismiss\0run_cmd\0cmd\0"
    "stop\0getPosX\0getPosY\0getPosZ\0xyDeviceName\0"
    "zDeviceName\0speedX\0speedY\0speedZ\0"
    "zContact\0zSep\0IsAtContact"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackEnd[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       8,  162, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  129,    2, 0x06 /* Public */,
       3,    0,  130,    2, 0x06 /* Public */,
       4,    0,  131,    2, 0x06 /* Public */,
       5,    1,  132,    2, 0x06 /* Public */,
       7,    1,  135,    2, 0x06 /* Public */,
       9,    0,  138,    2, 0x06 /* Public */,
      10,    0,  139,    2, 0x06 /* Public */,
      11,    0,  140,    2, 0x06 /* Public */,
      12,    0,  141,    2, 0x06 /* Public */,
      13,    0,  142,    2, 0x06 /* Public */,
      14,    0,  143,    2, 0x06 /* Public */,
      15,    0,  144,    2, 0x06 /* Public */,
      16,    0,  145,    2, 0x06 /* Public */,
      17,    0,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  147,    2, 0x0a /* Public */,
      19,    1,  150,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      20,    0,  153,    2, 0x02 /* Public */,
      21,    0,  154,    2, 0x02 /* Public */,
      22,    1,  155,    2, 0x02 /* Public */,
      24,    0,  158,    2, 0x02 /* Public */,
      25,    0,  159,    2, 0x02 /* Public */,
      26,    0,  160,    2, 0x02 /* Public */,
      27,    0,  161,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // methods: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,

 // properties: name, type, flags
      28, QMetaType::QString, 0x00495103,
      29, QMetaType::QString, 0x00495103,
      30, QMetaType::Float, 0x00495103,
      31, QMetaType::Float, 0x00495103,
      32, QMetaType::Float, 0x00495103,
      33, QMetaType::Bool, 0x00095103,
      34, QMetaType::Float, 0x00095103,
      35, QMetaType::Bool, 0x00095103,

 // properties: notify_signal_id
       0,
       1,
      11,
      12,
      13,
       0,
       0,
       0,

       0        // eod
};

void BackEnd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xyDeviceNameChanged(); break;
        case 1: _t->zDeviceNameChanged(); break;
        case 2: _t->deviceConnected(); break;
        case 3: _t->positionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->infoUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->chipArrived(); break;
        case 6: _t->srcImageArrived(); break;
        case 7: _t->chipArrivedForCalibrateZ(); break;
        case 8: _t->posXGot(); break;
        case 9: _t->posYGot(); break;
        case 10: _t->posZGot(); break;
        case 11: _t->speedXSet(); break;
        case 12: _t->speedYSet(); break;
        case 13: _t->speedZSet(); break;
        case 14: _t->checkPositionInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->receiveUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: { int _r = _t->connectDevice();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->dismiss(); break;
        case 18: _t->run_cmd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->stop(); break;
        case 20: { float _r = _t->getPosX();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 21: { float _r = _t->getPosY();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 22: { float _r = _t->getPosZ();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::xyDeviceNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::zDeviceNameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::deviceConnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::positionChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::infoUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::chipArrived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::srcImageArrived)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::chipArrivedForCalibrateZ)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::posXGot)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::posYGot)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::posZGot)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::speedXSet)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::speedYSet)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (BackEnd::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackEnd::speedZSet)) {
                *result = 13;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->xyDeviceName(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->zDeviceName(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->getSpeedX(); break;
        case 3: *reinterpret_cast< float*>(_v) = _t->getSpeedY(); break;
        case 4: *reinterpret_cast< float*>(_v) = _t->getSpeedZ(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->zContact(); break;
        case 6: *reinterpret_cast< float*>(_v) = _t->zSep(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->IsAtContact(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<BackEnd *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setXyDeviceName(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setZDeviceName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSpeedX(*reinterpret_cast< float*>(_v)); break;
        case 3: _t->setSpeedY(*reinterpret_cast< float*>(_v)); break;
        case 4: _t->setSpeedZ(*reinterpret_cast< float*>(_v)); break;
        case 5: _t->setZContact(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setZSep(*reinterpret_cast< float*>(_v)); break;
        case 7: _t->setIsAtContact(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject BackEnd::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_BackEnd.data,
    qt_meta_data_BackEnd,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BackEnd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackEnd::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackEnd.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackEnd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 23;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void BackEnd::xyDeviceNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BackEnd::zDeviceNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BackEnd::deviceConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BackEnd::positionChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BackEnd::infoUpdated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void BackEnd::chipArrived()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void BackEnd::srcImageArrived()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void BackEnd::chipArrivedForCalibrateZ()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void BackEnd::posXGot()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void BackEnd::posYGot()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void BackEnd::posZGot()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void BackEnd::speedXSet()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void BackEnd::speedYSet()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void BackEnd::speedZSet()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
