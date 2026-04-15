#include <stdio.h>

int main() {
    int age, workshop;
    char initial;
    double points;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your previous points: ");
    scanf("%lf", &points);

    printf("Choose workshop (1, 2, or 3): ");
    scanf("%d", &workshop);

    printf("\n--- Registration Summary ---\n");
    printf("Age: %d\n", age);
    printf("Initial: %c\n", initial);
    printf("Previous Points: %.2lf\n", points);

    if (age >= 14 && age <= 19) {
        printf("Participation Status: Allowed\n");
    } else {
        printf("Participation Status: Not Allowed\n");
    }

    if (points < 50) {
        printf("Level: Needs More Practice\n");
    } else if (points < 80) {
        printf("Level: Ready to Continue\n");
    } else {
        printf("Level: Ready for Challenge\n");
    }

    switch (workshop) {
        case 1:
            printf("Workshop: Programming Basics\n");
            break;
        case 2:
            printf("Workshop: Problem Solving\n");
            break;
        case 3:
            printf("Workshop: Git and GitHub\n");
            break;
        default:
            printf("Workshop: Invalid Option\n");
    }

    return 0;
}
