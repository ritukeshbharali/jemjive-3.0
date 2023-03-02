
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

#ifndef JEM_NET_NATIVE_POSIXSERVER_H
#define JEM_NET_NATIVE_POSIXSERVER_H

#include <jem/util/Flex.h>
#include <jem/net/Socket.h>
#include "NativeAddress.h"

extern "C"
{
  #include <poll.h>
}


JEM_BEGIN_PACKAGE( net )


//-----------------------------------------------------------------------
//   class NativeServer
//-----------------------------------------------------------------------


class NativeServer : public Object
{
 public:

  typedef Object          Super;
  typedef NativeServer    Self;


                          NativeServer  ();

  idx_t                   listen

    ( const NativeAddress&  addr,
      int                   backlog );

  Ref<Socket>             accept

    ( idx_t                 idx );

  void                    close

    ( idx_t                 idx );

  idx_t                   poll

    ( const Time&           timeout );

  inline bool             isListening   () const;

  inline bool             isListening

    ( idx_t                 idx )          const;

  Ref<SocketAddress>      getLocalAddress

    ( idx_t                 idx )          const;


 protected:

  virtual                ~NativeServer  ();


 private:

  typedef struct pollfd   pollfd_t;

  util::Flex<pollfd_t>    socks_;
  util::Flex<idx_t>       iperm_;
  idx_t                   openc_;

};


//#######################################################################
//  implementation
//#######################################################################

//-----------------------------------------------------------------------
//   isListening
//-----------------------------------------------------------------------


inline bool NativeServer::isListening () const
{
  return (openc_ > 0);
}


inline bool NativeServer::isListening ( idx_t idx ) const
{
  return ((idx            >= 0)             &&
          (idx            <  socks_.size()) &&
          (socks_[idx].fd >= 0));
}


JEM_END_PACKAGE( net )

#endif

