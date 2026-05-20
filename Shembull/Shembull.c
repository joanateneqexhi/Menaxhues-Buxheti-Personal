// Ushtrim me Struktura dhe Funksione
//     1. Të ndërtohet një program që mban informacion për artikujt që mbahen në një magazine. Programi përdor një vektor strukturash, ku cdo structure mban informacion – numri i artikullit, emri, gjendja në magazine – për një artikull. Veprimet që do mund të kryhen në këtë program janë:
//     a) (Shtim) Shtimi i një artikulli të ri (numri i artikullit, emri, gjendja)
//     b) (Kërkim) Nëse na jepet numri i një artikulli të kërkohet në databazë dhe nëse ekziston të shfaqet emri dhe gjendja e tij.
//     c) (Modifikim) Nëse na jepet numri i një artikulli, të mund të modifikohet gjendja e tij.
//     d) (Printim) të printojë në formë të rregullt gjithë informacionin e databazës.
//     e) Të përfundojë ekzekutimin e programit;



    

//  Hapat:
//     1. Përcaktoni strukturën ku do të ruhen të dhënat;
//     2. Përcakto prototipet e funksioneve që do ju duhen;
//     3. Disa funksione që duhet të përcaktoni:

//     • int gjej_artikull(int ID)
// Funksioni gjej_artikull kerkon ne vektorin inventari artikull me variablin numri sa vlera qe merr si argument. Kthen indeksin e vektorit nese gjen nje artikull me nje numer te tille, ne te kundert kthen -1

//     • void shto(void);
// Funksioni shto, i kerkon perdoruesit informacion per nje artikull te ri dhe me pas e shton artikullin ne databaze. Kthen nje mesazh gabimi nese artikulli ekzistonte qe me pare ose nese databaza eshte plot 
//     • void kerko (void);
// Funksioni kerko i kerkon perdoruesit te jap nje numer artikulli, pastaj kerkon ne databaze, nese artikulli me kete numer ekziston kthen emrin dhe gjendjen e artikullit, ne te kundert printon nje mesazh gabimi. 
//     • void update(void);
// Funksioni update i kerkon perdoruesit te jape nje numer artikulli. Kthen nje mesazh gabimi nese artikulli nuk ekziston; ne te kundert i kerkon perdoruesit te jape ndryshimin ne gjendje te artikullit dhe i ben update.
//     • void printo(void);
// Funksioni printo, printon gjithe artikujt ne databaze, duke dhene numrin, emrin dhe gjendjen e artikullit. Artikujt printohen me ate renditje qe jane futur ne databaze.
//     4. Ne funksionin main duhet të përcaktoni opsionet që mund të zgjidhen dhe një switch për të përcaktuar opsionin e zgjedhur.

#include <stdio.h>
#include <stdlib.h>

//Percaktojme nje konstante MAX e cila do te ruaje kapacitetin e magazines
#define MAX 100
#define filename "inventari.txt"

//Percaktojme formatin e struktures
struct artikulli
{
	int numri;
	char emri[20];
	int gjendja;
}inventari[MAX];

//Deklarojme nje variabel globale e cila do te mbaje numrin aktual te artikujve ne inventar
int nr_artikull=0;
FILE *f;

//Percaktojme prototipet e funksioneve qe do te perdorim gjate programit
int gjej_artikull(int numri);
void menu(void);
void shto(void);
void kerko(void);
void update(void);
void printo(void);
void ruaj(void);
void lexo(void);

//Deklarojme funksionin main
int main()
{
	//Variabli opsion do te ruaje zgjedhjen e perdoruesit
	int opsioni;
	
	//Therrasim funksionin menu()
	menu();
	
	f=fopen(filename,"r");
	if(f==NULL)
	{
		//krijojme
		f=fopen(filename,"w");  //Heren e pare te ekzekutimit
		int nr=0;
		fprintf(f,"%d\n",nr);
		fclose(f);
	}
	
	//Thirrja e funksionit lexo
	lexo();
	
	//Perdoruesi jep si input opsionin e zgjedhur
	printf("\nZgjidhni nje opsion nga menu:");
	scanf("%d",&opsioni);
	
	//Cikel i pafundem 
	//Programi vazhdon deri kur perdoruesi zgjedhj opsionin 5
	while(1)
	{
		switch(opsioni)
		{
			case 1:
				system("cls");
				menu();
				shto();
				break;
			case 2:
				system("cls");
				menu();
				kerko();
				break;
			case 3:
				system("cls");
				menu();
				update();
				break;
			case 4:
				system("cls");
				menu();
				printo();
				break;
			case 5:
				ruaj();
				break;
			case 6:
				return 0;
			default:
				printf("Opsioni i zgjedhur nuk eshte i sakte. Shkruaj nje numer tjeter.");
				break;	
		}
		
		printf("\n\nZgjidhni nje opsion tjeter:");
		scanf("%d",&opsioni);
	}	
}

