#include<stdio.h>
#include<string.h>

void to_upper(char a[]) {
	int stala='a'-'A',i;
	for(i=0;i<40;i++) {
		if(a[i]==(char)0)
			break;
		if(a[i]>='a' && a[i]<='z')
			a[i]=a[i]-stala;
	}
}

main() {
	char a[40]="";
	printf("Zmiana malych liter na duze\nPodaj zdanie: ");
	gets(a);
	printf("Wynik: ");
	to_upper(a);
	printf("%s",a);
}
