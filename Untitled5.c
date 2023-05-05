#include<stdio.h>

int czy_lustrzana(int n, int *l) {
	int i=1, temp=n;
	while(n) {
		(*l)=(*l)*10;
		(*l)=(*l)+n%10;
		i=i*10;
		n=n/10;
	}
	if(temp==(*l))
		return 1;
	else
		return 0;
}

main() {
	int n, l=0;
	scanf("%d",&n);
	if(czy_lustrzana(n, &l)) {
		printf("Liczba %d jest lustrzana", n);
	} else {
		printf("Liczba %d nie jest lustrzana, a jej lustrzane odbicie to %d", n, l);
	}
}
