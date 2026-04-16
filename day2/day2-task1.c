#include <stdio.h>

int main() {
    
    int age;
    char initial;
    float height;
    double average;
    short year = 2025;   
    long population = 1800000; 

    
    printf("Shkruaj moshen: ");
    scanf("%d", &age);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &initial);

    printf("Shkruaj gjatesine (p.sh 1.75): ");
    scanf("%f", &height);

    printf("Shkruaj mesataren: ");
    scanf("%lf", &average);

    
    printf("\n PROFILI I PERDORUESIT \n");
    printf("Mosha: %d\n", age);
    printf("Iniciali: %c\n", initial);
    printf("Gjatesia: %.2f m\n", height);
    printf("Mesatarja: %.2lf\n", average);
    printf("Viti (short): %hd\n", year);
    printf("Popullsia (long): %ld\n", population);

    return 0;
}