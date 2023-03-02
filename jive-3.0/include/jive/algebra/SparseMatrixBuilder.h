
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

#ifndef JIVE_ALGEBRA_SPARSEMATRIXBUILDER_H
#define JIVE_ALGEBRA_SPARSEMATRIXBUILDER_H

#include <jive/SparseMatrix.h>
#include <jive/algebra/import.h>
#include <jive/algebra/typedefs.h>
#include <jive/algebra/MatrixBuilder.h>


JIVE_BEGIN_PACKAGE( algebra )


//-----------------------------------------------------------------------
//   class SparseMatrixBuilder
//-----------------------------------------------------------------------


class SparseMatrixBuilder : public MatrixBuilder
{
 public:

  JEM_DECLARE_CLASS       ( SparseMatrixBuilder, MatrixBuilder );


  explicit                  SparseMatrixBuilder

    ( const String&           name = "",
      Ref<SparseMatrixObj>    mat  = nullptr );

  virtual void              clear               ()       override;

  virtual void              scale

    ( double                  factor )                   override;

  virtual void              setToZero           ()       override;
  virtual void              updateMatrix        ()       override;

  virtual void              setMultiplier

    ( double                  x )                        override;

  virtual double            getMultiplier       () const override;

  virtual void              setData

    ( const idx_t*            irows,
      idx_t                   icount,
      const idx_t*            jcols,
      idx_t                   jcount,
      const double*           values )                   override;

  virtual void              addData

    ( const idx_t*            irows,
      idx_t                   icount,
      const idx_t*            jcols,
      idx_t                   jcount,
      const double*           values )                   override;

  virtual idx_t             eraseData

    ( const idx_t*            irows,
      idx_t                   icount,
      const idx_t*            jcols,
      idx_t                   jcount )                   override;

  virtual void              getData

    ( double*                 buf,
      const idx_t*            irows,
      idx_t                   icount,
      const idx_t*            jcols,
      idx_t                   jcount )             const override;

  virtual AbstractMatrix*   getMatrix           () const override;
  SparseMatrixObj*          getSparseMatrix     () const;

  virtual void              setStructure

    ( const SparseStruct&     st );


 protected:

  virtual                  ~SparseMatrixBuilder ();


 private:

  void                      init_               ();
  void                      valuesChanged_      ();
  void                      structChanged_      ();

  inline void               checkRowIndex_

    ( idx_t                   irow )               const;

  void                      noSuchValueError_

    ( idx_t                   irow,
      idx_t                   jcol )               const;


 private:

  Ref<SparseMatrixObj>      output_;

  IdxVector                 rowOffsets_;
  IdxVector                 colIndices_;
  Vector                    values_;

  double                    multiplier_;
  idx_t                     rowCount_;
  idx_t                     colCount_;
  bool                      newValues_;
  bool                      newStruct_;

};


//-----------------------------------------------------------------------
//   related types
//-----------------------------------------------------------------------


typedef
  SparseMatrixBuilder       SparseMBuilder;


JIVE_END_PACKAGE( algebra )

#endif
