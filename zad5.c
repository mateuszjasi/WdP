#include<stdio.h>
#include<string.h>

main() {
	int i;
	char napis1[40]="", *tab1, napis2[40]="", *tab2;
	tab1=napis1;
	tab2=napis2;
	gets(tab1);
	for(i=0;i<40;i++)
		if(*(tab1+i)!=NULL)
			*(tab2+i)=*(tab1+i);
	printf("slowo1: %s\nslowo2: %s",tab1,tab2);
}
