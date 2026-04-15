#include <stdio.h>

int main() {
    int age, workshop;
    char initial;
    double points;

    // Input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial); // space para %c për të shmangur probleme

    printf("Enter your points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1-3): ");
    scanf("%d", &workshop);

    // Kontroll i moshës
    if(age < 14 || age > 25) {
        printf("\nYou are not eligible to participate.\n");
    } else {
        printf("\nYou are eligible to participate.\n");
    }

    // Klasifikimi sipas pikëve
    printf("Performance: ");
    if(points < 50) {
        printf("Needs more practice\n");
    } else if(points < 80) {
        printf("Ready to continue\n");
    } else {
        printf("Ready for challenge\n");
    }

    // Workshop selection
    printf("Workshop: ");
    switch(workshop) {
        case 1:
            printf("Programming Basics\n");
            break;
        case 2:
            printf("Web Development\n");
            break;
        case 3:
            printf("Cyber Security\n");
            break;
        default:
            printf("Invalid workshop option\n");
    }

    // Final Summary
    printf("\n--- Summary ---\n");
    printf("Initial: %c\n", initial);
    printf("Age: %d\n", age);
    printf("Points: %.2lf\n", points);
    printf("Workshop choice: %d\n", workshop);

    return 0;
}