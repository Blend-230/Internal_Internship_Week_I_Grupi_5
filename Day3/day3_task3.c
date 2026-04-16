#include <stdio.h>

int main() {
    int start, end;

    int sumDiv3 = 0, countDiv3 = 0;
    int sumDiv5Not3 = 0, countDiv5Not3 = 0;

    printf("Enter start of interval: ");
    scanf("%d", &start);

    printf("Enter end of interval: ");
    scanf("%d", &end);

    // Validate interval
    if (start > end) {
        printf("Invalid interval! Start must be less than or equal to end.\n");
        return 0;
    }

    // Loop through interval
    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            sumDiv3 += i;
            countDiv3++;
        }
        else if (i % 5 == 0 && i % 3 != 0) {
            sumDiv5Not3 += i;
            countDiv5Not3++;
        }
    }

    // Output
    printf("\n--- INTERVAL ANALYSIS ---\n");
    printf("Interval: [%d, %d]\n", start, end);

    printf("\nNumbers divisible by 3:\n");
    printf("Count: %d\n", countDiv3);
    printf("Sum: %d\n", sumDiv3);

    printf("\nNumbers divisible by 5 but NOT by 3:\n");
    printf("Count: %d\n", countDiv5Not3);
    printf("Sum: %d\n", sumDiv5Not3);

    // Comparison
    if (sumDiv3 > sumDiv5Not3) {
        printf("\nSum of numbers divisible by 3 is greater.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("\nSum of numbers divisible by 5 (not 3) is greater.\n");
    } else {
        printf("\nBoth sums are equal.\n");
    }

    return 0;
}