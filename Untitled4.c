#include<stdio.h>

int licz(int a, int b, int *s, int *i) {
	int x;
	while(1) {
		scanf("%d", &x);
		(*s)=(*s)+x;
		if(x<0)
			(*i)++;
		if((*s)>a)
			return 1;
		if((*i)>b)
			return 0;
	}
}

main() {
	int a, b, s=0, i=0;
	scanf("%d", &a);
	scanf("%d", &b);
	licz(a, b, &s, &i);
	printf("Suma = %d\n Ilosc = %d",s,i);
}
