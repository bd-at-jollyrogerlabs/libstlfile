# $Id$

AC_PREREQ(2.59)
AC_INIT([libstlfile], [0.1.4])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([stl_file_parser_driver.cpp])
AC_CONFIG_AUX_DIR([scripts])

AM_INIT_AUTOMAKE([-Wall foreign])
AM_MAINTAINER_MODE

LT_PREREQ([2.2])
LT_INIT([disable-shared])

if test "$CFLAGS" == ""; then
    CFLAGS="-g -I/usr/include"
fi
if test "$CXXFLAGS" == ""; then
    CXXFLAGS="-g -I/usr/include"
fi

# enable full optimization by configure switch
AC_ARG_ENABLE(optimize,
	AS_HELP_STRING([--enable-optimize],
		       [Build with full optimization @<:@default=no@:>@]),
        [ case "${enableval}" in
          yes)
                CFLAGS="$CFLAGS -O3 -DNDEBUG";
                CXXFLAGS="$CXXFLAGS -O3 -DNDEBUG";
          ;;
          no) ;;
          *) AC_MSG_ERROR(bad value ${enableval} for --enable-optimize) ;;
          esac ],
        [ optimize=false ])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LEX

# Create Makefiles
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
