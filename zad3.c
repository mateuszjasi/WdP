#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void wypelnij(int Tab[],int n,int a,int b) {
	int i;
	if(a>b) { //zabezpieczenie przed podaniem zlego przedzialu
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
	for(i=0;i<n;i++) {
		Tab[i]=rand()%(b-a+1)+a;
		printf("%d\t",Tab[i]);
	}
}

main() {
	int a,b,n, *Tab;
	printf("Podaj wielkosc tablicy: ");
	scanf("%d",&n);
	printf("Podaj przedzial wartosci (np. 69 420): ");
	scanf("%d%d",&a,&b);
	Tab=(int*)malloc(n*sizeof(int));
	srand(time(0));
	wypelnij(Tab,n,a,b);
	free(Tab);
}
