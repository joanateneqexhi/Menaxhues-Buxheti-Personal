#include "header.h"

void menu_user(int user_index)
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
                system("clear");
                shto_shpenzim(user_index);
                shfaq_menu_user();
                break;
            }
            case 2:
            {
                system("clear");

                shfaq_menu_user();
                break;
            }
            case 3:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 4:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 5:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 6:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 7:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 8:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 9:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 10:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 11:
            {
                system("clear");
                
                shfaq_menu_user();
                break;
            }
            case 12:
            {
                system("clear");
                printf("                               MENU\n");
                printf("---------------------------------------------------------------------\n\n");
                return ;
            }
            default:
            {
                printf("Zgjidhni nje opsion te sakte (1-12)!    ");
                break;
            }
        }
    }
}

//                                          Shfaq menu

void shfaq_menu_user(void)
{
    printf("                           MENU PERDORUES\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("1. Shto një shpenzim të ri\n");
    printf("2. Shto të ardhura\n");
    printf("3. Shfaq shpenzimet e mia\n");
    printf("4. Shfaq të ardhurat e mia\n");
    printf("5. Raport mujor / vjetor \n");
    printf("6. Kontrollo buxhetin\n");
    printf("7. Kërko shpenzim sipas kategorisë\n");
    printf("8. Fshini të dhënat e një shpenzimi\n");
    printf("9. Rendit shpenzimet sipas shumës\n");
    printf("10. Rendit shpenzimet sipas datës\n");
    printf("11. Kërko shpenzim sipas ID, datës, kategorisë, interval të datave\n");
    printf("12. Dilni nga menuja e përdoruesit\n");
}

//                                         Funksionet

void shto_shpenzim(int user_index)
{
    if(shpenzim_aktual == MAX_SHPENZIME)
    {
        printf("Kemi arritur numrin maksimal te shpenzimeve.");
        printf("\nNuk mund te shtojme dot tjeter ne sistem");
        printf("\nKontaktoni me administratorin per ta rregulluar.\n\n\n");
        return ;
    }
    printf("Jepni te dhenat per shpenzimin e ri:\n");

    // ID_shpenzim + kontroll
    shpenzimet[shpenzim_aktual].id_shpenzim = merr_id_input("shpenzim");

    // ID_user automatikisht
    shpenzimet[shpenzim_aktual].id_user = perdoruesit[user_index].id_user;

    // ID_kategori + kontroll
    int n;
    shfaq_kategorite();
    printf("\nZgjidhni nje nga kategorite: ");
    while (1)
    {
        scanf("%d", &n);
        if (n < 1 || n > kategoria_aktuale)
        {
            printf("Kjo kategori nuk ekziston!\n");
            printf("Zgjidhni nje opsion te sakte (1-%d): ", kategoria_aktuale);
            continue;
        }
        break;
    }
    shpenzimet[shpenzim_aktual].id_kategori = kategorite[n - 1].id_kategori;

    // Shuma
    float para;
    printf("\nShuma: ");
    while (1)
    {
        if (scanf("%f", &para) != 1)
        {
            printf("Jepni nje vlere numerike: ");
            while (getchar() != '\n');
            continue;
        }
        if (para <= 0)
        {
            printf("Jepni nje vlere pozitive te shpenzimit: ");
            continue;
        }
        break;
    }
    shpenzimet[shpenzim_aktual].shuma = para;

    // Data + kontrolli
    printf("\nData (dd/mm/yyyy): ");
    while (1)
    {
        scanf("%s", shpenzimet[shpenzim_aktual].data);
        if (kontroll_data(shpenzimet[shpenzim_aktual].data) == -1)
        {
            printf("\nFormat i gabuar! Perdorni dd/mm/yyyy: ");
            continue;
        }
        break;
    }

    // Pershkrimi
    printf("\nPershkrimi (max 150 karaktere): ");
    while(getchar()!='\n');
    scanf("%[^\n]", shpenzimet[shpenzim_aktual].pershkrim);

    shpenzim_aktual++;
    if (ruaj_shpenzime() != -1)
    {
        printf("\nSHPENZIMI U SHTUA ME SUKSES!\n\n\n");
    }
    else
    {
        printf("\nPati problem ne shtimin e shpenzimit!\n\n\n");
    }
}

//                                                Utilities

// shfaq index ne vend te ID
void shfaq_kategorite(void)
{
    printf("\n     KATEGORITE\n");
    printf("_______________________\n\n");
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        printf("%d. %s %s\n", i + 1, 
            kategorite[i].emertim, kategorite[i].pershkrim);
    }
}

int kontroll_data(char *data)
{
    // formati i sakte: dd/mm/yyyy = 10 chars
    if (strlen(data) != 10)
        return -1;
    if (data[2] != '/' || data[5] != '/')
        return -1;
    
    int dd = atoi(data);
    int mm = atoi(data + 3);
    int yyyy = atoi(data + 6);
    
    if (dd < 1 || dd > 31) 
        return -1;
    if (mm < 1 || mm > 12) 
        return -1;
    if (yyyy < 2000 || yyyy > 2100) 
        return -1;
    
    return 1;
}
