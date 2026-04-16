#include <stdio.h>

int main() {
    int n, choice;

    printf("Enter size (1-12): ");
    scanf("%d", &n);

    // Validation
    if (n < 1 || n > 12) {
        printf("Invalid input! Please enter a number between 1 and 12.\n");
        return 0;
    }

    printf("Choose pattern type:\n");
    printf("1 - Stars (*)\n");
    printf("2 - Numbers\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    printf("\n--- PATTERN ---\n");

    // Stars pattern
    if (choice == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    // Numbers pattern
    else if (choice == 2) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}