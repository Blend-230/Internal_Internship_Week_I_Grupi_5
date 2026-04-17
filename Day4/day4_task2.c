#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nChoose Status:\n");
        printf("1. Not Started\n");
        printf("2. In Progress\n");
        printf("3. Completed\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: return NOT_STARTED;
            case 2: return IN_PROGRESS;
            case 3: return COMPLETED;
            default:
                printf("Invalid status choice! Try again.\n");
        }
    }
}

void addStudent(Student *s) {
    printf("\n--- Add New Student ---\n");

    printf("Enter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress (0-100): ");
    scanf("%f", &s->progress);

    while (s->progress < 0 || s->progress > 100) {
        printf("Invalid progress! Enter again (0-100): ");
        scanf("%f", &s->progress);
    }

    s->status = chooseStatus();

    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    printf("\n--- Student List ---\n");

    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", students[i].id);
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

// 🔥 TASK 3 - RAPORTI ANALITIK
void generateReport(Student students[], int count) {
    printf("\n===== STUDENT REPORT =====\n");

    if (count == 0) {
        printf("No data available.\n");
        return;
    }

    int completed = 0;
    float sum = 0;
    float max = students[0].progress;
    float min = students[0].progress;

    for (int i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].status == COMPLETED) {
            completed++;
        }

        if (students[i].progress > max) {
            max = students[i].progress;
        }

        if (students[i].progress < min) {
            min = students[i].progress;
        }
    }

    float avg = sum / count;

    printf("Total Students: %d\n", count);
    printf("Completed Students: %d\n", completed);
    printf("Average Progress: %.2f\n", avg);
    printf("Highest Progress: %.2f\n", max);
    printf("Lowest Progress: %.2f\n", min);

    printf("\nPerformance: ");
    if (avg >= 80) {
        printf("Excellent\n");
    } else if (avg >= 50) {
        printf("Good\n");
    } else {
        printf("Needs Improvement\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n==== Student Progress Tracker ====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 4) {
            printf("Invalid menu option! Try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Maximum limit reached!\n");
                } else {
                    addStudent(&students[count]);
                    count++;
                }
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                generateReport(students, count);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;
        }
    }

    return 0;
}
