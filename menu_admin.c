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
    printf("9. Modifiko kategori\n");
    printf("10. Statistika të sistemit\n");
    printf("11. Rradhisni të gjithë përdoruesit sipas ID\n");
    //(numri total i përdoruesve, numri total i shpenzimeve, 
    //përdoruesi me më shumë / më pak shpenzime, etj.)
    printf("12. Dilni nga menuja e administratorit\n");
    //(rikthehet në Menu 1)

    int n;
    while(1)
    {
        printf("\nZgjidhni (1-12):   ");
        // while (getchar() != '\n'); GABIM
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                system("cls");
                shto_user();
                shfaq_menu_admin(); 
                break;
            }
            case 2:
            {
                system("cls");
                shfaq_users();
                shfaq_menu_admin();
                break;
            }
            case 3:
            {
                system("cls"); 
                kerko_user_sipas_id();
                shfaq_menu_admin();
                break;
            }
            case 4:
            {
                system("cls");
                fshi_user();
                shfaq_menu_admin();
                break;
            }
            case 5:
            {
                system("cls");
                ndyrsho_user();
                shfaq_menu_admin();
                break;
            }
            case 6:
            {
                system("cls");
                shfaq_users_full();
                shfaq_menu_admin();
                break;
            }
            case 7:
            {
                system("cls");
                kerko_user_sipas_username();
                shfaq_menu_admin();
                break;
            }
            case 8:
            {
                system("cls");
                rradhit_users_sipas_username();
                shfaq_menu_admin();
                break;
            }
            case 9:
            {
                system("cls");
                modifiko_kategorite();
                shfaq_menu_admin();
                break;
            }
            case 10:
            {
                system("cls");
                statistika_sistemi();
                shfaq_menu_admin();
                break;
            }
            case 11:
            {
                system("cls");
                rradhit_users_sipas_id();
                shfaq_menu_admin();
                break;  
            }
            case 12:
            {
                system ("cls");
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
    printf("9. Modifiko kategori\n");
    printf("10. Statistika të sistemit\n");
    printf("11. Rradhisni të gjithë përdoruesit sipas ID\n");
    printf("12. Dilni nga menuja e administratorit\n");
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
    perdoruesit[user_aktual].id_user = merr_id_input("user");

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
        system("cls");
        printf("\nPERDORUESI U SHTUA ME SUKSES!\n");
        return (perdoruesit[user_aktual - 1].id_user);  //return id e user-it te shtuar
    }
    else //Deshtoi ruajtja
    {
        system("cls");
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
        system("cls");
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
        if (scanf("%d", &id) != 1)
        {
            printf("Vendosni nje vlere numerike!");
            while (getchar() != '\n');
            continue;
        }
        // kontrollo_id_ekzistuese shikon nese eshte valid (ekziston + pozitive) 
        // dhe nese po, rikthen indexin
        if (kontrollo_id_ekzistuese(id, "user") == -1) 
        {
            printf("Vendosni ID e sakte: ");
            continue;
        }
        break;
    }
    index = kontrollo_id_ekzistuese(id, "user");
    strcpy(emri_temp, perdoruesit[index].emri);
    int id_user_temp = perdoruesit[index].id_user;
    for (int i = index; i < user_aktual - 1; i++)
    {       
        perdoruesit[i] = perdoruesit[i + 1]; 
    }
    user_aktual--;

    // Fshirja e shpenzimeve te perdoruesit
    for (int i = shpenzim_aktual - 1; i >= 0; i--)
    {
        if (shpenzimet[i].id_user == id_user_temp)
        {
            for (int j = i; j < shpenzim_aktual - 1; j++)
            {
                shpenzimet[j] = shpenzimet[j + 1];
            }
            shpenzim_aktual--;
        }
    }

    // Fshirja e te ardhurave te perdoruesit
    for (int i = e_ardhura_aktuale - 1; i >= 0; i--)
    {
        if (te_ardhurat[i].id_user == id_user_temp)
        {
            for (int j = i; j < e_ardhura_aktuale - 1; j++)
            {
                te_ardhurat[j] = te_ardhurat[j + 1];
            }
            e_ardhura_aktuale--;
        }
    }

    if (ruaj_te_dhenat() != -1)
    {
        system("cls");
        printf("\nPERDORUESI \"%s\" ME GJITHE TE DHENAT E TIJ U FSHI ME SUKSES!\n", emri_temp);
    }
    else
    {
        system("cls");
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
            perdoruesit[id_index].id_user = merr_id_input("user");
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
            perdoruesit[id_index].id_user = merr_id_input("user");
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
            system("cls");
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
        system("cls");
        if (strcmp(choice, "Po") == 0 || strcmp(choice, "po") == 0 || 
            strcmp(choice, "PO") == 0)
        {
            shto_user();
        }
    }
}

