
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

#ifndef JIVE_GEOM_STDSHAPE_H
#define JIVE_GEOM_STDSHAPE_H

#include <jem/base/Object.h>
#include <jem/util/event/Event.h>
#include <jive/Array.h>


JIVE_BEGIN_PACKAGE( geom )


using jem::util::Event;


//-----------------------------------------------------------------------
//   class StdShape
//-----------------------------------------------------------------------


class StdShape : public Object
{
 public:

  JEM_DECLARE_CLASS       ( StdShape, Object );

  typedef const void*       ExtensionID;

  Event < Self& >           changeEvent;


  virtual idx_t             rank             () const = 0;
  virtual idx_t             shapeFuncCount   () const = 0;
  virtual String            getGeometry      () const = 0;
  virtual bool              isLinear         () const;
  virtual idx_t             vertexCount      () const;
  virtual Matrix            getVertexCoords  () const;

  virtual bool              containsPoint

    ( const Vector&           u )               const = 0;

  virtual bool              clipPoint

    ( const Vector&           u )               const = 0;

  virtual void              evalShapeFunctions

    ( const Vector&           f,
      const Vector&           u )               const = 0;

  virtual void              evalShapeGradients

    ( const Vector&           f,
      const Matrix&           g,
      const Vector&           u )               const = 0;

  virtual void              evalShapeGradGrads

    ( const Vector&           f,
      const Matrix&           g,
      const Matrix&           h,
      const Vector&           u )               const = 0;

  virtual void*             getExtByID

    ( ExtensionID             extID )           const;

  template <class Ext>
    inline bool             hasExtension     () const;

  template <class Ext>
    inline Ext*             getExtension     () const;


 protected:

  virtual                  ~StdShape         ();

};


//-----------------------------------------------------------------------
//   related types and functions
//-----------------------------------------------------------------------


typedef StdShape            SShape;




//#######################################################################
//   Implementation
//#######################################################################

//-----------------------------------------------------------------------
//   hasExtension
//-----------------------------------------------------------------------


template <class Ext>

  inline bool StdShape::hasExtension () const

{
  return getExtByID ( Ext::ID );
}


//-----------------------------------------------------------------------
//   getExtension
//-----------------------------------------------------------------------


template <class Ext>

  inline Ext* StdShape::getExtension () const

{
  return static_cast<Ext*> ( getExtByID( Ext::ID ) );
}


JIVE_END_PACKAGE( geom )

#endif
