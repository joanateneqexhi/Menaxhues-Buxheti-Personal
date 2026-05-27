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
        // while (getchar() != '\n'); GABIM
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                system("clear");
                shto_user();
                shfaq_menu_admin(); 
                break;
            }
            case 2:
            {
                system("clear");
                shfaq_users();
                shfaq_menu_admin();
                break;
            }
            case 3:
            {
                system("clear"); 
                kerko_user_sipas_id();
                shfaq_menu_admin();
                break;
            }
            case 4:
            {
                system("clear");
                fshi_user();
                shfaq_menu_admin();
                break;
            }
            case 5:
            {
                system("clear");
                ndyrsho_user();
                shfaq_menu_admin();
                break;
            }
            case 6:
            {
                system("clear");
                shfaq_users_full();
                shfaq_menu_admin();
                break;
            }
            case 7:
            {
                system("clear");
                kerko_user_sipas_username();
                shfaq_menu_admin();
                break;
            }
            case 8:
            {
                system("clear");
                rradhit_users_username();
                shfaq_menu_admin();
                break;
            }
            case 9:
            {
                system("clear");

                shfaq_menu_admin();
                break;
            }
            case 10:
            {
                system("clear");

                shfaq_menu_admin();
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

//                                       Shfaq menu

void shfaq_menu_admin(void)
{
    printf("\n\n                        MENU ADMINISTRATOR\n");
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

//                                       Funksionet

int shto_user(void)
{
    if (user_aktual == MAX_USER)
    {
        printf("Kemi arritur numrin maksimal te perdoruesve. Nuk mund te shtojme tjeter.\n");
        return -1;
    }

    printf("Jepni te dhenat per user-in e ri:\n");

    // ID + kontrolli
    perdoruesit[user_aktual].id_user = merr_id_input();

    // Emri
    printf("Emri: ");
    scanf("%s", perdoruesit[user_aktual].emri);

    // Username + kontrolli
    merr_username(perdoruesit[user_aktual].username);

    // Password + kontrolli
    merr_pass_input(perdoruesit[user_aktual].password);

    // Buxheti mujor + kontrolli
    perdoruesit[user_aktual].buxheti_mujor = merr_buxhet_input();

    // Ruajtja ne file
    user_aktual++;
    if (ruaj_users() != -1)
    {
        system("clear");
        printf("\nPERDORUESI U SHTUA ME SUKSES!\n");
        return (perdoruesit[user_aktual - 1].id_user);  //return id e user-it te shtuar
    }
    else //Deshtoi ruajtja
    {
        system("clear");
        user_aktual--;
        printf("Perdoruesi nuk u shtua.\n");
        return -1;
    }
}

void shfaq_users(void)
{
    printf("\n     PERDORUESIT\n");
    printf("_______________________\n\n");
    for (int i = 0; i < user_aktual; i++)
    {
        printf("%d. %s\n", i + 1, perdoruesit[i].emri);
    }
}

// returns index e ID nese gjehet/krijohet
int kerko_user_sipas_id(void)
{
    int id;
    printf("Vendosni ID e perdoruesit qe po kerkoni: ");
    while (1)
    {
        scanf("%d", &id);
        if (id <= 0)
            {
                printf("ID ne sistem jane numra pozitive!\n");
                printf("Vendosni ID e perdoruesit qe po kerkoni: ");
                continue;
            }
        else
            break;
    }    
    int index = gjej_user_id(id);
    if (index != -1)
    {
        printf("\nPerdoruesi u gjet! Te dhenat:\n\n");
        printf("1. ID: %d\n2. Emri: %s\n3. Username: %s\n4. Buxheti Mujor: %.2f\n", 
            perdoruesit[index].id_user, perdoruesit[index].emri, 
            perdoruesit[index].username, perdoruesit[index].buxheti_mujor);
        return (index);
    }
    else
    {
        printf("\nPerdoruesi me kete ID nuk u gjet.\n");
        printf("Deshiron ta shtosh? (Po/Jo) ");
        char choice[4];
        scanf("%s", choice);
        system("clear");
        if (strcmp(choice, "Po") == 0 || strcmp(choice, "po") == 0 || 
            strcmp(choice, "PO") == 0)
        {
            return(shto_user());
        }
        else
        {
            return -1; // nuk u gjet dhe as nuk u shtua nje ID
        }
    }
}

void fshi_user(void)
{
    int id;
    int index;
    char emri_temp[30];
    printf("Vendosni ID e user-it qe doni te fshini: ");
    //Nuk perdor kerko_user_sipas_id sepse ajo krijon ID nese nuk gjehet (nese do admini)
    while (1)
    {
        scanf("%d", &id);
        // kontrollo_id_ekzistuese shikon nese eshte valid (ekziston + pozitive) 
        // dhe nese po, rikthen indexin
        if (kontrollo_id_ekzistuese(id) == -1) 
        {
            printf("Vendosni ID e sakte: ");
            continue;
        }
        break;
    }
    index = kontrollo_id_ekzistuese(id);
    strcpy(emri_temp, perdoruesit[index].emri);
    for (int i = index; i < user_aktual - 1; i++)
    {       
        perdoruesit[i] = perdoruesit[i + 1]; 
    }
    user_aktual--;
    if (ruaj_users() != -1)
    {
        system("clear");
        printf("\nPERDORUESI \"%s\" U FSHI ME SUKSES!\n", emri_temp);
    }
    else
    {
        system("clear");
        user_aktual++;
        printf("Perdoruesi nuk u fshi dot.\n");
    }
}

void ndyrsho_user(void)
{
    int opsioni;
    int id_index = kerko_user_sipas_id();
    if (id_index == -1)
    {
        printf("Ndryshimi nuk mund te behet pa nje ID.\n");
        return ;
    }
    printf("5. Password: %s", perdoruesit[id_index].password);
    printf("\n6. Te gjitha\n7. Kthehu mbrapsht\n\n");
    printf("Zgjidhni cilen te dhene doni te ndryshoni (1-7): ");
    while (1)
    {
        scanf("%d", &opsioni);
        if (opsioni < 1 || opsioni > 7)
        {
            printf("Zgjidhni nje opsion te sakte (1-7): ");
            continue;
        }
        break;
    }
    switch(opsioni)
    {
        case 1: //ID
        {
            perdoruesit[id_index].id_user = merr_id_input();
            printf("\n\nID u ndryshua me sukses!\n\n\n");
            break;
        }
        case 2: //Emri
        {
            printf("Emri: ");
            scanf("%s", perdoruesit[id_index].emri);
            printf("\n\nEmri u ndryshua me sukses!\n\n\n");
            break;
        }
        case 3: //Username
        {
            merr_username(perdoruesit[id_index].username);
            printf("\n\nUsername u ndryshua me sukses!\n\n\n");
            break;
        }
        case 4: //Buxheti
        {
            perdoruesit[id_index].buxheti_mujor = merr_buxhet_input();
            printf("\n\nBuxheti mujor u ndryshua me sukses!\n\n\n");
            break;
        } 
        case 5: //Password
        {
            merr_pass_input(perdoruesit[id_index].password);
            printf("\n\nPassword u ndryshua me sukses!\n\n\n");
            break;
        }
        case 6: //Te gjitha
        {
            perdoruesit[id_index].id_user = merr_id_input();
            printf("Emri: ");
            scanf("%s", perdoruesit[id_index].emri);
            merr_username(perdoruesit[id_index].username);
            perdoruesit[id_index].buxheti_mujor = merr_buxhet_input();
            merr_pass_input(perdoruesit[id_index].password);
            printf("\n\nTe dhenat u ndryshuan me sukses!\n\n\n");
            break;
        }
        case 7:
        {
            system("clear");
            break;
        }
        default:
        {
            printf("Error\n");
            break;
        }
    }
    if (ruaj_users() == -1)
    {
        printf("Problem ne ruajtjen e ndryshimeve!\n");
    }
}

void shfaq_users_full(void)
{
    printf("\n                             PERDORUESIT\n");
    printf("________________________________________________________________________\n\n");
    for (int i = 0; i < user_aktual; i++)
    {
        printf("Perdoruesi %d", i + 1);
        printf("\n-----------------------------------\n");
        printf("ID: %d\nEmri: %s\nUsername: %s\nPassword: %s\nBuxheti: %.2f", 
            perdoruesit[i].id_user, perdoruesit[i].emri, perdoruesit[i].username,
            perdoruesit[i].password, perdoruesit[i].buxheti_mujor);
        printf("\n-----------------------------------\n\n\n");
    }
}

void kerko_user_sipas_username(void)
{
    char username[15];
    printf("Vendosni username qe po kerkoni: ");
    scanf("%s", username);
    int index = gjej_user_username(username);
    if (index != -1)
    {
        printf("\nPerdoruesi u gjet! Te dhenat:\n\n");
        printf("ID: %d\nEmri: %s\nUsername: %s\nPassword: %s\nBuxheti Mujor: %.2f\n", 
            perdoruesit[index].id_user, perdoruesit[index].emri, perdoruesit[index].username, 
            perdoruesit[index].password,perdoruesit[index].buxheti_mujor);
    }
    else
    {
        printf("\nPerdorues me kete username nuk u gjet.\n");
        printf("Deshiron ta shtosh? (Po/Jo) ");
        char choice[4];
        scanf("%s", choice);
        system("clear");
        if (strcmp(choice, "Po") == 0 || strcmp(choice, "po") == 0 || 
            strcmp(choice, "PO") == 0)
        {
            shto_user();
        }
    }
}

// Vetem per printim, nuk ruhet ne file
void rradhit_users_username(void)
{
    int i, j;
    struct perdorues temp;
    for (i = 0; i < user_aktual - 1; i++)
    {
        for (j = i + 1; j < user_aktual; j++)
        {
            if (strcmp(perdoruesit[i].username, perdoruesit[j].username) > 0)
            {
                temp = perdoruesit[i];
                perdoruesit[i] = perdoruesit[j];
                perdoruesit[j] = temp;
            }
        }
    }
    shfaq_users_full();
}

void modifiko_kategorite(void)
{
    int opsioni;
    printf("1. Shto\n2.Ndrysho\n3.Fshi\n");
    printf("Zgjidh opsionin (1-3): ");
    while (1)
    {
        scanf("%d", &opsioni);
        if (opsioni < 1 || opsioni > 3)
        {
            printf("Zgjidhni opsion te duhur (1-3): ");
            continue;
        }
        break;
    }
    switch(opsioni)
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
        default:
        {
            break;
        }
    }
}

//                                         Utilities

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

// kontroll ID pozitive dhe te ekzitoje -> per tek funksioni kerko sipas id + fshi
int kontrollo_id_ekzistuese(int id)
{
    int index;
    if (id <= 0)
        {
            printf("ID ne sistem jane numra pozitive!\n");
            return -1;
        }
        index = gjej_user_id(id);
        if (index == -1)
        {
            printf("User me kete ID nuk ekziston!\n");
            return -1;
        }
    return index; //ID eshte valid
}

// kontroll ID pozitive dhe NUK ekziston -> per tek shto + ndrysho user
int merr_id_input(void)
{
    int n;
    while (1)
    {
        printf("\nID: ");
        while (getchar() != '\n');
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("Vendosni nje numer ID pozitiv!");
            continue;
        }
        if (gjej_user_id(n) != -1)
        {
            printf("Kjo ID eshte e zene!");
            continue;
        }
        break;
    }
    return n;
}

