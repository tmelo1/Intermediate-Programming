#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "catalog.h"
#include "transcript.h"
#include "prompts.h"


int coursePrompt(Course catalog[], char input[], int numCourses) {
    reprompt:
    course_prompt();
    scanf(" %10s ", input);
    if (!isValidIdentifier(input)) {
        invalid_input_msg();
        goto reprompt;
    }
    int idx = searchByIdentifier(catalog, input, numCourses);
    if (idx == -1) {
        invalid_input_msg();
        goto reprompt;
    }
    return idx;
}

void titlePrompt(char title[]) {
    prompttitleagain:
    new_title_prompt();
    int charsRead = 0;
    fgets(title, 34, stdin);
    printf("%s\n", title);
    for (int i = 0; i < 34; i++) {
        if (title[i] != '\n') {
            charsRead++;
        }
        if (title[i] == '\n') {
            if (i > 32 || i == 0) {
                invalid_input_msg();
                goto prompttitleagain;
            }
            title[i] = '\0';
            break;
        }
    }
}

float creditPrompt(char creditInput[]) {
    promptcreditsagain:
    new_credit_prompt();
    float newCredits;
    scanf(" %5s", creditInput);
    if (!isdigit(creditInput[0])) {
        invalid_input_msg();
        goto promptcreditsagain;
    }
    if (creditInput[1] != '.') {
        invalid_input_msg();
        goto promptcreditsagain;
    }
    if (!isdigit(creditInput[2])) {
        invalid_input_msg();
        goto promptcreditsagain;
    }
    if ((int)creditInput[3] != 0) {
        invalid_input_msg();
        goto promptcreditsagain;
    }
    newCredits = atof(creditInput);
    return newCredits;

}

void semesterPrompt(char semesterInput[]) {
    promptsemesteragain:
    semester_prompt();
    scanf(" %6s", semesterInput);
    for (int i = 0; i < 4; i++) {
        if (!isdigit(semesterInput[i])) {
            printf("digit\n");
            invalid_input_msg();
            goto promptsemesteragain;
        }
    }
    if (semesterInput[4] != '.') {
        printf(".\n");
        invalid_input_msg();
        goto promptsemesteragain;
    }
    if (!isalpha(semesterInput[5])) {
        printf("not alpha\n");
        invalid_input_msg();
        goto promptsemesteragain;
    }
    printf("%c\n", semesterInput[5]);
    if (isalpha(semesterInput[5])) {
        if (tolower(semesterInput[5]) == 'f' || tolower(semesterInput[5]) == 's') {
            printf("gucci\n");
        } else {
            invalid_input_msg();
            goto promptsemesteragain;
        }
    }
}

void gradePrompt(char grade[]) {
    promptgradeagain:
    grade_prompt();
    scanf(" %2s", grade);
    if (!isalpha(grade[0])) {
        invalid_input_msg();
        goto promptgradeagain;
    }
    switch(tolower(grade[0])) {
        case 'a': case 'b': case 'c': case 'd': case 'f': case 's': case 'i': case 'u':
            break;
        default:
            invalid_input_msg();
            goto promptgradeagain;
    }
    switch(grade[1]) {
        case '+': case '-': case '/':
            break;
        default:
            invalid_input_msg();
            goto promptgradeagain;
    }
}
