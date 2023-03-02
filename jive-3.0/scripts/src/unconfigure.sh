
. "${JEMDIR:?}/scripts/include/error.sh"
. "${JIVEDIR:?}/scripts/include/conf-utils.sh"

#========================================================================
#   Global variables
#========================================================================


VERBOSE=""


#========================================================================
#   Functions
#========================================================================

#------------------------------------------------------------------------
#   PrintHelp ()
#------------------------------------------------------------------------


PrintHelp()
{
  cat<<EOF

Usage: $(basename "$0") [OPTIONS]

Unconfigures the Jive toolkit.

Options:

  -h, --help    : show this help.
  -v, --verbose : show what is going on.

EOF
}


#------------------------------------------------------------------------
#   Run ( [%arg1 %arg2 ...] )
#------------------------------------------------------------------------


Run()
{
  local arg=""

  for arg in "$@" ; do

    case "$arg" in

      -h|--help)

        PrintHelp
        exit 0 ;;

      -v|--verbose)

        VERBOSE=1 ;;

      *)

        OptionError "$arg" ;;

    esac

  done

  UnconfigureJive

  if [ -n "$VERBOSE" ]; then
    echo "Done. Run \`\$JIVEDIR/configure' to configure Jive again."
  fi
}


#========================================================================
#   Main script
#========================================================================


Run "$@"
