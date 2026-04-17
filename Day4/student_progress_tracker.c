#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define NAME_LENGTH 50

enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS = 2,
    COMPLETED = 3
};

struct Student {
    int id;
    char name[NAME_LENGTH];
    float progress;
    enum Status status;
};

void clearInputBuffer();
void printMainMenu();
void printStatusMenu();
void printSeparator();
void printSectionTitle(const char title[]);

int readInt(const char prompt[], int *value);
int readFloat(const char prompt[], float *value);
void readLine(const char prompt[], char buffer[], int size);
int isValidProgress(float progress);
int chooseStatus(enum Status *status);

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
int findStudentIndexById(struct Student students[], int count, int id);

const char* getStatusText(enum Status status);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printMainMenu();

        if (!readInt("Choose an option: ", &choice)) {
            printf("Invalid input. Please enter a valid number.\n");
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

void printSeparator() {
    printf("====================================================\n");
}

void printSectionTitle(const char title[]) {
    printf("\n");
    printSeparator();
    printf("%s\n", title);
    printSeparator();
}

void printMainMenu() {
    printSectionTitle("STUDENT PROGRESS TRACKER");
    printf("1. Add Student Record\n");
    printf("2. Display All Records\n");
    printf("3. Show Analytical Report\n");
    printf("4. Update Student Progress\n");
    printf("5. Search Student\n");
    printf("6. Rank Students by Progress\n");
    printf("7. Edit Student Record\n");
    printf("8. Delete Student Record\n");
    printf("9. Exit\n");
}

void printStatusMenu() {
    printf("1. Not Started\n");
    printf("2. In Progress\n");
    printf("3. Completed\n");
}

int readInt(const char prompt[], int *value) {
    int result;
    printf("%s", prompt);
    result = scanf("%d", value);

    if (result != 1) {
        clearInputBuffer();
        return 0;
    }

    return 1;
}

int readFloat(const char prompt[], float *value) {
    int result;
    printf("%s", prompt);
    result = scanf("%f", value);

    if (result != 1) {
        clearInputBuffer();
        return 0;
    }

    return 1;
}

void readLine(const char prompt[], char buffer[], int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int isValidProgress(float progress) {
    return progress >= 0 && progress <= 100;
}

int chooseStatus(enum Status *status) {
    int statusChoice;

    printf("\nChoose student status:\n");
    printStatusMenu();

    if (!readInt("Enter status choice: ", &statusChoice)) {
        printf("Invalid status input.\n");
        return 0;
    }

    switch (statusChoice) {
        case 1:
            *status = NOT_STARTED;
            return 1;
        case 2:
            *status = IN_PROGRESS;
            return 1;
        case 3:
            *status = COMPLETED;
            return 1;
        default:
            printf("Invalid status choice.\n");
            return 0;
    }
}

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of records reached. Cannot add more students.\n");
        return;
    }

    printSectionTitle("ADD STUDENT RECORD");

    if (!readInt("Enter student ID: ", &students[*count].id)) {
        printf("Invalid ID input. Record was not added.\n");
        return;
    }

    clearInputBuffer();
    readLine("Enter student name: ", students[*count].name, NAME_LENGTH);

    if (!readFloat("Enter progress (0 - 100): ", &students[*count].progress)) {
        printf("Invalid progress input. Record was not added.\n");
        return;
    }

    if (!isValidProgress(students[*count].progress)) {
        printf("Invalid progress value. It must be between 0 and 100.\n");
        return;
    }

    if (!chooseStatus(&students[*count].status)) {
        printf("Record was not added.\n");
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

    printSectionTitle("STORED STUDENT RECORDS");

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
        printSectionTitle("ANALYTICAL REPORT");
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

    printSectionTitle("ANALYTICAL REPORT");
    printf("Total Records      : %d\n", count);
    printf("Completed Students : %d\n", completedCount);
    printf("Average Progress   : %.2f\n", averageProgress);
    printf("Highest Progress   : %.2f\n", highestProgress);
    printf("Lowest Progress    : %.2f\n", lowestProgress);

    if (averageProgress >= 85) {
        printf("Performance Message: Overall progress is excellent.\n");
    } else if (averageProgress >= 50) {
        printf("Performance Message: Overall progress is satisfactory.\n");
    } else {
        printf("Performance Message: Overall progress needs improvement.\n");
    }
}

int findStudentIndexById(struct Student students[], int count, int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1;
}

void updateStudent(struct Student students[], int count) {
    int searchId;
    int index;

    if (count == 0) {
        printf("\nNo student records available to update.\n");
        return;
    }

    printSectionTitle("UPDATE STUDENT PROGRESS");

    if (!readInt("Enter student ID to update progress: ", &searchId)) {
        printf("Invalid ID input.\n");
        return;
    }

    index = findStudentIndexById(students, count, searchId);

    if (index == -1) {
        printf("No student found with that ID.\n");
        return;
    }

    printf("\nStudent found before update:\n");
    printStudentDetails(students[index], index + 1);

    updateStudentProgress(&students[index]);

    printf("\nStudent record after update:\n");
    printStudentDetails(students[index], index + 1);
}

void updateStudentProgress(struct Student *student) {
    float newProgress;

    if (!readFloat("Enter new progress (0 - 100): ", &newProgress)) {
        printf("Invalid progress input. Update cancelled.\n");
        return;
    }

    if (!isValidProgress(newProgress)) {
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
    int searchId;
    char searchName[NAME_LENGTH];
    int i;
    int found = 0;

    if (count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    printSectionTitle("SEARCH STUDENT");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");

    if (!readInt("Choose search option: ", &searchChoice)) {
        printf("Invalid search option input.\n");
        return;
    }

    switch (searchChoice) {
        case 1:
            if (!readInt("Enter student ID to search: ", &searchId)) {
                printf("Invalid ID input.\n");
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
            readLine("Enter student name to search: ", searchName, NAME_LENGTH);

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

    printSectionTitle("STUDENT RANKING BY PROGRESS");

    for (i = 0; i < count; i++) {
        printf("\nRank #%d\n", i + 1);
        printf("ID       : %d\n", students[i].id);
        printf("Name     : %s\n", students[i].name);
        printf("Progress : %.2f\n", students[i].progress);
        printf("Status   : %s\n", getStatusText(students[i].status));
    }
}

void editStudent(struct Student students[], int count) {
    int searchId;
    int index;
    enum Status newStatus;

    if (count == 0) {
        printf("\nNo student records available to edit.\n");
        return;
    }

    printSectionTitle("EDIT STUDENT RECORD");

    if (!readInt("Enter student ID to edit: ", &searchId)) {
        printf("Invalid ID input.\n");
        return;
    }

    index = findStudentIndexById(students, count, searchId);

    if (index == -1) {
        printf("No student found with that ID.\n");
        return;
    }

    clearInputBuffer();

    printf("\nStudent found:\n");
    printStudentDetails(students[index], index + 1);

    readLine("\nEnter new name: ", students[index].name, NAME_LENGTH);

    if (!chooseStatus(&newStatus)) {
        printf("Edit cancelled.\n");
        return;
    }

    students[index].status = newStatus;

    printf("Student record updated successfully.\n");
    printStudentDetails(students[index], index + 1);
}

void deleteStudent(struct Student students[], int *count) {
    int searchId;
    int index;
    int i;

    if (*count == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    printSectionTitle("DELETE STUDENT RECORD");

    if (!readInt("Enter student ID to delete: ", &searchId)) {
        printf("Invalid ID input.\n");
        return;
    }

    index = findStudentIndexById(students, *count, searchId);

    if (index == -1) {
        printf("No student found with that ID.\n");
        return;
    }

    for (i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }

    (*count)--;

    printf("Student record deleted successfully.\n");
}

void printStudentDetails(struct Student student, int recordNumber) {
    printf("\nRecord #%d\n", recordNumber);
    printf("ID       : %d\n", student.id);
    printf("Name     : %s\n", student.name);
    printf("Progress : %.2f\n", student.progress);
    printf("Status   : %s\n", getStatusText(student.status));
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
