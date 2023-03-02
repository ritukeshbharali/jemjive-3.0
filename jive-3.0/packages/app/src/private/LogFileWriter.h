
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

#ifndef JIVE_APP_PRIVATE_LOGFILEWRITER_H
#define JIVE_APP_PRIVATE_LOGFILEWRITER_H

#include <jem/io/FileFlags.h>
#include <jem/io/OutputStreamWriter.h>
#include <jive/app/import.h>


JIVE_BEGIN_PACKAGE( app )


using jem::io::OutputStreamWriter;


//-----------------------------------------------------------------------
//   class LogFileWriter
//-----------------------------------------------------------------------


class LogFileWriter : public OutputStreamWriter,
                      public jem::io::FileFlags
{
 public:

  JEM_DECLARE_CLASS     ( LogFileWriter, OutputStreamWriter );


                          LogFileWriter   ();

  explicit                LogFileWriter

    ( const String&         fname,
      OpenFlags             flags = 0 );

  virtual Ref<Writer>     dup             ()          override;
  virtual void            close           ()          override;

  virtual void            write

    ( int                   c )                       override;

  virtual void            write

    ( int                   c,
      idx_t                 n )                       override;

  virtual void            write

    ( const char*           buf,
      idx_t                 n )                       override;

  virtual void            writeNoThrow

    ( const char*           buf,
      idx_t                 n )              noexcept override;

  void                    reset           ();


 protected:

  virtual                ~LogFileWriter   ();


 private:

  const bool              stdout_;
  volatile byte           atStart_;

};


JIVE_END_PACKAGE( app )

#endif