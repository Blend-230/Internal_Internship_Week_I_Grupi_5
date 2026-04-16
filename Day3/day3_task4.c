#include <stdio.h>

int main() {
    int number;
    float decimal;

    int *pNumber;
    float *pDecimal;

    int oldNumber;
    float oldDecimal;

    printf("Enter an integer value: ");
    scanf("%d", &number);

    printf("Enter a decimal value: ");
    scanf("%f", &decimal);

    pNumber = &number;
    pDecimal = &decimal;

    oldNumber = number;
    oldDecimal = decimal;

    printf("\n--- BEFORE CHANGE ---\n");
    printf("Integer value: %d\n", number);
    printf("Integer address: %p\n", (void*)&number);
    printf("Integer value through pointer: %d\n", *pNumber);

    printf("Decimal value: %.2f\n", decimal);
    printf("Decimal address: %p\n", (void*)&decimal);
    printf("Decimal value through pointer: %.2f\n", *pDecimal);

    *pNumber = *pNumber + 10;
    *pDecimal = *pDecimal * 2;

    printf("\n--- AFTER CHANGE ---\n");
    printf("Integer value: %d\n", number);
    printf("Integer address: %p\n", (void*)&number);
    printf("Integer value through pointer: %d\n", *pNumber);

    printf("Decimal value: %.2f\n", decimal);
    printf("Decimal address: %p\n", (void*)&decimal);
    printf("Decimal value through pointer: %.2f\n", *pDecimal);

    printf("\n--- FINAL CHECK ---\n");

    if (number > oldNumber) {
        printf("The integer value has increased.\n");
    } else if (number < oldNumber) {
        printf("The integer value has decreased.\n");
    } else {
        printf("The integer value has remained the same.\n");
    }

    if (decimal > oldDecimal) {
        printf("The decimal value has increased.\n");
    } else if (decimal < oldDecimal) {
        printf("The decimal value has decreased.\n");
    } else {
        printf("The decimal value has remained the same.\n");
    }

    if (number >= 0 && number <= 100) {
        printf("The final integer value is in the interval 0 to 100.\n");
    } else {
        printf("The final integer value is outside the interval 0 to 100.\n");
    }

    return 0;
}