void menu(void)
{
	//Printojme vlerat e menu
	printf("MENU");
	printf("\n------------------------------");
	printf("\n1.Shto nje artikull te ri.\n");
	printf("\n2.Kerko per nje artikull ekzistues.\n");
	printf("\n3.Modifiko nje artikull ekzistues.\n");
	printf("\n4.Printo vlerat e gjithë artikujve të ruajtur.\n");
	printf("\n5.Ruaj te dhenat ne file.\n");
	printf("\n6.Dil nga programi.\n");
}

int gjej_artikull(int numri)
{
	int i;
	//Krijojme nje cikel for per te kontrolluar secilin index ne vektorin inventari[]
	for(i=0;i<nr_artikull;i++)
	{
		if(inventari[i].numri==numri)
		{
			//Numri u gjet ne vektor, kthejme indeksin i ku gjendet ky numer artikulli
			return i;
		}
	}
	
	//Nese numri i artikullit nuk gjendet ne inventar, kthejme nje vlere -1
	return -1;
}

void shto(void)
{
	printf("\n\nSHTIMI I NJE ARTIKULLI");
	printf("\n------------------------------\n");
	//Do kontrollojme dy kushte
	//1. Kontrollojme nese vektori inventari eshte plot apo jo.
	if(nr_artikull==MAX)
	{
		printf("Inventari eshte i mbushur, nuk kemi vend per artikull tjeter.");
		return;
	}
	
	//2.Kontrollojme nese artikulli ekziston apo jo
	int nr;
	printf("Jepni numrin e artikullit qe deshironi te shtoni:\n");
	scanf("%d",&nr);
	
	//Kerkojme nese numri i dhene (nr) gjendet ne vektorin inventari[]
	int index=gjej_artikull(nr);
	if(index>=0)
	{
		printf("Ky artikull ekziston. Nuk lejohet qe ta shtoni serish.");
		return;
	}
	else
	{
		//Ruajme te dhenat e artikullit ne indeksin perkates te vektorit inventari[]
		inventari[nr_artikull].numri=nr;
		
		printf("\nJepni emrin e artikullit:\n");
		scanf("%s",inventari[nr_artikull].emri);
		printf("\nJepni gjendjen e artikullit:\n");
		scanf("%d",&inventari[nr_artikull].gjendja);
		
		//Inkrementojme vleren e variablit global qe ruan numrin aktual te artikujve
		nr_artikull++;
		
		printf("\nARTIKULLI U SHTUA!");
	}	
}

void kerko(void)
{
	printf("\n\nKERKIMI I NJE ARTIKULLI");
	printf("\n------------------------------\n");
	int numri;
	printf("\nJepni numrin e artikullit qe doni te kerkoni:\n");
	scanf("%d",&numri);
	
	//Therrasim funksionin gjej_artikull
	int index=gjej_artikull(numri);
	if(index>=0)
	{
		printf("\nTe dhenat per artikullin e kerkuar jane:\n");
		printf("Numri i artikullit: %d\n",inventari[index].numri);
		printf("Emri i artikullit: %s\n",inventari[index].emri);
		printf("Gjendja e artikullit: %d\n",inventari[index].gjendja);
	}
	else
	{
		printf("Artikulli me numrin %d nuk ekziston.\n",numri);
	}
	return;
}

void update(void)
{
	printf("\n\nMODIFIKIMI I NJE ARTIKULLI");
	printf("\n------------------------------\n");
	int numri;
	printf("\nJepni numrin e artikullit qe doni te ndryshoni:\n");
	scanf("%d",&numri);
	
	int i=gjej_artikull(numri);
	if(i>=0)
	{
		int ndryshimi;
		printf("Jepni vleren e re te gjendjes se artikullit:\n");
		scanf("%d",&ndryshimi);
		
		inventari[i].gjendja=ndryshimi;
		printf("\nARTIKULLI U NDRYSHUA!");
	}
	else
	{
		printf("Ky numer artikulli nuk ekziston!\n");
		return;
	}	
}
void printo(void)
{
	printf("\n\nPRINTIMI I ARTIKUJVE");
	printf("\n------------------------------\n");
	int i;
	for(i=0;i<nr_artikull;i++)
	{
		printf("\n_____________________________\n");
		printf("Artikulli %d ka te dhenat:\n",i);
		printf("Nr. i artikullit: %d\n",inventari[i].numri);
		printf("Emri: %s\n",inventari[i].emri);
		printf("Gjendja: %d\n",inventari[i].gjendja);
		printf("_____________________________\n\n");
	}
}


void ruaj(void)
{
	//Shkrim ne file
	f=fopen(filename,"w");
	
	fprintf(f,"%d\n",nr_artikull);
	for(int i=0;i<nr_artikull;i++)
	{
		fprintf(f,"%d %s %d\n",inventari[i].numri,inventari[i].emri,inventari[i].gjendja);
	}
	fclose(f);	
}

void lexo(void)
{
	//Lexim ne file
	f=fopen(filename,"r");
	
	fscanf(f,"%d\n",&nr_artikull);
	for(int i=0;i<nr_artikull;i++)
	{
		fscanf(f,"%d %s %d\n",&inventari[i].numri,inventari[i].emri,&inventari[i].gjendja);
	}
		
}
