#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hw5.h"


int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Invalid usage, please provide a catalog file to read from");
        return 1;
    }

    char line[48];
    Course *catalog;
    char option;
    int numCourses = 0;
    char id[11];
    char titleInput[34];
    char creditInput[5];
    int transcriptSize = 0;
    Entry *head = NULL;
    int ch;
    FILE *catalogFile = fopen(argv[1], "r");
    if (!catalogFile) {
        printf("Invalid catalog file");
        return 2;
    }
    while (!feof(catalogFile)) {
        ch = fgetc(catalogFile);
        if (ch == '\n') {
            numCourses++;
        }
    }
    rewind(catalogFile);
    int i = 0;
    int index;
    char semesterInput[7];
    char gradeInput[3];
    catalog = malloc(numCourses * sizeof(Course));
    while(fgets(line, 48 * numCourses, catalogFile) != NULL) {
        catalog[i++] = makeCourse(line);
    }
    fclose(catalogFile);
    while (option != 'q' && option != 'Q') {
        menu_prompt();
        scanf(" %c", &option);
        switch(option) {
            case '1':
                if (!numCourses) {
                    break;
                }
                displayCatalog(catalog, numCourses);
                break;
            case '2':
                index = coursePrompt(catalog, id, numCourses);
                displayCourse(catalog[index]);
                break;
            case '3':
                index = coursePrompt(catalog, id, numCourses);
                titlePrompt(titleInput);
                strcpy(catalog[index].title, titleInput);
                break;
            case '4':
                index = coursePrompt(catalog, id, numCourses);
                float creds = creditPrompt(creditInput);
                catalog[index].credits = creds;
                break;
            case '5':
                tryagain:
                index = coursePrompt(catalog, id, numCourses);
                semesterPrompt(semesterInput);
                gradePrompt(gradeInput);
                if (head == NULL) {
                    head = createEntry(&catalog[index], semesterInput, gradeInput);
                    transcriptSize++;
                    transcript_updated_msg();
                    break;
                }
                if (transcriptSize == 1) {
                    if(addCourse(head, &catalog[index], semesterInput, gradeInput) == -1) {
                        duplicate_course_msg();
                        goto tryagain;
                    } else {
                        transcript_updated_msg();
                        transcriptSize++;
                        break;
                    }
                }
                if (addCourse(head, &catalog[index], semesterInput, gradeInput) == -1) {
                    duplicate_course_msg();
                    goto tryagain;
                } else {
                    transcriptSize++;
                    transcript_updated_msg();
                    break;
                }
            case '7':
                if (head == NULL) {
                    empty_transcript_msg();
                    break;
                }
                displayTranscript(head);
                break;
            case '8':
                tryagain1:
                index = coursePrompt(catalog, id, numCourses);
                int found = displayCourseInfo(head, &catalog[index]);
                if (!found) {
                    course_not_taken_msg();
                    goto tryagain1;
                }





        }

    }
}

