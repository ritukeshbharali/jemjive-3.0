
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

#ifndef JIVE_FEM_MISC_TRANSPORTMODEL_H
#define JIVE_FEM_MISC_TRANSPORTMODEL_H

#include <jem/io/Serializable.h>
#include <jive/model/Model.h>
#include <jive/femodel/import.h>


JIVE_BEGIN_PACKAGE( femodel )


//-----------------------------------------------------------------------
//   class TransportModel
//-----------------------------------------------------------------------


class TransportModel : public Model, public Serializable
{
 public:

  JEM_DECLARE_CLASS       ( TransportModel, Model );


  static const char*        TYPE_NAME;
  static const char*        COORD_NAMES[3];


                            TransportModel  ();

                            TransportModel

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat );

  virtual void              readFrom

    ( ObjectInput&            in )                   override;

  virtual void              writeTo

    ( ObjectOutput&           out )            const override;

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

  static Ref<Model>         makeNew

    ( const String&           name,
      const Properties&       conf,
      const Properties&       props,
      const Properties&       globdat );


 protected:

  virtual                  ~TransportModel  ();


 private:

  void                      getIntVector_

    ( const Vector&           fint,
      const Vector&           state    )       const;

  void                      getMatrix0_

    ( MBuilder&               mbld,
      const Vector&           fint,
      const Vector&           state )          const;

  void                      getMatrix1_

    ( MBuilder&               mbld )           const;

  bool                      getTable_

    ( const Properties&       params,
      const Properties&       globdat )        const;

  void                      getNodeFluxes_

    ( XTable&                 fluxes,
      const Vector&           weights,
      const Vector&           state,
      const ItemGroup*        irows    )       const;


 private:

  Ref<IElement>             element_;
  Ref<ElemIter>             elemIter_;

  Ref<XDofSpace>            dofs_;
  String                    dofName_;
  idx_t                     dofType_;

  Ref<Table>                flowTable_;
  String                    flowName_;
  IdxVector                 flowCols_;
  Vector                    diffusion_;

};


JIVE_END_PACKAGE( fem )

#endif
