
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


#include <jem/base/limits.h>
#include <jem/crypto/CryptKey.h>
#include <jem/crypto/DecryptContext.h>
#include <jem/crypto/native/CryptoLib.h>


JEM_BEGIN_PACKAGE( crypto )


//=======================================================================
//   class DecryptContext
//=======================================================================

//-----------------------------------------------------------------------
//   destructor
//-----------------------------------------------------------------------


DecryptContext::~DecryptContext ()
{}


//-----------------------------------------------------------------------
//   start
//-----------------------------------------------------------------------


void DecryptContext::start

  ( Cipher::Type     type,
    const CryptKey&  key )

{
  JEM_PRECHECK ( key.isSuitable( type ) );

  int  rv;

  rv = EVP_DecryptInit (
    JEM_CIPHER_CTX_CAST  ( context_ ),
    CryptoLib::getCipher ( type ),
    key.getKeyAddr       (),
    key.getIVAddr        ()
  );

  if ( 1 != rv )
  {
    CryptoLib::raiseError (
      JEM_FUNC,
      "decryption start failed"
    );
  }

  started_ = true;
}


//-----------------------------------------------------------------------
//   update
//-----------------------------------------------------------------------


idx_t DecryptContext::update

  ( void*        dest,
    const void*  data,
    idx_t        size )

{
  JEM_PRECHECK ( started() );
  JEM_PRECHECK ( size >= 0 );

  EVP_CIPHER_CTX*  ctx = JEM_CIPHER_CTX_CAST ( context_ );
  idx_t            len = 0;


  while ( size )
  {
    int  k = (int) jem::min ( (idx_t) maxOf<int>(), size );
    int  n = 0;

    if ( 1 != EVP_DecryptUpdate( ctx, (byte*)  dest, &n,
                                 (const byte*) data,  k ) )
    {
      CryptoLib::raiseError (
        JEM_FUNC,
        "decryption update failed"
      );
    }

    size -= (idx_t) k;
    len  += (idx_t) n;
    dest  = (byte*)       dest + n;
    data  = (const byte*) data + k;
  }

  return len;
}


//-----------------------------------------------------------------------
//   finish
//-----------------------------------------------------------------------


idx_t DecryptContext::finish

  ( void*        dest,
    const void*  data,
    idx_t        size )

{
  EVP_CIPHER_CTX*  ctx   = JEM_CIPHER_CTX_CAST ( context_ );
  idx_t            count = update ( dest, data, size );
  int              len   = 0;

  dest = (byte*) dest + count;

  if ( 1 != EVP_DecryptFinal( ctx, (byte*) dest, &len ) )
  {
    CryptoLib::raiseError (
      JEM_FUNC,
      "decryption finalization failed"
    );
  }

  started_ = false;

  return (count + (idx_t) len);
}


//-----------------------------------------------------------------------
//   decrypt_
//-----------------------------------------------------------------------


void DecryptContext::decrypt_

  ( ByteVector&      out,
    Cipher::Type     type,
    const CryptKey&  key,
    const void*      data,
    idx_t            size )

{
  Ref<DecryptContext>  ctx = newInstance<DecryptContext> ();

  ctx->start ( type, key );
  out.ref    ( ctx->finish<ByteVector>( data, size ) );
}


void DecryptContext::decrypt_

  ( String&          out,
    Cipher::Type     type,
    const CryptKey&  key,
    const void*      data,
    idx_t            size )

{
  Ref<DecryptContext>  ctx = newInstance<DecryptContext> ();

  ctx->start ( type, key );

  out = ctx->finish<String> ( data, size );
}


JEM_END_PACKAGE( crypto )

