#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *help(char *nazwa_pliku, int *tab, int *n) {
	FILE* plik=fopen(nazwa_pliku,"r");
	if(!plik) {
		printf("Nie znaleziono pliku do wczytania!");
		exit(0);
	}
	int i;
	while(fscanf(plik,"%*d")!=EOF)
		*n=*n+1;
	rewind(plik);
	tab=(int*)malloc(*n*sizeof(int));
	for(i=0;i<*n;i++)
		fscanf(plik,"%d",&tab[i]);
	fclose(plik);
	return tab;
}

int f1_4(int *x1, int n1, int *x2, int n2, int *x3, int n3, int *x4, int n4, int *tab1, int *tab2, int *tab3, int *tab4) {
	if(tab1[*x1]<tab2[*x2] && tab1[*x1]<tab3[*x3] && tab1[*x1]<tab4[*x4]) {
		*x1=*x1+1;
		return tab1[*x1-1];
	}
	else if(tab2[*x2]<tab3[*x3] && tab2[*x2]<tab4[*x4]) {
		*x2=*x2+1;
		return tab2[*x2-1];
	} else if(tab3[*x3]<tab4[*x4]) {
		*x3=*x3+1;
		return tab3[*x3-1];
	} else {
		*x4=*x4+1;
		return tab4[*x4-1];
	}
}

int f1_3(int *x2, int n2, int *x3, int n3, int *x4, int n4, int *tab2, int *tab3, int *tab4) {
	if(tab2[*x2]<tab3[*x3] && tab2[*x2]<tab4[*x4]) {
		*x2=*x2+1;
		return tab2[*x2-1];
	} else if(tab3[*x3]<tab4[*x4]) {
		*x3=*x3+1;
		return tab3[*x3-1];
	} else {
		*x4=*x4+1;
		return tab4[*x4-1];
	}
}

int f1_2(int *x3, int n3, int *x4, int n4, int *tab3, int *tab4) {
	if(tab3[*x3]<tab4[*x4]) {
		*x3=*x3+1;
		return tab3[*x3-1];
	} else {
		*x4=*x4+1;
		return tab4[*x4-1];
	}
}

int *wczytaj(char *nazwa_pliku1, char *nazwa_pliku2, char *nazwa_pliku3, char *nazwa_pliku4, int *tab, int *n) {
	int i, n1=0, n2=0, n3=0, n4=0, *tab1, *tab2, *tab3, *tab4, x1, x2, x3, x4;
	tab1=help(nazwa_pliku1, tab1, &n1);
	tab2=help(nazwa_pliku2, tab2, &n2);
	tab3=help(nazwa_pliku3, tab3, &n3);
	tab4=help(nazwa_pliku4, tab4, &n4);
	*n=n1+n2+n3+n4;
	tab=(int*)malloc(*n*sizeof(int));
	for(i=0,x1=0,x2=0,x3=0,x4=0;x1<n1||x2<n2||x3<n3||x4<n4;i++) {
		if(x1<n1 && x2<n2 && x3<n3 && x4<n4)
			tab[i]=f1_4(&x1,n1,&x2,n2,&x3,n3,&x4,n4,tab1,tab2,tab3,tab4);
		else if(x1<n1 && x2<n2 && x3<n3)
			tab[i]=f1_3(&x1,n1, &x2,n2, &x3,n3, tab1,tab2,tab3);
		else if(x1<n1 && x2<n2 && x4<n4)
			tab[i]=f1_3(&x1,n1, &x2,n2, &x4,n4, tab1,tab2,tab4);
		else if(x1<n1 && x3<n3 && x4<n4)
			tab[i]=f1_3(&x1,n1, &x4,n4, &x3,n3, tab1,tab4,tab3);
		else if(x2<n2 && x3<n3 && x4<n4)
			tab[i]=f1_3(&x4,n4, &x2,n2, &x3,n3, tab4,tab2,tab3);
		else if(x1<n1 && x2<n2)
			tab[i]=f1_2(&x1,n1, &x2,n2, tab1,tab2);
		else if(x1<n1 && x3<n3)
			tab[i]=f1_2(&x1,n1, &x3,n3, tab1,tab3);
		else if(x1<n1 && x4<n4)
			tab[i]=f1_2(&x1,n1, &x4,n4, tab1,tab4);
		else if(x2<n2 && x3<n3)
			tab[i]=f1_2(&x2,n2, &x3,n3, tab2,tab3);
		else if(x2<n2 && x4<n4)
			tab[i]=f1_2(&x2,n2, &x4,n4, tab2,tab4);
		else if(x3<n3 && x4<n4)
			tab[i]=f1_2(&x3,n3, &x4,n4, tab3,tab4);
		else if(x1<n1) {
			tab[i]=tab1[x1];
			x1++;
		} else if(x2<n2) {
			tab[i]=tab2[x2];
			x2++;
		} else if(x3<n3) {
			tab[i]=tab3[x3];
			x3++;
		} else if(x4<n4) {
			tab[i]=tab4[x4];
			x4++;
		} 
	}
	free(tab1);
	free(tab2);
	free(tab3);
	free(tab4);
	return tab;
}

zapisz(char *nazwa_pliku, int *tab, int n) {
	FILE* plik=fopen(nazwa_pliku,"w");
	int i;
	for(i=0;i<n;i++)
		fprintf(plik,"%d\n",tab[i]);
	fclose(plik);
}

main() {
	int *tab, n, i;
	char *nazwa_pliku1=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku2=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku3=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku4=(char*)calloc(50, sizeof(char*));
	char *nazwa_pliku5=(char*)calloc(50, sizeof(char*));
	printf("Podaj nazwe pliku1 do wczytania wartosci: ");
	gets(nazwa_pliku1);
	printf("Podaj nazwe pliku2 do wczytania wartosci: ");
	gets(nazwa_pliku2);
	printf("Podaj nazwe pliku3 do wczytania wartosci: ");
	gets(nazwa_pliku3);
	printf("Podaj nazwe pliku4 do wczytania wartosci: ");
	gets(nazwa_pliku4);
	printf("Podaj nazwe pliku do zapisania wartosci: ");
	gets(nazwa_pliku5);
	tab=wczytaj(nazwa_pliku1, nazwa_pliku2, nazwa_pliku3, nazwa_pliku4, tab, &n);
	printf("\nPosortowane liczby:\n");
	for(i=0;i<n;i++) {
		printf("%d\t",tab[i]);
		if((i+1)%10==0)
			printf("\n");
	}
	zapisz(nazwa_pliku5, tab, n);
	free(nazwa_pliku1);
	free(nazwa_pliku2);
	free(nazwa_pliku3);
	free(nazwa_pliku4);
	free(nazwa_pliku5);
	free(tab);
	return 0;
}