void rradhit_users_sipas_username(void)
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
    char pergjigja[4];
    printf("Deshiron ta ruash kete renditje ne file? (Po/Jo):  ");
    scanf("%s", pergjigja);
    if (strcmp(pergjigja, "po") == 0 || strcmp(pergjigja, "Po") == 0 || 
        strcmp(pergjigja, "PO") == 0)
    {
        ruaj_users();
        printf("\nRUAJTJA U BE ME SUKSES!\n");
    }
}

void rradhit_users_sipas_id(void)
{
    int i, j;
    struct perdorues temp;
    for (i = 0; i < user_aktual - 1; i++)
    {
        for (j = i + 1; j < user_aktual; j++)
        {
            if (perdoruesit[i].id_user > perdoruesit[j].id_user)
            {
                temp = perdoruesit[i];
                perdoruesit[i] = perdoruesit[j];
                perdoruesit[j] = temp;
            }
        }
    }
    shfaq_users_full();
    char pergjigja[4];
    printf("Deshiron ta ruash kete renditje ne file? (Po/Jo):  ");
    scanf("%s", pergjigja);
    if (strcmp(pergjigja, "po") == 0 || strcmp(pergjigja, "Po") == 0 || 
        strcmp(pergjigja, "PO") == 0)
    {
        ruaj_users();
        printf("\nRUAJTJA U BE ME SUKSES!\n");
    }
}

void modifiko_kategorite(void)
{
    int opsioni;
    printf("Ju mund te:\n");
    printf("1. Shtoni nje kategori\n2. Ndryshoni nje kategori\n3. Fshini nje kategori\n");
    printf("4. Shfaqni kategorite\n5. Kthehu mbrapsht\n\n");
    printf("Zgjidhni opsionin (1-4): ");
    while (1)
    {
        scanf("%d", &opsioni);
        if (opsioni < 1 || opsioni > 4)
        {
            printf("Zgjidhni opsion te duhur (1-4): ");
            continue;
        }
        break;
    }
    switch(opsioni)
    {
        case 1:
        {
            printf("\nVendosni te dhenat e kategorise qe doni te shtoni:\n");
            kategorite[kategoria_aktuale].id_kategori = merr_id_input("kategorite");
            printf("Emri: ");
            scanf("%s", kategorite[kategoria_aktuale].emertim);
            printf("Pershkrimi (max 150 karaktere): ");
            while(getchar() != '\n');
            scanf("%[^\n]", kategorite[kategoria_aktuale].pershkrim);
            kategoria_aktuale++;
            break;
        }
        case 2:
        {
            if (ndrysho_kategori() == -1)
            {
                return ;
            }
            break;
        }
        case 3:
        {
            fshi_kategori();
            break;
        }
        case 4:
        {
            shfaq_kategorite_full();
            return ;
        }
        case 5:
        {
            system("cls");
            return ;
        }
        default:
        {
            printf("Error!\n");
            return ;
        }
    }
    if (ruaj_kategorite() != -1 )
    {
        printf("\nKATEGORIA U MODIFIKUA ME SUKSES!\n");
    }
    else 
    {
        printf("\nPati problem ne modifikimin e kategorise!\n");
    }
}

