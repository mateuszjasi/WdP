#include<stdio.h>
#include<time.h>

int losuj(int a, int b) {
	return rand()%(b-a+1)+a;
}

main() {
	int Tab[5],a,b,*tab,i, mini, maxi;
	tab=Tab;
	srand(time(0));
	scanf("%d%d",&a,&b);
	for(i=0;i<5;i++) {
		*(tab+i)=losuj(a,b);
		printf("%d\t", *(tab+i));
	}
	printf("\n");
	mini=b;
	maxi=a;
	for(i=0; i<5;i++) {
		if(*(tab+i)>maxi)
			maxi=*(tab+i);
		if(*(tab+i)<mini)
			mini=*(tab+i);
	}
	printf("Min = %d\nMax = %d",mini,maxi);
}
