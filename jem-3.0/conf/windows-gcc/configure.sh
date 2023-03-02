
#========================================================================
#   Functions
#========================================================================

#------------------------------------------------------------------------
#   ConfigureWindowsGCC_ia32 ()
#------------------------------------------------------------------------


ConfigureWindowsGCC_ia32()
{
  local march="$(uname -m)"
  local mtune=""
  local mmath=""

  case "$march" in

    i486|i586|i686) ;;

    x86_64)   march="i686" ;;

    *)        march="i486" ;;

  esac

  mtune=$march

  if [ $CXX_VERSION -ge 30100 ]; then

    if   [ $CXX_VERSION -ge 40200 ]; then
      mtune="-mtune=native"
    elif [ $CXX_VERSION -gt 30400 ]; then
      mtune="-mtune=$mtune"
    else
      mtune="-mcpu=$mtune"
    fi

    CXX_STD_FLAGS="$CXX_STD_FLAGS -march=$march $mtune $mmath"

  fi
}


#------------------------------------------------------------------------
#   ConfigureWindowsGCC_x86_64
#------------------------------------------------------------------------


ConfigureWindowsGCC_x86_64()
{
  local mtune=""
  local mbits=""

  if [ -z "$USR_BIT_MODE" ]; then
    mbits="-m64"
  else
    mbits="-m$USR_BIT_MODE"
  fi

  printf "Testing if g++ supports the \`$mbits' option ... "

  if TestCompiler "$CXX" "$mbits" ; then

    echo "yes."

    CXX_STD_FLAGS="$CXX_STD_FLAGS $mbits"

  else

    echo "no."

    mbits=""

  fi

  case "$mbits" in

    -m64)

      SYS_BITS=64
      CXX_STD_FLAGS="$CXX_STD_FLAGS -msse2"

      LogEcho "Compiling in 64-bit mode" \
              "(specify \`-32' for 32-bit mode)." ;;

    -m32)

      SYS_BITS=32

      LogEcho "Compiling in 32-bit mode" \
              "(specify \`-64' for 64-bit mode)."

      ConfigureWindowsGCC_ia32 ;;

    *)

      LogEcho "Compiling in the default bit mode." ;;

  esac

  if [ "$SYS_BITS" = "64" ] && [ $CXX_VERSION -gt 30400 ]; then

    if [ $CXX_VERSION -ge 40200 ]; then
      mtune=native
    fi

    if [ -n "$mtune" ]; then
      CXX_STD_FLAGS="$CXX_STD_FLAGS -mtune=$mtune"
    fi

  fi

  CXX_BIT_MODE=""
}


#------------------------------------------------------------------------
#   ConfigureWindowsGCC ()
#------------------------------------------------------------------------


ConfigureWindowsGCC()
{
  local oflags="-DNDEBUG -funroll-loops"

  CXX_LNK_FLAGS=""
  CXX_DBG_FLAGS="-g"
  CXX_PRF_FLAGS="-pg"
  CXX_OPT_LEVEL="3"
  CXX_BLD_FLAGS="-Wconversion"
  CXX_OPT_FLAGS1="-O1 $oflags"
  CXX_OPT_FLAGS2="-O2 $oflags"
  CXX_OPT_FLAGS3="-O3 $oflags"

  if [ "xx$CXX_NAME2" != "xxclang" ]; then

    CXX_BLD_FLAGS="$CXX_BLD_FLAGS -finline-functions"

    if [ $CXX_VERSION -ge 50000 ]; then
      CXX_BLD_FLAGS="$CXX_BLD_FLAGS -Wsuggest-override"
    fi

  fi

  if [ $CXX_VERSION -ge 40000 ]; then

    LogEcho "Enabled vectorization support."

    CXX_OPT_FLAGS3="$CXX_OPT_FLAGS3 -ftree-vectorize"

  fi

  if [ -z "$USR_CXX_FLAGS" ]; then

    CXX_STD_FLAGS="-O -Wall -fstrict-aliasing"

    case "$SYS_ARCH" in

      ia32)    ConfigureWindowsGCC_ia32 ;;

      x86_64)  ConfigureWindowsGCC_x86_64 ;;

    esac

  fi

  if [ $CXX_VERSION -lt 60100 ]; then
    CXX_STD_FLAGS="$CXX_STD_FLAGS -std=c++11"
  fi

  # Link with the math library.

  SYS_LIBS="$SYS_LIBS m"

  # Search for a special version of `ar'.

  AR=$(echo "$CXX" | sed -e "s/g[+][+]/ar/")

  if FindExe -s "$AR"; then
    AR="$AR -ruc"
  else
    AR="ar -ruc"
  fi
}


#========================================================================
#   Main script
#========================================================================

if [ "xx$CXX_NAME2" = "xxclang" ]; then
  echo "Configuring for the GNU compiler (g++ [clang])."
else
  echo "Configuring for the GNU compiler (g++)."
fi

ConfigureWindowsGCC
