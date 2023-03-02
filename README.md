![Ubuntu Build Status](https://github.com/ritukeshbharali/jemjive-3.0/actions/workflows/ci.yml/badge.svg)

# Jem-Jive-3.0

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/690c695e28384c4390a1038f3849fd92)](https://app.codacy.com/gh/ritukeshbharali/jemjive-3.0?utm_source=github.com&utm_medium=referral&utm_content=ritukeshbharali/jemjive-3.0&utm_campaign=Badge_Grade_Settings)

The Jem and Jive libraries are general purpose C++ programming toolkit for solving Partial Differential Equations (PDEs). They are developed and maintained by the [Dynaflow Research Group](https://dynaflow.com/).

This repository is an ***unofficial copy*** of the original software package, available at the Dynaflow [webpage](https://software.dynaflow.com/jive/).

*Note that the original library has been modified here!*

## Installation

 - Obtain a copy of the library (download or clone via git).
 - Install pre-requisites
   > (sudo) apt-get install build-essential g++ zlib1g-dev libreadline-dev freeglut3-dev
 - Unpack archives Jem and Jive (say, in /home/user/libraries/jemjive)
  - Enter jem directory and './configure'
  - *(for MPI version)   ./configure --with-mpi --mpi-incdirs=/usr/include/x86_64-linux-gnu/openmpi --mpi-libdirs=/usr/lib/x86_64-linux-gnu/openmpi/lib --mpi-libs="mpi_cxx mpi"*
  - 'make' the library
  - export JEMDIR='/home/user/libraries/jemjive/jem-3.0'
  - Enter Jive directory and './configure', and 'make' the library
  - export JIVEDIR='/home/user/libraries/jemjive/jive-3.0'

## (Apptainer) container for HPC systems

 - Install apptainer
   > (sudo) add-apt-repository -y ppa:apptainer/ppa && apt update && apt install -y apptainer
 - Go to ./apptainer directory
 - Install Jem-Jive in an Ubuntu environment
   > apptainer build jive30.sif jive30.def


## Support
For support, contact the [Dynaflow Research Group](https://dynaflow.com/).

## Contributing
Make a Pull Request.

## License
Jem and Jive libraries has been released by the [Dynaflow Research Group](https://dynaflow.com/) under the LGPL (GNU Lesser General Public License) license.