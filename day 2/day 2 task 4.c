#include <stdio.h>

int main() {
    // Vlera të gatshme
    int age = 17;
    char initial = 'D';   // iniciali yt (mund ta ndërron)
    double points = 78.5;
    int option = 2;

    printf("\n--- WORKSHOP REGISTRATION ---\n\n");

    // Kontroll moshe
    if (age < 15 || age > 25) {
        printf("Age status: Not eligible for workshop\n");
    } else {
        printf("Age status: Eligible\n");
    }

    // Klasifikimi
    if (points < 50) {
        printf("Level: Needs more practice\n");
    }
    else if (points < 80) {
        printf("Level: Ready to continue\n");
    }
    else {
        printf("Level: Ready for challenge\n");
    }

    // Workshop (switch)
    printf("Workshop: ");
    switch(option) {
        case 1:
            printf("Programming Basics\n");
            break;
        case 2:
            printf("Web Development\n");
            break;
        case 3:
            printf("Data Structures\n");
            break;
        default:
            printf("Invalid workshop\n");
    }

    // Përmbledhja finale
    printf("\n--- SUMMARY ---\n");
    printf("Initial: %c\n", initial);
    printf("Age: %d\n", age);
    printf("Points: %.2lf\n", points);
    printf("Workshop option: %d\n", option);

    printf("\nRegistration completed successfully!\n");

    return 0;
}