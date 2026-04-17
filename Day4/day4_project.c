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

int findStudentById(struct Student students[], int count, int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void printStudent(struct Student student, int index) {
    printf("\n--- Student %d ---\n", index + 1);
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Progress: %.2f\n", student.progress);
    printf("Status: ");
    showStatus(student.status);
    printf("\n");
}

void addStudent(struct Student students[], int *count) {
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("Maximum limit reached. Cannot add more students.\n");
        return;
    }

    printf("Enter student ID: ");
    if (scanf("%d", &students[*count].id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter student name: ");
    if (scanf("%49s", students[*count].name) != 1) {
        printf("Invalid name input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter progress (0-100): ");
    if (scanf("%f", &students[*count].progress) != 1) {
        printf("Invalid progress input.\n");
        clearInputBuffer();
        return;
    }

    updateProgress(&students[*count].progress);

    printf("Choose status:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Enter status: ");

    if (scanf("%d", &statusChoice) != 1) {
        printf("Invalid status input.\n");
        clearInputBuffer();
        return;
    }

    switch (statusChoice) {
        case 1:
            students[*count].status = NOT_STARTED;
            break;
        case 2:
            students[*count].status = IN_PROGRESS;
            break;
        case 3:
            students[*count].status = COMPLETED;
            break;
        default:
            printf("Invalid status choice. Record not added.\n");
            return;
    }

    (*count)++;
    printf("Student record added successfully.\n");
}

void showAllStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("No student records saved yet.\n");
        return;
    }

    printf("\n=== ALL STUDENT RECORDS ===\n");
    for (i = 0; i < count; i++) {
        printStudent(students[i], i);
    }
}

void showReport(struct Student students[], int count) {
    int i;
    int completedCount = 0;
    float totalProgress = 0;
    float highest, lowest, average;

    if (count == 0) {
        printf("No records available for report.\n");
        return;
    }

    highest = students[0].progress;
    lowest = students[0].progress;

    for (i = 0; i < count; i++) {
        totalProgress += students[i].progress;

        if (students[i].status == COMPLETED) {
            completedCount++;
        }

        if (students[i].progress > highest) {
            highest = students[i].progress;
        }

        if (students[i].progress < lowest) {
            lowest = students[i].progress;
        }
    }

    average = totalProgress / count;

    printf("\n=== STUDENT REPORT ===\n");
    printf("Total records: %d\n", count);
    printf("Completed students: %d\n", completedCount);
    printf("Average progress: %.2f\n", average);
    printf("Highest progress: %.2f\n", highest);
    printf("Lowest progress: %.2f\n", lowest);

    if (average >= 80) {
        printf("Class performance: Excellent\n");
    } else if (average >= 50) {
        printf("Class performance: Good\n");
    } else {
        printf("Class performance: Needs improvement\n");
    }
}

void modifyStudentProgress(struct Student students[], int count) {
    int id;
    int index;
    float newProgress;

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("Enter student ID to update progress: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    index = findStudentById(students, count, id);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Current progress: %.2f\n", students[index].progress);
    printf("Enter new progress: ");
    if (scanf("%f", &newProgress) != 1) {
        printf("Invalid progress input.\n");
        clearInputBuffer();
        return;
    }

    students[index].progress = newProgress;
    updateProgress(&students[index].progress);

    if (students[index].progress >= 100) {
        students[index].status = COMPLETED;
    } else if (students[index].progress > 0) {
        students[index].status = IN_PROGRESS;
    } else {
        students[index].status = NOT_STARTED;
    }

    printf("Student progress updated successfully.\n");
}

void searchStudent(struct Student students[], int count) {
    int choice;
    int id;
    char name[50];
    int i, found = 0;

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid choice input.\n");
        clearInputBuffer();
        return;
    }

    if (choice == 1) {
        printf("Enter ID: ");
        if (scanf("%d", &id) != 1) {
            printf("Invalid ID input.\n");
            clearInputBuffer();
            return;
        }

        for (i = 0; i < count; i++) {
            if (students[i].id == id) {
                printStudent(students[i], i);

                if (students[i].progress < 40 && students[i].status != COMPLETED) {
                    printf("Warning: Low progress, student needs more practice.\n");
                } else if (students[i].progress >= 40 && students[i].progress < 80) {
                    printf("Recommendation: Student is improving, keep working.\n");
                } else {
                    printf("Great job: Student is performing very well.\n");
                }

                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter name: ");
        if (scanf("%49s", name) != 1) {
            printf("Invalid name input.\n");
            clearInputBuffer();
            return;
        }

        for (i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printStudent(students[i], i);

                if (students[i].progress < 40 && students[i].status != COMPLETED) {
                    printf("Warning: Low progress, student needs more practice.\n");
                } else if (students[i].progress >= 40 && students[i].progress < 80) {
                    printf("Recommendation: Student is improving, keep working.\n");
                } else {
                    printf("Great job: Student is performing very well.\n");
                }

                found = 1;
            }
        }
    } else {
        printf("Invalid search choice.\n");
        return;
    }

    if (!found) {
        printf("No matching student found.\n");
    }
}

void rankStudents(struct Student students[], int count) {
    int i, j;
    struct Student temp;

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (students[j].progress > students[i].progress) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n=== STUDENT RANKING BY PROGRESS ===\n");
    for (i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i + 1, students[i].name, students[i].progress);
    }
}

