#include <stdio.h>

int main() {
    int score;

    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Invalid input\n");
    } else if (score >= 90) {
        printf("Evaluation: Shkelqyeshem\n");
    } else if (score >= 75) {
        printf("Evaluation: Shume mire\n");
    } else if (score >= 60) {
        printf("Evaluation: Mire\n");
    } else {
        printf("Evaluation: Ne permiresim\n");
    }

    return 0;
}