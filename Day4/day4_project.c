#include <stdio.h>
#include <string.h>

enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

void updateProgress(float *progress) {
    if (*progress < 0) {
        *progress = 0;
    } else if (*progress > 100) {
        *progress = 100;
    }
}

void showStatus(enum Status status) {
    switch (status) {
        case NOT_STARTED:
            printf("Not Started");
            break;
        case IN_PROGRESS:
            printf("In Progress");
            break;
        case COMPLETED:
            printf("Completed");
            break;
        default:
            printf("Unknown");
    }
}

int main() {
    struct Student student;
    int hasRecord = 0;
    int choice;
    int statusChoice;

    do {
        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add student record\n");
        printf("2. Show student record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &student.id);

                printf("Enter student name: ");
                scanf("%s", student.name);

                printf("Enter progress (0-100): ");
                scanf("%f", &student.progress);

                updateProgress(&student.progress);

                printf("Choose status:\n");
                printf("1. Not Started\n");
                printf("2. In Progress\n");
                printf("3. Completed\n");
                printf("Enter status: ");
                scanf("%d", &statusChoice);

                if (statusChoice == 1) {
                    student.status = NOT_STARTED;
                } else if (statusChoice == 2) {
                    student.status = IN_PROGRESS;
                } else if (statusChoice == 3) {
                    student.status = COMPLETED;
                } else {
                    printf("Invalid status. Default set to Not Started.\n");
                    student.status = NOT_STARTED;
                }

                hasRecord = 1;
                printf("Student record saved successfully.\n");
                break;

            case 2:
                if (hasRecord == 0) {
                    printf("No student record saved yet.\n");
                } else {
                    printf("\n--- Student Record ---\n");
                    printf("ID: %d\n", student.id);
                    printf("Name: %s\n", student.name);
                    printf("Progress: %.2f\n", student.progress);
                    printf("Status: ");
                    showStatus(student.status);
                    printf("\n");
                }
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid menu choice.\n");
        }

    } while (choice != 3);

    return 0;
}
