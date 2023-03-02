# Jem-Jive-3.0

The Jem and Jive libraries are general purpose C++ programming toolkit for solving partial differential equations (PDEs). They are developed and maintained by the [Dynaflow Research Group](https://dynaflow.com/).

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

## Support
For support, contact the [Dynaflow Research Group](https://dynaflow.com/).

## Contributing
Make a Pull Request.

## License
Jem and Jive libraries has been released by the [Dynaflow Research Group](https://dynaflow.com/) under the LGPL (GNU Lesser General Public License) license.