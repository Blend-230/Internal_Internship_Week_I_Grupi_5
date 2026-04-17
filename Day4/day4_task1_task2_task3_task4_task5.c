#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5

/* =========================
   ENUM STATUS
========================= */
typedef enum {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
} Status;

/* =========================
   STRUCT STUDENT
========================= */
typedef struct {
    int id;
    char name[50];
    float progress;
    Status status;
} Student;

/* =========================
   STATUS SELECTION
========================= */
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
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

/* =========================
   ADD STUDENT (POINTER)
========================= */
void addStudent(Student *s) {
    printf("\n--- Add Student ---\n");

    printf("Enter ID: ");
    scanf("%d", &s->id);

    printf("Enter Name: ");
    scanf("%s", s->name);

    printf("Enter Progress (0-100): ");
    scanf("%f", &s->progress);

    while (s->progress < 0 || s->progress > 100) {
        printf("Invalid! Enter again (0-100): ");
        scanf("%f", &s->progress);
    }

    s->status = chooseStatus();

    printf("Student added successfully!\n");
}

/* =========================
   DISPLAY STUDENTS
========================= */
void displayStudents(Student students[], int count) {
    printf("\n--- Student List ---\n");

    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Progress: %.2f\n", students[i].progress);

        printf("Status: ");
        switch (students[i].status) {
            case NOT_STARTED:
                printf("Not Started\n");
                break;
            case IN_PROGRESS:
                printf("In Progress\n");
                break;
            case COMPLETED:
                printf("Completed\n");
                break;
        }
    }
}

/* =========================
   REPORT (ANALYTICS)
========================= */
void generateReport(Student students[], int count) {
    printf("\n===== STUDENT REPORT =====\n");

    if (count == 0) {
        printf("No data available.\n");
        return;
    }

    int completed = 0;
    float sum = 0;
    float max = students[0].progress;
    float min = students[0].progress;

    for (int i = 0; i < count; i++) {
        sum += students[i].progress;

        if (students[i].status == COMPLETED)
            completed++;

        if (students[i].progress > max)
            max = students[i].progress;

        if (students[i].progress < min)
            min = students[i].progress;
    }

    float avg = sum / count;

    printf("Total Students: %d\n", count);
    printf("Completed: %d\n", completed);
    printf("Average Progress: %.2f\n", avg);
    printf("Highest Progress: %.2f\n", max);
    printf("Lowest Progress: %.2f\n", min);

    printf("\nPerformance: ");
    if (avg >= 80)
        printf("Excellent\n");
    else if (avg >= 50)
        printf("Good\n");
    else
        printf("Needs Improvement\n");
}

/* =========================
   SEARCH SYSTEM
========================= */
void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to search.\n");
        return;
    }

    int choice, id;
    char name[50];
    int found = 0;

    printf("\nSearch by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter ID: ");
        scanf("%d", &id);

        for (int i = 0; i < count; i++) {
            if (students[i].id == id) {
                printf("\n--- Student Found ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);

                found = 1;

                if (students[i].progress < 50)
                    printf("Warning: Low performance!\n");
                else if (students[i].progress >= 80)
                    printf("Excellent performance!\n");
                else
                    printf("Good progress.\n");
            }
        }
    }
    else if (choice == 2) {
        printf("Enter Name: ");
        scanf("%s", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(students[i].name, name) == 0) {
                printf("\n--- Student Found ---\n");
                printf("ID: %d\n", students[i].id);
                printf("Name: %s\n", students[i].name);
                printf("Progress: %.2f\n", students[i].progress);

                found = 1;

                if (students[i].progress < 50)
                    printf("Warning: Low performance!\n");
                else if (students[i].progress >= 80)
                    printf("Excellent performance!\n");
                else
                    printf("Good progress.\n");
            }
        }
    }
    else {
        printf("Invalid choice!\n");
        return;
    }

    if (!found)
        printf("No matching student found.\n");
}

/* =========================
   UPDATE SYSTEM (POINTER)
========================= */
void updateStudent(Student *s) {
    printf("\n--- Update Student ---\n");

    printf("Current Progress: %.2f\n", s->progress);

    printf("Enter new Progress (0-100): ");
    scanf("%f", &s->progress);

    while (s->progress < 0 || s->progress > 100) {
        printf("Invalid! Enter again: ");
        scanf("%f", &s->progress);
    }

    if (s->progress == 0)
        s->status = NOT_STARTED;
    else if (s->progress < 100)
        s->status = IN_PROGRESS;
    else
        s->status = COMPLETED;

    printf("Student updated successfully!\n");
}

/* =========================
   UPDATE BY ID
========================= */
void updateStudentById(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students available.\n");
        return;
    }

    int id, found = 0;

    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            updateStudent(&students[i]); // POINTER REAL
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");
}

/* =========================
   MAIN MENU
========================= */
int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n==== STUDENT TRACKER ====\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Show Report\n");
        printf("4. Search Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 6) {
            printf("Invalid option!\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= MAX_STUDENTS)
                    printf("Limit reached!\n");
                else {
                    addStudent(&students[count]);
                    count++;
                }
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
                printf("Exiting...\n");
                return 0;
        }
    }

    return 0;
}
