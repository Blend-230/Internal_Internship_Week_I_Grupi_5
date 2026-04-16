#include <stdio.h>

int main() {
    int start, end;

    int countDiv3 = 0, sumDiv3 = 0;
    int countDiv5 = 0, sumDiv5 = 0;

    // Marrja e input-it
    printf("Shkruani vleren fillestare: ");
    if (scanf("%d", &start) != 1) {
        printf("Input i pavlefshem!\n");
        return 1;
    }

    printf("Shkruani vleren perfundimtare: ");
    if (scanf("%d", &end) != 1) {
        printf("Input i pavlefshem!\n");
        return 1;
    }

    // Validimi
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 1;
    }

    // For loop për analizë
    for (int i = start; i <= end; i++) {

        // Kategoria 1: pjesetohet me 3
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        }
        // Kategoria 2: pjesetohet me 5 por JO me 3
        else if (i % 5 == 0) {
            countDiv5++;
            sumDiv5 += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d - %d]\n", start, end);

    printf("\nNumrat qe pjesetohen me 3:\n");
    printf("Numeruesi: %d\n", countDiv3);
    printf("Shuma: %d\n", sumDiv3);

    printf("\nNumrat qe pjesetohen me 5 (jo me 3):\n");
    printf("Numeruesi: %d\n", countDiv5);
    printf("Shuma: %d\n", sumDiv5);

    // Krahasimi i shumave
    if (sumDiv3 > sumDiv5) {
        printf("\nShuma e numrave qe pjesetohen me 3 eshte ME E MADHE.\n");
    } else if (sumDiv5 > sumDiv3) {
        printf("\nShuma e numrave qe pjesetohen me 5 eshte ME E MADHE.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}