#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

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
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int statusChoice;
    int i;

    do {
        printf("\n--- Student Progress Tracker ---\n");
        printf("1. Add student record\n");
        printf("2. Show all student records\n");
        printf("3. Exit\n");
        printf("Current records: %d / %d\n", count, MAX_STUDENTS);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Maximum limit reached. Cannot add more students.\n");
                } else {
                    printf("Enter student ID: ");
                    scanf("%d", &students[count].id);

                    printf("Enter student name: ");
                    scanf("%s", students[count].name);

                    printf("Enter progress (0-100): ");
                    scanf("%f", &students[count].progress);

                    updateProgress(&students[count].progress);

                    printf("Choose status:\n");
                    printf("1. Not Started\n");
                    printf("2. In Progress\n");
                    printf("3. Completed\n");
                    printf("Enter status: ");
                    scanf("%d", &statusChoice);

                    if (statusChoice == 1) {
                        students[count].status = NOT_STARTED;
                    } else if (statusChoice == 2) {
                        students[count].status = IN_PROGRESS;
                    } else if (statusChoice == 3) {
                        students[count].status = COMPLETED;
                    } else {
                        printf("Invalid status. Default set to Not Started.\n");
                        students[count].status = NOT_STARTED;
                    }

                    count++;
                    printf("Student record added successfully.\n");
                }
                break;

            case 2:
                if (count == 0) {
                    printf("No student records saved yet.\n");
                } else {
                    printf("\n--- All Student Records ---\n");
                    for (i = 0; i < count; i++) {
                        printf("Student %d\n", i + 1);
                        printf("ID: %d\n", students[i].id);
                        printf("Name: %s\n", students[i].name);
                        printf("Progress: %.2f\n", students[i].progress);
                        printf("Status: ");
                        showStatus(students[i].status);
                        printf("\n-------------------------\n");
                    }
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
