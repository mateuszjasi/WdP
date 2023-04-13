#include <stdio.h>
#include <stdlib.h>

typedef struct ksiazka{
	char tytul[40];
	char autor[40];
	struct ksiazka *nastepna;
} ksiazka;

int gui() {
	system("cls");
	printf("Ewidencja ksiazek\n"
	"----------------------------------------------\n"
	"[0] Wyjscie z programu\n"
	"[1] Dodaj ksiazke\n"
	"[2] Usun ksiazke\n"
	"[3] Szukaj ksiazki po tytule\n"
	"[4] Wyswietl liste ksiazek\n"
	"----------------------------------------------\n\n"
	"Wybrana komenda: ");
}

dodaj(ksiazka **poczatek) {
	ksiazka *nowa;
	nowa=(ksiazka*)malloc(sizeof(ksiazka));
	nowa->nastepna=*poczatek;
	*poczatek=nowa;
	printf("Dodawanie ksiazki\n"
	"----------------------------------------------\n"
	"Podaj tytul: ");
	fflush(stdin);
	gets(nowa->tytul);
	printf("Podaj imie i nazwisko autora: ");
	gets(nowa->autor);
	fflush(stdin);
	printf("Pomysle dodano!\nKliknij aby kontynuowac.");
	getch();
}

int usun2(ksiazka *poczatek, char tytul[]) {
	ksiazka *pop=poczatek;
	while(poczatek) {
		if(!strcmp(poczatek->tytul,tytul)) {
			pop->nastepna=poczatek->nastepna;
			free(poczatek);
			return 1;
		} else {
			pop=poczatek;
			poczatek=poczatek->nastepna;
		}
	}
	return 0;
}

usun(ksiazka **poczatek) {
	if(*poczatek!=NULL) {
		int cos;
		char tytul[40];
		ksiazka *do_usuniecia;
		do_usuniecia=*poczatek;
		printf("Podaj tytul ksiazki do usuniecia: ");
		fflush(stdin);
		gets(tytul);
		fflush(stdin);
		if(!strcmp(do_usuniecia->tytul,tytul)) {
			*poczatek=do_usuniecia->nastepna;
			free(do_usuniecia);
			cos=1;
		} else
			cos=usun2(*poczatek,tytul);
		if(cos)
			printf("Pomysle usunieto!\n");
		else
			printf("Nie znaleziono ksiazki o danym tytule!\n");
	} else
		printf("Lista jest pusta, dodaj cos!\n");
	printf("\nKliknij aby kontynuowac.");
	getch();
}

szukaj(ksiazka *poczatek) {
	ksiazka *i;
	int cos=0, poz;
	char tytul[40];
	if(poczatek==NULL) {
		printf("Lista jest pusta, nie ma czego szukac.\n");
		cos=1;
	}
	else {
		printf("Podaj tytul ksiazki, ktorej szukasz: ");
		fflush(stdin);
		gets(tytul);
		fflush(stdin);
		for(i=poczatek, poz=1; i!=NULL; i=i->nastepna, poz++) {
			if(!strcmp(i->tytul,tytul)) {
				printf("Lp.%d\t", poz);
				printf("Tytul: %s\t", i->tytul);
				printf("Autor: %s\t", i->autor);
				cos=1;
				break;
			}
		}
	}
	if(!cos)
		printf("Nie znaleziono ksiazki o danym tytule.\n");
	printf("\nKliknij aby kontynuowac.");
	getch();
}

wyswietl(ksiazka *poczatek) {
	ksiazka *i;
	int poz=1;
	if(poczatek==NULL)
		printf("Lista jest pusta, dodaj cos!\n");
	else
		for(i=poczatek; i!=NULL; i=i->nastepna, poz++) {
			printf("Lp.%d\t", poz);
			printf("Tytul: %s\t", i->tytul);
			printf("Autor: %s\t", i->autor);
			printf("\n");
		}
	printf("\nKliknij aby kontynuowac.");
	getch();
}

main() {
	int polecenie;
	ksiazka *pierwsza = NULL;
	do {
		gui();
		scanf("%d", &polecenie);
		system("cls");
		switch(polecenie) {
			case 0:
				printf("Zakonczono dzialanie programu.");
				break;
			case 1:
				dodaj(&pierwsza);
				break;
			case 2:
				usun(&pierwsza);
				break;
			case 3:
				szukaj(pierwsza);
				break;
			case 4:
				wyswietl(pierwsza);
				break;
		}
	} while(polecenie);
	if(pierwsza==NULL)		//usuwanie elementow listy ktore zostaly po dzialaniu programu
		free(pierwsza);
	else
		while(1) {
			if(pierwsza->nastepna==NULL) {
				free(pierwsza);
				break;
			} else {
				ksiazka *pop=pierwsza;
				pierwsza=pierwsza->nastepna;
				free(pop);
			}
		}
}
