#include<stdio.h>

main() {
	int i;
	char napis[40]="", *tab;
	tab=napis;
	gets(tab);
	for(i=39;i>=0;i--)
		if(*(napis+i)!=NULL)
			printf("%c", *(tab+i));
}
