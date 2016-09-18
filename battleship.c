#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones.h"

int main(){
	
	int menu=0;
	while (menu!=10){
		printf("\t\tMENU\n\n");
		printf("1) Crear tablero\n");
		printf("2) Grabar tablero\n");
		printf("3) Cargar tablero\n");
		printf("4) Verificar tablero\n");
		printf("5) Jugar\n");
		printf("6) Posicionar embarcaciones\n");
		printf("7) Visualizar tablero\n");
		scanf("%d",&menu);
	}
	code* statusCode;
	Params* params= (Params*)crearParams(1);
	Board* board= (Board*) createBoard(24,10,*params,statusCode);
	Position* position=(Position*) crearPosition(12,3);
	Ship* ship= (Ship*) crearShip('L');
	putShip(board,*position,*ship,statusCode);

	printf("0    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 101 102\n");
	printf("1    P - - - - - - - - -  -  -  -  -  -   P   - \n");
	printf("2                                               \n");
	printf("3                                               \n");
	printf("4                                               \n");
	printf("5                                               \n");
	printf("6                                               \n");
	printf("7                                               \n");
	printf("8                                               \n");
	printf("9                                               \n");
	printf("10  P                                           \n");
	printf("11                                              \n");
	printf("12                                              \n");
	printf("13                                              \n");
	printf("14                                              \n");
	printf("15                                              \n");
	printf("100 P                                           \n");


	//char** p=inicio();
	//imprimir(p);
	/*Ship** hola = (Ship**) malloc(sizeof(Ship*)*3);
	hola[0] = (Ship*)crearShip('P');
	imprimirShip(hola[0]);
	printf("\n");
	Position* position=(Position*)crearPosition(2,4);
	Ship* ship= (Ship*) crearShip('S');
	Info* info=(Info*)crearInfo(position,ship);
	imprimirInfo(info);
	ship->vida-=1;
	printf("\n");
	imprimirInfo(info);

	printf("\n");
	Params* params=(Params*) crearParams(5);
	imprimirParams(params);*/
	
	return 0;
}

//https://github.com/micodigo/Principiante-N1/blob/master/Programas/batalla%20nabal.cpp
//yapo yapo yapooo 