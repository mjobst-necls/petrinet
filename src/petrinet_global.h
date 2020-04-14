/*******************************************************
 * Copyright (C) 2018 Michael Jobst <mjobst@tecratech.de>
 *
 * This file is part of Dimaqs.
 *
 * Dimaqs can not be copied and/or distributed without the express
 * permission of Michael Jobst
 *******************************************************/

#ifndef PETRINET_GLOBAL_H
#define PETRINET_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PETRINET_LIBRARY)
#  define PETRINETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PETRINETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PETRINET_GLOBAL_H
