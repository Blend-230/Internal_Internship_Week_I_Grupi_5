#include <stdio.h>

int main() {
    int score;

    // Input
    printf("Shkruaj rezultatin (0-100): ");
    scanf("%d", &score);

    // Kontrolli i validitetit
    if (score < 0 || score > 100) {
        printf("Input-i nuk eshte valid! Duhet te jete nga 0 deri ne 100.\n");
    }
    else if (score >= 90) {
        printf("Vleresimi: Shkelqyeshem\n");
    }
    else if (score >= 80) {
        printf("Vleresimi: Shume mire\n");
    }
    else if (score >= 70) {
        printf("Vleresimi: Mire\n");
    }
    else if (score >= 60) {
        printf("Vleresimi: Ne permiresim\n");
    }
    else {
        printf("Vleresimi: Deshtim\n");
    }

    return 0;
}
