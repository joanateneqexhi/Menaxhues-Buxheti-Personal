#include "header.h"

//gcc main.c menu_admin.c menu_user.c id_utils.c -o program.exe

//Variabla globale per indexet aktuale te seciles strukture
int user_aktual = 0;
int shpenzim_aktual = 0;
int e_ardhura_aktuale = 0;
int kategoria_aktuale = 0;

//Variabla globale per secilen strukture
struct perdorues perdoruesit[MAX_USER];
struct kategori kategorite[MAX_KATEGORI];
struct shpenzim shpenzimet[MAX_SHPENZIME];
struct te_ardhura te_ardhurat[MAX_ARDHURA];

FILE *fp;

int main()
{
    system("cls");

    // Per heren e pare te ekzekutimit, krijimi i file-ve
    if (inicializo_file("user.txt") == -1 || inicializo_file("shpenzime.txt") == -1 ||
        inicializo_file("teArdhura.txt") == -1 || inicializo_file("kategori.txt") == -1)
    {
        printf("Po mbyllet programi...\n");
        return -1;
    }

    // Kalojme gjithe te dhenat nga files ne structs
    if (lexo_users() == -1 || lexo_kategorite() == -1 ||
        lexo_shpenzime() == -1 || lexo_ardhura() == -1)
    {
        printf("Po mbyllet programi...\n");
        return -1;
    }

    int opsioni;

    printf("================= MIRESEVINI =================\n\n");
    
    while (1)
    {
        opsioni = menu_1();
        switch (opsioni)
        {
            case 1:
            {
                system("cls");
                char admin_pass[20];
                for(int i = 3; i > 0; i--)
                {
                    printf("Vendosni passwordin e admin-it: ");
                    scanf("%s", admin_pass);
                    if (strcmp(admin_pass, ADMIN_PASS) != 0)
                    {
                        printf("Passwordi i gabuar. Mund te provoni dhe %d here.\n\n", i - 1);
                    }
                    else
                        break;
                }
                if (strcmp(admin_pass, ADMIN_PASS) == 0)
                {
                    system("cls");
                    menu_admin();
                }
                else
                {
                    printf("Ju nuk mund te logoheni si administrator!\n\n");
                }    
                break;
            }
            case 2:
            {
                system("cls");
                char user_username[15];
                char user_pass[20];
                int user_index;
                printf("Vendosni username tuaj:\n");
                while (1)
                {
                    scanf("%s", user_username);
                    user_index = gjej_user_username(user_username);
                    if (user_index == -1)
                    {
                        printf("\nKy username nuk ekziston!");
                        printf("\nProvoni perseri: ");
                    }
                    else
                        break;
                }
                for (int i = 3; i > 0; i--)
                {
                    printf("Vendosni password-in tuaj: ");
                    scanf("%s", user_pass);
                    if (strcmp(user_pass, perdoruesit[user_index].password) == 0)
                    {
                        system("cls");
                        printf(":)  Mireseerdhe %s!\n\n\n", perdoruesit[user_index].emri);
                        menu_user(user_index);
                        break;
                    }
                    else
                    {
                        printf("Passwordi i gabuar. Mund te provoni dhe %d here.\n\n", i - 1);
                    }
                }
                break;
            }
            case 3:
            {
                system("cls");
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

//                                         Funksionet

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
        while (getchar() != '\n');
        scanf("%d", &n);
    }
    return (n); 
}

int inicializo_file(char *filename)
{
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
            printf("Gabim ne krijimin e file %s!\n", filename);
            return -1;
        }

        fprintf(fp, "0\n");
        fclose(fp);
    }

    else
    {
        fclose(fp);
    }

    return 1;
}

//                                       Funksionet lexo_*

int lexo_users(void)
{
    fp = fopen("user.txt", "r");

    if (fp == NULL)
    {
        printf("Gabim ne leximin e file user.txt!\n");
        return -1;
    }

    fscanf(fp, "%d\n", &user_aktual);
    for (int i = 0; i < user_aktual; i++)
    {
        fscanf(fp, "%d %s %s %s %f\n", &perdoruesit[i].id_user, perdoruesit[i].emri, 
            perdoruesit[i].username, perdoruesit[i].password, 
            &perdoruesit[i].buxheti_mujor);
    }

    fclose(fp);

    return 1;
}

