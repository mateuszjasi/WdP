#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//deklaracja struktury
typedef struct pola {
	int i;
	char ch;
} pola;

//funkcja losujaca liczbe z przedzialu <a,b>
int losuj_i(int a, int b) {
	if(a>b) {
		int temp=a;
		a=b;
		b=temp;
	}
	return rand()%(b-a+1)+a;
}

//funkcja losujaca znak z przedzialu <a,z>
int losuj_ch() {
	return rand()%26+'a';
}

//funkcja zapisu do pliku
zapisz(char *nazwa_pliku, pola *tab, int n) {
	//otworz plik w trybie zapisu binarnego
	FILE* plik=fopen(nazwa_pliku,"wb");
	int i;
	//jezeli plik nie zostal otwarty to wyswietl komunikat i zakoncz program
	if(!plik) {
		printf("Nie udalo sie utworzyc pliku!");
		exit(0);
	}
	//wpisz dane z tablicy do pliku
	for(i=0;i<n;i++)
		fwrite(tab+i, sizeof(tab), 1, plik);
	//zamknij plik
	fclose(plik);
}

main() {
	int i, n, a, b;
	pola *tab;
	char *nazwa_pliku=(char*)calloc(50, sizeof(char*));
	srand(time(0));
	printf("Podaj nazwe pliku: ");
	gets(nazwa_pliku);
	fflush(stdin);
	printf("Podaj ilosc elementow: ");
	scanf("%d",&n);
	tab=(pola*)malloc(n*sizeof(tab));
	printf("Podaj przedzial wartosci liczb: ");
	scanf("%d%d",&a,&b);
	for(i=0; i<n; i++) {
		tab[i].i=losuj_i(a,b);
		tab[i].ch=(char)losuj_ch();
	}
	zapisz(nazwa_pliku, tab, n);
	//zwalnianie pamieci
	free(nazwa_pliku);
	return 0;
}
