
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

#ifndef JIVE_ALGEBRA_FORWARD_H
#define JIVE_ALGEBRA_FORWARD_H

#include <jive/defines.h>


JIVE_BEGIN_PACKAGE( algebra )


class                     AbstractMatrix;
class                     ClassicalGramSchmidt;
class                     ConDistiller;
class                     ConMatrixBuilder;
class                     ConstrainedMatrix;
class                     DenseMatrixObject;
class                     DiagMatrixExtension;
class                     DiagMatrixObject;
class                     DirectMatrixExtension;
class                     FlexMatrixBuilder;
class                     GramSchmidt;
class                     GramSchmidtFactory;
class                     IdentMatrixObject;
class                     IteratedGramSchmidt;
class                     LumpedMatrixBuilder;
class                     MPMatrixExtension;
class                     MPMatrixObject;
class                     MPVectorSpace;
class                     MatrixBuilder;
class                     ModifiedGramSchmidt;
class                     MultiMatmulExtension;
class                     NullMatrixObject;
class                     SparseMatrixBuilder;
class                     SparseMatrixExtension;
class                     SparseMatrixObject;
class                     StdVectorSpace;
class                     VectorSpace;

typedef                   SparseMatrixObject      SparseMatrixObj;
typedef                   NullMatrixObject        NullMatrixObj;
typedef                   MPMatrixObject          MPMatrixObj;
typedef                   IdentMatrixObject       IdentMatrixObj;
typedef                   DiagMatrixObject        DiagMatrixObj;
typedef                   DenseMatrixObject       DenseMatrixObj;
typedef                   MatrixBuilder           MBuilder;
typedef                   FlexMatrixBuilder       FlexMBuilder;
typedef                   SparseMatrixBuilder     SparseMBuilder;
typedef                   LumpedMatrixBuilder     LumpedMBuilder;
typedef                   MPMatrixExtension       MPMatrixExt;
typedef                   DiagMatrixExtension     DiagMatrixExt;
typedef                   MultiMatmulExtension    MultiMatmulExt;
typedef                   DirectMatrixExtension   DirectMatrixExt;
typedef                   SparseMatrixExtension   SparseMatrixExt;
typedef                   GramSchmidtFactory      GSFactory;
typedef                   ClassicalGramSchmidt    ClassicalGS;
typedef                   ModifiedGramSchmidt     ModifiedGS;
typedef                   IteratedGramSchmidt     IteratedGS;


JEM_END_PACKAGE( algebra )

#endif
