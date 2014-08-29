# $Id$

AM_CFLAGS = -W -Wall -Wextra -ansi
AM_CXXFLAGS = -W -Wall -Wextra -ansi
ACLOCAL_AMFLAGS = -I m4

BUILT_SOURCES = \
	stl_parse.tab.cpp

BISON = /usr/bin/bison

lib_LTLIBRARIES = \
	libstlfile.la

libstlfile_la_SOURCES = \
	stl_parse.tab.cpp \
	stl_scan.lpp

include_HEADERS = \
	StlFileProcessor.h

bin_PROGRAMS = parsertest

parsertest_SOURCES = \
	parsertest.cpp

parsertest_LDADD = \
	libstlfile.la

stl_parse.tab.cpp: stl_parse.ypp
	$(BISON) -d $?

INTERMEDIATES = \
	stl_parse.tab.cpp \
	stl_parse.tab.hpp \
	stl_scan.cpp

extraclean:
	rm -f $(INTERMEDIATES)

rebuild: clean extraclean all
