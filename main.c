#include "header.h"

//Kompilimi: cc menu_admin.c menu_user.c main.c header.h

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
    system("clear");

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
                system("clear");  //system ("cls")  - per Windows
                if (menu_admin() == -1)
                {
                    // Mesazhi i gabimit specifik eshte bere sapo eshte hasur gabimi
                    printf("Po mbyllet programi...\n");
                    return -1;
                }
                break;
            }
            case 2:
            {
                system("clear");
                if (menu_user() == -1)
                {
                    // Mesazhi i gabimit specifik eshte bere sapo eshte hasur gabimi
                    printf("Po mbyllet programi...\n");
                    return 0;
                }
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
        while (getchar() != '\n');  //Bej skip gjithe inputin e gabuar (char)
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