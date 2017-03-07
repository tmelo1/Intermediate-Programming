/*
Homework 1, 600.120 Spring 2017
Tony Melo - tmelo1@jhu.edu

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 16  //LENGTH is now a constant with value 16

int main(int argc, char* argv[]) {

    // Confirm that a command-line argument is present
    if (argc == 1) {
        printf("Usage: hw0 XX.###.###Gg#.#\n");
        return 1;  // exit program because no command line argument present
    }

    // Declare a char array to hold the command-line argument string;
    // ensure last char is null character
    char course[LENGTH];
    strncpy(course, argv[1], LENGTH);
    course[LENGTH-1] = '\0';

    // TO DO: eventually remove the line below; it's just for debugging purposes


    // TO DO: add your code here
    int division = 0;
    int letterGrade = 0;
    int sign = 0;
    int leftDecimal = 0;
    int rightDecimal = 0;

    /*
    * Encodes the division based on the first two characters in the "course" string representation.
    * Since most of the divisons have a unique first letter,
    * not much conditional checking to do.
    */
    switch(course[0]) {
    case 'M':
        division = 0;
        break;
    case 'B':
        division = 1;
        break;
    case 'E':
        if (course[1] == 'D') {
            division = 2;
            break;
        }
        division = 3;
        break;
    case 'A':
        division = 4;
        break;
    case 'P':
        if (course[1] == 'H') {
            division = 5;
            break;
        }
        division = 6;
        break;
    default:
        division = 7;
        break;
    }

    /* Converts the department strings and course numbers into decimal representations. */
    int department = 100*(course[3] - '0') + 10*(course[4] - '0') + (course[5] - '0');
    int courseNo = 100*(course[7] - '0') + 10*(course[8] - '0') + (course[9] - '0');

    /* Encodes the letter grades for the course as an integer from 0-7 */
    switch(course[10]) {
    case 'A':
        letterGrade = 0;
        break;
    case 'B':
        letterGrade = 1;
        break;
    case 'C':
        letterGrade = 2;
        break;
    case 'D':
        letterGrade = 3;
        break;
    case 'F':
        letterGrade = 4;
        break;
    case 'I':
        letterGrade = 5;
        break;
    case 'S':
        letterGrade = 6;
        break;
    case 'U':
        letterGrade = 7;
        break;
    }

    /* Encodes the plus, minus, or lack thereof as a 0, 1, or 2, respectively.*/
    switch(course[11]) {
    case '+':
        sign = 0;
        break;
    case '-':
        sign = 1;
        break;
    case '/':
        sign = 2;
        break;
    }

    /* No need to do any checking on this one. */
    leftDecimal = course[12] - '0';

    /* Either encodes the 0 or 0.5 as a 0 or 1, respectively. */
    if (course[14] == '0') {
        rightDecimal = 0;
    } else {
        rightDecimal = 1;
    }

    /* Simple formatting. */
    printf("Division: %d\n", division);
    printf("Department: %03d\n", department);
    printf("Course: %03d\n", courseNo);
    printf("Grade: %d %d\n", letterGrade, sign);
    printf("Credits: %d %d\n", leftDecimal, rightDecimal);

    return 0;
}
