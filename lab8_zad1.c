#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int losuj(int a, int b) {
	if(a>b) {
		int temp=a;
		a=b;
		b=temp;
	}
	return rand()%(b-a+1)+a;
}

zapisz(char *nazwa_pliku, int *tab, int n) {
	FILE* plik=fopen(nazwa_pliku,"w");
	int i;
	if(!plik) {
		printf("Nie udalo sie utworzyc pliku!");
		exit(0);
	}
	for(i=0;i<n;i++)
		fprintf(plik,"%d\n",tab[i]);
	fclose(plik);
}

main() {
	int i, n, a, b, *tab;
	char *nazwa_pliku=(char*)calloc(50, sizeof(char*));
	srand(time(0));
	printf("Podaj nazwe pliku: ");
	gets(nazwa_pliku);
	fflush(stdin);
	printf("Podaj ilosc elementow: ");
	scanf("%d",&n);
	tab=(int*)malloc(n*sizeof(int));
	printf("Podaj przedzial wartosci liczb: ");
	scanf("%d%d",&a,&b);
	for(i=0; i<n; i++)
		tab[i]=losuj(a,b);
	zapisz(nazwa_pliku, tab, n);
	free(nazwa_pliku);
	return 0;
}
