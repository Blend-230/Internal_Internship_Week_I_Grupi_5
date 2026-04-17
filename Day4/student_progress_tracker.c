#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

enum Status {
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
};

struct Student {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
const char* getStatusText(enum Status status);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== STUDENT PROGRESS TRACKER =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of records reached. Cannot add more students.\n");
        return;
    }

    printf("\nEnter student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter student name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter progress (0 - 100): ");
    scanf("%f", &students[*count].progress);

    if (students[*count].progress < 0 || students[*count].progress > 100) {
        printf("Invalid progress. Setting progress to 0.\n");
        students[*count].progress = 0;
    }

    if (students[*count].progress == 0) {
        students[*count].status = NOT_STARTED;
    } else if (students[*count].progress < 100) {
        students[*count].status = IN_PROGRESS;
    } else {
        students[*count].status = COMPLETED;
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
