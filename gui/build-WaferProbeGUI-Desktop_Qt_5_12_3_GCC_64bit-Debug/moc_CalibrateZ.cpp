/****************************************************************************
** Meta object code from reading C++ file 'CalibrateZ.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WaferProberGUI/src/CalibrateZ.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalibrateZ.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalibrateWorker_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibrateWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibrateWorker_t qt_meta_stringdata_CalibrateWorker = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CalibrateWorker"
QT_MOC_LITERAL(1, 16, 15), // "focusPointFound"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "maxAbsZ"
QT_MOC_LITERAL(4, 41, 5), // "start"
QT_MOC_LITERAL(5, 47, 8), // "startRun"
QT_MOC_LITERAL(6, 56, 4), // "stop"
QT_MOC_LITERAL(7, 61, 3) // "run"

    },
    "CalibrateWorker\0focusPointFound\0\0"
    "maxAbsZ\0start\0startRun\0stop\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibrateWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalibrateWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalibrateWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->focusPointFound((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->start(); break;
        case 2: _t->startRun(); break;
        case 3: _t->stop(); break;
        case 4: _t->run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalibrateWorker::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrateWorker::focusPointFound)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalibrateWorker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CalibrateWorker.data,
    qt_meta_data_CalibrateWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalibrateWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibrateWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrateWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CalibrateWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CalibrateWorker::focusPointFound(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_CalibrateZ_t {
    QByteArrayData data[12];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalibrateZ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalibrateZ_t qt_meta_stringdata_CalibrateZ = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CalibrateZ"
QT_MOC_LITERAL(1, 11, 19), // "motionHandleChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "cameraChanged"
QT_MOC_LITERAL(4, 46, 10), // "focusFound"
QT_MOC_LITERAL(5, 57, 5), // "start"
QT_MOC_LITERAL(6, 63, 4), // "stop"
QT_MOC_LITERAL(7, 68, 7), // "dismiss"
QT_MOC_LITERAL(8, 76, 12), // "motionHandle"
QT_MOC_LITERAL(9, 89, 8), // "BackEnd*"
QT_MOC_LITERAL(10, 98, 6), // "camera"
QT_MOC_LITERAL(11, 105, 9) // "CVCamera*"

    },
    "CalibrateZ\0motionHandleChanged\0\0"
    "cameraChanged\0focusFound\0start\0stop\0"
    "dismiss\0motionHandle\0BackEnd*\0camera\0"
    "CVCamera*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalibrateZ[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x02 /* Public */,
       6,    0,   48,    2, 0x02 /* Public */,
       7,    0,   49,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, 0x80000000 | 9, 0x0049510b,
      10, 0x80000000 | 11, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void CalibrateZ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalibrateZ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->motionHandleChanged(); break;
        case 1: _t->cameraChanged(); break;
        case 2: _t->focusFound(); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        case 5: _t->dismiss(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalibrateZ::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrateZ::motionHandleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CalibrateZ::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrateZ::cameraChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CalibrateZ::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalibrateZ::focusFound)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BackEnd* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CVCamera* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CalibrateZ *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< BackEnd**>(_v) = _t->motionHandle(); break;
        case 1: *reinterpret_cast< CVCamera**>(_v) = _t->camera(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CalibrateZ *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMotionHandle(*reinterpret_cast< BackEnd**>(_v)); break;
        case 1: _t->setCamera(*reinterpret_cast< CVCamera**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CalibrateZ::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CalibrateZ.data,
    qt_meta_data_CalibrateZ,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalibrateZ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalibrateZ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalibrateZ.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CalibrateZ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CalibrateZ::motionHandleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CalibrateZ::cameraChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CalibrateZ::focusFound()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
