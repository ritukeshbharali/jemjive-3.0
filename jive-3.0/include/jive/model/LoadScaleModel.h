
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

#ifndef JIVE_MODEL_LOADSCALEMODEL_H
#define JIVE_MODEL_LOADSCALEMODEL_H

#include <jem/io/Serializable.h>
#include <jive/model/import.h>
#include <jive/model/Model.h>


JIVE_BEGIN_PACKAGE( model )


//-----------------------------------------------------------------------
//   class LoadScaleModel
//-----------------------------------------------------------------------


class LoadScaleModel : public Model,
                       public Serializable
{
 public:

  JEM_DECLARE_CLASS       ( LoadScaleModel, Model );

  static const char*        TYPE_NAME;


  explicit                  LoadScaleModel

    ( const String&           name     = "load",
      const String&           loadCase = "load",
      const Ref<Model>&       child    = nullptr );

  virtual void              readFrom

    ( ObjectInput&            in  )                  override;

  virtual void              writeTo

    ( ObjectOutput&           out )            const override;

  virtual Model*            findModel

    ( const String&           name )           const override;

  virtual void              configure

    ( const Properties&       props,
      const Properties&       globdat )              override;

  virtual void              getConfig

    ( const Properties&       props,
      const Properties&       globdat )        const override;

  virtual bool              takeAction

    ( const String&           action,
      const Properties&       params,
      const Properties&       globdat )              override;

  double                    getScaleFactor  () const;

  void                      setScaleFactor

    ( double                  scale );

  static Ref<Model>         makeNew

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat );

  static void               declare         ();


 protected:

  virtual                  ~LoadScaleModel  ();


 private:

  Ref<Model>                child_;
  String                    loadCase_;
  double                    loadScale_;

  Ref<Function>             scaleFunc_;

};


JIVE_END_PACKAGE( model )

#endif
