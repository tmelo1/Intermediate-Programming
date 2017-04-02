#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

typedef struct Entry {
	Course *c;
	char semester[7];
	char grade[3];
	struct Entry *next;
} Entry;

Entry *createEntry(Course *course, char sem[], char grade[]);
int addCourse(Entry *head, Course *course, char sem[], char grade[]);
int deleteCourse(Entry *head, Course *course, char sem[]);
void displayTranscript(Entry *head);
int displayCourseInfo(Entry *head, Course *course);
void insertHead(Entry **head, Course *course, char sem[], char grade[]);
/**float calculateGPA(const Entry *head);
*/


#endif