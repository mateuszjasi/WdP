#include<stdio.h>

typedef struct{
	char imie[40];
	char nazwisko[40];
	char pesel[10];
	char zainteresowania[256];
}osoba;

main() {
	osoba czlowiek, *wsk;
	wsk=&czlowiek;
	printf("Podaj imie: ");
	gets(wsk->imie);
	printf("Podaj nazwisko: ");
	gets(wsk->nazwisko);
	printf("Podaj pesel: ");
	gets(wsk->pesel);
	printf("Podaj zainteresowania: ");
	gets(wsk->zainteresowania);
	printf("Imie: %s\nNazwisko: %s\nPesel: %s\nZainteresowania: %s",wsk->imie,wsk->nazwisko,wsk->pesel,wsk->zainteresowania);
}
