// Auta.cpp : Defines the entry point for the application.
//

#include "Auta.h"

#include <stdio.h>
#include <ctype.h>              // tolower
#include <stdlib.h>				// system

#include "AutaDB.h"

struct t_album* prvni = NULL; // globalni ukazatel na prvni auto

void OnAdd()
{
	char my_name[ALBUM_SIZE];
	char my_interpret[INTERPRET_SIZE];
	int my_year;

	printf("\nAlbum : ");         // dotazeme se na polozky
	scanf_s("%s", my_name, ALBUM_SIZE);
	while (getchar() != '\n');

	printf("\nInterpret : ");         // dotazeme se na polozky
	scanf_s("%s", my_interpret, INTERPRET_SIZE);
	while (getchar() != '\n');

	printf("\nRok : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	add(my_name, my_year, &prvni, my_interpret);         // volame pridavaci funkci
}

void OnDel()
{
	int my_year;

	printf("\nRok : ");
	scanf_s("%d", &my_year);
	while (getchar() != '\n');
	del(my_year, &prvni);         // volame mazaci funkci
}

void ShowAlbums()
{
	struct t_album* aktAlbum = prvni; // ukazatel na aktualni auto
	printf("\n\n");
	char pocPismeno;
	printf("Pocatecni jmeno interpreta: ");
	scanf_s("%c", &pocPismeno);
	tolower(pocPismeno);
	while (getchar() != '\n');

	while (aktAlbum) // prochazeni seznamu
	{
		if (aktAlbum->interpret[0] == pocPismeno) {
			printf("%d: %s %s\n", aktAlbum->rok, aktAlbum->nazev_alba, aktAlbum->interpret); // tisk radku
		}
		
		aktAlbum = aktAlbum->dalsi; // posun na dalsi auto
	}
	getchar();
}


int main()
{
	char  cmd;

	do
	{
		system("cls");		// smaze obrazovku
		printf("A: Pridat     ");
		printf("D: Smazat     ");
		printf("P: Tisk     ");
		printf("Q: Konec\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd)
		{
		case 'a':
			OnAdd();					// volame pridani
			break;
		case 'd':
			OnDel();					// volame mazani
			break;
		case 'p':
			ShowAlbums();
			break;
		}
	} while (cmd != 'q');     // koncime az pri Q
	return 0;
}