float merr_buxhet_input(void)
{
    float buxhet;
    while (1)
    {
        printf("Buxheti mujor: ");
        if (scanf("%f", &buxhet) != 1)
        {
            printf("Vendosni nje vlere numerike!\n");
            while (getchar() != '\n');  // flush inputin e gabuar
            continue;
        }
        if (buxhet <= 0)
        {
            printf("Buxheti duhet te jete pozitiv!\n");
            continue;
        }
        break;
    }
    return buxhet;
}

void merr_username(char *username)
{
    char temp[15];
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
    strcpy(username, temp);
}

void merr_pass_input(char *password)
{
    int pass_len;
    while (1)
    {
        printf("Password: ");
        scanf("%s", password);

        pass_len = strlen(password);

        if (pass_len < 4)
        {
            printf("Password duhet te kete minimumi 4 karaktere!\n");
            continue;
        }

        if (pass_len >= 19)
        {
            printf("Password duhet te jete me pak se 20 karaktere!\n");
            continue;
        }

        if (password[0] < 'A' || password[0] > 'Z')
        {
            printf("Password duhet te filloje me shkronje te madhe!\n");
            continue;
        }

        int ka_numer = 0;
        for (int i = 0; i < pass_len; i++)
        {
            if (password[i] >= '0' && password [i] <= '9')
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
            if (ispunct(password[i]) != 0)
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
}