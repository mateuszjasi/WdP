#include<stdio.h>
#include<stdlib.h>

void to_upper(char a[]) {
	int stala='a'-'A',i;
	for(i=0;i<40;i++) {
		if(a[i]==(char)0)
			break;
		if(a[i]>='a' && a[i]<='z')
			a[i]=a[i]-stala;
	}
}

void Szyfr_Cezar(int n, char a[], char b[]) {
	int i;
	for(i=0;i<40;i++) {
		if(a[i]!=(char)0)
			if(a[i]!=' ')
				if(a[i]+n>'Z')
					b[i]='A'+(n-('Z'-a[i])-1);
				else
					b[i]=a[i]+n;
			else
				b[i]=' ';
		 else
			break;
	}
}

void DeSzyfr_Cezar(int n, char *a, char *b) {
	int i;
	for(i=0;i<40;i++) {
		if(a[i]!=(char)0)
			if(a[i]!=' ')
				if(a[i]-n<'A')
					b[i]='Z'-(n-(a[i]-'A')-1);
				else
					b[i]=a[i]-n;
			else
				b[i]=' ';
		else 
			break;
	}
}

main() {
	char a[40]="", b[40]="";
	int n, x;
	printf("Co chcesz zrobic:\n1 - zaszyfrowac\n2 - rozszyfrowac\nInna wartosc - nic nie chce\n");
	scanf("%d",&x);
	if(x==1 || x==2) {
		printf("Podaj zdanie: ");
		fflush(stdin);
		gets(a); //fflush - wyczyszczenie "wejscia" przy zmiane sposobu wprowadzania danych (np. z scanf() na gets()), aby uniknac mozliwej duplikacji wprowadzanych danych
		fflush(stdin);
		to_upper(a);
		printf("Podaj liczbe 'szyfru Cezara': ");
		scanf("%d",&n);
		if(x==1) {
			Szyfr_Cezar(n,a,b);
			printf("Zaszyfrowane: %s",b);
		} else if(x==2) {
			DeSzyfr_Cezar(n,a,b);
			printf("Rozszyfrowane: %s",b);
		}
	}
}
