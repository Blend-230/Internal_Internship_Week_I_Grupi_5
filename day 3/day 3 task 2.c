#include <stdio.h>

int main() {
    int start, end;

    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalNumbers = 0;

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

    // Validimi i intervalit
    if (start > end) {
        printf("Interval i pavlefshem! Vlera fillestare duhet te jete me e vogel ose e barabarte me vleren perfundimtare.\n");
        return 1;
    }

    // Analiza me for loop
    for (int i = start; i <= end; i++) {
        totalNumbers++;

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    // Output
    printf("\n--- REZULTATI ---\n");
    printf("Intervali: [%d - %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("\nNumrat çift: %d\n", evenCount);
    printf("Shuma e numrave çift: %d\n", evenSum);

    printf("\nNumrat tek: %d\n", oddCount);
    printf("Shuma e numrave tek: %d\n", oddSum);

    // Krahasimi
    if (evenCount > oddCount) {
        printf("\nKa me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("\nKa me shume numra tek.\n");
    } else {
        printf("\nNumrat çift dhe tek jane te barabarte.\n");
    }

    return 0;
}