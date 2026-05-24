#include "header.h"

int menu_user(void)
{
    printf("                           MENU PERDORUES\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("1. Shto një shpenzim të ri\n");
    printf("2. Shto të ardhura\n");
    printf("3. Shfaq shpenzimet e mia\n");
    printf("4. Shfaq të ardhurat e mia\n");
    printf("5. Raport mujor / vjetor \n");
    //(totali i të ardhurave, shpenzimeve, kursimet, kategoria me më shumë shpenzime)
    printf("6. Kontrollo buxhetin\n");
    printf("7. Kërko shpenzim sipas kategorisë\n");
    printf("8. Fshini të dhënat e një shpenzimi\n");
    printf("9. Rendit shpenzimet sipas shumës\n");
    printf("10. Rendit shpenzimet sipas datës\n");
    printf("11. Kërko shpenzim sipas ID, datës, kategorisë, interval të datave\n");
    printf("12. Dilni nga menuja e përdoruesit\n");
    //(rikthehet në Menu 1)

    int n;

    while(1)
    {
        printf("\nZgjidhni (1-12):   ");
        while (getchar() != '\n');
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
            case 11:
            {
                break;
            }
            case 12:
            {
                system("clear");
                printf("                               MENU\n");
                printf("---------------------------------------------------------------------\n\n");
                return 0;
            }
            default:
            {
                printf("Zgjidhni nje opsion te sakte (1-12)!    ");
                break;
            }
        }
    }
    return 0;
}
