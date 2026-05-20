#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //per funksionin: int system(const char *command) / system("cls")

struct perdorues
{
    int id_user;
    char emri[30];
    char username[15];
    char password[20];
    float buxheti_mujor;
};

struct kategori
{
    int id_kategori;
    char emertim[20];
    char  pershkrim[150];
};

struct shpenzim
{
    int id_shpenzim;
    int id_user;
    char pershkrim[150];
    struct kategori kategoria;
    float shuma;
    char data[10];
};

struct te_ardhura
{
    int id_hyrje;
    int id_user;
    char burimi[20];
    float shuma;
    char data[10];
};

int menu_1(void);
void menu_admin(void);
void menu_user(void);


#endif