#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;

    short luckyNumber = 7;
    long population = 1800000;

    // Input from user
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);  // space fixes input bug

    printf("Enter your height (in meters): ");
    scanf("%f", &height);

    printf("Enter your average grade: ");
    scanf("%lf", &average);

    // Output
    printf("\n--- USER PROFILE ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f meters\n", height);
    printf("Average Grade: %.2lf\n", average);
    printf("Lucky Number (short): %d\n", luckyNumber);
    printf("Population (long): %ld\n", population);

    return 0;
}