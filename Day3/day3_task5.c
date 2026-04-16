#include <stdio.h>

// Define enum
enum Level {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
};

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    printf("Choose level:\n");
    printf("1 - Beginner\n");
    printf("2 - Intermediate\n");
    printf("3 - Advanced\n");
    printf("4 - Expert\n");

    // Loop for 3 inputs
    for (int i = 1; i <= 3; i++) {
        printf("\nEnter choice for user %d: ", i);
        scanf("%d", &choice);

        // Check if valid
        if (choice >= 1 && choice <= 4) {
            validCount++;

            enum Level level = choice;

            switch(level) {
                case BEGINNER:
                    printf("Beginner: Focus on basics.\n");
                    break;
                case INTERMEDIATE:
                    printf("Intermediate: Practice more complex tasks.\n");
                    break;
                case ADVANCED:
                    printf("Advanced: Work on real projects.\n");
                    break;
                case EXPERT:
                    printf("Expert: Solve challenging problems.\n");
                    break;
            }
        } else {
            invalidCount++;
            printf("Invalid choice!\n");
        }
    }

    // Final statistics
    printf("\n--- STATISTICS ---\n");
    printf("Valid inputs: %d\n", validCount);
    printf("Invalid inputs: %d\n", invalidCount);

    return 0;
}