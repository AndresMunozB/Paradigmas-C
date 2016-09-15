#include <stdio.h>
#include <stdlib.h>


int main(){
	char** arreglostring=malloc(sizeof(char*)*3);
	arreglostring[2]="hola";
	arreglostring[1]="chao";
	arreglostring[0]="como estas?";
	int i;
	for (i=0;i<3;i++){
			printf("%s\n",arreglostring[i] );


	}

	return 0;
}