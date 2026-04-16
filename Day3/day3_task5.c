#include <stdio.h>

enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int i, choice;
    int validCount = 0, invalidCount = 0;

    for (i = 1; i <= 3; i++) {
        printf("Enter level for student %d (1-4): ", i);
        scanf("%d", &choice);

        enum Level studentLevel = choice;

        switch (studentLevel) {
            case BEGINNER:
                printf("Student %d: Beginner level\n", i);
                validCount++;
                break;
            case INTERMEDIATE:
                printf("Student %d: Intermediate level\n", i);
                validCount++;
                break;
            case ADVANCED:
                printf("Student %d: Advanced level\n", i);
                validCount++;
                break;
            case EXPERT:
                printf("Student %d: Expert level\n", i);
                validCount++;
                break;
            default:
                printf("Student %d: Invalid choice\n", i);
                invalidCount++;
        }
    }

    printf("\n--- Final Statistics ---\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}
