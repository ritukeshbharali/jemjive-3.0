
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

#ifndef JIVE_MESH_DUMMYGEOMETRY_H
#define JIVE_MESH_DUMMYGEOMETRY_H

#include <jive/mesh/Geometry.h>


JIVE_BEGIN_PACKAGE( mesh )


//-----------------------------------------------------------------------
//   class DummyGeometry
//-----------------------------------------------------------------------


class DummyGeometry : public Geometry
{
 public:

  JEM_DECLARE_CLASS       ( DummyGeometry, Geometry );

  static const char*        TYPE_NAME;


  explicit                  DummyGeometry

    ( const String&           name = "dummy" );

  virtual idx_t             rank          () const override;

  virtual void              makeMesh

    ( const XMesh&            mesh,
      const Params&           params )             override;

  static void               declare       ();

  static Ref<Geometry>      makeNew

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat );


 protected:

  virtual                  ~DummyGeometry ();

};


JIVE_END_PACKAGE( mesh )

#endif
