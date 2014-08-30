LIBRARY_CURRENT_INTERFACE_VERSION = 0
LIBRARY_CURRENT_INTERFACE_REVISION = 0
LIBRARY_SUPPORTED_INTERFACE_AGE = 0

LIBRARY_VERSION = $(LIBRARY_CURRENT_INTERFACE_VERSION):$(LIBRARY_CURRENT_INTERFACE_REVISION):$(LIBRARY_SUPPORTED_INTERFACE_AGE)

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

libstlfile_la_LDFLAGS = -version-info $(LIBRARY_VERSION)

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
