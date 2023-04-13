#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deklaracja struktury
typedef struct pola {
	int i;
	char ch;
} pola;

//funckja pomocnicza do funkcji wczytaj() - wczytuje dane z pliku do tablicy i ja zwraca
pola *help(char *nazwa_pliku, pola *tab, int *n) {
	//otworz plik w trybie 'czytaj binarne'
	FILE* plik=fopen(nazwa_pliku,"rb");
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

//funckja pomocnicza do funkcji wczytaj() - wybiera najmniejszy element z 4
pola f1_4(int *x1, int n1, int *x2, int n2, int *x3, int n3, int *x4, int n4, pola *tab1, pola *tab2, pola *tab3, pola *tab4) {
	if(tab1[*x1].i<tab2[*x2].i && tab1[*x1].i<tab3[*x3].i && tab1[*x1].i<tab4[*x4].i) {
		*x1=*x1+1;
		return tab1[*x1-1];
	}
	else if(tab2[*x2].i<tab3[*x3].i && tab2[*x2].i<tab4[*x4].i) {
		*x2=*x2+1;
		return tab2[*x2-1];
	} else if(tab3[*x3].i<tab4[*x4].i) {
		*x3=*x3+1;
		return tab3[*x3-1];
	} else {
		*x4=*x4+1;
		return tab4[*x4-1];
	}
}

//funckja pomocnicza do funkcji wczytaj() - wybiera najmniejszy element z 3
pola f1_3(int *x2, int n2, int *x3, int n3, int *x4, int n4, pola *tab2, pola *tab3, pola *tab4) {
	if(tab2[*x2].i<tab3[*x3].i && tab2[*x2].i<tab4[*x4].i) {
		*x2=*x2+1;
		return tab2[*x2-1];
	} else if(tab3[*x3].i<tab4[*x4].i) {
		*x3=*x3+1;
		return tab3[*x3-1];
	} else {
		*x4=*x4+1;
		return tab4[*x4-1];
	}
}

//funckja pomocnicza do funkcji wczytaj() - wybiera najmniejszy element z 2
pola f1_2(int *x3, int n3, int *x4, int n4, pola *tab3, pola *tab4) {
	if(tab3[*x3].i<tab4[*x4].i) {
		*x3=*x3+1;
		return tab3[*x3-1];
	} else {
		*x4=*x4+1;
		return tab4[*x4-1];
	}
}

//funkcja wczytywania danych z plikow do tabeli
pola *wczytaj(char *nazwa_pliku1, char *nazwa_pliku2, char *nazwa_pliku3, char *nazwa_pliku4, pola *tab, int *n) {
	int i, n1=0, n2=0, n3=0, n4=0, x1, x2, x3, x4;
	pola *tab1, *tab2, *tab3, *tab4;
	//wczytaj pliki uzywajac funkcji help()
	tab1=help(nazwa_pliku1, tab1, &n1);
	tab2=help(nazwa_pliku2, tab2, &n2);
	tab3=help(nazwa_pliku3, tab3, &n3);
	tab4=help(nazwa_pliku4, tab4, &n4);
	*n=n1+n2+n3+n4;
	tab=(pola*)malloc(*n*sizeof(pola));
	for(i=0,x1=0,x2=0,x3=0,x4=0;x1<n1||x2<n2||x3<n3||x4<n4;i++) {
		//sprawdzamy czy zostaly jakies elementy do przepisania:
		//-jezeli zostaly elementy w czterech tablicach
		if(x1<n1 && x2<n2 && x3<n3 && x4<n4)
			tab[i]=f1_4(&x1,n1,&x2,n2,&x3,n3,&x4,n4,tab1,tab2,tab3,tab4);
		//-jezeli zostaly elementy w trzech tablicach
		else if(x1<n1 && x2<n2 && x3<n3)
			tab[i]=f1_3(&x1,n1, &x2,n2, &x3,n3, tab1,tab2,tab3);
		else if(x1<n1 && x2<n2 && x4<n4)
			tab[i]=f1_3(&x1,n1, &x2,n2, &x4,n4, tab1,tab2,tab4);
		else if(x1<n1 && x3<n3 && x4<n4)
			tab[i]=f1_3(&x1,n1, &x4,n4, &x3,n3, tab1,tab4,tab3);
		else if(x2<n2 && x3<n3 && x4<n4)
			tab[i]=f1_3(&x4,n4, &x2,n2, &x3,n3, tab4,tab2,tab3);
		//-jezeli zostaly elementy w dwoch tablicach
		else if(x1<n1 && x2<n2)
			tab[i]=f1_2(&x1,n1, &x2,n2, tab1,tab2);
		else if(x1<n1 && x3<n3)
			tab[i]=f1_2(&x1,n1, &x3,n3, tab1,tab3);
		else if(x1<n1 && x4<n4)
			tab[i]=f1_2(&x1,n1, &x4,n4, tab1,tab4);
		else if(x2<n2 && x3<n3)
			tab[i]=f1_2(&x2,n2, &x3,n3, tab2,tab3);
		else if(x2<n2 && x4<n4)
			tab[i]=f1_2(&x2,n2, &x4,n4, tab2,tab4);
		else if(x3<n3 && x4<n4)
			tab[i]=f1_2(&x3,n3, &x4,n4, tab3,tab4);
		//-jezeli zostaly elementy w jednej tablicy
		else if(x1<n1) {
			tab[i]=tab1[x1];
			x1++;
		} else if(x2<n2) {
			tab[i]=tab2[x2];
			x2++;
		} else if(x3<n3) {
			tab[i]=tab3[x3];
			x3++;
		} else if(x4<n4) {
			tab[i]=tab4[x4];
			x4++;
		} 
	}
	free(tab1);
	free(tab2);
	free(tab3);
	free(tab4);
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
	int n, i;
	pola *tab;
	char *nazwa_pliku1=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku2=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku3=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku4=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku5=(char*)calloc(50, sizeof(char*));
	printf("Podaj nazwe pliku1 do wczytania wartosci: ");
	gets(nazwa_pliku1);
	printf("Podaj nazwe pliku2 do wczytania wartosci: ");
	gets(nazwa_pliku2);
	printf("Podaj nazwe pliku3 do wczytania wartosci: ");
	gets(nazwa_pliku3);
	printf("Podaj nazwe pliku4 do wczytania wartosci: ");
	gets(nazwa_pliku4);
	printf("Podaj nazwe pliku do zapisania wartosci: ");
	gets(nazwa_pliku5);
	//przypisz tablicy tablice z wczytanymi wartosciami zwrocana z funkcji wczytaj()
	tab=wczytaj(nazwa_pliku1, nazwa_pliku2, nazwa_pliku3, nazwa_pliku4, tab, &n);
	printf("\nPosortowane liczby:\nint\tchar\n");
	for(i=0;i<n;i++)
		printf("%d\t%c\n",tab[i].i,tab[i].ch);
	zapisz(nazwa_pliku5, tab, n);
	//zwalnianie pamieci
	free(nazwa_pliku1);
	free(nazwa_pliku2);
	free(nazwa_pliku3);
	free(nazwa_pliku4);
	free(nazwa_pliku5);
	free(tab);
	return 0;
}