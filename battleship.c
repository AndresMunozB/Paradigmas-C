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


	


	printf("id: %d \n",*id );
	Position position;
	cargarPosition(&position,1,2);
	Params params;
	cargarParams(&params,1,2,3,4,2,id);
	printf("inicio print params\n");
	int i;
	for (i=0;i<params.cantidad_ship;i++){
		imprimirShip(params.arreglo_ship_cpu[i]);
	}
	printf("fin print params\n");

	Ship* arreglo=(Ship*)crearArregloShip(5);
	cargarShip(&arreglo[1],'S',id);
	imprimirShip(arreglo[1]);
	cargarShip(&arreglo[2],'P',id);
	
	putPositionShip(&arreglo[2],1,4,1);
	imprimirShip(arreglo[2]);
	//memcpy(&arreglo[1].posiciones[1],&position,sizeof(Position));
	printf("hola!\n");
	putPositionShip(&arreglo[1],3,3,0);
	imprimirShip(arreglo[1]);
	printf("hola!11\n");
	printf("%d\n",compararPosition(position,arreglo[1].posiciones[0]) );
	printf("%d\n",sobreponeShip(arreglo[1],arreglo[2]) );
	//imprimirShip(arreglo[1]);
	//cargarShip

	
	return 0;
}



//https://github.com/micodigo/Principiante-N1/blob/master/Programas/batalla%20nabal.cpp
//yapo yapo yapooo 