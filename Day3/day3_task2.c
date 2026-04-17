#include <stdio.h>

int main() {
    int start, end;
    int evenCount = 0, oddCount = 0;
    int evenSum = 0, oddSum = 0;
    int totalValues = 0;

    printf("Enter the starting value of the interval: ");
    scanf("%d", &start);

    printf("Enter the ending value of the interval: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval! The starting value cannot be greater than the ending value.\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        totalValues++;

        if (i % 2 == 0) {
            evenCount++;
            evenSum += i;
        } else {
            oddCount++;
            oddSum += i;
        }
    }

    printf("\n--- INTERVAL ANALYSIS ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Total values: %d\n", totalValues);
    printf("Even numbers count: %d\n", evenCount);
    printf("Odd numbers count: %d\n", oddCount);
    printf("Sum of even numbers: %d\n", evenSum);
    printf("Sum of odd numbers: %d\n", oddSum);

    if (evenCount > oddCount) {
        printf("Category with more numbers: Even numbers\n");
    } else if (oddCount > evenCount) {
        printf("Category with more numbers: Odd numbers\n");
    } else {
        printf("Both categories have the same number of values.\n");
    }

    return 0;
}
