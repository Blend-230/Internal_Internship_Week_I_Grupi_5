#include <stdio.h>

int main() {
    // Variablat me vlera të caktuara
    int age = 17;
    char initial = 'A';
    float height = 1.84;
    double average = 4;

    short year = 2024;
    long population = 1800000;

    // Output
    printf("\n--- USER PROFILE ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Height: %.2f m\n", height);
    printf("Average: %.2lf\n", average);
    printf("Study Year (short): %d\n", year);
    printf("Population (long): %ld\n", population);

    return 0;
}