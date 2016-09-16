#include <stdio.h>
#include <stdlib.h>
#include <direct.h>


int main(){
	char** arreglostring=malloc(sizeof(char*)*3);
	arreglostring[2]="hola";
	arreglostring[1]="chao";
	arreglostring[0]="como estas?";
	int i;
	for (i=0;i<3;i++){
			printf("%s\n",arreglostring[i] );


	}
	sleep(2);
	system("color fd");
	sleep(2);
	system("cls");
	sleep(2);
	system("color fd");
	return 0;
}