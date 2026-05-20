#include "header.h"

//Kompilimi: cc menu_admin.c menu_user.c main.c header.h

// Kushte të cilat duhen kontrolluar në program:
// - Vlera e id duhet të jetë numër pozitiv dhe unik
// - Username duhet të jetë unik
// - Password duhet të nisë e shkronjë të madhe, të ketë minimumi 4 karaktere, të përmbajë të
// paktën një numër dhe një simbol.

int main()
{
    system("clear");
    int opsioni;

    printf("================= MIRESEVINI =================\n\n");
    
    while (1)
    {
        opsioni = menu_1();
        switch (opsioni)
        {
            case 1:
            {
                system("clear");  //system ("cls")  - per Windows
                menu_admin();
                break;
            }
            case 2:
            {
                system("clear");
                menu_user();
                break;
            }
            case 3:
            {
                system("clear");
                printf("Po mbyllet programi...\n");
                return 0;
            }
            default:
            {
                printf("\nError!");
                return (-1);
            }
        }
    }
    return 0;
}

int menu_1(void)
{
    printf("Hyni ne sistem si:\n");
    printf("1. Administrator\n");
    printf("2. Perdorues\n");
    printf("3. Dil nga programi\n\n");
    printf("Zgjidhni (1-3):   ");

    int n;
    scanf("%d", &n);

    while (n < 1 || n > 3)
    {
        printf("Zgjidhni nje opsion 1-3!  ");
        while (getchar() != '\n');  //Bej skip gjithe inputin e gabuar (char)
        scanf("%d", &n);
    }
    return (n); 
}