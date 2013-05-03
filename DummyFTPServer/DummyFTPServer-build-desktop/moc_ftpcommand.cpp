/****************************************************************************
** Meta object code from reading C++ file 'ftpcommand.h'
**
** Created: Wed Mar 7 15:56:45 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../source/ftpcommand.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpcommand.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DummyFTPServer__FTPCommand[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   27,   27,   27, 0x0a,
      50,   27,   27,   27, 0x0a,
      67,   62,   27,   27, 0x0a,
      79,   27,   27,   27, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_DummyFTPServer__FTPCommand[] = {
    "DummyFTPServer::FTPCommand\0\0finished()\0"
    "sendData()\0finishing()\0stop\0error(bool)\0"
    "error()\0"
};

const QMetaObject DummyFTPServer::FTPCommand::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DummyFTPServer__FTPCommand,
      qt_meta_data_DummyFTPServer__FTPCommand, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DummyFTPServer::FTPCommand::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DummyFTPServer::FTPCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DummyFTPServer::FTPCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DummyFTPServer__FTPCommand))
        return static_cast<void*>(const_cast< FTPCommand*>(this));
    return QObject::qt_metacast(_clname);
}

int DummyFTPServer::FTPCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: sendData(); break;
        case 2: finishing(); break;
        case 3: error((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: error(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DummyFTPServer::FTPCommand::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
