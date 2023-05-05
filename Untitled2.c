#include<stdio.h>

int takie_same(int a,int b, int c, int *te_same) {
	if(a==b || a==c) {
		*te_same=a;
		return 1;
	}
	if(b==c) {
		*te_same=b;
		return 1;
	}
	return 0;
}

main() {
	int a, b, c, te_same;
	scanf("%d%d%d",&a,&b,&c);
	if(takie_same(a,b,c,&te_same)) {
		printf("Sa 2 takie same wartosci: %i",te_same);
	} else {
		printf("Nie ma 2 takich samych wartosci");
	}
}
