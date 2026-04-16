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
    int validCount = 0;
    int invalidCount = 0;

    // Loop for 3 test cases
    for(int i = 1; i <= 3; i++) {
        printf("\n--- User %d ---\n", i);
        printf("Choose level:\n");
        printf("1. Beginner\n");
        printf("2. Intermediate\n");
        printf("3. Advanced\n");
        printf("4. Expert\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Convert input to enum
        enum Level userLevel = choice;

        // Switch logic
        switch(userLevel) {
            case BEGINNER:
                printf("You selected Beginner level.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("You selected Intermediate level.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("You selected Advanced level.\n");
                validCount++;
                break;

            case EXPERT:
                printf("You selected Expert level.\n");
                validCount++;
                break;

            default:
                printf("Invalid choice! Please select between 1 and 4.\n");
                invalidCount++;
        }
    }

    // Final statistics
    printf("\n--- FINAL STATISTICS ---\n");
    printf("Valid selections: %d\n", validCount);
    printf("Invalid selections: %d\n", invalidCount);

    return 0;
}
