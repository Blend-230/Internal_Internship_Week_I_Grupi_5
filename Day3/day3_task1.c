#include <stdio.h>

int main() {
    int n, choice;

    printf("Enter a positive number (1-12): ");
    scanf("%d", &n);

    if (n < 1 || n > 12) {
        printf("Invalid input! Please enter a number between 1 and 12.\n");
        return 1;
    }

    printf("Choose pattern type:\n");
    printf("1. Star pattern\n");
    printf("2. Number pattern\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nStar Pattern:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else if (choice == 2) {
        printf("\nNumber Pattern:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d", j);
            }
            printf("\n");
        }
    } else {
        printf("Invalid choice! Please run the program again and choose 1 or 2.\n");
    }

    return 0;
}
