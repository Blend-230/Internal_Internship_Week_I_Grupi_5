#include <stdio.h>

int main() {
    int start, end;
    int i;
    int sumDiv3 = 0, countDiv3 = 0;
    int sumDiv5Not3 = 0, countDiv5Not3 = 0;

    printf("Enter the starting value: ");
    scanf("%d", &start);

    printf("Enter the ending value: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval! The starting value must be less than or equal to the ending value.\n");
        return 0;
    }

    for (i = start; i <= end; i++) {
        if (i % 3 == 0) {
            sumDiv3 += i;
            countDiv3++;
        } else if (i % 5 == 0) {
            sumDiv5Not3 += i;
            countDiv5Not3++;
        }
    }

    printf("\n--- Interval Summary ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Numbers divisible by 3: %d\n", countDiv3);
    printf("Sum of numbers divisible by 3: %d\n", sumDiv3);
    printf("Numbers divisible by 5 but not by 3: %d\n", countDiv5Not3);
    printf("Sum of numbers divisible by 5 but not by 3: %d\n", sumDiv5Not3);

    if (sumDiv3 > sumDiv5Not3) {
        printf("The sum of numbers divisible by 3 is greater.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("The sum of numbers divisible by 5 but not by 3 is greater.\n");
    } else {
        printf("The two sums are equal.\n");
    }

    return 0;
}
