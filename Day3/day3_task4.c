#include <stdio.h>

int main() {
    int a;
    float b;

    int *pa;
    float *pb;

    float oldB;

    // Input
    printf("Enter integer value (a): ");
    scanf("%d", &a);

    printf("Enter float value (b): ");
    scanf("%f", &b);

    // Pointer assignment
    pa = &a;
    pb = &b;

    // Show original values and addresses
    printf("\n--- BEFORE CHANGE ---\n");
    printf("a value: %d\n", a);
    printf("a address: %p\n", &a);
    printf("a via pointer: %d\n\n", *pa);

    printf("b value: %.2f\n", b);
    printf("b address: %p\n", &b);
    printf("b via pointer: %.2f\n", *pb);

    // Save old value
    oldB = b;

    // Change value via pointer
    *pb = b + 10.5;

    printf("\n--- AFTER CHANGE ---\n");
    printf("b new value: %.2f\n", b);
    printf("b via pointer: %.2f\n", *pb);

    // Comparison
    printf("\n--- ANALYSIS ---\n");

    if (*pb > oldB) {
        printf("Value increased.\n");
    }
    else if (*pb < oldB) {
        printf("Value decreased.\n");
    }
    else {
        printf("Value stayed the same.\n");
    }

    // Interval check example
    if (*pb >= 0 && *pb <= 100) {
        printf("Value is inside range [0 - 100].\n");
    } else {
        printf("Value is outside range [0 - 100].\n");
    }

    return 0;
}
