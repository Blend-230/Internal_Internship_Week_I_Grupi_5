#include <stdio.h>

int main() {
    int score;

    printf("Enter a score (0-100): ");
    scanf("%d", &score);

    // Check if input is valid
    if (score < 0 || score > 100) {
        printf("Invalid input! Score must be between 0 and 100.\n");
    }
    // Classification (from highest to lowest)
    else if (score >= 90) {
        printf("Excellent (Shkelqyeshem)\n");
    }
    else if (score >= 75) {
        printf("Very Good (Shume mire)\n");
    }
    else if (score >= 60) {
        printf("Good (Mire)\n");
    }
    else {
        printf("Needs Improvement (Ne permiresim)\n");
    }

    return 0;
}