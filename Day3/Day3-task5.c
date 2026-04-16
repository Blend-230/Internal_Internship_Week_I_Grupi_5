#include <stdio.h>

// Enum për nivelet
typedef enum {
    BEGINNER = 1,
    INTERMEDIATE,
    ADVANCED,
    EXPERT
} Level;

int main() {
    int choice;
    int validCount = 0, invalidCount = 0;

    // Loop për 3 testime
    for (int i = 1; i <= 3; i++) {

        printf("\nZgjedh nivelin (%d/3):\n", i);
        printf("1 - Beginner\n");
        printf("2 - Intermediate\n");
        printf("3 - Advanced\n");
        printf("4 - Expert\n");
        printf("Zgjedhja: ");
        scanf("%d", &choice);

        Level level = choice;

        switch (level) {
            case BEGINNER:
                printf("Ti je fillestar. Fillo me bazat.\n");
                validCount++;
                break;

            case INTERMEDIATE:
                printf("Ti ke njohuri mesatare. Vazhdo me ushtrime.\n");
                validCount++;
                break;

            case ADVANCED:
                printf("Ti je i avancuar. Puno ne projekte reale.\n");
                validCount++;
                break;

            case EXPERT:
                printf("Ti je ekspert. Mund te mesosh te tjeret.\n");
                validCount++;
                break;

            default:
                printf("Zgjedhje e pavlefshme!\n");
                invalidCount++;
        }
    }

    // Statistikat
    printf("\n--- Statistikat ---\n");
    printf("Zgjedhje valide: %d\n", validCount);
    printf("Zgjedhje pavlefshme: %d\n", invalidCount);

    return 0;
}