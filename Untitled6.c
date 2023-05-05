#include<stdio.h>

ile_liczb(int n, int *ile) {
	while(n) {
		if(n%10!=0)
			(*ile)++;
		n=n/10;
	}
	if((*ile)>=2)
		return 1;
	else
		return 0;
}

main() {
	int n, ile=0;
	scanf("%i",&n);
	if(ile_liczb(n,&ile)) {
		printf("W liczbie jest co najmniej 2 cyfry rozne od 0");
	} else {
		printf("W liczbie nie ma nawet 2 cyfr roznych od 0");
	}
	
}
