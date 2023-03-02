
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


#include <jem/crypto/CipherContext.h>
#include <jem/crypto/native/CryptoLib.h>


JEM_BEGIN_PACKAGE( crypto )


//=======================================================================
//   class CipherContext
//=======================================================================

//-----------------------------------------------------------------------
//   constructor & destructor
//-----------------------------------------------------------------------


CipherContext::CipherContext ()
{
  context_ = EVP_CIPHER_CTX_new ();
  started_ = false;

  if ( ! context_ )
  {
    CryptoLib::raiseError (
      JEM_FUNC,
      "cipher context allocation failed"
    );
  }
}


CipherContext::~CipherContext ()
{
  if ( context_ )
  {
    EVP_CIPHER_CTX_free ( JEM_CIPHER_CTX_CAST( context_ ) );

    context_ = nullptr;
  }
}


//-----------------------------------------------------------------------
//   sizeHint
//-----------------------------------------------------------------------


idx_t CipherContext::sizeHint ( idx_t size ) const noexcept
{
  return (size + 2 * EVP_MAX_BLOCK_LENGTH);
}


JEM_END_PACKAGE( crypto )

