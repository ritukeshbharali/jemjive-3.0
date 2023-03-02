
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

#ifndef JIVE_APP_ROOTONLYMODULE_H
#define JIVE_APP_ROOTONLYMODULE_H

#include <jive/app/typedefs.h>
#include <jive/app/Module.h>


JIVE_BEGIN_PACKAGE( app )


//-----------------------------------------------------------------------
//   class RootOnlyModule
//-----------------------------------------------------------------------


class RootOnlyModule : public Module
{
 public:

  JEM_DECLARE_CLASS       ( RootOnlyModule, Module );

  static const char*        TYPE_NAME;


  explicit                  RootOnlyModule

    ( const Ref<Module>&      child );

  virtual Status            init

    ( const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat )              override;

  virtual Status            run

    ( const Properties&       globdat )              override;

  virtual void              shutdown

    ( const Properties&       globdat )              override;

  virtual void              configure

    ( const Properties&       conf,
      const Properties&       globdat )              override;

  virtual void              getConfig

    ( const Properties&       props,
      const Properties&       globdat )        const override;

  virtual bool              takeAction

    ( const String&           action,
      const Properties&       params,
      const Properties&       globdat )              override;

  static Ref<Module>        makeNew

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat );

  static void               declare         ();


 protected:

  virtual                  ~RootOnlyModule  ();


 private:

  static const char*        ROOT_CONTEXT_;

  Ref<Module>               child_;
  int                       myRank_;

  Ref<MPContext>            origContext_;
  Ref<MPContext>            rootContext_;

};


//-----------------------------------------------------------------------
//   related functions
//-----------------------------------------------------------------------


inline Ref<Module>          rootOnly

  ( const Ref<Module>&        mod );




//#######################################################################
//   Implementation
//#######################################################################

//-----------------------------------------------------------------------
//   rootOnly
//-----------------------------------------------------------------------


inline Ref<Module> rootOnly ( const Ref<Module>& mod )
{
  return jem::newInstance<RootOnlyModule> ( mod );
}


JIVE_END_PACKAGE( app )

#endif
