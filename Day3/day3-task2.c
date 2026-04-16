#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

    
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    
    if (start > end) {
        printf("Interval i pavlefshem! Fillimi duhet te jete <= fundi.\n");
        return 1;
    }

    
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int totalNumbers = end - start + 1;

   
    printf("\n--- Rezultatet ---\n");
    printf("Intervali: [%d, %d]\n", start, end);
    printf("Totali i numrave: %d\n", totalNumbers);

    printf("\nNumrat çift: %d\n", evenCount);
    printf("Shuma e numrave çift: %d\n", evenSum);

    printf("\nNumrat tek: %d\n", oddCount);
    printf("Shuma e numrave tek: %d\n", oddSum);


    if (evenCount > oddCount) {
        printf("\nKa me shume numra çift.\n");
    } else if (oddCount > evenCount) {
        printf("\nKa me shume numra tek.\n");
    } else {
        printf("\nNumri i numrave çift dhe tek eshte i barabarte.\n");
    }

    return 0;
}