#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* createArray(int size, int value);
void readArray (FILE *fp, int *newSize, int **newArray);
void printArrayImproved(FILE *outFile, int *array, int size);
int* my_realloc(int* ptr, int oldSize, int newSize);


int main(int argc, char* argv[]) {

  //Collect int values from command line to represent size and initialization value
  if (argc < 3) {
    printf("Too few command-line arguments.\nUsage: %s <size> <value>\n", argv[0]);
    return 1;
  }
  int size = atoi(argv[1]);
  int value = atoi(argv[2]);

  if (size < 1) {
    printf("Size argument %d too small.  Please run with size > 0.\n", size);
    return 1;
  }
  
  printf("Creating an array with %d elements all initialized to %d.\n\n", size, value);
  

  int* list;

  //Initialize list with array of size elements initialized to value
  list = createArray(size, value);

  //Output all of the values in the array that was created by the function
  printArrayImproved(stdout, list, size);

  int size2 = 0;
  int *list2 = NULL;
  // note that we use stdin as our filehandle, which means the function
  // will read input interactively; the function, however, shouldn't
  // care what filehandle it gets
  readArray(stdin, &size2, &list2);
  printArrayImproved(stdout, list2, size2);

  //Call my_realloc function to double list's size
  list = my_realloc(list, size, size*2);
  size *= 2;

  //Output all of the values in the array that was newly reallocated
  printArrayImproved(stdout, list, size);

  //Call my_realloc function to double array list2's size
  list2 = my_realloc(list2, size2, size2*2);
  size2 *= 2;
  
  //Output all of the values in the array that was newly reallocated
  printArrayImproved(stdout, list2, size2);

  //Call my_realloc function to cut list2's size to one-fourth
  list2 = my_realloc(list2, size2, size2/4);
  size2 /= 4;


  //Output all of the values in the array that was newly reallocated
  printArrayImproved(stdout, list2, size2);

  //TO DO: Perform necessary cleanup here



  
  return 0;
}


/*
  Function that returns an array of "size" int elements,
  where each position has been initalized to "value"
*/
int* createArray(int size, int value){

  //Request the memory required, and assert that malloc succeeded
  int* array = malloc (size * sizeof(int));
  assert(array != NULL);

  //Initalize each position with the given value
  for (int i = 0; i < size; i++) {
    array[i] = value;
  }

  //Return the address
  return array;

}

/*
  Function that outputs size elements of an array
  to the stream denoted by the given file pointer.
  Assumes stream is already open when passed in,
  and does not close the stream.
*/
void printArrayImproved(FILE *outFile, int *array, int size) {
  int* cur = array;
  if (cur) {
    for (int i = 0; i < size; i++) {
      fprintf(outFile, "%d ", *cur);
      cur++;
    }
    fprintf(outFile, "\n\n");
  } else {
    fprintf(outFile, "[ null ]\n");
  }
}


/*
  Function that returns a newly allocated array with values
  obtained from the given filehandle.  The first number
  read will be treated as the size of the new array, and
  the function will then allocate the array and attempt to
  fill it with the requested number of integers. 
*/
void readArray (FILE *fp, int *newSize, int **newArray) {
  if (!fp) { // make sure fp is not null
    fprintf(stderr, "readArray: passed bad filehandle\n");
    return;
  }

  int n = fscanf(fp, "%d", newSize);
  if (n < 1) { // make sure we read something
    fprintf(stderr, "readArray: Error reading from filehandle\n");
    return;
  }

  // allocate array space
  *newArray = malloc(sizeof(int) * (*newSize));
  
  // try to read integers
  for (int i=0; i < *newSize; i++) {
    int tmp;
    if (fscanf(fp, "%d", &tmp) > 0) {
      (*newArray)[i] = tmp;
    } else {
      fprintf(stdout, "readArray: warning, didn't get as many elements as requested\n");
      // make sure we don't say we read more than we actually did
      *newSize = i;
      return;
    }
  }
}

/*
  Function that reallocates memory block assigned to
  "ptr" to the given "newSize", copying over as much
  data from the oldPtr array as will fit in the new
  array.
*/
  int* my_realloc(int* oldPtr, int oldSize, int newSize){

    //TO DO - Function stub, replace with real function.
    //  Doesn't do anything (yet), returns a NULL pointer for now 
    //  to indicate that it didn't actually allocate more space
    return NULL;  //replace this stub
  }
