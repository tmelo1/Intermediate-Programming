CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g

hw6: hw6.o menuUtils.o
	$(CC) $(CFLAGS) -o hw6 hw6.o menuUtils.o ppmIO.o imageManip.o

hw6.o: hw6.c menuUtils.h
	$(CC) $(CFLAGS) -c hw6.c

menuUtils.o: ppmIO.o imageManip.o ppmIO.h imageManip.h menuUtils.h
	$(CC) $(CFLAGS) -c menuUtils.c 
	
ppmIO.o: ppmIO.h ppmIO.c
	$(CC) $(CFLAGS) -c ppmIO.c

imageManip.o: ppmIO.h imageManip.h ppmIO.o
	$(CC) $(CFLAGS) -c imageManip.c

clean:
	rm -f *.o unittest hw5