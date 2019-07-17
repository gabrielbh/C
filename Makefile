CC=g++
CXX=g++
RANLIB=ranlib
LSRC=osm.cpp
LOBJ=$(LSRC:.cpp=.o)
INCS=-I.
CFLG = -Wall -std=c++11 -g $(INCS)
CXXFLG = -Wall -std=c++11 -g $(INCS)

LIBOSM = libosm.a
TARGETS = $(LIBOSM)

TAR=tar
TARFLG=-cvf
TARNAME=ex1.tar


all: libosm.a

#Library
libosm.a: osm.o
	ar -rcs libosm.a osm.o


#Compiling
osm.o: osm.cpp osm.h
	$(CC) $(CFLG) -c osm.cpp


clean:
	$(RM) -f *.o
	$(RM) libosm.a
	$(RM) ex1.tar

depend:
	makedepend -- $(CFLG) -- $(SRC) $(LSRC)

tar:
	$(TAR) $(TARFLG) $(TARNAME) osm.cpp Makefile README
