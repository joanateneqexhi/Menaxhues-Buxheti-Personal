#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h> // per strcmp
# include <stdlib.h> //per funksionin: int system(const char *command) / system("cls")
# include <ctype.h> // per funksionin: ispunct (pass validation)

// limitet maksimale qe mund te mbaj secili struct array
# define MAX_USER 50
# define MAX_SHPENZIME 250
# define MAX_ARDHURA 250
# define MAX_KATEGORI 25

// password per tu loguar si admin
# define ADMIN_PASS "Admin@2026"

//                                        Strukturat

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
    int id_kategori;
    float shuma;
    char data[10];
    char pershkrim[150];
};

struct te_ardhura
{
    int id_hyrje;
    int id_user;
    float shuma;
    char data[10];
    char burimi[30];
};

// extern 
// -> qe te njihen nga gjithe files, mos te tentoje secila ti deklaroje vet (deklaruar ne main)
extern int user_aktual;
extern int shpenzim_aktual;
extern int e_ardhura_aktuale;
extern int kategoria_aktuale;

extern struct perdorues perdoruesit[MAX_USER];
extern struct kategori kategorite[MAX_KATEGORI];
extern struct shpenzim shpenzimet[MAX_SHPENZIME];
extern struct te_ardhura te_ardhurat[MAX_ARDHURA];

//                                           Funksionet
void rradhit_users_username(void);

//                                            - Menu
int menu_1(void);
void shfaq_menu_admin(void);
void shfaq_menu_user(void);
void menu_admin(void);
void menu_user(void);

int inicializo_file(char *filename);

//                                            - lexo_*
int lexo_users(void);
int lexo_kategorite(void);
int lexo_shpenzime(void);
int lexo_ardhura(void);

//                                            - ruaj_*
int ruaj_te_dhenat(void);
int ruaj_users(void);
int ruaj_kategorite(void);
int ruaj_shpenzime(void);
int ruaj_ardhura(void);

//                                            - gjej_* kontrollo_*
int gjej_user_username(char *username);
int gjej_user_id(int id);
int kontrollo_id_ekzistuese(int id);
int merr_id_input(void);
float merr_buxhet_input(void);
void merr_username(char *username);
void merr_pass_input(char *password);

//                                            - menu_admin
int shto_user(void);
void shfaq_users(void);
int kerko_user_sipas_id(void);
void fshi_user(void);
void ndyrsho_user(void);
void shfaq_users_full(void);
void kerko_user_sipas_username(void);
void rradhit_users_username(void);

//                                            - menu_user

#endif