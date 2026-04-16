#include <stdio.h>

int main() {
    int n, choice;

    // Marrja e numrit nga përdoruesi
    printf("Shkruani nje numer (1 - 12): ");
    if (scanf("%d", &n) != 1) {
        printf("Input i pavlefshem!\n");
        return 1;
    }

    // Kontrolli i kufijve
    if (n < 1 || n > 12) {
        printf("Input i pavlefshem! Lejohen vetem numra nga 1 deri ne 12.\n");
        return 1;
    }

    // Menu për zgjedhje
    printf("\nZgjidhni pattern-in:\n");
    printf("1 - Pattern me yje (*)\n");
    printf("2 - Pattern me numra\n");
    printf("Zgjedhja juaj: ");

    if (scanf("%d", &choice) != 1) {
        printf("Zgjedhje e pavlefshme!\n");
        return 1;
    }

    printf("\nRezultati:\n\n");

    // Pattern me yje
    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Pattern me numra
    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    // Zgjedhje e gabuar
    else {
        printf("Zgjedhje e pavlefshme! Duhet 1 ose 2.\n");
        return 1;
    }

    return 0;
}