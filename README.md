# Sistem për Menaxhimin e Shpenzimeve Personale

Detyrë kursi — **Teknikat dhe Gjuhët e Programimit** (Inxhinieri Kompjuterike, viti I)
Gjuha e programimit: **C**

## Përshkrimi i projektit

Program konsol (CLI) që lejon menaxhimin e shpenzimeve dhe të ardhurave personale të disa përdoruesve. Sistemi ka dy role:

- **Administrator** — menaxhon llogaritë e përdoruesve dhe kategoritë e shpenzimeve.
- **Përdorues** — regjistron shpenzime/të ardhura, gjeneron raporte dhe kontrollon buxhetin mujor.

Të dhënat ruhen në mënyrë të përhershme në skedarë teksti (`.txt`) dhe ngarkohen në memorie (array structesh) në fillim të ekzekutimit.

## Struktura e projektit

| Skedar | Përshkrim |
|---|---|
| `main.c` | Funksioni `main`, Menu 1 (login), leximi/ruajtja e të dhënave nga/në skedarë (`lexo_*`, `ruaj_*`) |
| `menu_admin.c` | Të gjitha funksionalitetet e menusë së administratorit |
| `menu_user.c` | Të gjitha funksionalitetet e menusë së përdoruesit |
| `id_utils.c` | Funksione ndihmëse për validimin/gjenerimin e ID-ve unike (`merr_id_input`, `kontrollo_id_ekzistuese`, `gjej_*_id`) |
| `header.h` | Deklarimet e structeve, konstanteve, variablave globale `extern` dhe prototipet e funksioneve |
| `user.txt` | Të dhënat e përdoruesve |
| `shpenzime.txt` | Të dhënat e shpenzimeve |
| `teArdhura.txt` | Të dhënat e të ardhurave |
| `kategori.txt` | Të dhënat e kategorive të shpenzimeve |

## Strukturat kryesore (`header.h`)

```c
struct perdorues     { id_user, emri, username, password, buxheti_mujor };
struct kategori      { id_kategori, emertim, pershkrim };
struct shpenzim       { id_shpenzim, id_user, id_kategori, shuma, data, pershkrim };
struct te_ardhura    { id_hyrje, id_user, shuma, data, burimi };
```

Limitet maksimale të array-ve: `MAX_USER=50`, `MAX_SHPENZIME=250`, `MAX_ARDHURA=250`, `MAX_KATEGORI=25`.

## Menutë e programit

### Menu 1 — Login
1. Hyrje si Administrator (kërkon fjalëkalimin e admin-it, max 3 tentativa)
2. Hyrje si Përdorues (kërkon username + password, max 3 tentativa për password)
3. Dalje nga programi

### Menu 2 — Administrator
1. Shtoni një përdorues të ri
2. Shfaq përdoruesit
3. Kërko përdorues sipas ID
4. Fshini kredencialet e një përdoruesi
5. Ndryshoni të dhënat e një përdoruesi ekzistues
6. Printoni të gjitha të dhënat e përdoruesve
7. Kërkoni një përdorues sipas username
8. Rradhitni të gjithë përdoruesit sipas username
9. Shto/Ndrysho/Fshi kategori
10. Statistika të sistemit
11. Rradhitni të gjithë përdoruesit sipas ID
12. Dilni nga menuja e administratorit

### Menu 3 — Përdorues
1. Shto një shpenzim të ri
2. Shto të ardhura
3. Shfaq shpenzimet e mia
4. Shfaq të ardhurat e mia
5. Raport mujor / vjetor (totali i të ardhurave, shpenzimeve, kursimet, kategoria me më shumë shpenzime)
6. Kontrollo buxhetin
7. Kërko shpenzim sipas kategorisë
8. Fshini të dhënat e një shpenzimi
9. Rendit shpenzimet sipas shumës
10. Rendit shpenzimet sipas datës
11. Kërko shpenzim sipas ID, datës, kategorisë, intervali të datave
12. Fshini të dhënat e një të ardhure
13. Dilni nga menuja e përdoruesit

## Kushtet e validimit

- ID-të duhet të jenë numra pozitivë dhe **unikë** (kontrollohen te `id_utils.c`).
- Username duhet të jetë **unik**.
- Password duhet të:
  - fillojë me shkronjë të madhe,
  - ketë minimumi 4 karaktere,
  - përmbajë të paktën 1 numër dhe 1 simbol.
- Data validohet me `kontroll_data()` (formati `dd/mm/yyyy`, brenda intervalit `VITI_MINIMAL`–`VITI_AKTUAL`), krahasimi mes datave bëhet me `krahaso_datat()`.

## Kompilimi dhe ekzekutimi

Programi është shkruar për Windows (përdor `system("cls")`).

```bash
gcc main.c menu_admin.c menu_user.c id_utils.c -o program.exe
program.exe
```

> Në Linux/macOS, zëvendëso `system("cls")` me `system("clear")` te `main.c` nëse do ta ekzekutosh atje.

Fjalëkalimi i administratorit (i përcaktuar në `header.h`):
```
ADMIN_PASS = "Admin@2026"
```

## Shënime

- Skedarët `.txt` krijohen automatikisht (me `inicializo_file`) nëse nuk ekzistojnë, që në ekzekutimin e parë.
- Të dhënat lexohen në structe në fillim të programit dhe ruhen mbrapsht në skedarë me funksionet `ruaj_*`.
- Projekt individual, i zhvilluar për lëndën "Teknikat dhe Gjuhët e Programimit".
