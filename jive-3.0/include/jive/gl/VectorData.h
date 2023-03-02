
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

#ifndef JIVE_GL_VECTORDATA_H
#define JIVE_GL_VECTORDATA_H

#include <jive/gl/AppRef.h>
#include <jive/gl/DataSet.h>


JIVE_BEGIN_PACKAGE( gl )


//-----------------------------------------------------------------------
//   class VectorData
//-----------------------------------------------------------------------


class VectorData : public DataSet
{
 public:

  JEM_DECLARE_CLASS       ( VectorData, DataSet );

  static const char*        TYPE_NAME;


                            VectorData

    ( const String&           name,
      const String&           vpath = "state" );

                            VectorData

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props );

  virtual void              update

    ( const Properties&       globdat,
      const AppContext&       apx )                override;

  virtual void              configure

    ( const Properties&       props,
      const Properties&       globdat,
      const AppContext&       apx )                override;

  virtual void              getConfig

    ( const Properties&       props )        const override;

  virtual idx_t             rowCount

    ( const AppContext&       apx )          const override;

  virtual idx_t             columnCount

    ( const AppContext&       apx )          const override;

  virtual idx_t             findColumn

    ( const String&           name,
      const AppContext&       apx )          const override;

  virtual ItemSet*          getItems

    ( const AppContext&       apx )          const override;

  virtual void              getData

    ( const Matrix&           buf,
      const IdxVector&        irows,
      const IdxVector&        jcols,
      const AppContext&       apx )          const override;

  static Ref<DataSet>       makeNew

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat,
      const AppContext&       apx );

  static void               declare       ();


 protected:

  virtual                  ~VectorData    ();


 private:

  void                      setPath_

    ( const String&           vpath,
      const AppContext&       apx );

  void                      getDofSpace_

    ( const Properties&       globdat,
      const AppContext&       apx );

  void                      invalidate_   ();


 private:

  String                    vpath_;
  String                    vname_;

  AppRef<DofSpace>          dofs_;
  Vector                    vdata_;

  double                    nullValue_;
  bool                      updated_;

};


JIVE_END_PACKAGE( gl )

#endif
