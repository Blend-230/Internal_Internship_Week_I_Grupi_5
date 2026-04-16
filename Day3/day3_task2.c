#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;

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
        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    int totalNumbers = end - start + 1;

    // Output
    printf("\n--- INTERVAL ANALYSIS ---\n");
    printf("Interval: [%d, %d]\n", start, end);
    printf("Total numbers: %d\n", totalNumbers);

    printf("\nEven numbers:\n");
    printf("Count: %d\n", evenCount);
    printf("Sum: %d\n", evenSum);

    printf("\nOdd numbers:\n");
    printf("Count: %d\n", oddCount);
    printf("Sum: %d\n", oddSum);

    // Comparison
    if (evenCount > oddCount) {
        printf("\nMore even numbers in the interval.\n");
    } else if (oddCount > evenCount) {
        printf("\nMore odd numbers in the interval.\n");
    } else {
        printf("\nEqual number of even and odd numbers.\n");
    }

    return 0;
}