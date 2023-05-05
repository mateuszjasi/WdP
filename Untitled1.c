#include<stdio.h>

main() {
	int *iw, i;
	float *fw, f;
	long int *liw, li;
	double *dw, d;
	char *cw, c;
	iw=&i;
	fw=&f;
	liw=&li;
	dw=&d;
	cw=&c;
	*iw=2;
	*fw=1.2;
	*liw=19999;
	*dw=2.03;
	*cw='c';
	printf("int: %d \t %d\n",i,*iw);
	printf("float: %f \t %f\n",f,*fw);
	printf("long int: %i \t %d\n",li,*liw);
	printf("double: %f \t %f\n",d,*dw);
	printf("char: %c \t %c",c,*cw);
}
