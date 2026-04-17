#include <stdio.h>

enum StudentLevel {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    printf("=== Student Level Program ===\n");

    for (int i = 1; i <= 3; i++) {
        printf("\nUser %d\n", i);
        printf("Choose a level:\n");
        printf("1. Beginner\n");
        printf("2. Intermediate\n");
        printf("3. Advanced\n");
        printf("4. Expert\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        enum StudentLevel level = choice;

        switch (level) {
            case BEGINNER:
                printf("Message: You are at the beginner level. Start with the basics.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Message: You are at the intermediate level. Keep practicing.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Message: You are at the advanced level. You are doing very well.\n");
                validCount++;
                break;

            case EXPERT:
                printf("Message: You are at the expert level. Excellent work!\n");
                validCount++;
                break;

            default:
                printf("Invalid input! Please choose a number from 1 to 4.\n");
                invalidCount++;
                break;
        }
    }

    printf("\n=== FINAL STATISTICS ===\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}
