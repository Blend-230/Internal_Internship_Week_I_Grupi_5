#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef enum {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

// funksion me pointer
void addStudent(Student *s) {
    printf("\n--- Add New Student ---\n");

    printf("Enter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress (0-100): ");
    scanf("%f", &s->progress);

    // validim
    if (s->progress < 0 || s->progress > 100) {
        printf("Invalid progress! Setting to 0.\n");
        s->progress = 0;
    }

    // vendos statusin
    if (s->progress == 0)
        s->status = NOT_STARTED;
    else if (s->progress < 100)
        s->status = IN_PROGRESS;
    else
        s->status = COMPLETED;

    printf("Student added successfully!\n");
}

// shfaq të gjithë studentët
void displayStudents(Student students[], int count) {
    printf("\n--- Student List ---\n");

    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        printf("Status: ");
        switch (students[i].status) {
            case NOT_STARTED:
                printf("Not Started\n");
                break;
            case IN_PROGRESS:
                printf("In Progress\n");
                break;
            case COMPLETED:
                printf("Completed\n");
                break;
        }
    }
}

int main() {
    Student students[MAX_STUDENTS]; // array fikse
    int count = 0;                  // sa janë aktualisht
    int choice;

    while (1) {
        printf("\n==== Student Progress Tracker ====\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Maximum limit reached! Cannot add more students.\n");
                } else {
                    addStudent(&students[count]); // pointer
                    count++;
                    printf("Current count: %d/%d\n", count, MAX_STUDENTS);
                }
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}
