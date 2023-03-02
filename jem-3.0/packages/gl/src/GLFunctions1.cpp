
/*
 *  Copyright (C) 2019 DRG. All rights reserved.
 *
 *  This file is part of Jem, a general purpose programming toolkit.
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
 *
 *  Jem version: 3.0
 *  Date:        Fri 20 Dec 14:27:58 CET 2019
 */


#include <jem/gl/GLFunctions1.h>
#include "ftable/GLFuncTables.h"


JEM_BEGIN_PACKAGE( gl )


//=======================================================================
//   class GLFunctions1Core
//=======================================================================

//-----------------------------------------------------------------------
//   constructor & destructor
//-----------------------------------------------------------------------


GLFunctions1Core::GLFunctions1Core ( GLFuncTables& tables )
{
  table_ = tables.get ( tables.funcs1Core );
}


GLFunctions1Core::~GLFunctions1Core ()
{}


//-----------------------------------------------------------------------
//   glGetString
//-----------------------------------------------------------------------


String GLFunctions1Core::glGetString ( GLenum name )
{
  return jem::clone ( (const char*) table_->glGetString( name ) );
}


//=======================================================================
//   class GLFunctions1Compat
//=======================================================================

//-----------------------------------------------------------------------
//   constructor & destructor
//-----------------------------------------------------------------------


GLFunctions1Compat::GLFunctions1Compat ( GLFuncTables& tables )
{
  table_ = tables.get ( tables.funcs1Compat );
}


GLFunctions1Compat::~GLFunctions1Compat ()
{}


//=======================================================================
//   class GLFunctions1
//=======================================================================

//-----------------------------------------------------------------------
//   constructor
//-----------------------------------------------------------------------


GLFunctions1::GLFunctions1 ( GLFuncTables& tables ) :

  GLFunctions1Core   ( tables ),
  GLFunctions1Compat ( tables )

{}


JEM_END_PACKAGE( gl )
