#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "constantes.h"
#include "funciones.h"
#include <time.h>


int intrandom(int desde,int hasta){
	int random;
	hasta+=1;
	while (!(random>=desde && random<=hasta)){
		random = rand()% hasta;
	}	
	return random;
}

//utilidades:
void cargarPosition(Position* position,int fila,int columna){
	position->fila=fila;
	position->columna=columna;
}
void imprimirPosition(Position position){
	printf("(%d,%d) ",position.fila,position.columna );

}
int compararPosition(Position position1,Position position2){
	if(position1.fila==position2.fila && position1.columna==position2.columna){
		return 1;
	}
	else{
		return 0;
	}

}
void inicialiarArregloPosiciones(Position* posiciones){
	int i;
	for (i=0;i<5;i++){
		posiciones[i].fila=-1;
		posiciones[i].columna=-1;
	}
}
void putPositionShip(Ship* ship,int fila, int columna, int orientacion){
	int i;
	for (i=0;i<ship->tamano;i++){
		if (orientacion==0){ //si es que es horizaontal 
			cargarPosition(&ship->posiciones[i],fila,columna+i);
		}
		else{
			cargarPosition(&ship->posiciones[i],fila+i,columna);
		}
	}
}
int sobreponeShip(Ship ship1, Ship ship2){
	int i,j;
	for (i=0;i<ship1.tamano;i++){
		printf("sobrepone for i\n");
		printf("%d \n",ship2.tamano );
		for(j=0;j<ship2.tamano;j++){
			printf("sobrepone for j\n");
			if(compararPosition(ship1.posiciones[i],ship2.posiciones[j])){
				return 1;
			}
		}
	}
	return 0;
}
void cargarShip(Ship* ship,char tipo,int* id){
	ship->id=*id;
	ship->tipo=tipo;
	inicialiarArregloPosiciones(ship->posiciones);

	if(tipo=='L'){
		ship->vida=1;
		ship->orientacion=0;
		ship->habilidad=0;
		ship->tamano=1;
	}
	else if(tipo=='S'){
		ship->vida=2;
		ship->orientacion=0;
		ship->habilidad=0;
		ship->tamano=2;
	}
	else if(tipo=='C'){
		ship->vida=3;
		ship->orientacion=0;
		ship->habilidad=2;
		ship->tamano=3;
	}
	else if(tipo=='D'){
		ship->vida=4;
		ship->orientacion=0;
		ship->habilidad=2;
		ship->tamano=4;
	}
	else if(tipo=='P'){
		ship->vida=5;
		ship->orientacion=0;
		ship->habilidad=2;
		ship->tamano=5;
	}
	
	*id+=1;
	
}

void imprimirShip(Ship ship){
	printf("Id: %d\n",ship.id );
	printf("tipo: %c\n", ship.tipo); 
	printf("vida: %d\n", ship.vida); 
	printf("orientacion: %d\n", ship.orientacion);
	printf("habildiad: %d. \n", ship.habilidad);
	printf("Posiciones:");
	int i;
	for (i=0;i<5;i++){
		imprimirPosition(ship.posiciones[i]);
	}
	printf("\n");
}

Ship* crearArregloShip(int cantidad_ship){
	Ship* arreglo=(Ship*)malloc(sizeof(Ship)*(cantidad_ship));
	int i,posicion;
	return arreglo;
}

//mias!!:
void  cargarParams(Params* params,int lancha, int submarino,int crucero,int destructor,int portaviones){
	
	params->cuadros_minimos = (lancha*2)+(submarino*4)+(crucero*9)+(destructor*16)+(portaviones*25);
	params->cuadros_ship=(lancha*1)+(submarino*2)+(crucero*3)+(destructor*4)+(portaviones*5);
	params->cantidad_ship=lancha+submarino+crucero+destructor+portaviones;



	
}

void imprimirParams(Params params){

	printf("cuadros_minimos: %d\n",params.cuadros_minimos );
	printf("cuadros_ship: %d\n",params.cuadros_ship );
	printf("cantidad_ship: %d \n",params.cantidad_ship);
}






Board* inicializarBoard(int n,int m, Params params,code *statusCode){
	if ((n%2)!=0){ //verificando que el numero de filas es un numero par:
		//printf("n no es par\n");		
		return NULL;
	}
	//printf("cuadros_minimos dentro de inicializar: %d \n",params.cuadros_minimos);
	//printf("n y m: %d %d \n",n,m );
	//imprimirParams(&params);
	if (params.cuadros_minimos>(n*m)){ //verificando si se pueden poner todos los barcos
		//printf("dimensiones invalidas\n");
		return NULL;
	}
	//printf("entreeee\n");

	Board* board=(Board*) malloc(sizeof(Board)); //verificando si hay memoria para el board
	if (board==NULL){
		return NULL;
	}

	else{
		board->fila=n;
		board->columna=m;
		board->params=params;



		printf("termino inicializar board\n");
		return board;

		//board->
		
	}
}
void liberarBoard(Board* board){

	free(board);
	printf("liberarBoar: OK\n");
}


//fin de mis funciones..

Board* createBoard(int n,int m, Params params,code *statusCode){
	Board* board= inicializarBoard(n,m,params,statusCode);


	return board;

	
} 


void saveBoar(Board* board, int *id, code*statusCode);
Board* loadBoard(int id, code*statusCode);
int checkBoard(Board* board, code* statusCode);

int play(Board* board,Ship* ship, Position* pArray, code* statusCode){
	printf("funciones play para el board\n");
}

void putShip(Board* board,Position position,Ship ship,code* statusCode){
	printf("funciones putship para el board\n");

}
void print(Board* board,int showComplete,code* statusCode){
	printf("funciones print para el board\n");
}
