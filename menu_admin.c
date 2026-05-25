#include "header.h"

// Kushte të cilat duhen kontrolluar në program:
// - Vlera e id duhet të jetë numër pozitiv dhe unik
// - Username duhet të jetë unik
// - Password duhet të nisë e shkronjë të madhe, të ketë minimumi 4 karaktere, të përmbajë të
// paktën një numër dhe një simbol.

int menu_admin(void)
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
        // while (getchar() != '\n'); GABIM
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                system("clear");
                shto_user();
                if (ruaj_te_dhenat() == -1)
                {
                    return -1;
                }   
                system("clear"); 
                shfaq_menu_admin(); 
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
                return 0;
            }
            default:
            {
                printf("Zgjidhni nje opsion te sakte (1-11)!    ");
                break;
            }
        }
    }
    return 0;
}

//                                       Shfaq menu

void shfaq_menu_admin(void)
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
    printf("11. Dilni nga menuja e administratorit\n");
}

//                                     Funksionet

void shto_user(void)
{
    if (user_aktual == MAX_USER)
    {
        printf("Kemi arritur numrin maksimal te perdoruesve. Nuk mund te shtojme tjeter.\n");
        return ;
    }

    printf("Jep te dhenat per user-in e ri:\n");

    // ID + kontrolli
    int n;
    while (1)
    {
        printf("ID: ");
        while (getchar() != '\n');
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("Vendosni nje numer ID pozitiv!\n");
            continue;
        }

        if (gjej_user_id(n) != -1)
        {
            printf("Perdoruesi me id = %d eshte ne sistem!\n", n);
            continue;
        }
        break;
    }
    perdoruesit[user_aktual].id_user = n;

    // Emri
    printf("Emri: ");
    scanf("%s", perdoruesit[user_aktual].emri);

    // Username + kontrolli
    char temp[20]; //20 = max(size of(username)=15, size of(password)=20)
    while (1)
    {
        printf("Username: ");
        scanf("%s", temp);

        if (gjej_user_username(temp) != -1)
        {
            printf("Ky username eshte i zene!\n");
            continue;
        }
        break;
    }
    strcpy(perdoruesit[user_aktual].username, temp);

    // Password + kontrolli
    int pass_len;
    while (1)
    {
        printf("Password: ");
        scanf("%s", temp);

        pass_len = strlen(temp);

        if (pass_len < 4)
        {
            printf("Password duhet te kete minimumi 4 karaktere!\n");
            continue;
        }

        if (temp[0] < 'A' || temp[0] > 'Z')
        {
            printf("Password duhet te filloje me shkronje te madhe!\n");
            continue;
        }

        int ka_numer = 0;
        for (int i = 0; i < pass_len; i++)
        {
            if (temp[i] >= '0' && temp [i] <= '9')
            {
                ka_numer = 1;
                break;
            }
        }
        if (ka_numer == 0)
        {
            printf("Password duhet te permbaje te pakten 1 numer!\n");
            continue;
        }

        int ka_simbol = 0;
        for (int i = 0; i < pass_len; i++)
        {
            if (ispunct(temp[i]) != 0)
            {
                ka_simbol = 1;
                break;
            }
        }
        if (ka_simbol == 0)
        {
            printf("Passowrd duhet te permbaje te pakten 1 simbol!\n");
            continue;
        }
        break;
    }
    strcpy(perdoruesit[user_aktual].password, temp);

    // Buxheti mujor + kontrolli
    float nr;
    while (1)
    {
        printf("Buxheti mujor: ");
        if (scanf("%f", &nr) != 1)
        {
            printf("Vendosni nje vlere numerike!\n");
            while (getchar() != '\n');  // flush inputin e gabuar
            continue;
        }
        if (nr <= 0)
        {
            printf("Buxheti duhet te jete pozitiv!\n");
            continue;
        }
        break;
    }
    perdoruesit[user_aktual].buxheti_mujor = nr;

    // Ruajtja ne file
    user_aktual++;
    if (ruaj_users() != -1)
    {
        printf("\nPERDORUESI U SHTUA ME SUKSES!\n\n");
    }
    else
    {
        user_aktual--;
        printf("Perdoruesi nuk u shtua.\n");
    }
}

int gjej_user_id(int id)
{
    for (int i = 0; i < user_aktual; i++)
    {
        if (id == perdoruesit[i].id_user)
        {
            return i;
        }
    }
    return -1;
}

int gjej_user_username(char *username)
{
    for (int i = 0; i < user_aktual; i++)
    {
        if (strcmp(username, perdoruesit[i].username) == 0)
        {
            return i;
        }
    }
    return -1;
}
