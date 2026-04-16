#include <stdio.h>

int main() {
    int num;
    double value;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter a decimal number: ");
    scanf("%lf", &value);

    // Pointers
    int *pNum = &num;
    double *pValue = &value;

    // Show original values and addresses
    printf("\n--- ORIGINAL VALUES ---\n");
    printf("num = %d\n", num);
    printf("Address of num = %p\n", &num);
    printf("Value via pointer = %d\n", *pNum);

    printf("\nvalue = %.2lf\n", value);
    printf("Address of value = %p\n", &value);
    printf("Value via pointer = %.2lf\n", *pValue);

    // Store old value
    double oldValue = value;

    // Modify value using pointer
    *pValue = *pValue + 10;

    // Show updated values
    printf("\n--- AFTER MODIFICATION ---\n");
    printf("Old value = %.2lf\n", oldValue);
    printf("New value = %.2lf\n", *pValue);

    // Decision logic
    printf("\n--- ANALYSIS ---\n");

    if (*pValue > oldValue) {
        printf("Value has increased.\n");
    } else if (*pValue < oldValue) {
        printf("Value has decreased.\n");
    } else {
        printf("Value remained the same.\n");
    }

    // Extra interval check
    if (*pValue >= 0 && *pValue <= 100) {
        printf("Value is within range [0, 100].\n");
    } else {
        printf("Value is outside range [0, 100].\n");
    }

    return 0;
}