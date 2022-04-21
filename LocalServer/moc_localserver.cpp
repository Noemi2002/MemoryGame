/****************************************************************************
** Meta object code from reading C++ file 'localserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "localserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LocalServer_t {
    QByteArrayData data[11];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LocalServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LocalServer_t qt_meta_stringdata_LocalServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LocalServer"
QT_MOC_LITERAL(1, 12, 13), // "nuevaConexion"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "leerSocket"
QT_MOC_LITERAL(4, 38, 16), // "obtenerResultado"
QT_MOC_LITERAL(5, 55, 3), // "uno"
QT_MOC_LITERAL(6, 59, 3), // "dos"
QT_MOC_LITERAL(7, 63, 12), // "iniciarJuego"
QT_MOC_LITERAL(8, 76, 6), // "enviar"
QT_MOC_LITERAL(9, 83, 7), // "mensaje"
QT_MOC_LITERAL(10, 91, 6) // "puntos"

    },
    "LocalServer\0nuevaConexion\0\0leerSocket\0"
    "obtenerResultado\0uno\0dos\0iniciarJuego\0"
    "enviar\0mensaje\0puntos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    2,   41,    2, 0x08 /* Private */,
       7,    0,   46,    2, 0x08 /* Private */,
       8,    2,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    9,   10,

       0        // eod
};

void LocalServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LocalServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nuevaConexion(); break;
        case 1: _t->leerSocket(); break;
        case 2: { int _r = _t->obtenerResultado((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->iniciarJuego(); break;
        case 4: _t->enviar((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LocalServer::staticMetaObject = { {
    &QTcpServer::staticMetaObject,
    qt_meta_stringdata_LocalServer.data,
    qt_meta_data_LocalServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LocalServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LocalServer.stringdata0))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int LocalServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
