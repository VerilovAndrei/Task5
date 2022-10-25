#ifndef SIGNAL_GLOBAL_H
#define SIGNAL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIGNAL_LIBRARY)
#  define SIGNAL_EXPORT Q_DECL_EXPORT
#else
#  define SIGNAL_EXPORT Q_DECL_IMPORT
#endif

#endif // SIGNAL_GLOBAL_H
