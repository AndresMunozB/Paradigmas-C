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
	
	Ship** hola = (Ship**) malloc(sizeof(Ship*)*3);
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
	imprimirParams(params);
	
	return 0;
}
//yapo yapo yapooo 