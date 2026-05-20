#include "header.h"

void menu_admin(void)
{
    printf("                         MENU ADMINISTRATOR\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("1. Shtoni një përdorues të ri\n");
    printf("2. Shfaq përdoruesit\n");
    printf("3. Kërko përdorues sipas ID\n");
    printf("4. Fshini kredencialet e një përdoruesi\n");
    printf("5. Ndryshoni të dhënat e një përdoruesi ekzistues\n");
    printf("6. Printoni të gjithë të dhënat e përdoruesve\n");
    printf("7. Kërkoni një përdorues sipas username\n");
    printf("8. Rradhisni të gjithë përdoruesit sipas username\n");
    printf("9. Shto / Ndrysho / Fshi kategori\n");
    printf("10. Statistika të sistemit\n");
    //(numri total i përdoruesve, numri total i shpenzimeve, 
    //përdoruesi me më shumë / më pak shpenzime, etj.)
    printf("11. Dilni nga menuja e administratorit\n");
    //(rikthehet në Menu 1)

    int n;
    while(1)
    {
        printf("\nZgjidhni (1-11):   ");
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
                system ("clear");
                printf("                               MENU\n");
                printf("---------------------------------------------------------------------\n\n");
                return ;
            }
            default:
            {
                printf("Zgjidhni nje opsion te sakte (1-11)!    ");
                break;
            }
        }
    }
}
