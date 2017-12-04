/****************************************************************************
** Meta object code from reading C++ file 'UserView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UserView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UserView_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UserView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UserView_t qt_meta_stringdata_UserView = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UserView"
QT_MOC_LITERAL(1, 9, 19), // "slot_CurrentChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "index"
QT_MOC_LITERAL(4, 36, 16), // "slot_ItemClicked"
QT_MOC_LITERAL(5, 53, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 71, 4), // "item"
QT_MOC_LITERAL(7, 76, 17), // "slot_ValueChanged"
QT_MOC_LITERAL(8, 94, 5), // "value"
QT_MOC_LITERAL(9, 100, 11), // "slot_BuyOne"
QT_MOC_LITERAL(10, 112, 20), // "slot_bookTableChoose"
QT_MOC_LITERAL(11, 133, 3), // "row"
QT_MOC_LITERAL(12, 137, 3), // "col"
QT_MOC_LITERAL(13, 141, 20), // "slot_foodTableChoose"
QT_MOC_LITERAL(14, 162, 21) // "slot_clothTableChoose"

    },
    "UserView\0slot_CurrentChanged\0\0index\0"
    "slot_ItemClicked\0QTableWidgetItem*\0"
    "item\0slot_ValueChanged\0value\0slot_BuyOne\0"
    "slot_bookTableChoose\0row\0col\0"
    "slot_foodTableChoose\0slot_clothTableChoose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    2,   59,    2, 0x08 /* Private */,
      13,    2,   64,    2, 0x08 /* Private */,
      14,    2,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

       0        // eod
};

void UserView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserView *_t = static_cast<UserView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_CurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slot_ItemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slot_ValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slot_BuyOne(); break;
        case 4: _t->slot_bookTableChoose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->slot_foodTableChoose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->slot_clothTableChoose((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject UserView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserView.data,
      qt_meta_data_UserView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UserView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UserView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int UserView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
