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

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

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

void printStudent(struct Student student) {
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Progress: %.2f\n", student.progress);
    printf("Status: ");
    showStatus(student.status);
    printf("\n");
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

void modifyStudentProgress(struct Student *student) {
    float oldProgress, newProgress;

    oldProgress = student->progress;

    printf("Current progress: %.2f\n", student->progress);
    printf("Enter new progress (0-100): ");

    if (scanf("%f", &newProgress) != 1) {
        printf("Invalid progress input.\n");
        clearInputBuffer();
        return;
    }

    student->progress = newProgress;
    updateProgress(&student->progress);

    if (student->progress == 100) {
        student->status = COMPLETED;
    } else if (student->progress > 0) {
        student->status = IN_PROGRESS;
    } else {
        student->status = NOT_STARTED;
    }

    printf("Address of selected student: %p\n", (void *)student);
    printf("Old progress: %.2f\n", oldProgress);
    printf("New progress: %.2f\n", student->progress);

    if (student->progress > oldProgress) {
        printf("Result: Progress increased.\n");
    } else if (student->progress < oldProgress) {
        printf("Result: Progress decreased.\n");
    } else {
        printf("Result: Progress stayed the same.\n");
    }
}

void showRecommendation(struct Student student) {
    printf("Recommendation: ");

    if (student.progress < 40 && student.status == NOT_STARTED) {
        printf("Urgent warning - student has very low progress and has not started yet.\n");
    } else if (student.progress < 40 && student.status == IN_PROGRESS) {
        printf("Warning - student needs much more practice.\n");
    } else if (student.progress >= 40 && student.progress < 70 && student.status == IN_PROGRESS) {
        printf("Student is improving, but still needs more work.\n");
    } else if (student.progress >= 70 && student.progress < 100 && student.status == IN_PROGRESS) {
        printf("Good progress - student is close to completion.\n");
    } else if (student.progress == 100 && student.status == COMPLETED) {
        printf("Excellent - student completed all progress.\n");
    } else if (student.progress >= 70 && student.status == NOT_STARTED) {
        printf("Check data - progress is high but status says Not Started.\n");
    } else if (student.progress == 0 && student.status == COMPLETED) {
        printf("Check data - completed status does not match the progress.\n");
    } else {
        printf("Student record is valid. Continue monitoring progress.\n");
    }
}

void searchById(struct Student students[], int count) {
    int searchId;
    int i;
    int found = 0;

    printf("Enter ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    for (i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("\n--- Matching Record ---\n");
            printStudent(students[i]);
            showRecommendation(students[i]);
            printf("-----------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with ID %d.\n", searchId);
    }
}

void searchByName(struct Student students[], int count) {
    char searchName[50];
    int i;
    int found = 0;

    printf("Enter name to search: ");
    if (scanf("%49s", searchName) != 1) {
        printf("Invalid name input.\n");
        clearInputBuffer();
        return;
    }

    for (i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n--- Matching Record ---\n");
            printStudent(students[i]);
            showRecommendation(students[i]);
            printf("-----------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with name %s.\n", searchName);
    }
}

void searchStudent(struct Student students[], int count) {
    int searchChoice;

    if (count == 0) {
        printf("No student records available for search.\n");
        return;
    }

    printf("\n--- Search Student ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Enter choice: ");

    if (scanf("%d", &searchChoice) != 1) {
        printf("Invalid search menu input.\n");
        clearInputBuffer();
        return;
    }

    switch (searchChoice) {
        case 1:
            searchById(students, count);
            break;
        case 2:
            searchByName(students, count);
            break;
        default:
            printf("Invalid search option.\n");
    }
}

void rankStudents(struct Student students[], int count) {
    struct Student temp[MAX_STUDENTS];
    struct Student swap;
    int i, j;

    if (count == 0) {
        printf("No student records available for ranking.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        temp[i] = students[i];
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (temp[j].progress > temp[i].progress) {
                swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    printf("\n--- Student Ranking by Progress ---\n");
    for (i = 0; i < count; i++) {
        printf("Rank %d\n", i + 1);
        printStudent(temp[i]);

        if (temp[i].progress >= 80) {
            printf("Level: Top performer\n");
        } else if (temp[i].progress >= 50) {
            printf("Level: Medium progress\n");
        } else {
            printf("Level: Needs more work\n");
        }

        printf("-------------------------\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int statusChoice;
    int i;
    int searchId;
    int foundIndex;

    do {
        printf("\n=== Student Progress Tracker ===\n");
        printf("1. Add student record\n");
        printf("2. Show all student records\n");
        printf("3. Show progress report\n");
        printf("4. Update student progress\n");
        printf("5. Search student\n");
        printf("6. Rank students by progress\n");
        printf("7. Exit\n");
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
                        printStudent(students[i]);
                        printf("-------------------------\n");
                    }
                }
                break;

            case 3:
                showReport(students, count);
                break;

            case 4:
                if (count == 0) {
                    printf("No student records available to update.\n");
                    break;
                }

                printf("Enter student ID to update: ");
                if (scanf("%d", &searchId) != 1) {
                    printf("Invalid ID input.\n");
                    clearInputBuffer();
                    break;
                }

                foundIndex = -1;
                for (i = 0; i < count; i++) {
                    if (students[i].id == searchId) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    printf("Student with ID %d not found.\n", searchId);
                } else {
                    modifyStudentProgress(&students[foundIndex]);
                    printf("Student progress updated successfully.\n");
                }
                break;

            case 5:
                searchStudent(students, count);
                break;

            case 6:
                rankStudents(students, count);
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid menu choice. Please choose 1, 2, 3, 4, 5, 6, or 7.\n");
        }

    } while (choice != 7);

    return 0;
}
