#include <stdio.h>

int main() {
    int number, originalNumber;
    double value;
    int *pNumber;
    double *pValue;

    printf("Enter an integer value: ");
    scanf("%d", &number);

    printf("Enter a decimal value: ");
    scanf("%lf", &value);

    originalNumber = number;

    pNumber = &number;
    pValue = &value;

    printf("\n--- Before Change ---\n");
    printf("Direct integer value: %d\n", number);
    printf("Integer address: %p\n", (void*)&number);
    printf("Integer value through pointer: %d\n", *pNumber);

    printf("Direct decimal value: %.2lf\n", value);
    printf("Decimal address: %p\n", (void*)&value);
    printf("Decimal value through pointer: %.2lf\n", *pValue);

    *pNumber = *pNumber + 10;

    printf("\n--- After Change ---\n");
    printf("Updated integer value: %d\n", number);
    printf("Updated integer value through pointer: %d\n", *pNumber);

    if (number > originalNumber) {
        printf("Result: The integer value increased.\n");
    } else if (number < originalNumber) {
        printf("Result: The integer value decreased.\n");
    } else {
        printf("Result: The integer value stayed the same.\n");
    }

    if (number >= 0 && number <= 50) {
        printf("Final integer is in the interval 0 to 50.\n");
    } else {
        printf("Final integer is outside the interval 0 to 50.\n");
    }

    return 0;
}
