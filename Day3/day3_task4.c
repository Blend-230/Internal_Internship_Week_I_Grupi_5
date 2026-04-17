#include <stdio.h>

int main() {
    int num;
    float dec;

    int *pNum;
    float *pDec;

    int beforeNum, afterNum;
    float beforeDec, afterDec;

    printf("Enter an integer value: ");
    scanf("%d", &num);

    printf("Enter a decimal value: ");
    scanf("%f", &dec);

    pNum = &num;
    pDec = &dec;

    beforeNum = num;
    beforeDec = dec;

    printf("\n--- VALUES BEFORE CHANGE ---\n");
    printf("Direct integer value: %d\n", num);
    printf("Integer address: %p\n", (void*)&num);
    printf("Integer value through pointer: %d\n", *pNum);

    printf("Direct decimal value: %.2f\n", dec);
    printf("Decimal address: %p\n", (void*)&dec);
    printf("Decimal value through pointer: %.2f\n", *pDec);

    *pNum = *pNum + 5;
    *pDec = *pDec - 2.0f;

    afterNum = num;
    afterDec = dec;

    printf("\n--- VALUES AFTER CHANGE ---\n");
    printf("Direct integer value: %d\n", num);
    printf("Integer address: %p\n", (void*)&num);
    printf("Integer value through pointer: %d\n", *pNum);

    printf("Direct decimal value: %.2f\n", dec);
    printf("Decimal address: %p\n", (void*)&dec);
    printf("Decimal value through pointer: %.2f\n", *pDec);

    printf("\n--- COMPARISON FOR INTEGER ---\n");
    printf("Before change: %d\n", beforeNum);
    printf("After change: %d\n", afterNum);

    if (afterNum > beforeNum) {
        printf("The integer value has increased.\n");
    } else if (afterNum < beforeNum) {
        printf("The integer value has decreased.\n");
    } else {
        printf("The integer value has remained the same.\n");
    }

    if (afterNum >= 0 && afterNum <= 50) {
        printf("The final integer value is in the interval 0 to 50.\n");
    } else {
        printf("The final integer value is outside the interval 0 to 50.\n");
    }

    printf("\n--- COMPARISON FOR DECIMAL ---\n");
    printf("Before change: %.2f\n", beforeDec);
    printf("After change: %.2f\n", afterDec);

    if (afterDec > beforeDec) {
        printf("The decimal value has increased.\n");
    } else if (afterDec < beforeDec) {
        printf("The decimal value has decreased.\n");
    } else {
        printf("The decimal value has remained the same.\n");
    }

    if (afterDec >= -10.0f && afterDec <= 10.0f) {
        printf("The final decimal value is in the interval -10.00 to 10.00.\n");
    } else {
        printf("The final decimal value is outside the interval -10.00 to 10.00.\n");
    }

    return 0;
}
