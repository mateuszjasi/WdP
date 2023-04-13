#include<stdio.h>
#include<string.h>

main() {
	char napis1[40]="", *tab1, napis2[40]="", *tab2;
	tab1=napis1;
	tab2=napis2;
	gets(tab1);
	gets(tab2);
	if(!strcmp(tab1, tab2))
		printf("napisy sa takie same");
	else
		printf("napisy nie sa takie same");
}
