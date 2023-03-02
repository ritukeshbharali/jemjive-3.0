
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


#include <jem/base/utilities.h>
#include <jem/base/ClassTemplate.h>
#include <jem/io/File.h>
#include <jem/io/FileStream.h>
#include <jem/io/FileOutputStream.h>


JEM_DEFINE_CLASS( jem::io::FileOutputStream );


JEM_BEGIN_PACKAGE( io )


//=======================================================================
//   class FileOutputStream
//=======================================================================

//-----------------------------------------------------------------------
//   constructors & destructor
//-----------------------------------------------------------------------


FileOutputStream::FileOutputStream

  ( const String&  name,
    OpenFlags      flags )

{
  flags   &= ~FileFlags::READ;
  flags   |=  FileFlags::WRITE;

  fstream_ = File::open ( name, flags );
}


FileOutputStream::FileOutputStream ( Ref<FileStream> fs ) :

  fstream_ ( fs )

{
  JEM_PRECHECK ( fs );
}


FileOutputStream::FileOutputStream ( const Self& rhs ) :

  fstream_ ( rhs.fstream_->dup() )

{}


FileOutputStream::~FileOutputStream ()
{}


//-----------------------------------------------------------------------
//   dup
//-----------------------------------------------------------------------


Ref<OutputStream> FileOutputStream::dup ()
{
  return newInstance<Self> ( *this );
}


//-----------------------------------------------------------------------
//   close
//-----------------------------------------------------------------------


void FileOutputStream::close ()
{
  fstream_->close ();
}


//-----------------------------------------------------------------------
//   write
//-----------------------------------------------------------------------


void FileOutputStream::write

  ( const void*  buf,
    idx_t        n )

{
  fstream_->write ( buf, n );
}


//-----------------------------------------------------------------------
//   writeNoThrow
//-----------------------------------------------------------------------


void FileOutputStream::writeNoThrow

  ( const void*  buf,
    idx_t        n ) noexcept

{
  fstream_->writeNoThrow ( buf, n );
}


//-----------------------------------------------------------------------
//   getFileStream
//-----------------------------------------------------------------------


Ref<FileStream> FileOutputStream::getFileStream () const
{
  return fstream_;
}


JEM_END_PACKAGE( io )
