
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

#ifndef JEM_BASE_REFLECT_MEMBER_H
#define JEM_BASE_REFLECT_MEMBER_H

#include <jem/base/NamedObject.h>


JEM_BEGIN_PACKAGE_BASE


//-----------------------------------------------------------------------
//   class Member
//-----------------------------------------------------------------------


class Member : public NamedObject
{
 public:

  JEM_DECLARE_CLASS     ( Member, NamedObject );

  friend class            Class;


  explicit                Member

    ( const String&         name = "" );

  inline  Class*          getDeclaringClass   () const;
  virtual String          getContext          () const override;
  virtual bool            isStatic            () const = 0;


 protected:

  virtual                ~Member              ();


 private:

  Class*                  myClass_;

};



//#######################################################################
//   Implementation
//#######################################################################

//-----------------------------------------------------------------------
//   getDeclaringClass
//-----------------------------------------------------------------------


inline Class* Member::getDeclaringClass () const
{
  return myClass_;
}


JEM_END_PACKAGE_BASE

#endif