#include <stdio.h>

#define MAX_STUDENTS 5

enum Status {
    NEEDS_IMPROVEMENT = 1,
    READY_FOR_PROGRESS,
    READY_FOR_CHALLENGE
};

struct Student {
    int id;
    char name[50];
    double progress;
    enum Status status;
};

void addStudent(struct Student students[], int *count);
void showStudents(struct Student students[], int count);
void showStatusMessage(enum Status status);
void showReport(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Progress Tracker =====\n");
        printf("1. Add student record\n");
        printf("2. Show all records\n");
        printf("3. Show report\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                showStudents(students, count);
                break;
            case 3:
                showReport(students, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid menu choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void addStudent(struct Student students[], int *count) {
    int statusChoice;

    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of records reached!\n");
        return;
    }

    printf("\nEnter student ID: ");
    scanf("%d", &students[*count].id);

    printf("Enter student name: ");
    scanf("%s", students[*count].name);

    printf("Enter progress score: ");
    scanf("%lf", &students[*count].progress);

    printf("\nChoose status:\n");
    printf("1. Needs Improvement\n");
    printf("2. Ready for Progress\n");
    printf("3. Ready for Challenge\n");
    printf("Enter status choice: ");
    scanf("%d", &statusChoice);

    switch (statusChoice) {
        case 1:
            students[*count].status = NEEDS_IMPROVEMENT;
            break;
        case 2:
            students[*count].status = READY_FOR_PROGRESS;
            break;
        case 3:
            students[*count].status = READY_FOR_CHALLENGE;
            break;
        default:
            printf("Invalid status choice! Record not saved.\n");
            return;
    }

    (*count)++;
    printf("Student record added successfully.\n");
}

void showStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n===== Saved Student Records =====\n");
    for (i = 0; i < count; i++) {
        printf("\nRecord %d\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2lf\n", students[i].progress);
        printf("Status: ");
        showStatusMessage(students[i].status);
    }
}

void showStatusMessage(enum Status status) {
    switch (status) {
        case NEEDS_IMPROVEMENT:
            printf("Needs Improvement\n");
            break;
        case READY_FOR_PROGRESS:
            printf("Ready for Progress\n");
            break;
        case READY_FOR_CHALLENGE:
            printf("Ready for Challenge\n");
            break;
        default:
            printf("Unknown Status\n");
    }
}

void showReport(struct Student students[], int count) {
    int i;
    int needsImprovementCount = 0;
    int readyForProgressCount = 0;
    int readyForChallengeCount = 0;
    double totalProgress = 0;
    double averageProgress = 0;
    double highestProgress, lowestProgress;

    if (count == 0) {
        printf("\nNo records available for report.\n");
        return;
    }

    highestProgress = students[0].progress;
    lowestProgress = students[0].progress;

    for (i = 0; i < count; i++) {
        totalProgress += students[i].progress;

        if (students[i].progress > highestProgress) {
            highestProgress = students[i].progress;
        }

        if (students[i].progress < lowestProgress) {
            lowestProgress = students[i].progress;
        }

        if (students[i].status == NEEDS_IMPROVEMENT) {
            needsImprovementCount++;
        } else if (students[i].status == READY_FOR_PROGRESS) {
            readyForProgressCount++;
        } else if (students[i].status == READY_FOR_CHALLENGE) {
            readyForChallengeCount++;
        }
    }

    averageProgress = totalProgress / count;

    printf("\n===== Student Progress Report =====\n");
    printf("Total records: %d\n", count);
    printf("Average progress: %.2lf\n", averageProgress);
    printf("Highest progress: %.2lf\n", highestProgress);
    printf("Lowest progress: %.2lf\n", lowestProgress);
    printf("Needs Improvement: %d\n", needsImprovementCount);
    printf("Ready for Progress: %d\n", readyForProgressCount);
    printf("Ready for Challenge: %d\n", readyForChallengeCount);

    if (averageProgress >= 85) {
        printf("Class performance: Excellent\n");
    } else if (averageProgress >= 65) {
        printf("Class performance: Good\n");
    } else if (averageProgress >= 50) {
        printf("Class performance: Average\n");
    } else {
        printf("Class performance: Needs more work\n");
    }
}
