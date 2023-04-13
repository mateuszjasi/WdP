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
	bubble_sort(tab, n);
	printf("Posortowana tablica:\n");
	for(i=0; i<n; i++)
		printf("%d\t",tab[i]);
}
