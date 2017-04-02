#include "catalog.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


Course makeCourse(char line[]) {
    int ind = 0;
    char identifier[11];
    for (int i = 0; i < 10; i++) {
        identifier[i] = line[i];
    }
    identifier[11] = '\0';
 
    char c[4];
    for (int i = 11; i < 14; i++) {
        c[ind++] = line[i];
    }
    c[3] = '\0';

    ind = 0;
    char title[33];
    for (int i = 15; i < 48; i++) {
        title[ind++] = line[i];
    }
    title[ind] = '\0';

    char div[3];
    for (int i = 0; i < 2; i++) {
        div[i] = line[i];
    }
    div[2] = '\0';
    int dept = 100*(identifier[3] - '0') + 10*(identifier[4] - '0') + (identifier[5] - '0');
    int no = 100*(identifier[7] - '0') + 10*(identifier[8] - '0') + (identifier[9] - '0');
    float creds = atof(c);
	Course newCourse;
	newCourse.department = dept;
	newCourse.number = no;
	newCourse.credits = creds;
    strcpy(newCourse.title, title);
    strcpy(newCourse.identifier, identifier);
    strcpy(newCourse.division, div);
    return newCourse;
}

int searchByIdentifier(Course catalog[], char identifier[], int numCourses) {
    if (!isValidIdentifier(identifier)) {
        return -1;
    }
    int index = -1;
    for (int i = 0; i < numCourses; i++) {
        Course current = catalog[i];
        if (strcmp(identifier, current.identifier)) {
            continue;
        } else {
            index = i;
            break;
        }
    }
    return index;
}


void displayCatalog(Course catalog[], int numCourses) {
    for (int i = 0; i < numCourses; i++) {
        displayCourse(catalog[i]);
    }
}

void displayCourse(Course c) {
    printf("%s %.1f %s\n", c.identifier, c.credits, c.title);
}

int updateCourseTitle(Course catalog[], char identifier[], char newTitle[], int numCourses) {
    if (!isValidIdentifier(identifier) || (int) strlen(newTitle) > 32) {
        return 0;
    }
    int courseIndex = searchByIdentifier(catalog, identifier, numCourses);
    if (courseIndex == -1) {
        return 0;
    }
    strcpy(catalog[courseIndex].title, newTitle);
    return 1; 
}



int isValidIdentifier(char identifier[]) {
    if (!isalpha(identifier[0]) || !isalpha(identifier[1])) {
        return 0;
    }
    switch(tolower(identifier[0])) {
        case 'e':
            if (tolower(identifier[1]) == 'n' || tolower(identifier[1]) == 'd') {
                break;
            }
            return 0;
        case 'b':
            if (tolower(identifier[1]) == 'u') {
                break;
            }
            return 0;
        case 'm':
            if (tolower(identifier[1]) == 'e') {
                break;
            }
            return 0;
        case 'a':
            if (tolower(identifier[1]) == 's') {
                break;
            }
            return 0;
        case 'p':
            if (tolower(identifier[1]) == 'h' || tolower(identifier[1]) == 'y') {
                break;
            }
            return 0;
        case 's':
            if (tolower(identifier[1]) == 'a') {
                break;
            }
            return 0;
        default:
            return 0;
    }

    if (identifier[2] != '.' || identifier[6] != '.') {
        return 0;
    }

    for (int i = 3; i <= 9; i++) {
        if (i == 6) {
            continue;
        } else {
            if (!isdigit(identifier[i])) {
                return 0;
            }
        }

    }
    return 1;

}

