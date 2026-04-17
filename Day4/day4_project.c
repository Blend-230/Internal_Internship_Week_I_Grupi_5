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

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void showReport(struct Student students[], int count) {
    int i;
    int completedCount = 0;
    float totalProgress = 0;
    float highestProgress, lowestProgress, averageProgress;

    if (count == 0) {
        printf("\nNo records available for analysis.\n");
        return;
    }

    highestProgress = students[0].progress;
    lowestProgress = students[0].progress;

    for (i = 0; i < count; i++) {
        totalProgress += students[i].progress;

        if (students[i].status == COMPLETED) {
            completedCount++;
        }

        if (students[i].progress > highestProgress) {
            highestProgress = students[i].progress;
        }

        if (students[i].progress < lowestProgress) {
            lowestProgress = students[i].progress;
        }
    }

    averageProgress = totalProgress / count;

    printf("\n--- Student Progress Report ---\n");
    printf("Total records: %d\n", count);
    printf("Completed students: %d\n", completedCount);
    printf("Average progress: %.2f\n", averageProgress);
    printf("Highest progress: %.2f\n", highestProgress);
    printf("Lowest progress: %.2f\n", lowestProgress);

    if (averageProgress >= 80) {
        printf("Class performance: Excellent\n");
    } else if (averageProgress >= 60) {
        printf("Class performance: Good\n");
    } else if (averageProgress >= 40) {
        printf("Class performance: Needs Improvement\n");
    } else {
        printf("Class performance: Weak\n");
    }

    if (completedCount == count) {
        printf("Completion status: All students completed their progress.\n");
    } else if (completedCount > 0) {
        printf("Completion status: Some students completed their progress.\n");
    } else {
        printf("Completion status: No student has completed progress yet.\n");
    }

    printf("-------------------------------\n");
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
        printf("3. Show progress report\n");
        printf("4. Exit\n");
        printf("Current records: %d / %d\n", count, MAX_STUDENTS);
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS) {
                    printf("Maximum limit reached. Cannot add more students.\n");
                    break;
                }

                printf("Enter student ID: ");
                if (scanf("%d", &students[count].id) != 1) {
                    printf("Invalid ID input.\n");
                    clearInputBuffer();
                    break;
                }

                printf("Enter student name: ");
                if (scanf("%49s", students[count].name) != 1) {
                    printf("Invalid name input.\n");
                    clearInputBuffer();
                    break;
                }

                printf("Enter progress (0-100): ");
                if (scanf("%f", &students[count].progress) != 1) {
                    printf("Invalid progress input.\n");
                    clearInputBuffer();
                    break;
                }

                updateProgress(&students[count].progress);

                printf("Choose status:\n");
                printf("1. Not Started\n");
                printf("2. In Progress\n");
                printf("3. Completed\n");
                printf("Enter status: ");

                if (scanf("%d", &statusChoice) != 1) {
                    printf("Invalid status input.\n");
                    clearInputBuffer();
                    break;
                }

                switch (statusChoice) {
                    case 1:
                        students[count].status = NOT_STARTED;
                        break;
                    case 2:
                        students[count].status = IN_PROGRESS;
                        break;
                    case 3:
                        students[count].status = COMPLETED;
                        break;
                    default:
                        printf("Invalid status choice. Record not added.\n");
                        break;
                }

                if (statusChoice < 1 || statusChoice > 3) {
                    break;
                }

                count++;
                printf("Student record added successfully.\n");
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
                showReport(students, count);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid menu choice. Please choose 1, 2, 3, or 4.\n");
        }

    } while (choice != 4);

    return 0;
}
