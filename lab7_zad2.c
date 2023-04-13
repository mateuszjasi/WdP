#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losuj(int a, int b) {
	if(a>b) {
		int temp=a;
		a=b;
		b=temp;
	}
	return rand()%(b-a+1)+a;
}

selection_sort(int *tab, int n) {
	int i, j, k, temp;
	for(i=0;i<n;i++) {
		k=i;
		for(j=i+1;j<n;j++)
			if(tab[j]<tab[k])
				k=j;
		temp=tab[k];
		tab[k]=tab[i];
		tab[i]=temp;
	}
}

main() {
	srand(time(0));
	int i, n, *tab, a, b;
	printf("Podaj ilosc elementow: ");
	scanf("%d",&n);
	tab=(int*)malloc(n*sizeof(int));
	printf("Podaj przedzial wartosci elementow: ");
	scanf("%d %d",&a,&b);
	for(i=0; i<n; i++)
		tab[i]=losuj(a,b);
	selection_sort(tab, n);
	printf("Posortowana tablica:\n");
	for(i=0; i<n; i++)
		printf("%d\t",tab[i]);
}
