#include <stdio.h>

#define MAX 50

// ENUM
enum Status {
    NOT_STARTED = 1,
    IN_PROGRESS,
    COMPLETED
};

// STRUCT
struct Record {
    int id;
    char name[50];
    float progress;
    enum Status status;
};

// GLOBAL
struct Record records[MAX];
int count = 0;
int nextId = 1;

// PRINT STATUS
void printStatus(enum Status s) {
    if (s == NOT_STARTED) printf("Not Started");
    else if (s == IN_PROGRESS) printf("In Progress");
    else if (s == COMPLETED) printf("Completed");
}

// ADD
void addRecord() {
    if (count >= MAX) {
        printf("Kapaciteti maksimal u arrit!\n");
        return;
    }

    struct Record r;
    r.id = nextId++;

    printf("Emri: ");
    scanf("%s", r.name);

    printf("Progress (0-100): ");
    scanf("%f", &r.progress);

    int st;
    printf("Statusi (1-3): ");
    scanf("%d", &st);

    if (st < 1 || st > 3) st = 1;

    r.status = (enum Status)st;

    records[count] = r;
    count++;

    printf("U shtua me sukses!\n");
}

// SHOW
void showAll() {
    if (count == 0) {
        printf("Nuk ka regjistrime!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\n", records[i].id);
        printf("Emri: %s\n", records[i].name);
        printf("Progress: %.2f\n", records[i].progress);
        printf("Status: ");
        printStatus(records[i].status);
        printf("\n");
    }
}

// SEARCH
void searchRecord() {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    int found = 0;

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            found = 1;

            printf("Emri: %s\n", records[i].name);
            printf("Progress: %.2f\n", records[i].progress);

            if (records[i].progress < 30)
                printf("KUJDES: Progress i ulet!\n");
            else if (records[i].progress > 80)
                printf("Shume mire!\n");
        }
    }

    if (!found) printf("Nuk u gjet!\n");
}

// UPDATE (POINTER)
void updateRecord() {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {

            struct Record *p = &records[i];

            printf("Progress i ri: ");
            scanf("%f", &p->progress);

            printf("Status i ri (1-3): ");
            int st;
            scanf("%d", &st);

            if (st >= 1 && st <= 3)
                p->status = (enum Status)st;

            printf("U perditesua!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// DELETE
void deleteRecord() {
    int id;
    printf("ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                records[j] = records[j + 1];
            }

            count--;
            printf("U fshi!\n");
            return;
        }
    }

    printf("Nuk u gjet!\n");
}

// REPORT
void report() {
    if (count == 0) {
        printf("Ska te dhena!\n");
        return;
    }

    float sum = 0;
    float max = records[0].progress;
    float min = records[0].progress;

    for (int i = 0; i < count; i++) {
        sum += records[i].progress;

        if (records[i].progress > max) max = records[i].progress;
        if (records[i].progress < min) min = records[i].progress;
    }

    printf("\nTotali: %d\n", count);
    printf("Mesatarja: %.2f\n", sum / count);
    printf("Max: %.2f\n", max);
    printf("Min: %.2f\n", min);
}

// SORT
void sortRecords() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (records[j].progress > records[i].progress) {
                struct Record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }

    printf("U rendit!\n");
}

// MENU
void menu() {
    int choice;

    do {
        printf("\n1.Add\n2.Show\n3.Search\n4.Update\n5.Delete\n6.Report\n7.Sort\n0.Exit\n");
        printf("Zgjedh: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addRecord(); break;
            case 2: showAll(); break;
            case 3: searchRecord(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: report(); break;
            case 7: sortRecords(); break;
            case 0: printf("Bye!\n"); break;
            default: printf("Gabim!\n");
        }

    } while(choice != 0);
}

// MAIN
int main() {
    menu();
    return 0;
}