#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "constantes.h"
#include "funciones.h"
#include <time.h>


//utilidades:
int intrandom(int desde,int hasta){
	int random;
	hasta+=1;
	while (!(random>=desde && random<=hasta)){
		random = rand()% hasta;
	}	
	return random;
}
//mias!!:
void  cargarParams(Params* params,int lancha, int submarino,int crucero,int destructor,int portaviones){
	
	params->cuadros_minimos = (lancha*2)+(submarino*4)+(crucero*9)+(destructor*16)+(portaviones*25);
	params->cuadros_ship=(lancha*1)+(submarino*2)+(crucero*3)+(destructor*4)+(portaviones*5);
	params->cantidad_ship=lancha+submarino+crucero+destructor+portaviones;
	params->lancha=lancha;
	params->submarino=submarino;
	params->crucero=crucero;
	params->destructor=destructor;
	params->portaviones=portaviones;
	
}
Params* crearParams(int dificultad){
	Params* params= malloc(sizeof(Params));
	if (params==NULL){
		return NULL;
	}
	if (dificultad== 1){
		cargarParams(params,1,1,0,0,0);
	}
	else if (dificultad== 2){
		cargarParams(params,1,1,1,0,0);
	}
	else if (dificultad== 3){
		cargarParams(params,1,1,1,1,1);
	}
	else if (dificultad== 4){
		cargarParams(params,4,2,1,1,1);
	}
	else if (dificultad== 5){
		cargarParams(params,4,3,2,2,1);
	}
	else{
		return NULL;
	}
	return params;

}
void imprimirParams(Params* params){
	printf("lancha: %d \n",params->lancha );
	printf("submarino: %d \n",params->submarino );
	printf("crucero: %d \n",params->crucero );
	printf("destructor: %d \n",params->destructor );
	printf("portaviones: %d \n",params->portaviones );
	printf("cuadros_minimos: %d\n",params->cuadros_minimos );
	printf("cuadros_ship: %d\n",params->cuadros_ship );
	printf("cantidad_ship: %d \n",params->cantidad_ship);
}
void liberarParams(Params* params){
	free(params);
	printf("liberarParams: OK\n");
}

Position* crearPosition(int fila,int columna){
	Position* position=(Position*)malloc(sizeof(Position));
	position->fila=fila;
	position->columna=columna;
	return position;
}
void imprimirPosition(Position* position){
	printf("Fila: %d\n",position->fila );
	printf("Columna: %d\n",position->columna );
}
void liberarPosition(Position* position){
	free(position);
	printf("liberarPosition: OK\n");
}

void cargarShip(Ship* ship,char tipo,int vida, int orientacion, int habilidad){
	ship->tipo=tipo;
	ship->vida=vida;
	ship->orientacion=orientacion;
	ship->habilidad=habilidad;
	
}
Ship* crearShip(char tipo){
	Ship* ship = (Ship*) malloc(sizeof(Ship));
	
	if (tipo=='L'){
		cargarShip(ship,tipo,1,0,3);
	}
	else if (tipo=='S'){
		cargarShip(ship,tipo,2,0,2);
	}
	else if (tipo=='C'){
		cargarShip(ship,tipo,3,0,2);
	}
	else if (tipo=='D'){
		cargarShip(ship,tipo,4,0,2);
	}
	else if (tipo=='P'){
		cargarShip(ship,tipo,5,0,2);
	}
	else{
		free(ship);
		return NULL;
	}
	return ship;
}
void imprimirShip(Ship* ship){
	printf("tipo: %c\n", ship->tipo); 
	printf("vida: %d\n", ship->vida); 
	printf("orientacion: %d\n", ship->orientacion);
	printf("habildiad: %d. \n", ship->habilidad);
}
void liberarShip(Ship* ship){
	free(ship);
	printf("liberarShip: OK\n");
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
		board->largo_info_cpu=0;
		board->largo_info_player=0;
		board->arreglo_info_cpu=(Info**)malloc(sizeof(Info*)*params.cuadros_ship);
		if ((board->arreglo_info_cpu)==NULL){
			return NULL;
		}
		board->arreglo_info_player=(Info**)malloc(sizeof(Info*)*(params.cuadros_ship+1));
		if ((board->arreglo_info_player)==NULL){
			return NULL;
		}
		return board;

		//board->
		
	}
}
void liberarBoard(Board* board){
	/*free(board->arreglo_ship_player_1);
	free(board->arreglo_ship_player_2);
	free(board);
	printf("liberarBoar: OK\n");*/
}


Info* crearInfo(Position* position,Ship* ship){
	Info* info = (Info*)malloc(sizeof(Info));
	info->position=position;
	info->ship=ship;
	return info;
}
void imprimirInfo(Info* info){
	printf("Posicion: \n");
	imprimirPosition(info->position);
	printf("\n");
	printf("Ship: \n");
	imprimirShip(info->ship);
}


//fin de mis funciones..
Board* createBoard(int n,int m, Params params,code *statusCode){
	Board* board= inicializarBoard(n,m,params,statusCode);


	return board;



	
	 // mamorcito te quiero mucho :D 
	
} 


void saveBoar(Board* board, int *id, code*statusCode);
Board* loadBoard(int id, code*statusCode);
int checkBoard(Board* board, code* statusCode);
/*
int play(Board* board,Ship* ship, Position* pArray, code* statusCode){
 	printf("%d\n",ship->vida ); 
	ship->vida-=1;
	printf("%d\n",ship->vida ); 
	return 0;
}*/

void putShip(Board* board,Position position,Ship ship,code* statusCode){
	if ((position.fila)<=(board->fila/2)){
		printf("estoy arriiivaaa\n");
	}
	else {
		printf("holaa123123\n");
	}

} //ver lo de la posision y de el ship
void print(Board* board,int showComplete,code* statusCode);
	char**


void imprimir(char **p){
	int i,j;
	int x,y;
	x=10;
	y=20;
	for(i=0;i<y;i++)p[0][i]='0'+i;
	for(i=0;i<x;i++)p[i][0]='0'+i;
	p[1][3]='P';
	for(i=0;i<x;i++){
		printf("\n\t\t\t\t");
		for(j=0;j<y;j++)
			printf(" %c",p[i][j]);
	}
}

char** inicio(){
	char **p=NULL;
	int i,j;
	int x,y;
	x=10;
	y=20;
	p=(char**)malloc(x*sizeof(char*));
	for(i=0;i<=x;i++)
		p[i]=(char*)malloc(y*sizeof(char));
		
	for(i=0;i<=x;i++)
		for(j=0;j<=y;j++)
			p[i][j]='~';	
			
	return p;
}
