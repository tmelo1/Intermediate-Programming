/**
Tony Melo - tmelo1@jhu.edu (tmelo1)
EN600.120
Assignment #3
2/28/2017
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/** Encode the division, this time with error checks.*/
int getDivision(char courseIn[]) {
    int divisionCode = 0;
    switch(courseIn[0]) {
        case 'M':
	    if (courseIn[1] == 'E') {
                divisionCode = 0;
                break;
	    } else
	        exit(1);
        case 'B':
	    if (courseIn[1] == 'U') {
                divisionCode = 1;
                break;
	    } else
	        exit(1);
        case 'E':
            if(courseIn[1] == 'D') {
                divisionCode = 2;
                break;
            } else if (courseIn[1] == 'N') {
                divisionCode = 3;
                break;
            } else
	        exit(1);
        case 'A':
	    if (courseIn[1] == 'S') {
                divisionCode = 4;
                break;
	    } else
	        exit(1);
        case 'P':
            if (courseIn[1] == 'H') {
                divisionCode = 5;
                break;
            } else if (courseIn[1] == 'Y') {
                divisionCode = 6;
                break;
            } else
	        exit(1);
        case 'S':
	    if (courseIn[1] == 'A') {
                divisionCode = 7;
                break;
	    } else
	        exit(1);
        default:
	    printf("Invalid division!");
            divisionCode = -1;
	    exit(1);
    }
    return divisionCode;
}

/** Encoding department. */
int getDept(char courseIn[]) {
    char department[4];
    int departmentNumber;
    int j = 0;
    for(int i = 3; i < 6; i++) {
        department[j++] = courseIn[i];
    }
    if (sscanf(department, "%d", &departmentNumber) < 0) {
        printf("Invalid department!");
        departmentNumber = -1;
	exit(1);
    }
    return departmentNumber;
}

/** Encoding course number. */
int getCourseNo(char courseIn[]) {
    char cnumber[4];
    int courseNumber = 0;
    int h = 0;
    for (int i = 7; i < 10; i++) {
        cnumber[h++] = courseIn[i];
    }
    if (sscanf(cnumber, "%d", &courseNumber) < 0) {
        printf("Invalid course number!");
        courseNumber = -1;
	exit(1);
    }
    return courseNumber;
}

/** Encoding letter grade. */
int getLetterGrade(char courseIn[]) {
    int letterGrade = 0;
    switch(courseIn[10]) {
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
        default:
	    printf("Invalid letter grade!");
            letterGrade = -1;
	    exit(1);
    }
    return letterGrade;
}

/** Get grade sign. */
int getGradeSign(char courseIn[]) {
    int gradeSign = 0;
    switch(courseIn[11]) {
        case '+':
            gradeSign = 0;
            break;
         case '-':
            gradeSign = 1;
            break;
        case '/':
            gradeSign = 2;
            break;
        default:
	    printf("Invalid grade sign!");
            gradeSign = -1;
            exit(1);
     }
     return gradeSign;
}


/** Encode the right credit. */
int getRightCredit(char courseIn[]) {
    int rightCredit = 0;
    switch(courseIn[14]) {
        case '0':
            rightCredit = 0;
            break;
        case '5':
            rightCredit = 1;
            break;
        default:
	    printf("Invalid credit!");
            rightCredit = -1;
            exit(1);
     }
     return rightCredit;
}


/** Encode the left credit. */
int getLeftCredit(char courseIn[]) {
    int leftCredit = courseIn[12] - '0';
    if (leftCredit < 0 || leftCredit > 5) {
        printf("Invalid credit!");
        leftCredit = -1;
	exit(1);
    }
    return leftCredit;
}

/** Convert the decimal number to binary. */
void convertToBinary(char binary[], unsigned int decimal) {
    int i = 0;
    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
   
}


/** Convert the course to decimal. */
unsigned int convertToDecimal(char courseIn[]) {
    unsigned int decimal = 0;
    decimal = decimal ^ getDivision(courseIn);
    decimal = (decimal << 10) ^ getDept(courseIn);
    decimal = (decimal << 10) ^ getCourseNo(courseIn);
    decimal = (decimal << 3) ^ getLetterGrade(courseIn);
    decimal = (decimal << 2) ^ getGradeSign(courseIn);
    decimal = (decimal << 3) ^ getLeftCredit(courseIn);
    decimal = (decimal << 1) ^ getRightCredit(courseIn);
    return decimal;
}
