/****************************************************************************
** Meta object code from reading C++ file 'calendarwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calendarwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendarwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_calendarwidget_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_calendarwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_calendarwidget_t qt_meta_stringdata_calendarwidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "calendarwidget"
QT_MOC_LITERAL(1, 15, 10), // "workSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "vocSignal"
QT_MOC_LITERAL(4, 37, 12), // "changeFormat"
QT_MOC_LITERAL(5, 50, 5), // "value"
QT_MOC_LITERAL(6, 56, 13) // "setCursorFlag"

    },
    "calendarwidget\0workSignal\0\0vocSignal\0"
    "changeFormat\0value\0setCursorFlag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_calendarwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   40,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDate,    2,
    QMetaType::Void, QMetaType::QDate,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void calendarwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        calendarwidget *_t = static_cast<calendarwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workSignal((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 1: _t->vocSignal((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 2: _t->changeFormat((*reinterpret_cast< QDate(*)>(_a[1]))); break;
        case 3: _t->setCursorFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (calendarwidget::*_t)(QDate );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendarwidget::workSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (calendarwidget::*_t)(QDate );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&calendarwidget::vocSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject calendarwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_calendarwidget.data,
      qt_meta_data_calendarwidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *calendarwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *calendarwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_calendarwidget.stringdata0))
        return static_cast<void*>(const_cast< calendarwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int calendarwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void calendarwidget::workSignal(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void calendarwidget::vocSignal(QDate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CursorWidget_t {
    QByteArrayData data[4];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CursorWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CursorWidget_t qt_meta_stringdata_CursorWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CursorWidget"
QT_MOC_LITERAL(1, 13, 3), // "Def"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9) // "changeDef"

    },
    "CursorWidget\0Def\0\0changeDef"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CursorWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void CursorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CursorWidget *_t = static_cast<CursorWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Def((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeDef((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CursorWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CursorWidget::Def)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CursorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CursorWidget.data,
      qt_meta_data_CursorWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CursorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CursorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CursorWidget.stringdata0))
        return static_cast<void*>(const_cast< CursorWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CursorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CursorWidget::Def(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