int lexo_kategorite(void)
{
    fp = fopen ("kategori.txt", "r");

    if (fp == NULL)
    {
        printf("Gabim ne leximin e file kategori.txt");
        return -1;
    }

    fscanf(fp, "%d\n", &kategoria_aktuale);
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        fscanf(fp, "%d %s %[^\n] \n", &kategorite[i].id_kategori, 
            kategorite[i].emertim, kategorite[i].pershkrim);
    }

    fclose(fp);

    return 1;
}

int lexo_shpenzime(void)
{
    fp = fopen("shpenzime.txt", "r");

    if (fp == NULL)
    {
        printf("Gabim ne leximin e file shpenzime.txt!\n");
        return -1;
    }

    fscanf(fp, "%d\n", &shpenzim_aktual);
    for (int i = 0; i < shpenzim_aktual; i++)
    {
        fscanf(fp, "%d %d %d %f %s %[^\n] \n", &shpenzimet[i].id_shpenzim,
            &shpenzimet[i].id_user, &shpenzimet[i].id_kategori, &shpenzimet[i].shuma,
            shpenzimet[i].data, shpenzimet[i].pershkrim);
    }

    fclose(fp);

    return 1;
}

int lexo_ardhura(void)
{
    fp = fopen("teArdhura.txt", "r");

    if (fp == NULL)
    {
        printf("Gabim ne leximin e file teArdhura.txt!\n");
        return -1;
    }

    fscanf(fp, "%d\n", &e_ardhura_aktuale);
    for (int i = 0; i < e_ardhura_aktuale; i++)
    {
        fscanf(fp, "%d %d %f %s %[^\n] \n", &te_ardhurat[i].id_hyrje,
            &te_ardhurat[i].id_user, &te_ardhurat[i].shuma, 
            te_ardhurat[i].data, te_ardhurat[i].burimi);
    }

    fclose(fp);

    return 1;
}

//                                       Funksionet ruaj_*

int ruaj_te_dhenat(void)
{
    if (ruaj_users() == -1 || ruaj_kategorite() == -1 || 
        ruaj_shpenzime() == -1 || ruaj_ardhura() == -1)
    {
        // Nuk printojme mesazh gabimi sepse e ka printuar vete funksioni specifik
        return -1;
    }
    return 1;
}

int ruaj_users(void)
{
    fp = fopen("user.txt", "w");
    if (fp == NULL)
    {
        printf("Gabim ne ruajtjen e file user.txt!\n");
        return -1;
    }

    fprintf(fp, "%d\n", user_aktual);
    for (int i = 0; i < user_aktual; i++)
    {
        fprintf(fp, "%d %s %s %s %.2f\n", perdoruesit[i].id_user, perdoruesit[i].emri, 
            perdoruesit[i].username, perdoruesit[i].password, 
            perdoruesit[i].buxheti_mujor);
    }
    
    fclose(fp);

    return 1;
}

int ruaj_kategorite(void)
{
    fp = fopen("kategori.txt", "w");
    if (fp == NULL)
    {
        printf("Gabim ne ruajtjen e file kategori.txt!\n");
        return -1;
    }

    fprintf(fp, "%d\n", kategoria_aktuale);
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        fprintf(fp, "%d %s %s\n", kategorite[i].id_kategori, 
            kategorite[i].emertim, kategorite[i].pershkrim);
    }

    fclose(fp);

    return 1;
}

int ruaj_shpenzime(void)
{
    fp = fopen("shpenzime.txt", "w");

    if (fp == NULL)
    {
        printf("Gabim ne ruajtjen e file shpenzime.txt!\n");
        return -1;
    }

    fprintf(fp, "%d\n", shpenzim_aktual);
    for (int i = 0; i < shpenzim_aktual; i++)
    {
        fprintf(fp, "%d %d %d %.2f %s %s\n", shpenzimet[i].id_shpenzim,
            shpenzimet[i].id_user, shpenzimet[i].id_kategori, shpenzimet[i].shuma,
            shpenzimet[i].data, shpenzimet[i].pershkrim);
    }

    fclose(fp);

    return 1;
}

int ruaj_ardhura(void)
{
    fp = fopen("teArdhura.txt", "w");

    if (fp == NULL)
    {
        printf("Gabim ne ruajtjen e file teArdhura.txt!\n");
        return -1;
    }

    fprintf(fp, "%d\n", e_ardhura_aktuale);
    for (int i = 0; i < e_ardhura_aktuale; i++)
    {
        fprintf(fp, "%d %d %.2f %s %s\n", te_ardhurat[i].id_hyrje,
            te_ardhurat[i].id_user, te_ardhurat[i].shuma, 
            te_ardhurat[i].data, te_ardhurat[i].burimi);
    }

    fclose(fp);

    return 1;
}