void statistika_sistemi(void)
{
    int opsioni;
    printf("Ju mund te shikoni keto statistika: \n");
    printf("1. Numri total i perdoruesve\n2. Numri total i shpenzimeve\n");
    printf("3. Numri total i kategorive\n4. Numri total i te ardhurave\n");
    printf("5. Perdoruesi me me shume shpenzime\n6. Perdoruesi me me pak shpenzime\n");
    printf("7. Perdoruesi me me shume te ardhura\n8. Perdoruesi me me pak te ardhura\n");
    printf("\nZgjidhni njeren prej tyre (1-8): ");
    while (1)
    {
        scanf("%d", &opsioni);
        if (opsioni < 1 || opsioni > 8)
        {
            printf("Vendosni opsion te sakte! (1-8): ");
            continue;
        }
        break;
    }

    switch(opsioni)
    {
        case 1:
        {
            printf("\nNumri total i perdoruesve eshte %d.\n", user_aktual);
            break;
        }
        case 2:
        {
            printf("\nNumri total i shpenzimeve eshte %d.\n", shpenzim_aktual);
            break;
        }
        case 3:
        {
            printf("\nNumri total i kategorive eshte %d.\n", kategoria_aktuale);
            break;
        }
        case 4:
        {
            printf("\nNumri total i te ardhurave eshte %d.\n", e_ardhura_aktuale);
            break;
        }
        case 5:
        {
            int index_max = -1;
            float max_shpenzim = 0;

            for (int u = 0; u < user_aktual; u++)
            {
                float total = 0;

                for (int i = 0; i < shpenzim_aktual; i++)
                {
                    if (shpenzimet[i].id_user == perdoruesit[u].id_user)
                    {
                        total = total + shpenzimet[i].shuma;
                    }
                }

                if (total > max_shpenzim)
                {
                    max_shpenzim = total;
                    index_max = u;
                }
            }

            if (index_max != -1)
            {
                printf("\n\nPerdoruesi me me shume shpenzime eshte %s (%s)", 
                    perdoruesit[index_max].emri, perdoruesit[index_max].username);

                printf("\nKa shpenzuar gjithsej: %.2f leke\n", max_shpenzim);
            }
            break;
        }
        case 6:
        {
            int index_min = -1;
            float min_shpenzim = -1;

            for (int u = 0; u < user_aktual; u++)
            {
                float total = 0;

                for (int i = 0; i < shpenzim_aktual; i++)
                {
                    if (shpenzimet[i].id_user == perdoruesit[u].id_user)
                    {
                        total = total + shpenzimet[i].shuma;
                    }
                }

                if (min_shpenzim == -1 || total < min_shpenzim)
                {
                    min_shpenzim = total;
                    index_min = u;
                }
            }

            if (index_min != -1)
            {
                printf("\n\nPerdoruesi me me pak shpenzime eshte %s (%s)", 
                    perdoruesit[index_min].emri, perdoruesit[index_min].username);

                printf("\nKa shpenzuar gjithsej: %.2f leke\n", min_shpenzim);
            }
            break;
        }
        case 7:
        {
            int index_max = -1;
            float max_ardhura = 0;

            for (int u = 0; u < user_aktual; u++)
            {
                float total = 0;

                for (int i = 0; i < e_ardhura_aktuale; i++)
                {
                    if (te_ardhurat[i].id_user == perdoruesit[u].id_user)
                    {
                        total = total + te_ardhurat[i].shuma;
                    }
                }

                if (total > max_ardhura)
                {
                    max_ardhura = total;
                    index_max = u;
                }
            }

            if (index_max != -1)
            {
                printf("\n\nPerdoruesi me me shume te ardhura eshte %s (%s)", 
                    perdoruesit[index_max].emri, perdoruesit[index_max].username);

                printf("\nKa regjistruar gjithsej: %.2f leke\n", max_ardhura);
            }
            break;
        }
        case 8:
        {
            int index_min = -1;
            float min_ardhura = -1;

            for (int u = 0; u < user_aktual; u++)
            {
                float total = 0;

                for (int i = 0; i < e_ardhura_aktuale; i++)
                {
                    if (te_ardhurat[i].id_user == perdoruesit[u].id_user)
                    {
                        total = total + te_ardhurat[i].shuma;
                    }
                }

                if (min_ardhura == -1 || total < min_ardhura)
                {
                    min_ardhura = total;
                    index_min = u;
                }
            }

            if (index_min != -1)
            {
                printf("\n\nPerdoruesi me me pak te ardhura eshte %s (%s)", 
                    perdoruesit[index_min].emri, perdoruesit[index_min].username);

                printf("\nKa regjistruar gjithsej: %.2f leke\n", min_ardhura);
            }
            break;
        }
        default:
        {
            printf("Error!\n");
            break;
        }
    }
}

