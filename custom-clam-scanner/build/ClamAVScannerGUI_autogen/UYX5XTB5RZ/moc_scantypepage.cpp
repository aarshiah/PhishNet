/****************************************************************************
** Meta object code from reading C++ file 'scantypepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ui/scantypepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scantypepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScanWorker_t {
    QByteArrayData data[7];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanWorker_t qt_meta_stringdata_ScanWorker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ScanWorker"
QT_MOC_LITERAL(1, 11, 12), // "scanComplete"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "filesScanned"
QT_MOC_LITERAL(4, 38, 12), // "threatsFound"
QT_MOC_LITERAL(5, 51, 12), // "scanProgress"
QT_MOC_LITERAL(6, 64, 6) // "doScan"

    },
    "ScanWorker\0scanComplete\0\0filesScanned\0"
    "threatsFound\0scanProgress\0doScan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ScanWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScanWorker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->scanComplete((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->scanProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->doScan(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScanWorker::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::scanComplete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScanWorker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanWorker::scanProgress)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScanWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ScanWorker.data,
    qt_meta_data_ScanWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScanWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScanWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScanWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ScanWorker::scanComplete(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScanWorker::scanProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_ScanTypePage_t {
    QByteArrayData data[16];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanTypePage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanTypePage_t qt_meta_stringdata_ScanTypePage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ScanTypePage"
QT_MOC_LITERAL(1, 13, 17), // "backButtonClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "startScan"
QT_MOC_LITERAL(4, 42, 19), // "onBackButtonClicked"
QT_MOC_LITERAL(5, 62, 17), // "onScanTypeChanged"
QT_MOC_LITERAL(6, 80, 5), // "index"
QT_MOC_LITERAL(7, 86, 21), // "onBrowseButtonClicked"
QT_MOC_LITERAL(8, 108, 25), // "onCustomScanButtonClicked"
QT_MOC_LITERAL(9, 134, 14), // "startQuickScan"
QT_MOC_LITERAL(10, 149, 15), // "startSystemScan"
QT_MOC_LITERAL(11, 165, 15), // "startCustomScan"
QT_MOC_LITERAL(12, 181, 18), // "handleScanComplete"
QT_MOC_LITERAL(13, 200, 12), // "filesScanned"
QT_MOC_LITERAL(14, 213, 12), // "threatsFound"
QT_MOC_LITERAL(15, 226, 18) // "updateScanProgress"

    },
    "ScanTypePage\0backButtonClicked\0\0"
    "startScan\0onBackButtonClicked\0"
    "onScanTypeChanged\0index\0onBrowseButtonClicked\0"
    "onCustomScanButtonClicked\0startQuickScan\0"
    "startSystemScan\0startCustomScan\0"
    "handleScanComplete\0filesScanned\0"
    "threatsFound\0updateScanProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanTypePage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    2,   80,    2, 0x08 /* Private */,
      15,    1,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void ScanTypePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScanTypePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backButtonClicked(); break;
        case 1: _t->startScan(); break;
        case 2: _t->onBackButtonClicked(); break;
        case 3: _t->onScanTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onBrowseButtonClicked(); break;
        case 5: _t->onCustomScanButtonClicked(); break;
        case 6: _t->startQuickScan(); break;
        case 7: _t->startSystemScan(); break;
        case 8: _t->startCustomScan(); break;
        case 9: _t->handleScanComplete((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->updateScanProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScanTypePage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanTypePage::backButtonClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScanTypePage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScanTypePage::startScan)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ScanTypePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ScanTypePage.data,
    qt_meta_data_ScanTypePage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ScanTypePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanTypePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScanTypePage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ScanTypePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ScanTypePage::backButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ScanTypePage::startScan()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
