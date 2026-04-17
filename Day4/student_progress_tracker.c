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
const char* getStatusText(enum Status status);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;
    int result;

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Show Report\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        result = scanf("%d", &choice);

        if (result != 1) {
            printf("Invalid input. Please enter a number from the menu.\n");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu choice. Please select 1, 2, 3, or 4.\n");
        }

    } while (choice != 4);

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

    printf("\n===== STORED STUDENT RECORDS =====\n");
    for (i = 0; i < count; i++) {
        printf("\nRecord #%d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);
        printf("Status: %s\n", getStatusText(students[i].status));
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
        printf("\n===== ANALYTICAL REPORT =====\n");
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

    printf("\n===== ANALYTICAL REPORT =====\n");
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