void editStudent(struct Student students[], int count) {
    int id;
    int index;
    int option;
    int statusChoice;

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("Enter student ID to edit: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    index = findStudentById(students, count, id);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("What do you want to edit?\n");
    printf("1. Name\n");
    printf("2. Status\n");
    printf("Enter choice: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid option input.\n");
        clearInputBuffer();
        return;
    }

    switch (option) {
        case 1:
            printf("Enter new name: ");
            if (scanf("%49s", students[index].name) != 1) {
                printf("Invalid name input.\n");
                clearInputBuffer();
                return;
            }
            printf("Name updated successfully.\n");
            break;

        case 2:
            printf("Choose new status:\n");
            printf("1. Not Started\n");
            printf("2. In Progress\n");
            printf("3. Completed\n");
            printf("Enter status: ");
            if (scanf("%d", &statusChoice) != 1) {
                printf("Invalid status input.\n");
                clearInputBuffer();
                return;
            }

            switch (statusChoice) {
                case 1:
                    students[index].status = NOT_STARTED;
                    break;
                case 2:
                    students[index].status = IN_PROGRESS;
                    break;
                case 3:
                    students[index].status = COMPLETED;
                    break;
                default:
                    printf("Invalid status choice.\n");
                    return;
            }

            printf("Status updated successfully.\n");
            break;

        default:
            printf("Invalid edit option.\n");
    }
}

void deleteStudent(struct Student students[], int *count) {
    int id;
    int index;
    int i;

    if (*count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("Enter student ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    index = findStudentById(students, *count, id);

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student deleted successfully.\n");
}

void showMenu() {
    printf("\n========== STUDENT PROGRESS TRACKER ==========\n");
    printf("1. Add student record\n");
    printf("2. Show all student records\n");
    printf("3. Show report\n");
    printf("4. Update student progress\n");
    printf("5. Search student\n");
    printf("6. Rank students by progress\n");
    printf("7. Edit student\n");
    printf("8. Delete student\n");
    printf("9. Exit\n");
    printf("==============================================\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        showMenu();
        printf("Current records: %d / %d\n", count, MAX_STUDENTS);
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid menu input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showAllStudents(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                modifyStudentProgress(students, count);
                break;
            case 5:
                searchStudent(students, count);
                break;
            case 6:
                rankStudents(students, count);
                break;
            case 7:
                editStudent(students, count);
                break;
            case 8:
                deleteStudent(students, &count);
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu choice. Please choose from 1 to 9.\n");
        }

    } while (choice != 9);

    return 0;
}
