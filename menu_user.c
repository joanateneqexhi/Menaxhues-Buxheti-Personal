#include "header.h"

void menu_user(int user_index)
{
    printf("                           MENU PERDORUES\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("1. Shto nje shpenzim te ri\n");
    printf("2. Shto te ardhura\n");
    printf("3. Shfaq shpenzimet e mia\n");
    printf("4. Shfaq te ardhurat e mia\n");
    printf("5. Raport mujor / vjetor \n");
    //(totali i te ardhurave, shpenzimeve, kursimet, kategoria me me shume shpenzime)
    printf("6. Kontrollo buxhetin\n");
    printf("7. Kerko shpenzim sipas kategorise\n");
    printf("8. Fshini te dhenat e nje shpenzimi\n");
    printf("9. Rendit shpenzimet sipas shumes\n");
    printf("10. Rendit shpenzimet sipas dates\n");
    printf("11. Kerko shpenzim sipas ID, dates, kategorise, interval te datave\n");
    printf("12. Fshini te dhenat e nje te ardhure\n");
    printf("13. Dilni nga menuja e perdoruesit\n");
    //(rikthehet ne Menu 1)

    int n;

    while(1)
    {
        printf("\nZgjidhni (1-13):   ");
        while (getchar() != '\n');
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                system("cls");
                shto_shpenzim(user_index);
                shfaq_menu_user();
                break;
            }
            case 2:
            {
                system("cls");
                shto_te_ardhura(user_index);
                shfaq_menu_user();
                break;
            }
            case 3:
            {
                system("cls");
                shfaq_shpenzimet(user_index);
                shfaq_menu_user();
                break;
            }
            case 4:
            {
                system("cls");
                shfaq_te_ardhurat(user_index);
                shfaq_menu_user();
                break;
            }
            case 5:
            {
                system("cls");
                raport_mujor_vjetor(user_index);
                shfaq_menu_user();
                break;
            }
            case 6:
            {
                system("cls");
                kontrollo_buxhetin(user_index);
                shfaq_menu_user();
                break;
            }
            case 7:
            {
                system("cls");
                kerko_shpenzim_sipas_kategorise(user_index);
                shfaq_menu_user();
                break;
            }
            case 8:
            {
                system("cls");
                fshi_shpenzim(user_index);
                shfaq_menu_user();
                break;
            }
            case 9:
            {
                system("cls");
                rendit_shpenzimet_sipas_shumes(user_index);
                shfaq_menu_user();
                break;
            }
            case 10:
            {
                system("cls");
                rendit_shpenzimet_sipas_dates(user_index);
                shfaq_menu_user();
                break;
            }
            case 11:
            {
                system("cls");
                kerko_shpenzim(user_index);
                shfaq_menu_user();
                break;
            }
            case 12:
            {
                system("cls");
                fshi_te_ardhura(user_index);
                shfaq_menu_user();
                break;
            }
            case 13:
            {
                system("cls");
                printf("                               MENU\n");
                printf("---------------------------------------------------------------------\n\n");
                return ;
            }
            default:
            {
                printf("Zgjidhni nje opsion te sakte (1-13)!    ");
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
    printf("1. Shto nje shpenzim te ri\n");
    printf("2. Shto te ardhura\n");
    printf("3. Shfaq shpenzimet e mia\n");
    printf("4. Shfaq te ardhurat e mia\n");
    printf("5. Raport mujor / vjetor \n");
    printf("6. Kontrollo buxhetin\n");
    printf("7. Kerko shpenzim sipas kategorise\n");
    printf("8. Fshini te dhenat e nje shpenzimi\n");
    printf("9. Rendit shpenzimet sipas shumes\n");
    printf("10. Rendit shpenzimet sipas dates\n");
    printf("11. Kerko shpenzim sipas ID, dates, kategorise, interval te datave\n");
    printf("12. Fshini te dhenat e nje te ardhure\n");
    printf("13. Dilni nga menuja e perdoruesit\n");
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
    shfaq_kategorite_index();
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

void shto_te_ardhura(int user_index)
{
    if(e_ardhura_aktuale == MAX_ARDHURA)
    {
        printf("Kemi arritur numrin maksimal te te ardhurave.");
        printf("\nNuk mund te shtojme dot tjeter ne sistem");
        printf("\nKontaktoni me administratorin per ta rregulluar.\n\n\n");
        return ;
    }
    printf("Jepni te dhenat per te ardhuren e re:\n");
    
    // ID_hyrje + kontroll
    te_ardhurat[e_ardhura_aktuale].id_hyrje = merr_id_input("te ardhura");
    
    // ID_user automatikisht
    te_ardhurat[e_ardhura_aktuale].id_user = perdoruesit[user_index].id_user;

    // Shuma
    float shuma;
    printf("\nShuma: ");
    while (1)
    {
        if (scanf("%f", &shuma) != 1)
        {
            printf("Jepni nje vlere numerike: ");
            while (getchar() != '\n');
            continue;
        }
        if (shuma <= 0)
        {
            printf("Jepni nje vlere pozitive te te ardhurave: ");
            continue;
        }
        break;
    }
    te_ardhurat[e_ardhura_aktuale].shuma = shuma;

    // Data + kontrolli
    printf("\nData (dd/mm/yyyy): ");
    while (1)
    {
        scanf("%s", te_ardhurat[e_ardhura_aktuale].data);
        if (kontroll_data(te_ardhurat[e_ardhura_aktuale].data) == -1)
        {
            printf("\nFormat i gabuar! Perdorni dd/mm/yyyy: ");
            continue;
        }
        break;
    }

    // Burimi
    printf("\nBurimi (max 30 karaktere): ");
    while(getchar()!='\n');
    scanf("%[^\n]", te_ardhurat[e_ardhura_aktuale].burimi);

    e_ardhura_aktuale++;
    if (ruaj_ardhura() != -1)
    {
        printf("\nE ARDHURA U SHTUA ME SUKSES!\n\n\n");
    }
    else
    {
        printf("\nPati problem ne shtimin e te ardhures!\n\n\n");
    }
}

void shfaq_shpenzimet(int user_index)
{
    int nr = 0;
    printf("\n                           SHPENZIMET E MIA\n");
    printf("________________________________________________________________________\n\n");
    for (int i = 0; i < shpenzim_aktual; i++)
    {
        if (shpenzimet[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        printf("Shpenzimi %d", ++nr);
        printf("\n-----------------------------------\n");
        printf("ID: %d\nKategoria: %s\nPershkrimi: %s\nShuma: %.2f\nData: %s", 
            shpenzimet[i].id_shpenzim, 
            kategorite[gjej_kategori_id(shpenzimet[i].id_kategori)].emertim, 
            shpenzimet[i].pershkrim, shpenzimet[i].shuma, shpenzimet[i].data);
        printf("\n-----------------------------------\n\n\n");
    }
}

void shfaq_te_ardhurat(int user_index)
{
    int nr = 0;
    printf("\n                          TE ARDHURAT E MIA\n");
    printf("________________________________________________________________________\n\n");
    for (int i = 0; i < e_ardhura_aktuale; i++)
    {
        if (te_ardhurat[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        printf("Hyrja %d", ++nr);
        printf("\n-----------------------------------\n");
        printf("ID: %d\nBurimi %s\nShuma: %.2f\nData: %s", 
            te_ardhurat[i].id_hyrje, te_ardhurat[i].burimi, 
            te_ardhurat[i].shuma, te_ardhurat[i].data);
        printf("\n-----------------------------------\n\n\n");
    }
}

void raport_mujor_vjetor(int user_index)
{
    int opsioni;
    printf("Deshironi te shikoni:\n");
    printf("1. Raportin mujor;\n2. Raportin vjetor?\n");
    printf("\nZgjidhni njeren prej tyre: ");
    
    while (1)
    {
        scanf("%d", &opsioni);
        if (opsioni != 1 && opsioni != 2)
        {
            printf("\nZgjidhni nje opsion te sakte (1-2): ");
            continue;
        }
        break;
    }

    switch (opsioni)
    {
        case 1:
        {
            system("cls");
            raport_mujor(user_index);
            break;
        }
        case 2:
        {
            system("cls");
            raport_vjetor(user_index);
            break;
        }
        default:
        {
            printf("Error!\n");
            break;
        }
    }
}

void kontrollo_buxhetin(int user_index)
{
    int muaji, viti, mm, yyyy;
    printf("Muaji (1-12): ");
    while (1)
    {
        scanf("%d", &muaji);
        if (muaji < 1 || muaji > 12)
        {
            printf("Vendosni nje muaj te sakte: ");
            continue;
        }
        break;
    }
    printf("Viti (yyyy): ");
    while (1)
    {
        scanf("%d", &viti);
        if (viti < VITI_MINIMAL|| viti > VITI_AKTUAL)
        {
            printf("Vendosni nje vit te sakte: ");
            continue;
        }
        break;
    }
    
    float total_shpenzime = 0;
    for(int i = 0; i < shpenzim_aktual; i++)
    {
        if (shpenzimet[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        mm = atoi(shpenzimet[i].data + 3);
        yyyy = atoi(shpenzimet[i].data + 6);

        if(mm == muaji && yyyy == viti)
            total_shpenzime = total_shpenzime + shpenzimet[i].shuma;
    }

    float buxheti = perdoruesit[user_index].buxheti_mujor;
    float mbetur = buxheti - total_shpenzime;

    printf("\n                    KONTROLLI I BUXHETIT %02d/%d\n", muaji, viti);
    printf("_______________________________________________________________________________");
    printf("\nBuxheti juaj mujor:              %.2f", buxheti);
    printf("\nTotali i shpenzimeve tuaja:      %.2f", total_shpenzime);
    printf("\nEnde pa shpenzuar:               %.2f", buxheti - total_shpenzime);
    printf("\n_______________________________________________________________________________\n");

    if (mbetur < 0)
        printf("!! KUJDES: Keni tejkaluar buxhetin me %.2f leke!\n\n\n", -mbetur);
    else if (mbetur < (buxheti / 2))
        printf("!! KUJDES: Keni me pak se gjysmen e buxhetit te mbetur! Konkretisht vetem %.1f%%\n\n\n", 
            (mbetur / buxheti) * 100);
    else
        printf("Jeni ne rregull me buxhetin! Bravo!\n\n\n");
}

void kerko_shpenzim_sipas_kategorise(int user_index)
{
    int id_kategoria;
    int index_kategori;
    shfaq_kategorite_id();
    printf("\nSipas ciles kategori doni te kerkoni shpenzimet? ");
    while (1)
    {
        scanf("%d", &id_kategoria);
        index_kategori = gjej_kategori_id(id_kategoria);
        if (index_kategori == -1)
        {
            printf("Zgjidhni nje kategori ne liste: ");
            continue;
        }
        break;
    }
    system("cls");
    printf("\n\n      KATEGORIA E ZGJEDHUR: %s", kategorite[index_kategori].emertim);
    printf("\n____________________________________________\n\n");
    int nr = 0;
    for (int i = 0; i < shpenzim_aktual; i++)
    {
        if (shpenzimet[i].id_user != perdoruesit[user_index].id_user)
            continue;
        if (shpenzimet[i].id_kategori != id_kategoria)
            continue;
        printf("Shpenzimi %d", ++nr);
        printf("\n-----------------------------------\n");
        printf("ID: %d\nPershkrimi: %s\nShuma: %.2f\nData: %s\n", 
            shpenzimet[i].id_shpenzim, shpenzimet[i].pershkrim, 
            shpenzimet[i].shuma, shpenzimet[i].data);
        printf("-----------------------------------\n\n\n");
    }
    if (nr == 0)
    {
        printf("\nNuk u gjet asnje shpenzim ne kete kategori.\n\n\n");
    }
}

void fshi_shpenzim(int user_index)
{
    int id;
    int id_index;
    shfaq_shpenzimet(user_index);
    printf("Vendosni ID e shpenzimit qe doni te fshini: ");
    while (1)
    {
        if (scanf("%d", &id) != 1)
        {
            printf("Vendosni nje vlere numerike: ");
            while (getchar() != '\n');
            continue;
        }
        if (kontrollo_id_ekzistuese(id, "shpenzim") == -1)
        {
            printf("Vendosni ID te sakte: ");
            continue;
        }
        id_index = gjej_shpenzim_id(id);
        if (shpenzimet[id_index].id_user != perdoruesit[user_index].id_user)
        {
            printf("Shpenzimi me kete ID nuk eshte kryer nga ju!\n");
            printf("\nVendosni ID te sakte: ");
            continue;
        }
        break;
    }
    for (int i = id_index; i < shpenzim_aktual - 1; i++)
    {
        shpenzimet[i] = shpenzimet[i + 1];
    }
    shpenzim_aktual--;
    if (ruaj_shpenzime() != -1 )
    {
        printf("\nSHPENZIMI U FSHI ME SUKSES!\n\n\n");
    }
    else 
    {
        printf("\nPati problem ne fshirjen e shpenzimit\n\n\n");
    }
}

void rendit_shpenzimet_sipas_shumes(int user_index)
{
    int i, j;
    struct shpenzim temp_arr[MAX_SHPENZIME]; // vektor me gjithe shpenzimet e user
    int nr_shpenzimesh = 0;

    for (i = 0; i < shpenzim_aktual; i++)
    {
        if(shpenzimet[i].id_user != perdoruesit[user_index].id_user)
            continue;
        temp_arr[nr_shpenzimesh] = shpenzimet[i];
        nr_shpenzimesh++;
    }
    struct shpenzim temp;
    for (i = 0; i < nr_shpenzimesh - 1; i++)
    {
        for (j = i + 1; j < nr_shpenzimesh; j++)
        {
            if (temp_arr[i].shuma < temp_arr[j].shuma)
            {
                temp = temp_arr[i];
                temp_arr[i] = temp_arr[j];
                temp_arr[j] = temp;
            }
        }
    }
    printf("\n                SHPENZIMET E RENDITURA SIPAS SHUMES\n");
    printf("________________________________________________________________________\n\n");
    for (int i = 0; i < nr_shpenzimesh; i++)
    {
        printf("Shpenzimi %d", i + 1);
        printf("\n-----------------------------------\n");
        printf("ID: %d\nKategoria: %s\nPershkrimi: %s\nShuma: %.2f\nData: %s", 
            temp_arr[i].id_shpenzim, 
            kategorite[gjej_kategori_id(temp_arr[i].id_kategori)].emertim, 
            temp_arr[i].pershkrim, temp_arr[i].shuma, temp_arr[i].data);
        printf("\n-----------------------------------\n\n\n");
    }
}

void rendit_shpenzimet_sipas_dates(int user_index)
{
    int i, j;
    struct shpenzim temp_arr[MAX_SHPENZIME]; // vektor me gjithe shpenzimet e user
    int nr_shpenzimesh = 0;

    for (i = 0; i < shpenzim_aktual; i++)
    {
        if(shpenzimet[i].id_user != perdoruesit[user_index].id_user)
            continue;
        temp_arr[nr_shpenzimesh] = shpenzimet[i];
        nr_shpenzimesh++;
    }
    struct shpenzim temp;
    for (i = 0; i < nr_shpenzimesh - 1; i++)
    {
        for (j = i + 1; j < nr_shpenzimesh; j++)
        {
            if (krahaso_datat(temp_arr[i].data, temp_arr[j].data) > 0)
            {
                temp = temp_arr[i];
                temp_arr[i] = temp_arr[j];
                temp_arr[j] = temp;
            }
        }
    }
    printf("\n                 SHPENZIMET E RENDITURA SIPAS DATES\n");
    printf("________________________________________________________________________\n\n");
    for (int i = 0; i < nr_shpenzimesh; i++)
    {
        printf("Shpenzimi %d", i + 1);
        printf("\n-----------------------------------\n");
        printf("ID: %d\nKategoria: %s\nPershkrimi: %s\nShuma: %.2f\nData: %s", 
            temp_arr[i].id_shpenzim, 
            kategorite[gjej_kategori_id(temp_arr[i].id_kategori)].emertim, 
            temp_arr[i].pershkrim, temp_arr[i].shuma, temp_arr[i].data);
        printf("\n-----------------------------------\n\n\n");
    }
}

void kerko_shpenzim(int user_index)
{
    int opsioni;
    printf("Mund te kerkoni shpenzime sipas:\n");
    printf("1. ID\n2. Dates\n3. Kategorise\n4. Intervali datash\n\n");
    printf("Zgjidhni njeren prej tyre: ");
    while (1)
    {
        scanf("%d", &opsioni);
        if (opsioni < 1 || opsioni > 4)
        {
            printf("Zgjidhni nje opsion te sakte (1-4): ");
            continue;
        }
        break;
    }

    switch(opsioni)
    {
        case 1:
        {
            int id;
            int id_index;
            printf("\nVendosni ID e shpenzimit qe po kerkoni: ");
            while (1)
            {
                scanf("%d", &id);
                id_index = kontrollo_id_ekzistuese(id, "shpenzim");
                if (id_index == -1)
                {
                    printf("\nVendosni ID te sakte: ");
                    continue;
                }
                if (shpenzimet[id_index].id_user != perdoruesit[user_index].id_user)
                {
                    printf("Shpenzimi me kete ID nuk ju perket juve!\n");
                    printf("\nVendosni ID te sakte: ");
                    continue;
                }
                break;
            }
            system("cls");
            printf("\n\nSHPENZIMI U GJET!");
            printf("\n-----------------------------------\n");
            printf("ID: %d\nKategoria: %s\nPershkrimi: %s\nShuma: %.2f\nData: %s", 
                shpenzimet[id_index].id_shpenzim, 
                kategorite[gjej_kategori_id(shpenzimet[id_index].id_kategori)].emertim, 
                shpenzimet[id_index].pershkrim, shpenzimet[id_index].shuma, shpenzimet[id_index].data);
            printf("\n-----------------------------------\n\n\n");
            break;
        }
        case 2:
        {
            char temp_data[11];
            printf("\nVendosni daten e shpenzimit qe po kerkoni (dd/mm/yyyy): ");
            while (1)
            {
                scanf("%s", temp_data);
                if (kontroll_data(temp_data) == -1)
                {
                    printf("Formati ose data e gabuar! Perdorni dd/mm/yyyy: ");
                    continue;
                }
                break;
            }
            system("cls");
            printf("\n\n                       SHPENZIMET (%s)\n", temp_data);
            printf("________________________________________________________________________\n");
            int nr = 0;
            for (int i = 0; i < shpenzim_aktual; i++)
            {
                if (shpenzimet[i].id_user == perdoruesit[user_index].id_user)
                {
                    if (strcmp(shpenzimet[i].data, temp_data) == 0)
                    {
                        printf("\n\nSHPENZIMI %d", ++nr);
                        printf("\n-----------------------------------\n");
                        printf("ID: %d\nKategoria: %s\nPershkrimi: %s\nShuma: %.2f\nData: %s", 
                            shpenzimet[i].id_shpenzim, 
                            kategorite[gjej_kategori_id(shpenzimet[i].id_kategori)].emertim, 
                            shpenzimet[i].pershkrim, shpenzimet[i].shuma, shpenzimet[i].data);
                        printf("\n-----------------------------------\n");
                    }
                }
            }
            if (nr == 0)
            {
                printf("\nNuk keni bere asnje shpenzim ne ate date.");
            }
            printf("\n\n\n");
            break;
        }
        case 3:
        {
            system("cls");
            kerko_shpenzim_sipas_kategorise(user_index);
            break;
        }
        case 4:
        {
            char data_fillim[11];
            char data_mbarim[11];
            printf("Data e fillimit (dd/mm/yyyy): ");
            while (1)
            {
                scanf("%s", data_fillim);
                if (kontroll_data(data_fillim) == -1)
                {
                    printf("Formati ose data e gabuar! Perdorni dd/mm/yyyy: ");
                    continue;
                }
                break;
            }
            printf("Data e mbarimit (dd/mm/yyyy): ");
            while (1)
            {
                scanf("%s", data_mbarim);
                if (kontroll_data(data_mbarim) == -1)
                {
                    printf("Formati ose data e gabuar! Perdorni dd/mm/yyyy: ");
                    continue;
                }
                if (krahaso_datat(data_fillim, data_mbarim) > 0)
                {
                    printf("Data e mbarimit duhet te jete pas dates se fillimit!\n");
                    continue;
                }
                break;
            }
            system("cls");
            int nr = 0;
            for (int i = 0; i < shpenzim_aktual; i++)
            {
                if (shpenzimet[i].id_user == perdoruesit[user_index].id_user)
                {
                    if (krahaso_datat(shpenzimet[i].data, data_fillim) >= 0 &&
                        krahaso_datat(shpenzimet[i].data, data_mbarim) <= 0)
                        {
                            if (nr == 0)
                            {
                                printf("\n\n                    SHPENZIMET (%s-%s)\n", data_fillim, data_mbarim);
                                printf("________________________________________________________________________\n\n");
                            }
                            printf("\nShpenzimi %d", ++nr);
                            printf("\n-----------------------------------\n");
                            printf("ID: %d\nKategoria: %s\nPershkrimi: %s\nShuma: %.2f\nData: %s", 
                                shpenzimet[i].id_shpenzim, 
                                kategorite[gjej_kategori_id(shpenzimet[i].id_kategori)].emertim, 
                                shpenzimet[i].pershkrim, shpenzimet[i].shuma, shpenzimet[i].data);
                            printf("\n-----------------------------------\n");
                        }
                }
            }
            if (nr == 0)
            {
                printf("\nNuk keni bere asnje shpenzim ne kete interval datash.");
            }
            printf("\n\n\n");
            break;
        }
        default:
        {
            printf("Error!\n");
            break;
        }
    }
}

void fshi_te_ardhura(int user_index)
{
    int id;
    int id_index;
    shfaq_te_ardhurat(user_index);
    printf("Vendosni ID e hyrjes qe doni te fshini: ");
    while (1)
    {
        if (scanf("%d", &id) != 1)
        {
            printf("Vendosni nje vlere numerike: ");
            while (getchar() != '\n');
            continue;
        }
        if (kontrollo_id_ekzistuese(id, "ardhura") == -1)
        {
            printf("Vendosni ID te sakte: ");
            continue;
        }
        id_index = gjej_ardhura_id(id);
        if (te_ardhurat[id_index].id_user != perdoruesit[user_index].id_user)
        {
            printf("Hyrja me kete ID nuk ju perket juve!\n");
            printf("\nVendosni ID te sakte: ");
            continue;
        }
        break;
    }
    for (int i = id_index; i < e_ardhura_aktuale - 1; i++)
    {
        te_ardhurat[i] = te_ardhurat[i + 1];
    }
    e_ardhura_aktuale--;
    if (ruaj_ardhura() != -1 )
    {
        printf("\nE ARDHURA U FSHI ME SUKSES!\n\n\n");
    }
    else 
    {
        printf("\nPati problem ne fshirjen e te ardhures!\n\n\n");
    }
}

//                                                Utilities

// shfaq me index ne vend te ID -> duhet tek shto_shpenzim
void shfaq_kategorite_index(void)
{
    printf("\n     KATEGORITE\n");
    printf("_______________________\n\n");
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        printf("%d. %s %s\n", i + 1, 
            kategorite[i].emertim, kategorite[i].pershkrim);
    }
}

// shfaq me ID ne vend te index -> duhet tek kerko_shpenzim_sipas_kategorise
void shfaq_kategorite_id(void) 
{
    printf("\n     KATEGORITE\n");
    printf("_______________________\n\n");
    for (int i = 0; i < kategoria_aktuale; i++)
    {
        printf("%d. %s %s\n", kategorite[i].id_kategori, 
            kategorite[i].emertim, kategorite[i].pershkrim);
    }
}

void raport_mujor(int user_index)
{
    int muaji, viti, mm, yyyy;
    printf("Muaji (1-12): ");
    while (1)
    {
        scanf("%d", &muaji);
        if (muaji < 1 || muaji > 12)
        {
            printf("Vendosni nje muaj te sakte: ");
            continue;
        }
        break;
    }
    printf("Viti (yyyy): ");
    while (1)
    {
        scanf("%d", &viti);
        if (viti < VITI_MINIMAL|| viti > VITI_AKTUAL)
        {
            printf("Vendosni nje vit te sakte: ");
            continue;
        }
        break;
    }
    
    float total_ardhura = 0;
    for(int i = 0; i < e_ardhura_aktuale; i++)
    {
        if (te_ardhurat[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        mm = atoi(te_ardhurat[i].data + 3);
        yyyy = atoi(te_ardhurat[i].data + 6);

        if (mm == muaji && yyyy == viti)
            total_ardhura = total_ardhura + te_ardhurat[i].shuma;
    }

    float total_shpenzime = 0;
    for(int i = 0; i < shpenzim_aktual; i++)
    {
        if (shpenzimet[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        mm = atoi(shpenzimet[i].data + 3);
        yyyy = atoi(shpenzimet[i].data + 6);

        if(mm == muaji && yyyy == viti)
            total_shpenzime = total_shpenzime + shpenzimet[i].shuma;
    }

    // Gjetja e kategorise me me shume shpenzime
    int max_shpenzime = 0;
    int index_max_shpenzime;
    int count = 0;
    for(int i = 0; i < kategoria_aktuale; i++)
    {
        for (int j = 0; j < shpenzim_aktual; j++)
        {
            if (shpenzimet[j].id_kategori != kategorite[i].id_kategori)
            {
                continue;
            }
            mm = atoi(shpenzimet[j].data + 3);
            yyyy = atoi(shpenzimet[j].data + 6);

            if(mm == muaji && yyyy == viti)
                count++;
        }
        if (count > max_shpenzime)
        {
            max_shpenzime = count;
            index_max_shpenzime = i;
        }
    }

    printf("\n                       RAPORT MUJOR %02d/%d\n", muaji, viti);
    printf("________________________________________________________________________");
    printf("\nTotali i te ardhurave tuaja:     %.2f", total_ardhura);
    printf("\nTotali i shpenzimeve tuaja:      %.2f", total_shpenzime);
    printf("\nKursimet tuaja:                  %.2f", total_ardhura - total_shpenzime);
    if (max_shpenzime != 0)
    {
        printf("\nKategoria ku ju keni shpenzuar me shume eshte: \"%s\"", 
            kategorite[index_max_shpenzime].emertim);
    }
    printf("\n________________________________________________________________________\n\n\n");
}

void raport_vjetor(int user_index)
{
    int viti, yyyy;
    printf("Viti (yyyy): ");
    while (1)
    {
        scanf("%d", &viti);
        if (viti < VITI_MINIMAL|| viti > VITI_AKTUAL)
        {
            printf("Vendosni nje vit te sakte: ");
            continue;
        }
        break;
    }
    
    float total_ardhura = 0;
    for(int i = 0; i < e_ardhura_aktuale; i++)
    {
        if (te_ardhurat[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        yyyy = atoi(te_ardhurat[i].data + 6);

        if (yyyy == viti)
            total_ardhura = total_ardhura + te_ardhurat[i].shuma;
    }

    float total_shpenzime = 0;
    for(int i = 0; i < shpenzim_aktual; i++)
    {
        if (shpenzimet[i].id_user != perdoruesit[user_index].id_user)
        {
            continue;
        }
        yyyy = atoi(shpenzimet[i].data + 6);

        if(yyyy == viti)
            total_shpenzime = total_shpenzime + shpenzimet[i].shuma;
    }

    // Gjetja e kategorise me me shume shpenzime
    int max_shpenzime = 0;
    int index_max_shpenzime;
    int count = 0;
    for(int i = 0; i < kategoria_aktuale; i++)
    {
        for (int j = 0; j < shpenzim_aktual; j++)
        {
            if (shpenzimet[j].id_kategori != kategorite[i].id_kategori)
            {
                continue;
            }
            yyyy = atoi(shpenzimet[j].data + 6);

            if(yyyy == viti)
                count++;
        }
        if (count > max_shpenzime)
        {
            max_shpenzime = count;
            index_max_shpenzime = i;
        }
    }

    printf("\n                       RAPORT VJETOR %d\n", viti);
    printf("________________________________________________________________________");
    printf("\nTotali i te ardhurave tuaja:     %.2f", total_ardhura);
    printf("\nTotali i shpenzimeve tuaja:      %.2f", total_shpenzime);
    printf("\nKursimet tuaja:                  %.2f", total_ardhura - total_shpenzime);
    if (max_shpenzime != 0)
    {
        printf("\nKategoria ku ju keni shpenzuar me shume eshte: \"%s\"", 
            kategorite[index_max_shpenzime].emertim);
    }
    printf("\n________________________________________________________________________\n\n\n");
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
    
    if (mm < 1 || mm > 12) 
        return -1;
    if (yyyy < VITI_MINIMAL || yyyy > VITI_AKTUAL) 
        return -1;

     // ditet maksimale per cdo muaj
    int ditet[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // kontroll per vitin brishte, muajin shkurt
    if (yyyy % 4 == 0 && (yyyy % 100 != 0 || yyyy % 400 == 0))
        ditet[1] = 29;

    if (dd < 1 || dd > ditet[mm - 1]) 
        return -1;

    return 1;
}

int krahaso_datat(char *data1, char *data2)
{
    int yyyy1 = atoi(data1 + 6);
    int yyyy2 = atoi(data2 + 6);
    if (yyyy1 != yyyy2) 
        return yyyy1 - yyyy2;
    
    int mm1 = atoi(data1 + 3);
    int mm2 = atoi(data2 + 3);
    if (mm1 != mm2) 
        return mm1 - mm2;

    int dd1 = atoi(data1); 
    int dd2 = atoi(data2);
        return dd1 - dd2;
}
