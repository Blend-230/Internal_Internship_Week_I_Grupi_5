#include <stdio.h>

int main() {
    int age, option;
    char initial;
    double score;

    // Input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your initial: ");
    scanf(" %c", &initial);

    printf("Enter your score: ");
    scanf("%lf", &score);

    printf("Choose workshop (1-Programming, 2-Design, 3-Robotics): ");
    scanf("%d", &option);

    // Age check
    if (age < 14) {
        printf("\nYou are not allowed to participate.\n");
    } else {

        // Score classification
        if (score < 50) {
            printf("\nLevel: Needs more practice\n");
        } else if (score < 80) {
            printf("Level: Ready to continue\n");
        } else {
            printf("Level: Ready for challenge\n");
        }

        // Workshop selection
        printf("Workshop: ");
        switch (option) {
            case 1:
                printf("Programming\n");
                break;
            case 2:
                printf("Design\n");
                break;
            case 3:
                printf("Robotics\n");
                break;
            default:
                printf("Invalid option\n");
        }

        // Final summary
        printf("\n--- SUMMARY ---\n");
        printf("Age: %d\n", age);
        printf("Initial: %c\n", initial);
        printf("Score: %.2lf\n", score);
    }

    return 0;
}
