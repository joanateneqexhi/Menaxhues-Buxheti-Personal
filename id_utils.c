#include "header.h"

// kontroll ID pozitive dhe NUK ekziston -> per tek shto + ndrysho user, kategori
int merr_id_input(char *struktura)
{
    int u_gjet = -1;
    int id;
    while (1)
    {
        printf("\nID: ");
        while (getchar() != '\n');
        if (scanf("%d", &id) != 1)
        {
            printf("Vendosni nje vlere numerike!");
            continue;
        }
        if (id <= 0)
        {
            printf("Vendosni nje numer ID pozitiv!");
            continue;
        }
        else if (strcmp(struktura, "user") == 0)
        {
            u_gjet = gjej_user_id(id);
        }
        else if (strcmp(struktura, "kategorite") == 0)
        {
            u_gjet = gjej_kategori_id(id);
        }
        else if(strcmp(struktura, "shpenzim") == 0)
        {
            u_gjet = gjej_shpenzim_id(id);
        }
        if (u_gjet != -1)
        {
            printf("Kjo ID eshte e zene!");
            continue;
        }
        break;
    }
    return id;
}

// kontroll ID pozitive dhe te ekzitoje -> per tek funksioni kerko sipas id + fshi + ndrysho
int kontrollo_id_ekzistuese(int id, char *struktura)
{
    int index = -1;
    if (id <= 0)
    {
        printf("ID ne sistem jane numra pozitive!\n");
        return -1;
    }
    else if (strcmp(struktura, "user") == 0)
    {
        index = gjej_user_id(id);
    }
    else if (strcmp(struktura, "kategorite") == 0)
    {
        index = gjej_kategori_id(id);
    }
    else if(strcmp(struktura, "shpenzim") == 0)
    {
        index = gjej_shpenzim_id(id);
    }
    if (index == -1)
    {
        printf("Kjo ID nuk ekziston ne sistem!\n");
        return -1;
    }
    return index; //ID eshte valid
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

int gjej_kategori_id(int id)
{
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        if (id == kategorite[i].id_kategori)
        {
            return i;
        }
    }
    return -1;
}

int gjej_shpenzim_id(int id)
{
    for (int i = 0; i < shpenzim_aktual; i++)
    {
        if (id == shpenzimet[i].id_shpenzim)
        {
            return i;
        }
    }
    return -1;
}

int gjej_ardhura_id(int id)
{
    for (int i = 0; i < e_ardhura_aktuale; i++)
    {
        if (id == te_ardhurat[i].id_hyrje)
        {
            return i;
        }
    }
    return -1;
}