
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

#ifndef JEM_IO_BUFFEREDINPUTSTREAM_H
#define JEM_IO_BUFFEREDINPUTSTREAM_H

#include <jem/io/FilterInputStream.h>


JEM_BEGIN_PACKAGE( io )


//-----------------------------------------------------------------------
//   class BufferedInputStream
//-----------------------------------------------------------------------


class BufferedInputStream : public FilterInputStream
{
 public:

  typedef
    BufferedInputStream   Self;
  typedef
    FilterInputStream     Super;


  explicit                BufferedInputStream

    ( Ref<InputStream>      in,
      idx_t                 bufsize = -1 );

                          BufferedInputStream

    ( const Self&           rhs );

  virtual
    Ref<InputStream>      dup     ()  override;

  virtual idx_t           poll

    ( const Time&           timeout ) override;

  virtual idx_t           read

    ( void*                 buf,
      idx_t                 n )       override;

  virtual idx_t           skip

    ( idx_t                 n )       override;


 protected:

  virtual                ~BufferedInputStream ();


 private:

  void                    init_

    ( idx_t                 bufsize );


 private:

  static const byte       CANARY_VALUE_;

  byte*                   buffer_;
  idx_t                   bufsize_;
  idx_t                   first_;
  idx_t                   last_;

};


JEM_END_PACKAGE( io )

#endif
