#include <stdio.h>

int main() {
    int start, end;

    int count3 = 0, sum3 = 0;
    int count5not3 = 0, sum5not3 = 0;

    // Input
    printf("Enter start value: ");
    scanf("%d", &start);

    printf("Enter end value: ");
    scanf("%d", &end);

    // Validation
    if (start > end) {
        printf("Invalid interval! Start must be <= end.\n");
        return 0;
    }

    // Loop through interval
    for (int i = start; i <= end; i++) {

        // Category 1: divisible by 3
        if (i % 3 == 0) {
            count3++;
            sum3 += i;
        }

        // Category 2: divisible by 5 but NOT by 3
        else if (i % 5 == 0) {
            count5not3++;
            sum5not3 += i;
        }
    }

    // Output
    printf("\nInterval: %d to %d\n", start, end);

    printf("Category 1 (divisible by 3): Count = %d, Sum = %d\n", count3, sum3);
    printf("Category 2 (divisible by 5 but not 3): Count = %d, Sum = %d\n", count5not3, sum5not3);

    // Comparison
    if (sum3 > sum5not3) {
        printf("Category 1 has a larger sum.\n");
    } 
    else if (sum5not3 > sum3) {
        printf("Category 2 has a larger sum.\n");
    } 
    else {
        printf("Both categories have equal sums.\n");
    }

    return 0;
}
