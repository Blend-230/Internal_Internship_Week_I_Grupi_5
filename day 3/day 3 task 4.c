#include <stdio.h>

int main() {
    int num;
    double value;

    // Pointerat
    int *pNum;
    double *pValue;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a double value: ");
    scanf("%lf", &value);

    // Lidhja me pointer
    pNum = &num;
    pValue = &value;

    // Para ndryshimit
    printf("\n--- BEFORE CHANGE ---\n");
    printf("num = %d\n", num);
    printf("Address of num = %p\n", pNum);
    printf("Value via pointer = %d\n", *pNum);

    printf("\nvalue = %.2lf\n", value);
    printf("Address of value = %p\n", pValue);
    printf("Value via pointer = %.2lf\n", *pValue);

    // Ruajmë vlerën e vjetër
    int oldNum = num;

    // Ndryshim përmes pointer
    *pNum = *pNum + 10;

    // Pas ndryshimit
    printf("\n--- AFTER CHANGE ---\n");
    printf("num = %d\n", num);
    printf("Value via pointer = %d\n", *pNum);

    // Kontroll me if/else
    printf("\n--- ANALYSIS ---\n");
    if (num > oldNum) {
        printf("Value has INCREASED\n");
    } else if (num < oldNum) {
        printf("Value has DECREASED\n");
    } else {
        printf("Value is the SAME\n");
    }

    // Kontroll intervali
    if (num >= 0 && num <= 50) {
        printf("Value is in range [0-50]\n");
    } else {
        printf("Value is outside range [0-50]\n");
    }

    return 0;
}