#include <stdio.h>

int main() {
    int start, end;

    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int total = 0;

    // Input
    printf("Enter start value: ");
    scanf("%d", &start);

    printf("Enter end value: ");
    scanf("%d", &end);

    // Validation
    if (start > end) {
        printf("Invalid interval! Start value must be less than or equal to end value.\n");
        return 0;
    }

    // Loop through interval
    for (int i = start; i <= end; i++) {
        total++;

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    // Output
    printf("\nInterval: %d to %d\n", start, end);
    printf("Total numbers: %d\n", total);

    printf("Even numbers: %d\n", evenCount);
    printf("Sum of even numbers: %d\n", evenSum);

    printf("Odd numbers: %d\n", oddCount);
    printf("Sum of odd numbers: %d\n", oddSum);

    // Comparison
    if (evenCount > oddCount) {
        printf("There are more EVEN numbers.\n");
    } else if (oddCount > evenCount) {
        printf("There are more ODD numbers.\n");
    } else {
        printf("Even and Odd numbers are equal.\n");
    }

    return 0;
}
