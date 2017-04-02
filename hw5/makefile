
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g

hw5: catalog.o transcript.o prompts.o hw5.o
	$(CC) $(CFLAGS) -o hw5 hw5.o catalog.o transcript.o prompts.o

hw5.o: hw5.c hw5.h catalog.h transcript.h
	$(CC) $(CFLAGS) -c hw5.c

catalog.o: catalog.c catalog.h
	$(CC) $(CFLAGS) -c catalog.c

transcript.o: catalog.o catalog.h transcript.c transcript.h
	$(CC) $(CFLAGS) -c transcript.c

prompts.o: prompts.c prompts.h
	$(CC) $(CFLAGS) -c prompts.c





#unittest.o: unittest.c dnasearch.h
#	$(CC) $(CFLAGS) -c unittest.c

# Links the test executable
#unittest: unittest.o dnasearch.o
#	$(CC) $(CFLAGS) -o unittest unittest.o dnasearch.o

# 'make clean' will remove intermediate & executable files
clean:
	rm -f *.o unittest hw5

