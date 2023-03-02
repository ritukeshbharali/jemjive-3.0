
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

#ifndef JIVE_SOLVER_FORWARD
#define JIVE_SOLVER_FORWARD

#include <jive/defines.h>


JIVE_BEGIN_PACKAGE( solver )


class                     AGMRES;
class                     CG;
class                     CoarseDofSpace;
class                     CoarseMatrix;
class                     CoarsePrecon;
class                     ConstrainedSolver;
class                     Constrainer;
class                     DenseRestrictor;
class                     DiagPrecon;
class                     DirectSolver;
class                     DualPrecon;
class                     DummyConstrainer;
class                     DummyPrecon;
class                     EigenSolver;
class                     FGMRES;
class                     GCR;
class                     GenericConstrainer;
class                     GMRES;
class                     IterativeSolverException;
class                     IterativeSolver;
class                     LocalRestrictor;
class                     LocalSolver;
class                     MPRestrictor;
class                     MultiRestrictor;
class                     NeumannPrecon;
class                     NullSpaceRestrictor;
class                     PointConstrainer;
class                     Preconditioner;
class                     Restrictor;
class                     RigidBodyRestrictor;
class                     SchurDofSpace;
class                     SchurMatrix;
class                     SchurRestrictor;
class                     SchurSolver;
class                     SimpleRestrictor;
class                     SkylineLU;
class                     SkylineSolver;
class                     SmoothRestrictor;
class                     SolverException;
class                     Solver;
class                     SolverPrecon;
class                     SparseIFactor;
class                     SparseILUd;
class                     SparseILUn;
class                     SparseLU;
class                     SparseRestrictor;
class                     StdConstrainer;
class                     StdIterativeSolver;
class                     SymdirEigenSolver;
class                     UserdefRestrictor;
class                     VerboseSolver;

typedef                   Preconditioner  Precon;


JEM_END_PACKAGE( solver )

#endif
