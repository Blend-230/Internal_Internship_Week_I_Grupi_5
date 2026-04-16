#include <stdio.h>

int main() {
    int mosha;
    char iniciali;
    double piket;
    int opsioni;

    
    printf("Shkruaj moshen: ");
    scanf("%d", &mosha);

    printf("Shkruaj inicialin: ");
    scanf(" %c", &iniciali);

    printf("Shkruaj piket paraprake: ");
    scanf("%lf", &piket);

    printf("Zgjedh punetorin (1, 2 ose 3): ");
    scanf("%d", &opsioni);

    
    if (mosha < 16 || mosha > 60) {
        printf("\nNuk jeni brenda kufirit te moshes per pjesemarrje!\n");
    } else {
        printf("\nMosha eshte ne rregull per pjesemarrje.\n");
    }

    
    if (piket < 50) {
        printf("Statusi: Nevojitet me shume ushtrim\n");
    } 
    else if (piket >= 50 && piket < 80) {
        printf("Statusi: Gati per vazhdim\n");
    } 
    else {
        printf("Statusi: Gati per sfide\n");
    }

    
    printf("Punetoria e zgjedhur: ");
    switch (opsioni) {
        case 1:
            printf("Punetoria A\n");
            break;
        case 2:
            printf("Punetoria B\n");
            break;
        case 3:
            printf("Punetoria C\n");
            break;
        default:
            printf("Opsion i pavlefshem\n");
    }

    
    printf("\n--- PERMBLEDHJE ---\n");
    printf("Mosha: %d\n", mosha);
    printf("Iniciali: %c\n", iniciali);
    printf("Piket: %.2lf\n", piket);
    printf("Opsioni: %d\n", opsioni);

    return 0;
}