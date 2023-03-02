
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

#ifndef JIVE_GEOM_HEXAHEDRON_H
#define JIVE_GEOM_HEXAHEDRON_H

#include <jive/util/Topology.h>
#include <jive/geom/typedefs.h>
#include <jive/geom/InternalShape.h>


JIVE_BEGIN_PACKAGE( geom )


//-----------------------------------------------------------------------
//   class Hexahedron
//-----------------------------------------------------------------------


class Hexahedron
{
 public:

  static const char*      GEOMETRY;
  static const char*      TYPE_NAME;

  static const int        BOUNDARY_COUNT = 6;


  static Ref<IShape>      getShape

    ( const String&         name,
      String&               ischeme,
      String&               bscheme,
      const Ref<SShape>&    xfuncs,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const MatrixVector&   ischeme,
      const Ref<SShape>&    xfuncs,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const Properties&     conf,
      const Properties&     props );

  static void             declare             ();


 protected:

  class                   Utils_;

};


//-----------------------------------------------------------------------
//   class Hexahedron8
//-----------------------------------------------------------------------


class Hexahedron8 : public Hexahedron
{
 public:

  static const char*      TYPE_NAME;

  static const int        NODE_COUNT         = 8;
  static const int        NODES_PER_BOUNDARY = 4;

  static const char*      ISCHEME;
  static const char*      BSCHEME;


  static Ref<IShape>      getShape

    ( const String&         name    = "hex8",
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      String&               ischeme,
      String&               bscheme,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const MatrixVector&   ischeme,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const Properties&     conf,
      const Properties&     props );

  static util::Topology   getBoundaryTopology ();

  static void             declare             ();

};


//-----------------------------------------------------------------------
//   class Hexahedron16
//-----------------------------------------------------------------------


class Hexahedron16 : public Hexahedron
{
 public:

  static const char*      TYPE_NAME;

  static const int        NODE_COUNT = 16;

  static const char*      ISCHEME;
  static const char*      BSCHEME;


  static Ref<IShape>      getShape

    ( const String&         name    = "hex16",
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      String&               ischeme,
      String&               bscheme,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const MatrixVector&   ischeme,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const Properties&     conf,
      const Properties&     props );

  static util::Topology   getBoundaryTopology ();

  static void             declare             ();

};


//-----------------------------------------------------------------------
//   class Hexahedron20
//-----------------------------------------------------------------------


class Hexahedron20 : public Hexahedron
{
 public:

  static const char*      TYPE_NAME;

  static const int        NODE_COUNT         = 20;
  static const int        NODES_PER_BOUNDARY =  8;

  static const char*      ISCHEME;
  static const char*      BSCHEME;


  static Ref<IShape>      getShape

    ( const String&         name    = "hex20",
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      String&               ischeme,
      String&               bscheme,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const MatrixVector&   ischeme,
      const Ref<SShape>&    sfuncs  = nullptr );

  static Ref<IShape>      getShape

    ( const String&         name,
      const Properties&     conf,
      const Properties&     props );


  static util::Topology   getBoundaryTopology ();

  static void             declare             ();

};


//-----------------------------------------------------------------------
//   compatibility typedefs
//-----------------------------------------------------------------------


typedef Hexahedron8       LinearHexahedron;
typedef Hexahedron20      QuadraticHexahedron;


JIVE_END_PACKAGE( geom )

#endif