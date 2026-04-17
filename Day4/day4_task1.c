#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

enum Status {
    NEEDS_PRACTICE,
    READY_TO_CONTINUE,
    READY_FOR_CHALLENGE
};

struct Student {
    int id;
    char name[50];
    double progress;
    enum Status status;
};

void setStatus(struct Student *s) {
    if (s->progress < 50) {
        s->status = NEEDS_PRACTICE;
    } else if (s->progress < 80) {
        s->status = READY_TO_CONTINUE;
    } else {
        s->status = READY_FOR_CHALLENGE;
    }
}

void printStatus(enum Status status) {
    switch (status) {
        case NEEDS_PRACTICE:
            printf("Needs More Practice");
            break;
        case READY_TO_CONTINUE:
            printf("Ready to Continue");
            break;
        case READY_FOR_CHALLENGE:
            printf("Ready for Challenge");
            break;
        default:
            printf("Unknown");
    }
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nMaximum limit reached! No more records can be added.\n");
        return;
    }

    printf("\nEnter student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter student name: ");
    scanf(" %49[^\n]", students[*count].name);

    printf("Enter progress/result: ");
    scanf("%lf", &students[*count].progress);

    setStatus(&students[*count]);

    (*count)++;
    printf("Record added successfully!\n");
}

void showStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo records stored yet.\n");
        return;
    }

    printf("\n--- STORED STUDENT RECORDS ---\n");
    for (i = 0; i < count; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2lf\n", students[i].progress);
        printf("Status: ");
        printStatus(students[i].status);
        printf("\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Progress Tracker =====\n");
        printf("1. Add new record\n");
        printf("2. Show all records\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
