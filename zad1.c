#include<stdio.h>

void nwd_nww(int a, int b, int *c, int *d) {
	int tempb=b;
	*c=a;
	while(b) {
		(*d)=b;
		b=(*c)%b;
		(*c)=(*d);
	}
	*d=(a*tempb)/(*c);
}

main() {
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	nwd_nww(a,b,&c,&d);
	printf("NWD: %d\nNWW: %d",c,d);
}
