#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "funciones.h"
#include <string.h>


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
	int* id=(int*)malloc(sizeof(int));
	*id=0;


	code* statusCode;


	printf("id: %d \n",*id );
	Params params;
	printf("hola antes params\n");
	cargarParams(&params,1,3,0,0,0,id);
	printf("inicio print params\n");
	/*int i;
	for (i=0;i<params.cantidad_ship;i++){
		imprimirShip(params.arreglo_ship_cpu[i]);
	}*/
	printf("fin print params\n");
	Board* board=(Board*)createBoard(20,20,params,statusCode);
	board->matriz[3][4]='L';
	board->matriz[3][5]='L';
	Board2*
	print(board,0,statusCode);
	//*****memcpy(&arreglo[1].posiciones[1],&position,sizeof(Position));
	printf("hola!11\n");
	printf("comparar posiciones: %d\n",compararPosition(params.arreglo_ship_cpu[0].posiciones[0],
														params.arreglo_ship_cpu[0].posiciones[0]	 ));
	printf("sbreposicion de ship: %d\n",sobreponeShip(params.arreglo_ship_cpu[0],params.arreglo_ship_cpu[0] ));
	
	
	return 0;
}



//https://github.com/micodigo/Principiante-N1/blob/master/Programas/batalla%20nabal.cpp
//yapo yapo yapooo 