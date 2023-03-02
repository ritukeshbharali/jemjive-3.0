
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


#include <jem/base/ClassTemplate.h>
#include <jive/gl/Plugin.h>


JEM_DEFINE_CLASS( jive::gl::Plugin );


JIVE_BEGIN_PACKAGE( gl )


//=======================================================================
//   class Plugin
//=======================================================================

//-----------------------------------------------------------------------
//   constructor & destructor
//-----------------------------------------------------------------------


Plugin::Plugin ( const String& name ) :

  Super ( name )

{}


Plugin::~Plugin ()
{}


//-----------------------------------------------------------------------
//   shutdown
//-----------------------------------------------------------------------


void Plugin::shutdown

  ( const Properties&  viewdat,
    const AppContext&  apx )

{}


//-----------------------------------------------------------------------
//   configure
//-----------------------------------------------------------------------


void Plugin::configure

  ( const Properties&  props,
    const Properties&  viewdat,
    const AppContext&  apx )

{}


//-----------------------------------------------------------------------
//   getConfig
//-----------------------------------------------------------------------


void Plugin::getConfig ( const Properties& props ) const
{}


//-----------------------------------------------------------------------
//   printHelp
//-----------------------------------------------------------------------


void Plugin::printHelp ( PrintWriter& pr ) const
{}


//-----------------------------------------------------------------------
//   getContext
//-----------------------------------------------------------------------


String Plugin::getContext () const
{
  return NamedObject::makeContext ( "plugin", myName_ );
}


JIVE_END_PACKAGE( gl )