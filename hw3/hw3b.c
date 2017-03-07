/**
Tony Melo - tmelo1@jhu.edu (tmelo1)
EN600.120
Assignment #3
2/28/2017
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 2500

void getCourseString(unsigned int courseInt, char course[]);

void printMenu() {
    printf(
        "n - display the total number of courses\n"
        "d - list all courses from a particular department\n"
        "l - list all courses with a particular letter grade\n"
        "c - list all courses with at least a specified number of credits\n"
        "g - compute the GPA of all the courses with letter grades\n"
        "q - quit the program\n"
        "Enter letter choice ->\n");
}

void promptN(int i) {
    printf("Total number of courses: %d\n", i);
}

void promptD() {
    printf("Enter the department:\n");
}

void promptL() {
    printf("Enter a letter grade and mark (+,-,/):\n");
}

void promptC() {
    printf("Enter number of credits:\n");
}

void promptG(float gpa) {
    printf("GPA: %.3f\n", gpa);
}

void noMatches() {
    printf("No matches\n");
}

void getCourseString(unsigned int courseInt, char course[]) {
    int courseNum;
    int department;
    int division;
    int leftCredit;
    int rightCredit;
    int letterGrade;
    int gradeSign;
    int tenBitMask = 1023;
    int threeBitMask = 7;
    int oneBitMask = 1;
    int twoBitMask = 3;
    division = (courseInt >> 29) & threeBitMask;
    department = (courseInt >> 19) & tenBitMask;
    courseNum = (courseInt >> 9) & tenBitMask;
    letterGrade = (courseInt >> 6) & threeBitMask;
    gradeSign = (courseInt >> 4) & twoBitMask;
    leftCredit = (courseInt >> 1) & threeBitMask;
    rightCredit = courseInt & oneBitMask;

    switch (division) {
        case 0:
            course[0] = 'A';
            course[1] = 'S';
            break;
        case 1:
            course[0] = 'B';
            course[1] = 'U';
            break;
        case 2:
            course[0] = 'E';
            course[1] = 'D';
            break;
        case 3:
            course[0] = 'E';
            course[1] = 'N';
            break;
        case 4:
            course[0] = 'M';
            course[1] = 'E';
            break;
        case 5:
            course[0] = 'P';
            course[1] = 'H';
            break;
        case 6:
            course[0] = 'P';
            course[1] = 'Y';
            break;
        case 7:
            course[0] = 'S';
            course[1] = 'A';
            break;
    }
    course[2] = '.';

    if (department >= 100) {
        course[3] = department / 100 + '0';
        course[4] = (department/10) % 10 + '0';
        course[5] = department % 10 + '0';
    } else if(department >= 10 && department < 100) {
        course[3] = '0';
        course[4] = department / 10 + '0';
        course[5] = department % 10 + '0';
    } else {
        course[3] = '0';
        course[4] = '0';
        course[5] = department + '0';;
    }
    course[6] = '.';

    if (courseNum >= 100) {
        course[7] = courseNum / 100 + '0';
        course[8] = (courseNum / 10) % 10 + '0';
        course[9] = courseNum % 10 + '0';
    } else if(courseNum >= 10 && courseNum < 100) {
        course[7] = '0';
        course[8] = courseNum / 10 + '0';
        course[9] = courseNum % 10 + '0';
    } else {
        course[7] = '0';
        course[8] = '0';
        course[9] = courseNum + '0';
    }

    switch (letterGrade) {
       case 0:
           course[10] = 'A';
           break;
       case 1:
           course[10] = 'B';
           break;
       case 2:
           course[10] = 'C';
           break;
       case 3:
           course[10] = 'D';
           break;
       case 4:
           course[10] = 'F';
           break;
       case 5:
           course[10] = 'I';
           break;
       case 6:
           course[10] = 'S';
           break;
       case 7:
           course[10] = 'U';
           break;
    }
    switch(gradeSign) {
       case 0:
           course[11] = '+';
           break;
       case 1:
           course[11] = '-';
           break;
       case 2:
           course[11] = '/';
           break;
    }
    switch(rightCredit) {
      case 0:
           course[14] = '0';
           break;
      case 1:
           course[14] = '5';
           break;
    }
    course[12] = leftCredit + '0';
    course[13] = '.';
    course[15] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        puts("Error, please input a file name.");
        return 1;
    }

    char option;
    int numLines = 0;
    char course_string[16];
    int depNum = 0;
    char grade[3];
    float numCredits = 0;
    float qualityPoints = 0;
    float totalQualityPoints = 0;
    float totalGPA = 0;
    int totalCredits = 0;
    int coursesFound = 0;
    unsigned int courseList[MAX_LINES] = {0};
    int i = 0;

    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) {
        puts("Error when reading file.");
        return 2;
    }
    while (fscanf(infile, "%u", &courseList[i]) != EOF) {
        if (courseList[i] != 0) {
            numLines++;
        }
	i++;
    }

    while (tolower(option) != 'q') {
        printMenu();
        scanf(" %c", &option);
        switch(tolower(option)) {
            case 'n':
                promptN(numLines);
                break;
            case 'd':
                coursesFound = 0;
                promptD();
                scanf("%d", &depNum);
                for (int i = 0; i < numLines; i++) {
                    getCourseString(courseList[i], course_string);
                    unsigned int depMask = depNum << 19;
                    if ((courseList[i] & depMask) == depMask) {
                        printf("%s\n", course_string);
                        coursesFound++;
                    }
                }
                if (coursesFound == 0) {
                    noMatches();
                }
                break;
            case 'l':
                coursesFound = 0;
                promptL();
                scanf("%s", grade);
                for (int i = 0; i < MAX_LINES; i++) {
                    getCourseString(courseList[i], course_string);
                    if (courseList[i] != 0) {
                        if (course_string[10] == grade[0] && course_string[11] == grade[1]) {
                            printf("%s\n", course_string);
                            coursesFound++;
                        }
                    }
                }
                if (coursesFound == 0) {
                    noMatches();
                }
                break;

            case 'c':
                coursesFound = 0;
                promptC();
                scanf("%f", &numCredits);
                for (int i = 0; i < MAX_LINES; i++) {
                    getCourseString(courseList[i], course_string);
                    float classCredit = (course_string[12] - '0')/1.0 + ((course_string[14] - '0')/10);
                    if (classCredit >= numCredits) {
                        printf("%s\n", course_string);
                        coursesFound++;
                    }
                }
                if (coursesFound == 0) {
                    noMatches();
                }
                break;
            case 'g':
                for (int i = 0; i < MAX_LINES; i++) {
                    getCourseString(courseList[i], course_string);
                    float classCredit = (course_string[12] - '0') / 1.0 + ((course_string[14] - '0') / 10.0);
                    if (courseList[i] != 0) {
                        switch(course_string[10]) {
                            case 'A':
                                if(course_string[11] == '+' || course_string[12] == '/')
                                    qualityPoints = 4.0;
                                else
                                    qualityPoints = 3.7;
                                break;
                            case 'B':
                                if(course_string[11] == '+')
                                    qualityPoints = 3.3;
                                else if(course_string[11] == '-')
                                    qualityPoints = 3.0;
                                else
                                    qualityPoints = 2.7;
                                break;
                            case 'C':
                                if(course_string[11] == '+')
                                    qualityPoints = 2.3;
                                else if(course_string[11] == '-')
                                    qualityPoints = 2.0;
                                else
                                    qualityPoints = 1.7;
                                break;
                            case 'D':
                                if(course_string[11] == '+')
                                    qualityPoints = 1.3;
                                else if(course_string[11] == '-')
                                    qualityPoints = 1.0;
                                else
                                    qualityPoints = 0.7;
                                break;
                            case 'F':
                                qualityPoints = 0.0;
                                break;
                    }
                    totalCredits += classCredit;
                    totalQualityPoints += classCredit * qualityPoints;
                }
            }
            totalGPA = totalQualityPoints/totalCredits;
            promptG(totalGPA);
            break;
        }
    }


    return 0;
}
