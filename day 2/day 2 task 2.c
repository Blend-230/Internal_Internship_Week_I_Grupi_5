#include <stdio.h>

int main() {
    int score;

    printf("Enter your score (0-100): ");
    scanf("%d", &score);

    // Kontrolli i validitetit
    if (score < 0 || score > 100) {
        printf("Invalid input\n");
    }
    // Klasifikimi i rezultateve
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