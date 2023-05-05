#include<stdio.h>

int podzielnosc(int *a, int *b, int *k) {
	return ((*b)-(*a)+1)/(*k);
}

main() {
	int a,b,k;
	scanf("%d%d%d",&a,&b,&k);
	printf("%d",podzielnosc(&a,&b,&k));
}
