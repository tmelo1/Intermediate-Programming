/* 
   In class exercise Ex-3-1.
   Practice using string functions and writing helper methods.
*/


#include <stdio.h>
#include <string.h>


/* 
   This is the function declaration (prototype) for the concat 
   function. Its definition is below.
*/
int concat(char word1[], char word2[], char result[], int resultCap);



int main() {

    char word1[11];  //allow up to 10 chars, then room for '\0' terminator
    char word2[11];  //allow up to 10 chars, then room for '\0' terminator

    scanf("%s", word1);
    scanf("%s", word2);
    
    int resultCap;
    scanf("%d", &resultCap);
    char result[resultCap];

    //Uncomment the line below for debugging; leave it commented out in order to pass tests
    printf("word1 is %s, word2 is %s, and resultCap is %d\n", word1, word2, resultCap);

    if(!concat(word1, word2, result, resultCap)) {
        printf("Concatenation was successful: %s\n", result);
    } else {
        printf("Concatenation was not successful.\n");
    }

    return 0;
}


/*
  Returns in the third argument the concatenation of the first
  argument and the second argument, provided that there is
  sufficient space in third argument, as specified by the fourth.
  e.g.
      concat("alpha", "beta", result, 10) puts "alphabeta" into result and returns 0
      concat("alpha", "gamma", result, 10) puts nothing into result and returns 1
 */
int concat(char word1[], char word2[], char result[], int resultCap){


    /* FILL IN YOUR CODE HERE */

    int len1 = strlen(word1);
    int len2 = strlen(word2);
    printf("len1: %d, len2: %d\n", len1, len2);
    if (len1 + len2 >= resultCap) {
      return 1;
    } else {
      strcpy(result, word1);
      strcat(result, word2);
      printf("%s", result);
      
     
    }
    return 0;  //replace this stub with something appropriate for function

}
