#include<stdio.h>
#include<stdlib.h>

//struktura drzewa
typedef struct drzewo {
	int wartosc;
	struct drzewo *lewo;
	struct drzewo *prawo;
} drzewo;

//wyswietlanie gui
int gui() {
	system("cls");
	printf("Drzewo binarne\n"
	"----------------------------------------------\n"
	"[0] Wyjscie z programu\n"
	"[1] Dodaj wezel\n"
	"[2] Wypisz LVR\n"
	"----------------------------------------------\n\n"
	"Wybrana komenda: ");
}

//dodawanie korzenia
Dodaj(drzewo **korzen) {
	drzewo *nowy;
	nowy=(drzewo*)malloc(sizeof(drzewo));
	nowy->lewo=NULL;
	nowy->prawo=NULL;
	printf("Podaj liczbe do wstawienia: ");
	scanf("%d", &nowy->wartosc);
	//jezeli drzewo jest puste to nowy korzen ustaw jako korzen 'glowny' w przeciwnym wypadku przechodz po korzeniach:
	//-w lewo jezeli wartosc korzenia jest wieksza od nowej wartosci
	//-w prawo jezeli wartosc korzenia jest mniejsza od nowej wartosci
	//jezeli wartosc korzenia jest rowna nowej wartosci wyswietl komunikat o tym i wroc do funkcji main
	if(*korzen==NULL)
		*korzen=nowy;
	else {
		drzewo *temp=*korzen;
		while(temp) {
			if(nowy->wartosc>temp->wartosc)
				if(temp->prawo!=NULL)
					temp=temp->prawo;
				else {
					temp->prawo=nowy;
					break;
				}
			else if(nowy->wartosc<temp->wartosc)
				if(temp->lewo!=NULL)
					temp=temp->lewo;
				else {
					temp->lewo=nowy;
					break;
				}
			else if(nowy->wartosc==temp->wartosc) {
				printf("\nTaka wartosc jest juz w drzewie");
				break;
			}
		}
	}
	printf("\nKliknij aby kontynuowac.");
	getch();
}

//wyswietlanie left visit right - lewo odwiedzone prawo
LVR(drzewo *korzen) {
	//jesli drzewo puste wyswietl "drzewo jest puste" w przeciwnym wypadku rekurencyjnie wyswietl LVR
	if(korzen==NULL)
		printf("Drzewo jest puste!");
	else {
		if(korzen->lewo!=NULL)
			LVR(korzen->lewo);
		printf("%d ",korzen->wartosc);
		if(korzen->prawo!=NULL)
			LVR(korzen->prawo);
	}
}

main() {
	drzewo *korzen=NULL;
	int polecenie;
	do {
		gui();
		//wczytaj liczbe do polecenie
		scanf("%d", &polecenie);
		system("cls");
		//wybierz case (przypadek) w zaleznosci od liczby w zmiennej 'polecenie'
		switch(polecenie) {
			case 0:
				printf("Zakonczono dzialanie programu.");
				break;
			case 1:
				Dodaj(&korzen);
				break;
			case 2:
				printf("Kolejnosc przechodzenia: ");
				LVR(korzen);
				printf("\nKliknij aby kontynuowac.");
				getch();
				break;
		}
	} while(polecenie);
}
