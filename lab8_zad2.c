#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bubble_sort(int *tab, int n) {
	int i, j, temp;
	for(i=n-1;i>=1;i--)
		for(j=0;j<=i-1;j++)
			if(tab[j]>tab[j+1]) {
				temp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=temp;
			}
}

int *wczytaj(char *nazwa_pliku1, int *tab, int *n) {
	FILE* plik=fopen(nazwa_pliku1,"r");
	if(!plik) {
		printf("Nie znaleziono pliku do wczytania!");
		exit(0);
	}
	int i;
	while(fscanf(plik,"%*d")!=EOF)
		*n=*n+1;
	rewind(plik);
	tab=(int*)malloc(*n*sizeof(int));
	for(i=0;i<*n;i++) {
		fscanf(plik,"%d",&tab[i]);
		printf("%d\t",tab[i]);
		if((i+1)%10==0)
			printf("\n");
	}
	fclose(plik);
	return tab;
}

zapisz(char *nazwa_pliku, int *tab, int n) {
	FILE* plik=fopen(nazwa_pliku,"w");
	if(!plik) {
		printf("Nie udalo sie utworzyc pliku!");
		exit(0);
	}
	int i;
	for(i=0;i<n;i++)
		fprintf(plik,"%d\n",tab[i]);
	fclose(plik);
}

main() {
	int *tab,i,n=0;
	char *nazwa_pliku1=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku2=(char*)calloc(50, sizeof(char*));
	printf("Podaj nazwe pliku do wczytania wartosci: ");
	gets(nazwa_pliku1);
	printf("Podaj nazwe pliku do zapisania wartosci: ");
	gets(nazwa_pliku2);
	tab=wczytaj(nazwa_pliku1, tab, &n);
	bubble_sort(tab,n);
	printf("\nPosortowane liczby:\n");
	for(i=0;i<n;i++) {
		printf("%d\t",tab[i]);
		if((i+1)%10==0)
			printf("\n");
	}
	zapisz(nazwa_pliku2, tab, n);
	free(nazwa_pliku1);
	free(nazwa_pliku2);
	free(tab);
	return 0;
}
