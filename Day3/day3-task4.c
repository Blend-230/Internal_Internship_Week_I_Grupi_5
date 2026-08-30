
#include <stdio.h>

int main() {
    int a;
    float b;

    // Pointerat
    int *pA;
    float *pB;

    // Input
    printf("Shkruaj nje numer int: ");
    scanf("%d", &a);

    printf("Shkruaj nje numer float: ");
    scanf("%f", &b);

    // Ruaj adresat
    pA = &a;
    pB = &b;

    // Print para ndryshimit
    printf("\n--- Para ndryshimit ---\n");
    printf("Vlera e a: %d\n", a);
    printf("Adresa e a: %p\n", pA);
    printf("Vlera e a permes pointerit: %d\n", *pA);

    printf("\nVlera e b: %.2f\n", b);
    printf("Adresa e b: %p\n", pB);
    printf("Vlera e b permes pointerit: %.2f\n", *pB);

    // Ruaj vlerat e vjetra
    int oldA = a;
    float oldB = b;

    // Ndryshim permes pointerit
    *pA = *pA + 10;
    *pB = *pB * 2;

    // Print pas ndryshimit
    printf("\n--- Pas ndryshimit ---\n");
    printf("a (e re): %d\n", a);
    printf("b (e re): %.2f\n", b);

    // Kontroll me if/else
    printf("\n--- Analiza ---\n");

    if (a > oldA) {
        printf("a eshte rritur.\n");
    } else if (a < oldA) {
        printf("a eshte zvogeluar.\n");
    } else {
        printf("a ka mbetur e njejte.\n");
    }

    if (b > oldB) {
        printf("b eshte rritur.\n");
    } else if (b < oldB) {
        printf("b eshte zvogeluar.\n");
    } else {
        printf("b ka mbetur e njejte.\n");
    }

    // Kontroll intervali
    if (a >= 0 && a <= 100) {
        printf("a eshte ne intervalin [0, 100].\n");
    } else {
        printf("a nuk eshte ne intervalin [0, 100].\n");
    }

    return 0;
}
