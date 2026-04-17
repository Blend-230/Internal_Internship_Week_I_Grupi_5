#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
};

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

void clearInputBuffer();
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void showReport(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void updateStudent(struct Student students[], int count);
void updateStudentProgress(struct Student *student);
void editStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);
void sortStudentsByProgress(struct Student students[], int count);
void printStudentDetails(struct Student student, int recordNumber);
void printRecommendation(struct Student student);
const char* getStatusText(enum Status status);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int result;

    do {
        printf("\n========== STUDENT PROGRESS TRACKER ==========\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Show Analytical Report\n");
        printf("4. Update Student Progress\n");
        printf("5. Search Student\n");
        printf("6. Rank Students by Progress\n");
        printf("7. Edit Student Record\n");
        printf("8. Delete Student Record\n");
        printf("9. Exit\n");
        printf("Choose an option: ");

        result = scanf("%d", &choice);

        if (result != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                searchStudent(students, count);
                break;
            case 6:
                sortStudentsByProgress(students, count);
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
                printf("Invalid menu choice. Please select from 1 to 9.\n");
        }

    } while (choice != 9);

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

void addStudent(struct Student students[], int *count) {
    int result;
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of records reached. Cannot add more students.\n");
        return;
    }

    printf("\nEnter student ID: ");
    result = scanf("%d", &students[*count].id);
    if (result != 1) {
        printf("Invalid ID input. Record was not added.\n");
        clearInputBuffer();
        return;
    }

    clearInputBuffer();

    printf("Enter student name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Enter progress (0 - 100): ");
    result = scanf("%f", &students[*count].progress);
    if (result != 1) {
        printf("Invalid progress input. Record was not added.\n");
        clearInputBuffer();
        return;
    }

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Invalid progress value. It must be between 0 and 100.\n");
        return;
    }

    printf("\nChoose student status:\n");
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
    printf("Enter status choice: ");

    result = scanf("%d", &statusChoice);
    if (result != 1) {
        printf("Invalid status input. Record was not added.\n");
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
            printf("Invalid status choice. Record was not added.\n");
            return;
    }

    (*count)++;
    printf("Student record added successfully.\n");
}

void displayStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== STORED STUDENT RECORDS ==========\n");
    for (i = 0; i < count; i++) {
        printStudentDetails(students[i], i + 1);
    }
}

