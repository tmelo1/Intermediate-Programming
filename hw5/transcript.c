/**
Tony Melo - tmelo1@jhu.edu (tmelo1)
EN600.120
Assignment #5
4/2/2017
 */
#include "catalog.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "transcript.h"

Entry *createEntry(Course *course, char sem[], char grade[]) {
	Entry *e = malloc(sizeof(Entry));
	if (!e) {
		return NULL;
	}
	e->next = NULL;
	e->c = course;
	strcpy(e->semester, sem);
	strcpy(e->grade, grade);
	return e;
}

int addCourse(Entry *head, Course *course, char sem[], char grade[]) {
	Entry *new = createEntry(course, sem, grade);
	if (!new) {
		return 0;
	}
	Entry *current = head;
	for (const Entry *e = head; e != NULL; e = e->next) {
		if (strcmp(e->c->identifier, course->identifier) == 0) {
			if (strcmp(e->semester, sem) == 0) {
				return -1;
			}
		}
	}
	while (strcmp(current->semester, sem) > 0 && current != NULL) {
		current = current->next;
	}
	if (strcmp(current->c->identifier, head->c->identifier) < 0) {
		insertHead(&head, course, sem, grade);
		return 1;
	}
	new->next = current->next;
	current->next = new; 
	return 1;
}

int deleteCourse(Entry *head, Course *course) {
	Entry *current = head;
	while (strcmp((current->c)->identifier, course->identifier) != 0 && (current->next)->next != NULL) {
		current = current->next;
	}
	if (current->next == NULL && strcmp((current->c)->identifier, course->identifier) != 0) {
		return 0;
	} else {
		Entry *temp = current;
		current = head;
		while (memcmp((current->next), temp, sizeof(Course)) != 0) {
			current = current->next;
		}
		current->next = (temp->next)->next;
		free(temp);
		return 1;
	}

}

void insertHead(Entry **head, Course *course, char sem[], char grade[]) {
	Entry *e = createEntry(course, sem, grade);
	e->next = *head;
	*head = e;
}

void displayTranscript(Entry *head) {
	for (const Entry *e = head; e != NULL; e = e->next) {
		printf("%s %s %s %f %s\n", e->semester, e->grade, (e->c)->identifier, (e->c)->credits, (e->c)->title);
	}
}

int displayCourseInfo(Entry *head, Course *course) {
	Entry *current = head;
	int found = 0;
	while (current->next != NULL) {
		if (strcmp((current->c)->identifier, course->identifier) == 0) {
			printf("%s %s\n", current->semester, current->grade);
			found = 1;	
		} 
	}
	return found;
}

/**
float calculateGPA(const Entry *head, Course *course) {

}
*/