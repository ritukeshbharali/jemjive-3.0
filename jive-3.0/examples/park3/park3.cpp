
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


#include <jem/util/Properties.h>
#include <jive/app/ChainModule.h>
#include <jive/app/ExitModule.h>
#include <jive/app/ControlModule.h>
#include <jive/app/ReportModule.h>
#include <jive/app/Application.h>
#include <jive/app/InfoModule.h>
#include <jive/app/RootOnlyModule.h>
#include <jive/app/OutputModule.h>
#include <jive/app/UserconfModule.h>
#include <jive/fem/declare.h>
#include <jive/fem/ShapeModule.h>
#include <jive/fem/InputModule.h>
#include <jive/fem/InitModule.h>
#include <jive/fem/MPInputModule.h>
#include <jive/fem/PartitionModule.h>
#include <jive/model/declare.h>
#include <jive/femodel/declare.h>
#include <jive/mesh/declare.h>
#include <jive/mesh/MeshgenModule.h>
#include <jive/implict/Park3Module.h>
#include <jive/implict/LinsolveModule.h>
#include <jive/gl/declare.h>
#include <jive/gl/FemViewModule.h>


using jem::Ref;
using jem::util::Properties;
using jive::app::Module;


//=======================================================================
//   other functions
//=======================================================================

//-----------------------------------------------------------------------
//   mainModule
//-----------------------------------------------------------------------


Ref<Module> mainModule ()
{
  using jem::newInstance;
  using jive::app::rootOnly;
  using jive::app::ChainModule;
  using jive::app::ControlModule;
  using jive::app::ExitModule;
  using jive::app::ReportModule;
  using jive::app::InfoModule;
  using jive::app::OutputModule;
  using jive::app::UserconfModule;
  using jive::fem::ShapeModule;
  using jive::fem::InputModule;
  using jive::fem::InitModule;
  using jive::fem::MPInputModule;
  using jive::fem::PartitionModule;
  using jive::mesh::MeshgenModule;
  using jive::implict::Park3Module;
  using jive::implict::LinsolveModule;
  using jive::gl::FemViewModule;

  Ref<ChainModule>  chain = newInstance<ChainModule> ();


  jive::mesh    :: declareGeometries ();
  jive::fem     :: declareMBuilders  ();
  jive::model   :: declareModels     ();
  jive::femodel :: declareModels     ();
  jive::gl      :: declareModules    ();

  chain->pushBack (
    rootOnly      ( newInstance<MeshgenModule>   () )
  );

//  chain->pushBack ( newInstance<MeshgenModule>   () );

//  chain->pushBack ( newInstance<MPInputModule>   () );
  chain->pushBack ( newInstance<InputModule>     () );
  chain->pushBack ( newInstance<PartitionModule> () );

  chain->pushBack ( newInstance<ShapeModule>     ( "" ) );
  chain->pushBack ( newInstance<InitModule>      () );
  chain->pushBack ( newInstance<InfoModule>      () );
  chain->pushBack ( newInstance<ControlModule>   () );

  chain->pushBack (
    newInstance<Park3Module> (
      "park3",
      newInstance<LinsolveModule> ()
    )
  );

  chain->pushBack ( newInstance<FemViewModule>   () );
  chain->pushBack ( newInstance<OutputModule>    () );
  chain->pushBack ( newInstance<UserconfModule>  ( "extra" ) );

  return newInstance<ReportModule> ( "report", chain );
}


//-----------------------------------------------------------------------
//   main
//-----------------------------------------------------------------------


int main ( int argc, char** argv )
{
  using jive::app::Application;

  return Application::pexec ( argc, argv, & mainModule );
}
