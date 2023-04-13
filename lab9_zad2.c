#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deklaracja struktury
typedef struct pola {
	int i;
	char ch;
} pola;

//funckja do sortowania babelkowego
bubble_sort(pola *tab, int n) {
	int i, j;
	pola *temp;
	//przejdz liste n-1 razy zamieniajac dwa sasiadujace elementy, jezeli element 1 jest wiekszy od elementu 2
	for(i=n-1;i>=1;i--)
		for(j=0;j<=i-1;j++)
			if(tab[j].i>tab[j+1].i) {
				*temp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=*temp;
			}
}

//funkcja wczytywania danych z pliku do tabeli
pola *wczytaj(char *nazwa_pliku1, pola *tab, int *n) {
	//otworz plik
	FILE* plik=fopen(nazwa_pliku1,"rb");
	pola *temp;
	//jezeli plik nie zostal otwarty to wyswietl komunikat i zakoncz program
	if(!plik) {
		printf("Nie znaleziono pliku do wczytania!");
		exit(0);
	}
	int i;
	//sprawdz ilosc elementow w pliku
	while(fread(&temp, sizeof(tab), 1, plik)!='\0')
		*n=*n+1;
	//wroc na poczatek pliku
	rewind(plik);
	tab=(pola*)malloc(*n*sizeof(tab));
	//wczytaj n elementow pliku do tabeli
	for(i=0;i<*n;i++)
		fread(tab+i, sizeof(tab), 1, plik);
	fclose(plik);
	//zwroc tablice z wczytanymi wartosciami
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
	int i,n=0;
	pola *tab;
	char *nazwa_pliku1=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku2=(char*)calloc(50, sizeof(char*));
	printf("Podaj nazwe pliku do wczytania wartosci: ");
	gets(nazwa_pliku1);
	printf("Podaj nazwe pliku do zapisania wartosci: ");
	gets(nazwa_pliku2);
	//przypisz tablicy tablice z wczytanymi wartosciami zwrocana z funkcji wczytaj()
	tab=wczytaj(nazwa_pliku1, tab, &n);
	bubble_sort(tab,n);
	printf("\nPosortowane liczby:\nint\tchar\n");
	for(i=0;i<n;i++)
		printf("%d\t%c\n",tab[i].i,tab[i].ch);
	zapisz(nazwa_pliku2, tab, n);
	//zwalnianie pamieci
	free(nazwa_pliku1);
	free(nazwa_pliku2);
	free(tab);
	return 0;
}