//                                         Utilities

//kontrollo nese ekziston
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

int ndrysho_kategori(void)
{
    int zgjedhja;
    int id;
    printf("\nVendosni ID e kategorise qe doni te ndryshoni: ");
    while (1)
    {
        if (scanf("%d", &id) != 1)
        {
            printf("Vendosni nje vlere numerike: ");
            while (getchar() != '\n');
            continue;
        }
        if (kontrollo_id_ekzistuese(id, "kategorite") == -1)
        {
            printf("Vendosni ID te sakte: ");
            continue;
        }
        break;
    }
    int id_index = gjej_kategori_id(id);
    printf("\nJu mund te ndryshoni:\n");
    printf("1. ID\n2. Emrin\n3. Pershkrimin\n4. Te gjitha\n5. Kthehu mbrapsht\n\n");
    printf("Zgjidhni opsionin qe deshironi (1-5): ");
    while (1)
    {
        scanf("%d", &zgjedhja);
        if (zgjedhja < 1 || zgjedhja > 5)
        {
            printf("\nZgjidhni nje opsion te sakte! (1-5): ");
            continue;
        }
        break;
    }

    switch(zgjedhja)
    {
        case 1:
        {
            kategorite[id_index].id_kategori = merr_id_input("kategorite");
            printf("\nKATEGORIA U NDRYSHUA ME SUKSES!\n");
            break;
        }
        case 2:
        {
            printf("Emri: ");
            while(getchar()!='\n');
            scanf("%s", kategorite[id_index].emertim);
            printf("\nEMRI I KATEGORISE U NDRYSHUA ME SUKSES!\n");
            break;
        }
        case 3:
        {
            printf("Pershkrimi (max 150 karaktere): ");
            while(getchar() != '\n');
            scanf("%[^\n]", kategorite[id_index].pershkrim);
            printf("\nPERSHKRIMI I KATEGORISE U NDRYSHUA ME SUKSES!\n");
            break;
        }
        case 4:
        {
            kategorite[id_index].id_kategori = merr_id_input("kategorite");
            printf("Emri: ");
            scanf("%s", kategorite[id_index].emertim);
            printf("Pershkrimi (max 150 karaktere): ");
            while(getchar() != '\n');
            scanf("%[^\n]", kategorite[id_index].pershkrim);
            break;
        }
        case 5:
        {
            system("cls");
            return -1;
        }
        default:
        {
            printf("Error!\n");
            return -1;
        }
    }
    return 1;
}

void fshi_kategori(void)
{
    int id;
    shfaq_kategorite_id();
    printf("\nVendosni ID e kategorise qe doni te fshini: ");
    while (1)
    {
        if (scanf("%d", &id) != 1)
        {
            printf("Vendosni nje vlere numerike: ");
            while (getchar() != '\n');
            continue;
        }
        if (kontrollo_id_ekzistuese(id, "kategorite") == -1)
        {
            printf("Vendosni ID te sakte: ");
            continue;
        }
        break;
    }
    int id_index = gjej_kategori_id(id);
    for (int i = id_index; i < kategoria_aktuale - 1; i++)
    {
        kategorite[i] = kategorite[i + 1];
    }
    kategoria_aktuale--;
}

void shfaq_kategorite_full(void)
{
    printf("\n                                         KATEGORITE \n");
    printf("__________________________________________________________________________________________\n\n");
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        printf("Kategoria %d", i + 1);
        printf("\n-------------------------------------------------------------------------------------------\n");
        printf("ID: %d\nEmri: %s\nPershkrimi: %s", 
            kategorite[i].id_kategori, kategorite[i].emertim, kategorite[i].pershkrim);
        printf("\n-------------------------------------------------------------------------------------------\n\n\n");
    }
}

//                                        merr_*_input

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

//kontrollo qe mos te jete i zene
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