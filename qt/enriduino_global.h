#ifndef ENRIDUINO_GLOBAL_H
#define ENRIDUINO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ENRIDUINO_LIBRARY)
#  define ENRIDUINOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ENRIDUINOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ENRIDUINO_GLOBAL_H
