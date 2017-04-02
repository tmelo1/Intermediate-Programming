#ifndef CATALOG_H
#define CATALOG_H

typedef struct Course {
	char identifier[11];
	char division[3];
	int department;
	int number;
	float credits;
	char title[33];
} Course;

Course makeCourse(char line[]);
int searchByIdentifier(Course catalog[], char identifier[], int numCourses);
void displayCourse(Course c);
void displayCatalog(Course catalog[], int numCourses);
int updateCourseTitle(Course catalog[], char identifier[], char newTitle[], int numCourses);
int updateCredits(float newCredit);
int isValidIdentifier(char identifier[]);

#endif