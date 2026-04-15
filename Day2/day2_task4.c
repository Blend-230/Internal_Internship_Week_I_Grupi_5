#include <stdio.h>

int main() {
    int age, workshop;
    char initial;
    double points;

    // Input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your previous points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1, 2, or 3): ");
    scanf("%d", &workshop);

    // Age validation
    int validAge = 1;
    if (age < 15 || age > 25) {
        validAge = 0;
    }

    // Classification (if / else)
    char* level;
    if (points < 50) {
        level = "Needs more practice";
    }
    else if (points < 75) {
        level = "Ready for continuation";
    }
    else {
        level = "Ready for challenge";
    }

    // Workshop selection (switch)
    char* workshopName;
    switch(workshop) {
        case 1:
            workshopName = "Web Development";
            break;
        case 2:
            workshopName = "Mobile Development";
            break;
        case 3:
            workshopName = "AI Basics";
            break;
        default:
            workshopName = "Invalid workshop";
    }

    // Output
    printf("\n--- REGISTRATION SUMMARY ---\n");
    printf("Initial: %c\n", initial);
    printf("Age: %d\n", age);

    if (validAge) {
        printf("Age Status: Eligible\n");
    } else {
        printf("Age Status: Not eligible\n");
    }

    printf("Points: %.2lf\n", points);
    printf("Level: %s\n", level);
    printf("Workshop: %s\n", workshopName);

    return 0;
}