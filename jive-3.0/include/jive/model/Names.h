
/*
 *  Copyright (C) 2019 DRG. All rights reserved.
 *
 *  This file is part of Jive, an object oriented toolkit for solving
 *  partial differential equations.
 *
 *  Commercial License Usage
 *
 *  This file may be used under the terms of a commercial license
 *  provided with the software, or under the terms contained in a written
 *  agreement between you and DRG. For more information contact DRG at
 *  http://www.dynaflow.com.
 *
 *  GNU Lesser General Public License Usage
 *
 *  Alternatively, this file may be used under the terms of the GNU
 *  Lesser General Public License version 2.1 or version 3 as published
 *  by the Free Software Foundation and appearing in the file
 *  LICENSE.LGPLv21 and LICENSE.LGPLv3 included in the packaging of this
 *  file. Please review the following information to ensure the GNU
 *  Lesser General Public License requirements will be met:
 *  https://www.gnu.org/licenses/lgpl.html and
 *  http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 *  This file is part of Jive, an object oriented toolkit for
 *  solving partial differential equations.
 *
 *  Jive version: 3.0
 *  Date:         Fri 20 Dec 14:30:12 CET 2019
 */

#ifndef JIVE_MODEL_NAMES_H
#define JIVE_MODEL_NAMES_H

#include <jive/defines.h>


JIVE_BEGIN_PACKAGE( model )


//-----------------------------------------------------------------------
//   class RunvarNames
//-----------------------------------------------------------------------


class RunvarNames
{
 public:

  static const char*    RUNTIME;
  static const char*    LOAD_SCALE;

};


//-----------------------------------------------------------------------
//   class PropertyNames
//-----------------------------------------------------------------------


class PropertyNames
{
 public:

  static const char*    CONSTANT;
  static const char*    CON_TABLE;
  static const char*    DEBUG;
  static const char*    EPSILON;
  static const char*    FILTERS;
  static const char*    ITEMS;
  static const char*    LINEAR;
  static const char*    LOAD_CASE;
  static const char*    LOAD_SCALE;
  static const char*    LOAD_TABLE;
  static const char*    MATRICES[3];
  static const char*    MATRIX;
  static const char*    MATRIX0;
  static const char*    MATRIX1;
  static const char*    MATRIX2;
  static const char*    MODEL;
  static const char*    MODELS;
  static const char*    NOISE_LEVEL;
  static const char*    SCALE_FUNC;
  static const char*    SYMMETRIC;
  static const char*    TABLES;
  static const char*    VECTORS;

};


//-----------------------------------------------------------------------
//   related types
//-----------------------------------------------------------------------


typedef RunvarNames     VarNames;
typedef PropertyNames   PropNames;


JIVE_END_PACKAGE( model )

#endif
