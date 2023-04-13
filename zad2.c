#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void min_max(int Tab[],int n,int *a,int *b) {
	int i;
	for(i=0;i<n;i++) {
		Tab[i]=rand()%10;
		printf("%d\t",Tab[i]);
		if(i==0) {
			*a=Tab[i];
			*b=Tab[i];
		} else if(Tab[i]>*a)
			*a=Tab[i];
		else if(Tab[i]<*b)
			*b=Tab[i];
	}
}

main() {
	int a,b,n, *Tab;
	printf("Podaj wielkosc tablicy: ");
	scanf("%d",&n);
	Tab=(int*)malloc(n*sizeof(int));
	srand(time(0));
	min_max(Tab,n,&a,&b);
	printf("\nMax: %d\nMin: %d",a,b);
	free(Tab);
}
