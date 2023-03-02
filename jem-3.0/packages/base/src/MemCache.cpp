
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


#include <jem/base/assert.h>
#include <jem/base/thread/ThreadCache.h>
#include <jem/base/thread/ThreadLib.h>
#include <jem/base/MemCache.h>


JEM_BEGIN_PACKAGE_BASE


//=======================================================================
//   class MemCache
//=======================================================================

//-----------------------------------------------------------------------
//   alloc
//-----------------------------------------------------------------------


void* MemCache::alloc ( size_t size )
{
  ThreadLib::init ();

  return ThreadLib::getCache()->alloc ( size, CAN_THROW );
}


//-----------------------------------------------------------------------
//   allocNoThrow
//-----------------------------------------------------------------------


void* MemCache::allocNoThrow ( size_t size ) noexcept
{
  ThreadLib::init ();

  return ThreadLib::getCache()->alloc ( size, NO_THROW );
}


//-----------------------------------------------------------------------
//   dealloc
//-----------------------------------------------------------------------


void MemCache::dealloc

  ( void*   addr,
    size_t  size ) noexcept

{
  JEM_ASSERT_NOTHROW ( ThreadLib::initialized() );

  ThreadLib::getCache()->dealloc ( addr, size );
}


//-----------------------------------------------------------------------
//   realloc
//-----------------------------------------------------------------------

void* MemCache::realloc

  ( void*   addr,
    size_t  oldSize,
    size_t  newSize )

{
  JEM_ASSERT_NOTHROW ( ThreadLib::initialized() );

  return ThreadLib::getCache ()

    -> realloc ( addr, oldSize, newSize, CAN_THROW );
}


//-----------------------------------------------------------------------
//   reallocNoThrow
//-----------------------------------------------------------------------


void* MemCache::reallocNoThrow

  ( void*   addr,
    size_t  oldSize,
    size_t  newSize ) noexcept

{
  JEM_ASSERT_NOTHROW ( ThreadLib::initialized() );

  return ThreadLib::getCache ()

    -> realloc ( addr, oldSize, newSize, NO_THROW );
}


//-----------------------------------------------------------------------
//   setSize
//-----------------------------------------------------------------------


void MemCache::setSize ( size_t size )
{
  ThreadLib::init ();
  ThreadLib::getCache()->setSize ( size );
}


JEM_END_PACKAGE_BASE