void showReport(struct Student students[], int count) {
    int i;
    int completedCount = 0;
    float totalProgress = 0;
    float averageProgress;
    float highestProgress;
    float lowestProgress;

    if (count == 0) {
        printf("\n========== ANALYTICAL REPORT ==========\n");
        printf("No records available yet.\n");
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

    printf("\n========== ANALYTICAL REPORT ==========\n");
    printf("Total Records: %d\n", count);
    printf("Completed Students: %d\n", completedCount);
    printf("Average Progress: %.2f\n", averageProgress);
    printf("Highest Progress: %.2f\n", highestProgress);
    printf("Lowest Progress: %.2f\n", lowestProgress);

    if (averageProgress >= 85) {
        printf("Performance Message: Overall progress is excellent.\n");
    } else if (averageProgress >= 50) {
        printf("Performance Message: Overall progress is satisfactory.\n");
    } else {
        printf("Performance Message: Overall progress needs improvement.\n");
    }
}

void updateStudent(struct Student students[], int count) {
    int searchId;
    int result;
    int i;
    int found = 0;

    if (count == 0) {
        printf("\nNo student records available to update.\n");
        return;
    }

    printf("\nEnter student ID to update progress: ");
    result = scanf("%d", &searchId);
    if (result != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    for (i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("\nStudent found before update:\n");
            printStudentDetails(students[i], i + 1);

            updateStudentProgress(&students[i]);

            printf("\nStudent record after update:\n");
            printStudentDetails(students[i], i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with that ID.\n");
    }
}

void updateStudentProgress(struct Student *student) {
    float newProgress;
    int result;

    printf("Enter new progress (0 - 100): ");
    result = scanf("%f", &newProgress);
    if (result != 1) {
        printf("Invalid progress input. Update cancelled.\n");
        clearInputBuffer();
        return;
    }

    if (newProgress < 0 || newProgress > 100) {
        printf("Invalid progress value. Update cancelled.\n");
        return;
    }

    student->progress = newProgress;

    if (student->progress == 0) {
        student->status = NOT_STARTED;
    } else if (student->progress < 100) {
        student->status = IN_PROGRESS;
    } else {
        student->status = COMPLETED;
    }

    printf("Student progress updated successfully using pointer.\n");
}

void searchStudent(struct Student students[], int count) {
    int searchChoice;
    int result;
    int searchId;
    char searchName[50];
    int i;
    int found = 0;

    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    printf("\n========== SEARCH STUDENT ==========\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Choose search option: ");

    result = scanf("%d", &searchChoice);
    if (result != 1) {
        printf("Invalid search option input.\n");
        clearInputBuffer();
        return;
    }

    switch (searchChoice) {
        case 1:
            printf("Enter student ID to search: ");
            result = scanf("%d", &searchId);
            if (result != 1) {
                printf("Invalid ID input.\n");
                clearInputBuffer();
                return;
            }

            for (i = 0; i < count; i++) {
                if (students[i].id == searchId) {
                    printStudentDetails(students[i], i + 1);
                    printRecommendation(students[i]);
                    found = 1;
                }
            }
            break;

        case 2:
            clearInputBuffer();
            printf("Enter student name to search: ");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            for (i = 0; i < count; i++) {
                if (strcmp(students[i].name, searchName) == 0) {
                    printStudentDetails(students[i], i + 1);
                    printRecommendation(students[i]);
                    found = 1;
                }
            }
            break;

        default:
            printf("Invalid search menu choice.\n");
            return;
    }

    if (!found) {
        printf("No matching record found.\n");
    }
}

void sortStudentsByProgress(struct Student students[], int count) {
    int i, j;
    struct Student temp;

    if (count == 0) {
        printf("\nNo student records available to rank.\n");
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

    printf("\n========== STUDENT RANKING BY PROGRESS ==========\n");
    for (i = 0; i < count; i++) {
        printf("\nRank #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);
        printf("Status: %s\n", getStatusText(students[i].status));
    }
}

void editStudent(struct Student students[], int count) {
    int searchId;
    int result;
    int i;
    int found = 0;
    int newStatus;

    if (count == 0) {
        printf("\nNo student records available to edit.\n");
        return;
    }

    printf("\nEnter student ID to edit: ");
    result = scanf("%d", &searchId);
    if (result != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    for (i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            clearInputBuffer();

            printf("\nStudent found:\n");
            printStudentDetails(students[i], i + 1);

            printf("\nEnter new name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter new status:\n");
            printf("1. Not Started\n");
            printf("2. In Progress\n");
            printf("3. Completed\n");
            printf("Choose new status: ");

            result = scanf("%d", &newStatus);
            if (result != 1) {
                printf("Invalid status input. Edit cancelled.\n");
                clearInputBuffer();
                return;
            }

            switch (newStatus) {
                case 1:
                    students[i].status = NOT_STARTED;
                    break;
                case 2:
                    students[i].status = IN_PROGRESS;
                    break;
                case 3:
                    students[i].status = COMPLETED;
                    break;
                default:
                    printf("Invalid status choice. Edit cancelled.\n");
                    return;
            }

            printf("Student record updated successfully.\n");
            printStudentDetails(students[i], i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with that ID.\n");
    }
}

void deleteStudent(struct Student students[], int *count) {
    int searchId;
    int result;
    int i, j;
    int found = 0;

    if (*count == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    printf("\nEnter student ID to delete: ");
    result = scanf("%d", &searchId);
    if (result != 1) {
        printf("Invalid ID input.\n");
        clearInputBuffer();
        return;
    }

    for (i = 0; i < *count; i++) {
        if (students[i].id == searchId) {
            found = 1;

            for (j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("Student record deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("No student found with that ID.\n");
    }
}

void printStudentDetails(struct Student student, int recordNumber) {
    printf("\nRecord #%d\n", recordNumber);
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Progress: %.2f\n", student.progress);
    printf("Status: %s\n", getStatusText(student.status));
}

void printRecommendation(struct Student student) {
    printf("Evaluation: ");

    if (student.progress < 50 && student.status == NOT_STARTED) {
        printf("Urgent attention needed. Student has very low progress and has not started properly.\n");
    } else if (student.progress < 50 && student.status == IN_PROGRESS) {
        printf("Student has started, but progress is still low. More support is recommended.\n");
    } else if (student.progress >= 50 && student.progress < 100 && student.status == IN_PROGRESS) {
        printf("Student is making acceptable progress. Keep working consistently.\n");
    } else if (student.progress == 100 && student.status == COMPLETED) {
        printf("Excellent result. Student has fully completed the progress successfully.\n");
    } else if (student.progress >= 80 && student.status == COMPLETED) {
        printf("Very good performance. The student is in a strong position.\n");
    } else {
        printf("Record found. Monitor this student for further updates.\n");
    }
}

const char* getStatusText(enum Status status) {
    switch (status) {
        case NOT_STARTED:
            return "Not Started";
        case IN_PROGRESS:
            return "In Progress";
        case COMPLETED:
            return "Completed";
        default:
            return "Unknown";
    }
}
