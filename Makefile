#Makefile for spiralPDF and reliant .o files

CC = g++ -std=c++11
CFLAGS = -Wall
LIBHARU = ./libharu

spiralPDF.o: spiralPDF.cpp Spiral.o HaruPDF.o $(LIBHARU)/src/libhpdfs.a
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c spiralPDF.cpp -L$(LIBHARU)/src/ -lhpdfs -lz

Spiral.o: Spiral.cpp Spiral.h
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o: HaruPDF.cpp HaruPDF.h $(LIBHARU)/src/libhpdfs.a
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -c HaruPDF.cpp -L$(LIBHARU)/src/ -lhpdfs -lz

spiralPDF: Spiral.o spiralPDF.o HaruPDF.o
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -o spiralPDF Spiral.o spiralPDF.o HaruPDF.o -L$(LIBHARU)/src/ -lhpdfs -lz

clean:
	rm -f *.o *.a *.pdf spiralPDF
