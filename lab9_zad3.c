#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deklaracja struktury
typedef struct pola {
	int i;
	char ch;
} pola;

//funkcja wczytywania danych z pliku do tabeli
pola *wczytaj(char *nazwa_pliku1, char *nazwa_pliku2, pola *tab, int *n) {
	//wczytaj pliki
	FILE* plik1=fopen(nazwa_pliku1,"rb");
	FILE* plik2=fopen(nazwa_pliku2,"rb");
	//jezeli plik1 lub plik2 nie zostal otwarty to zakoncz program
	if(!plik1 || !plik2) {
		printf("Nie znaleziono pliku do wczytania!");
		exit(0);
	}
	int i, n1=0, n2=0, x1, x2;
	pola *tab1, *tab2, *temp;
	//sprawdz ilosc elementow w plikach
	while(fread(&temp, sizeof(tab), 1, plik1)!='\0')
		n1++;
	while(fread(&temp, sizeof(tab), 1, plik2)!='\0')
		n2++;
	//wroc na poczatek plikow
	rewind(plik1);
	rewind(plik2);
	*n=n1+n2;
	tab=(pola*)malloc(*n*sizeof(tab));
	tab1=(pola*)malloc(n1*sizeof(tab));
	tab2=(pola*)malloc(n2*sizeof(tab));
	//wczytaj elementy do tablic
	for(i=0;i<n1;i++)
		fread(tab1+i, sizeof(tab), 1, plik1);
	for(i=0;i<n2;i++)
		fread(tab2+i, sizeof(tab), 1, plik2);
	//petla do laczenia dwoch tabeli w jedna
	for(i=0,x1=0,x2=0;x1<n1||x2<n2;i++) {
		//sprawdzamy czy zostaly jakies elementy do przepisania:
		//-jezeli zostaly elementy w obu tablicach
		if(x1<n1 && x2<n2) {
			////jezeli element z tablicy1 o indeksie 'x1' jest mniejszy od elementu tablicy2 o indeksie 'x2'
			//to wczytaj element tablicy1 do tablicy glownej
			if(tab1[x1].i<tab2[x2].i) {
				tab[i]=tab1[x1];
				x1++;
			}
			else {
				tab[i]=tab2[x2];
				x2++;
			}
		}
		//jezeli zostaly elementy w tablicy1, to przepisz je do tablicy glownej
		else if(x1<n1) {
			tab[i]=tab1[x1];
			x1++;
		}
		//jezeli zostaly elementy w tablicy2, to przepisz je do tablicy glownej
		else if(x2<n2) {
			tab[i]=tab2[x2];
			x2++;
		}
	}
	//zamknij pliki
	fclose(plik1);
	fclose(plik2);
	//zwolnij pamiec
	free(tab1);
	free(tab2);
	return tab;
}

//funkcja zapisu do pliku
zapisz(char *nazwa_pliku, pola *tab, int n) {
	//otworz plik w trybie zapisu binarnego
	FILE* plik=fopen(nazwa_pliku,"wb");
	//jezeli plik nie zostal otwarty to wyswietl komunikat i zakoncz program
	if(!plik) {
		printf("Nie udalo sie utworzyc pliku!");
		exit(0);
	}
	int i;
	for(i=0;i<n;i++)
	//wpisz dane z tablicy do pliku
		fwrite(tab+i, sizeof(tab), 1, plik);
	//zamknij plik
	fclose(plik);
}

main() {
	int n, i;
	pola *tab;
	char *nazwa_pliku1=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku2=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku3=(char*)calloc(50, sizeof(char*));
	printf("Podaj nazwe pliku1 do wczytania wartosci: ");
	gets(nazwa_pliku1);
	printf("Podaj nazwe pliku2 do wczytania wartosci: ");
	gets(nazwa_pliku2);
	printf("Podaj nazwe pliku do zapisania wartosci: ");
	gets(nazwa_pliku3);
	tab=wczytaj(nazwa_pliku1, nazwa_pliku2, tab, &n);
	printf("\nPosortowane liczby:\nint\tchar\n");
	for(i=0;i<n;i++)
		printf("%d\t%c\n",tab[i].i,tab[i].ch);
	zapisz(nazwa_pliku3, tab, n);
	//zwalnianie pamieci
	free(nazwa_pliku1);
	free(nazwa_pliku2);
	free(nazwa_pliku3);
	free(tab);
	return 0;
}
