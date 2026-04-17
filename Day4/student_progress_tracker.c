#include <stdio.h>
#include <string.h>

#define MAX 5

// Enum
enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

// Struct
struct Student {
    int id;
    char name[50];
    int progress;
    enum Status status;
};

struct Student students[MAX];
int count = 0;

// ---------- UTILITY ----------
void printStatus(enum Status status) {
    switch(status) {
        case NOT_STARTED: printf("Not Started"); break;
        case IN_PROGRESS: printf("In Progress"); break;
        case COMPLETED: printf("Completed"); break;
    }
}

// ---------- STATUS INPUT ----------
enum Status chooseStatus() {
    int choice;
    printf("Select Status (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: return NOT_STARTED;
        case 2: return IN_PROGRESS;
        case 3: return COMPLETED;
        default:
            printf("Invalid! Default = Not Started\n");
            return NOT_STARTED;
    }
}

// ---------- ADD ----------
void addStudent() {
    if (count >= MAX) {
        printf("Max capacity reached!\n");
        return;
    }

    struct Student *s = &students[count];

    printf("ID: ");
    scanf("%d", &s->id);

    printf("Name: ");
    scanf("%s", s->name);

    printf("Progress (0-100): ");
    scanf("%d", &s->progress);

    if (s->progress < 0 || s->progress > 100)
        s->progress = 0;

    s->status = chooseStatus();

    count++;
    printf("Added successfully!\n");
}

// ---------- DISPLAY ----------
void displayStudents() {
    if (count == 0) {
        printf("No data.\n");
        return;
    }

    printf("\n==== STUDENTS ====\n");

    for (int i = 0; i < count; i++) {
        printf("\n[%d]\n", i);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %d\n", students[i].progress);
        printf("Status: ");
        printStatus(students[i].status);
        printf("\n");
    }
}

// ---------- UPDATE (POINTER) ----------
void updateStudent(struct Student *s) {
    int newProgress;

    printf("New progress: ");
    scanf("%d", &newProgress);

    if (newProgress < 0 || newProgress > 100) {
        printf("Invalid.\n");
        return;
    }

    s->progress = newProgress;
    s->status = chooseStatus();

    printf("Updated.\n");
}

void findAndUpdate() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]);
            return;
        }
    }

    printf("Not found.\n");
}

// ---------- DELETE ----------
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            // shift left
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;
            printf("Deleted.\n");
            return;
        }
    }

    printf("Not found.\n");
}

// ---------- SEARCH ----------
void searchStudent() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nFound:\n");
            printf("Name: %s\n", students[i].name);
            printf("Progress: %d\n", students[i].progress);

            printf("Evaluation: ");
            if (students[i].progress < 40)
                printf("Needs improvement\n");
            else if (students[i].progress < 80)
                printf("On track\n");
            else
                printf("Excellent\n");

            return;
        }
    }

    printf("Not found.\n");
}

// ---------- REPORT ----------
void showReport() {
    if (count == 0) {
        printf("No data.\n");
        return;
    }

    int sum = 0, max = students[0].progress, min = students[0].progress;

    for (int i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].progress > max) max = students[i].progress;
        if (students[i].progress < min) min = students[i].progress;
    }

    double avg = (double)sum / count;

    printf("\n==== REPORT ====\n");
    printf("Total: %d\n", count);
    printf("Average: %.2lf\n", avg);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

// ---------- RANK ----------
void rankStudents() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].progress < students[j + 1].progress) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n==== RANKING ====\n");
    displayStudents();
}

// ---------- MAIN ----------
int main() {
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add\n");
        printf("2. View\n");
        printf("3. Report\n");
        printf("4. Update\n");
        printf("5. Search\n");
        printf("6. Rank\n");
        printf("7. Delete\n");
        printf("0. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: showReport(); break;
            case 4: findAndUpdate(); break;
            case 5: searchStudent(); break;
            case 6: rankStudents(); break;
            case 7: deleteStudent(); break;
            case 0: printf("Exit.\n"); break;
            default: printf("Invalid.\n");
        }

    } while (choice != 0);

    return 0;
}