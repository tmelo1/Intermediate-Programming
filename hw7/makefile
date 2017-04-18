CC = g++
FLAGS = -Wall -Wextra -pedantic -std=c++11 -g

#hw4b_test: hw4b_test.o
#	$(CC) $(CFLAGS) -o hw4b_test hw4b_test.o

#hw4b_test.o: hw4b_test.cpp
#	$(CC) $(CFLAGS) -c hw4b_test.cpp

#hw7b: hw7b.o
#	$(CC) $(CFLAGS) -o hw4b hw4b.o

#hw4b.o: hw4b.cpp
#	$(CC) $(CFLAGS) -c hw4b.cpp

hw7a: hw7a.o models.o
	$(CC) $(FLAGS) -o hw7a hw7a.o models.o

#hw4a_test: hw4a_test.o
#	$(CC) $(CFLAGS) -o hw4a_test hw4a_test.o

#hw4a_test.o: hw4a_test.cpp
#	$(CC) $(CFLAGS) -c hw4a_test.cpp

hw7a.o: hw7a.cpp models.hpp
	$(CC) $(FLAGS) -c hw7a.cpp

models.o: models.hpp models.cpp
	$(CC) $(FLAGS) -c models.cpp

clean:
	rm -f *.o hw7a