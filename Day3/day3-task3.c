#include <stdio.h>

int main() {
    int start, end;

    int sumDiv3 = 0, countDiv3 = 0;
    int sumDiv5 = 0, countDiv5 = 0;

    
    printf("Shkruaj fillimin e intervalit: ");
    scanf("%d", &start);

    printf("Shkruaj fundin e intervalit: ");
    scanf("%d", &end);

    
    if (start > end) {
        printf("Interval i pavlefshem!\n");
        return 1;
    }

    
    for (int i = start; i <= end; i++) {

        
        if (i % 3 == 0) {
            sumDiv3 += i;
            countDiv3++;
        }
        
        else if (i % 5 == 0 && i % 3 != 0) {
            sumDiv5 += i;
            countDiv5++;
        }
    }

    
    printf("\n--- Rezultatet ---\n");
    printf("Intervali: [%d, %d]\n", start, end);

    printf("\nNumrat qe pjesetohen me 3:\n");
    printf("Count: %d\n", countDiv3);
    printf("Shuma: %d\n", sumDiv3);

    printf("\nNumrat qe pjesetohen me 5 (jo me 3):\n");
    printf("Count: %d\n", countDiv5);
    printf("Shuma: %d\n", sumDiv5);

   
    if (sumDiv3 > sumDiv5) {
        printf("\nShuma e numrave qe pjesetohen me 3 eshte me e madhe.\n");
    } else if (sumDiv5 > sumDiv3) {
        printf("\nShuma e numrave qe pjesetohen me 5 eshte me e madhe.\n");
    } else {
        printf("\nShumat jane te barabarta.\n");
    }

    return 0;
}