/**
Tony Melo - tmelo1@jhu.edu (tmelo1)
EN600.120
Assignment #5
4/2/2017
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "transcript.h"
#include "catalog.h"

void testCourse(void) {

	Course test = {"EN.600.120", "EN", 600, 120, 4.0, "Intermediate Programming"};
	assert(test);
	assert(strcmp("EN.600.120", test.identifier) == 0);
	assert(strcmp("EN", test.division) == 0);
	assert(strcmp("Intermediate Programming", test.title) == 0);
	assert(test.department == 600);
	assert(test.number == 120);
	assert(test.credits == 4.0);
	free(test)
}

void testMakeCourse(void) {
	char identifier[11] = "EN.600.233";
	char division[3] = "EN";
	char title[33] = "Computer System Fundamentals";
	int department = 600;
	int number = 233;
	float credits = 3.0
	char line[48] = "EN.600.233 3.0 Computer System Fundamentals";
	Course test = makeCourse(line);
	assert(strcmp(identifier, test.identifier) == 0);
	assert(strcmp(division, test.division) == 0);
	assert(strcmp(title, test.title) == 0);
	assert(department == test.department);
	assert(test.number == number);
	assert(test.credits == credits);
	free(test);
}

void testSearchByIdentifier(void) {
	Course test1 = makeCourse("EN.600.120 4.0 Intermediate Programming");
	Course test2 = makeCourse("EN.600.233 3.0 Computer System Fundamentals");
	Course test3 = makeCourse("EN.600.226 4.0 Data Structures");
	Course *catalog = malloc(3 * sizeof(Course));
	catalog[0] = test1;
	catalog[1] = test2;
	catalog[2] = test3;
	int result = searchByIdentifier(catalog, "EN.600.120", 3);
	assert(result == 0);
	free(catalog);
}

void testSearchingForCourseNotPresent(void) {
	Course test1 = makeCourse("EN.600.120 4.0 Intermediate Programming");
	Course test2 = makeCourse("EN.600.233 3.0 Computer System Fundamentals");
	Course test3 = makeCourse("EN.600.226 4.0 Data Structures");
	Course *catalog = malloc(3 * sizeof(Course));
	catalog[0] = test1;
	catalog[1] = test2;
	catalog[2] = test3;
	int result = searchByIdentifier(catalog, "EN.600.316", 3);
	assert(result == -1);
	free(catalog);
}

void testValidIdentifier(void) {
	int result = isValidIdentifier("EN.600.120");
	assert(result);
}

void testInvalidIdentifier(void) {
	int result = isValidIdentifier("60.400.120");
	assert(!result);
}

void testInvalidIdentifierNonAlphaNum(void) {
	int result = isValidIdentifier("...");
	assert(!result);
}

void testTitleUpdate(void) {
	Course test1 = makeCourse("EN.600.120 4.0 Intermediate Programming");
	Course test2 = makeCourse("EN.600.233 3.0 Computer System Fundamentals");
	Course test3 = makeCourse("EN.600.226 4.0 Data Structures");
	Course *catalog = malloc(3 * sizeof(Course));
	catalog[0] = test1;
	catalog[1] = test2;
	catalog[2] = test3;
	int result = updateCourseTitle(catalog, "EN.600.120", "Inter. Prog.", 3);
	assert(result);
	free(catalog);
}

void testTitleUpdateForEmpty(void) {
	Course test1 = makeCourse("EN.600.120 4.0 Intermediate Programming");
	Course *catalog = malloc(sizeof(Course));
	catalog[0] = test1;
	int result = updateCourseTitle(catalog, "EN.600.120", "", 3)
	assert(!result);

}

void testTitleUpdateWhenTooLong(void) {
	Course test1 = makeCourse("EN.600.120 4.0 Intermediate Programming");
	Course *catalog = malloc(sizeof(Course));
	catalog[0] = test1;
	int result = updateCourseTitle(catalog, "EN.600.120", "AAAAAAAAAAAAAAAAAAAAAAAAAAaAAAAAAAAHHHHHHHHHH", 3);
	assert(!result);
}

void testEntry(void) {
	Course test1 = makeCourse("EN.600.120 4.0 Intermediate Programming");
	Course *catalog = malloc(sizeof(Course));
	catalog[0] = test1;
	Entry *new = createEntry(&test1, "2006.S", "A+");
	assert(strcmp(new->semester, "2006.S") == 0);
	assert(!new->next);
}

int main(void) {
	testEntry();
	testTitleUpdateForEmpty();
	testValidIdentifier();
	testSearchByIdentifier();
	testCourse();
	testInvalidIdentifier();
	testSearchingForCourseNotPresent();
	testInvalidIdentifierNonAlphaNum();
	testTitleUpdate();
	testMakeCourse();
	
}