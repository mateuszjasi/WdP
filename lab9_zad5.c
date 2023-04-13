#include <stdio.h>
#include <dir.h>
#include <stdlib.h>
#include <string.h>

main() {
	int dir_size=100;
	char *dir;
	dir=(char*)malloc(dir_size*sizeof(dir));
	getcwd(dir, dir_size);
	printf("Sciezka biezacego katalogu: %s\n", dir);
	char kat[50]={};
	printf("Podaj nazwe dla nowego katalogu: ");
	gets(kat);
	strcat(dir,"\\");
	strcat(dir,kat);
	mkdir(kat);
	free(dir);
	return 0;
}
