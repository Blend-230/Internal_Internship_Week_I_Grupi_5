#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

/* ========================= */
Status chooseStatus() {
    int choice;

    while (1) {
        printf("\nChoose Status:\n");
        printf("1. Not Started\n");
        printf("2. In Progress\n");
        printf("3. Completed\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: return NOT_STARTED;
            case 2: return IN_PROGRESS;
            case 3: return COMPLETED;
            default: printf("Invalid choice!\n");
        }
    }
}

/* ========================= */
void addStudent(Student *s) {
    printf("\n--- Add Student ---\n");

    printf("ID: ");
    scanf("%d", &s->id);

    printf("Name: ");
    scanf("%s", s->name);

    printf("Progress (0-100): ");
    scanf("%f", &s->progress);

    while (s->progress < 0 || s->progress > 100) {
        printf("Invalid! Try again: ");
        scanf("%f", &s->progress);
    }

    s->status = chooseStatus();
}

/* ========================= */
void displayStudents(Student students[], int count) {
    printf("\n===== STUDENT LIST =====\n");

    if (count == 0) {
        printf("No students.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("%d. %s | %.2f\n", i+1, students[i].name, students[i].progress);
    }
}

/* ========================= */
void generateReport(Student students[], int count) {
    if (count == 0) return;

    float sum = 0, max = students[0].progress, min = students[0].progress;

    for (int i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].progress > max) max = students[i].progress;
        if (students[i].progress < min) min = students[i].progress;
    }

    printf("\nAverage: %.2f\nMax: %.2f\nMin: %.2f\n",
           sum/count, max, min);
}

/* ========================= */
void searchStudent(Student students[], int count) {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found: %s %.2f\n", students[i].name, students[i].progress);
            return;
        }
    }

    printf("Not found!\n");
}

/* ========================= */
void updateStudent(Student *s) {
    int choice;

    printf("\n1. Name\n2. Progress\n3. Status\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("New name: ");
            scanf("%s", s->name);
            break;

        case 2:
            printf("New progress: ");
            scanf("%f", &s->progress);
            break;

        case 3:
            s->status = chooseStatus();
            break;

        default:
            printf("Invalid!\n");
    }
}

/* ========================= */
void updateStudentById(Student students[], int count) {
    int id;

    printf("Enter ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]);
            return;
        }
    }

    printf("Student not found!\n");
}

/* ========================= */
void deleteStudent(Student students[], int *count) {
    int id;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {

            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;
            printf("Deleted successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

/* ========================= */
void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].progress < students[j].progress) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    printf("\n===== RANKING =====\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %.2f\n", i+1, students[i].name, students[i].progress);
    }
}

/* ========================= */
int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice;

    while (1) {
        printf("\n==== MENU ====\n");
        printf("1. Add\n2. Show\n3. Report\n4. Search\n5. Update\n6. Delete\n7. Rank\n8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < MAX_STUDENTS)
                    addStudent(&students[count++]);
                else
                    printf("Limit reached!\n");
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                generateReport(students, count);
                break;

            case 4:
                searchStudent(students, count);
                break;

            case 5:
                updateStudentById(students, count);
                break;

            case 6:
                deleteStudent(students, &count);
                break;

            case 7:
                sortStudents(students, count);
                break;

            case 8:
                return 0;

            default:
                printf("Invalid option!\n");
        }
    }
}
