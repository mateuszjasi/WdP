#include<stdio.h>

void iloczyn_kartezjanski(int T1[], int T2[], int T3[][2]) {
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			T3[i][j]=T1[i]*T2[j];
}

main() {
	int i,j;
	int T1[3], T2[2], T3[3][2];
	printf("Podaj 3 wartosci dla Tablicy1: ");
	for(i=0;i<3;i++)
		scanf("%d",&T1[i]);
	printf("Podaj 2 wartosci dla Tablicy2: ");
	for(i=0;i<2;i++)
		scanf("%d",&T2[i]);
	iloczyn_kartezjanski(T1,T2,T3);
	for(i=0;i<3;i++) {
		for(j=0;j<2;j++)
			printf("%d\t",T3[i][j]);
		printf("\n");
	} // mozna bylo wyswietlic w funkcji, ale chce pokazac ze funkcja przekazuje uzupelniona tablice
}
