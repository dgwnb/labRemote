/****************************************************************************
** Meta object code from reading C++ file 'CVCamera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WaferProberGUI/src/CVCamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CVCamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CVCamera_t {
    QByteArrayData data[17];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CVCamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CVCamera_t qt_meta_stringdata_CVCamera = {
    {
QT_MOC_LITERAL(0, 0, 8), // "CVCamera"
QT_MOC_LITERAL(1, 9, 11), // "sizeChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "deviceListChanged"
QT_MOC_LITERAL(4, 40, 14), // "cvImageChanged"
QT_MOC_LITERAL(5, 55, 12), // "changeParent"
QT_MOC_LITERAL(6, 68, 11), // "QQuickItem*"
QT_MOC_LITERAL(7, 80, 6), // "parent"
QT_MOC_LITERAL(8, 87, 13), // "imageReceived"
QT_MOC_LITERAL(9, 101, 9), // "saveImage"
QT_MOC_LITERAL(10, 111, 8), // "location"
QT_MOC_LITERAL(11, 120, 6), // "device"
QT_MOC_LITERAL(12, 127, 12), // "videoSurface"
QT_MOC_LITERAL(13, 140, 22), // "QAbstractVideoSurface*"
QT_MOC_LITERAL(14, 163, 4), // "size"
QT_MOC_LITERAL(15, 168, 10), // "deviceList"
QT_MOC_LITERAL(16, 179, 7) // "cvImage"

    },
    "CVCamera\0sizeChanged\0\0deviceListChanged\0"
    "cvImageChanged\0changeParent\0QQuickItem*\0"
    "parent\0imageReceived\0saveImage\0location\0"
    "device\0videoSurface\0QAbstractVideoSurface*\0"
    "size\0deviceList\0cvImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CVCamera[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       5,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       8,    0,   50,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    1,   51,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   10,

 // properties: name, type, flags
      11, QMetaType::Int, 0x00095103,
      12, 0x80000000 | 13, 0x0009510b,
      14, QMetaType::QSize, 0x00495103,
      15, QMetaType::QStringList, 0x00495001,
      16, QMetaType::QVariant, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       1,
       2,

       0        // eod
};

void CVCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CVCamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sizeChanged(); break;
        case 1: _t->deviceListChanged(); break;
        case 2: _t->cvImageChanged(); break;
        case 3: _t->changeParent((*reinterpret_cast< QQuickItem*(*)>(_a[1]))); break;
        case 4: _t->imageReceived(); break;
        case 5: _t->saveImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQuickItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CVCamera::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CVCamera::sizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CVCamera::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CVCamera::deviceListChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CVCamera::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CVCamera::cvImageChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CVCamera *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getDevice(); break;
        case 1: *reinterpret_cast< QAbstractVideoSurface**>(_v) = _t->getVideoSurface(); break;
        case 2: *reinterpret_cast< QSize*>(_v) = _t->getSize(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = _t->getDeviceList(); break;
        case 4: *reinterpret_cast< QVariant*>(_v) = _t->getCvImage(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CVCamera *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDevice(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setVideoSurface(*reinterpret_cast< QAbstractVideoSurface**>(_v)); break;
        case 2: _t->setSize(*reinterpret_cast< QSize*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CVCamera::staticMetaObject = { {
    &QQuickItem::staticMetaObject,
    qt_meta_stringdata_CVCamera.data,
    qt_meta_data_CVCamera,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CVCamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CVCamera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CVCamera.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int CVCamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CVCamera::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CVCamera::deviceListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CVCamera::cvImageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
