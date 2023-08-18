#include <stdio.h>
#define MAX_CLASSES 2
#define MAX_STUDENTS_PER_CLASS 2
#define MAX_SUBJECTS 2
int main() {
    int studentGrades[MAX_CLASSES][MAX_STUDENTS_PER_CLASS][MAX_SUBJECTS];
    for (int classIdx = 0; classIdx < MAX_CLASSES; classIdx++) {
        for (int studentIdx = 0; studentIdx < MAX_STUDENTS_PER_CLASS; studentIdx++) {
            for (int subjectIdx = 0; subjectIdx < MAX_SUBJECTS; subjectIdx++) {
                printf("Enter grade for Class %d, Student %d, Subject %d: ", classIdx + 1, studentIdx + 1, subjectIdx + 1);
                scanf("%d", &studentGrades[classIdx][studentIdx][subjectIdx]);
            }
        }
    }
    for (int classIdx = 0; classIdx < MAX_CLASSES; classIdx++) {
        printf("Class %d:\n", classIdx + 1);
        for (int studentIdx = 0; studentIdx < MAX_STUDENTS_PER_CLASS; studentIdx++) {
            printf("Student %d: ", studentIdx + 1);
            for (int subjectIdx = 0; subjectIdx < MAX_SUBJECTS; subjectIdx++) {
                printf("%d ", studentGrades[classIdx][studentIdx][subjectIdx]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}