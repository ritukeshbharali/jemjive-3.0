
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

#ifndef JIVE_GL_MARKERSTYLETABLE_H
#define JIVE_GL_MARKERSTYLETABLE_H

#include <jem/base/Object.h>
#include <jem/gl/MarkerStyle.h>
#include <jive/Array.h>
#include <jive/gl/import.h>


namespace jem
{
  namespace util
  {
    class Dictionary;
  }
}


JIVE_BEGIN_PACKAGE( gl )


//-----------------------------------------------------------------------
//   class MarkerStyleTable
//-----------------------------------------------------------------------


class MarkerStyleTable : public Object
{
 public:

  JEM_DECLARE_CLASS       ( MarkerStyleTable, Object );

  typedef
    jem::gl::MarkerStyle    Style;

  typedef Ref<Style>      (*StyleCtor)        ();


                            MarkerStyleTable  ();

  void                      configure

    ( const Properties&       props );

  void                      getConfig

    ( const Properties&       props )            const;

  void                      clear             ();

  void                      addStyle

    ( const String&           name,
      const Ref<Style>&       style );

  void                      addStyles

    ( const StringVector&     names,
      const Properties&       conf,
      const Properties&       props );

  Ref<Style>                findStyle

    ( const String&           name )             const;

  Ref<Style>                getStyle

    ( const String&           name,
      const String&           context )          const;

  StringVector              listStyles        () const;

  static Ref<Self>          get

    ( const Properties&       viewdat );

  static void               declareStyle

    ( const String&           type,
      StyleCtor               ctor );

  static StringVector       listStyleTypes    ();

  static Ref<Style>         newStyle

    ( const String&           type );

  static Ref<Style>         newStyle

    ( const Properties&       conf,
      const Properties&       props );


 protected:

  virtual                  ~MarkerStyleTable  ();


 private:

  static void               initOnce_         ();


 private:

  typedef jem::
    util::Dictionary        Dict_;

  class                     CtorMap_;

  Ref<Dict_>                styles_;

};


JIVE_END_PACKAGE( gl )

#endif
