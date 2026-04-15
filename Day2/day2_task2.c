#include <stdio.h>

int main() {
    int result;

    printf("Enter your result (0-100): ");
    scanf("%d", &result);

    if (result < 0 || result > 100) {
        printf("Invalid input! Result must be between 0 and 100.\n");
    } else if (result >= 90) {
        printf("Excellent\n");
    } else if (result >= 75) {
        printf("Very Good\n");
    } else if (result >= 50) {
        printf("Good\n");
    } else {
        printf("Needs Improvement\n");
    }

    return 0;
}
