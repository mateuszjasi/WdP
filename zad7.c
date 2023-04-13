#include<stdio.h>

typedef struct{
	char imie[40];
	char nazwisko[40];
	char pesel[10];
	char zainteresowania[256];
}osoba;

void pobierz_dane(osoba *a) {
	printf("Podaj imie: ");
	gets(a->imie);
	printf("Podaj nazwisko: ");
	gets(a->nazwisko);
	printf("Podaj pesel: ");
	gets(a->pesel);
	printf("Podaj zainteresowania: ");
	gets(a->zainteresowania);
}

main() {
	osoba a;
	pobierz_dane(&a);
	printf("Imie: %s\nNazwisko: %s\nPesel: %s\nZainteresowania: %s",a.imie,a.nazwisko,a.pesel,a.zainteresowania);
}
