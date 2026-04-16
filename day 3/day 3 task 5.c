#include <stdio.h>

// Krijimi i enum
enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0;
    int invalidCount = 0;

    // 3 testime me for loop
    for (int i = 1; i <= 3; i++) {
        printf("\nUser %d - Choose level (1-4): ", i);
        scanf("%d", &choice);

        printf("Result: ");

        switch(choice) {
            case BEGINNER:
                printf("Beginner - You are starting your journey\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Intermediate - You have some experience\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Advanced - You are doing very well\n");
                validCount++;
                break;

            case EXPERT:
                printf("Expert - You are highly skilled\n");
                validCount++;
                break;

            default:
                printf("Invalid choice\n");
                invalidCount++;
        }
    }

    // Statistikat
    printf("\n--- STATISTICS ---\n");
    printf("Valid choices: %d\n", validCount);
    printf("Invalid choices: %d\n", invalidCount);

    return 0;
}