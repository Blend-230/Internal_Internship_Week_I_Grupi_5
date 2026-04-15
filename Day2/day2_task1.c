#include <stdio.h>

int main() {
    int age;
    char initial;
    float height;
    double average;
    short grade = 11;
    long points = 2500;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("Enter your average: ");
    scanf("%lf", &average);

    printf("\n--- User Profile ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f\n", height);
    printf("Average: %.2lf\n", average);
    printf("Grade: %hd\n", grade);
    printf("Points: %ld\n", points);

    return 0;
}
