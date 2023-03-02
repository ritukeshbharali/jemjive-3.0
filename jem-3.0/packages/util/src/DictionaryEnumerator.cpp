
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


#include <jem/base/rtti.h>
#include <jem/base/ClassTemplate.h>
#include <jem/base/IllegalOperationException.h>
#include <jem/util/ObjectPair.h>
#include <jem/util/DictionaryEnumerator.h>


JEM_DEFINE_CLASS( jem::util::DictionaryEnumerator );


JEM_BEGIN_PACKAGE( util )


//=======================================================================
//   class DictionaryEnumerator
//=======================================================================

//-----------------------------------------------------------------------
//   destructor
//-----------------------------------------------------------------------


DictionaryEnumerator::~DictionaryEnumerator ()
{}


//-----------------------------------------------------------------------
//   get
//-----------------------------------------------------------------------


Ref<Object> DictionaryEnumerator::get () const
{
  return newInstance<ObjPair> ( toObject( getKey() ), getValue() );
}


//-----------------------------------------------------------------------
//   atEndError_
//-----------------------------------------------------------------------


void DictionaryEnumerator::atEndError_ () const
{
  Class*  type = getClass ();

  throw IllegalOperationException (
    type->getName (),
    "enumerator is at the end of its dictionary"
  );
}


JEM_END_PACKAGE( util )