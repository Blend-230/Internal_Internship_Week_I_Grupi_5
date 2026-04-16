#include <stdio.h>

int main() {
    int start, end;
    int countDiv3 = 0, countDiv5Not3 = 0;
    int sumDiv3 = 0, sumDiv5Not3 = 0;

    printf("Enter the starting value of the interval: ");
    scanf("%d", &start);

    printf("Enter the ending value of the interval: ");
    scanf("%d", &end);

    if (start > end) {
        printf("Invalid interval! The starting value cannot be greater than the ending value.\n");
        return 1;
    }

    for (int i = start; i <= end; i++) {
        if (i % 3 == 0) {
            countDiv3++;
            sumDiv3 += i;
        } 
        else if (i % 5 == 0 && i % 3 != 0) {
            countDiv5Not3++;
            sumDiv5Not3 += i;
        }
    }

    printf("\n--- INTERVAL ANALYSIS ---\n");
    printf("Interval: %d to %d\n", start, end);
    printf("Numbers divisible by 3: %d\n", countDiv3);
    printf("Sum of numbers divisible by 3: %d\n", sumDiv3);
    printf("Numbers divisible by 5 but not by 3: %d\n", countDiv5Not3);
    printf("Sum of numbers divisible by 5 but not by 3: %d\n", sumDiv5Not3);

    if (sumDiv3 > sumDiv5Not3) {
        printf("The greater sum is for numbers divisible by 3.\n");
    } else if (sumDiv5Not3 > sumDiv3) {
        printf("The greater sum is for numbers divisible by 5 but not by 3.\n");
    } else {
        printf("Both sums are equal.\n");
    }

    return 0;
}
