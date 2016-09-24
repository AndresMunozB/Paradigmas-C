#ifndef _STRUCTS_H_
#define _STRUCTS_H_


//Position
typedef struct{

	int fila;
	int columna; 

}Position;

// Ship:
typedef struct{

	  char tipo; //lancha, submarino, crucero , destructor, portaviones; L,S,C,D,P
	  int vida; // 1, 2, 3, 4, 5. esto ademas nos sirve para saber cuanto espacio ocupa en el tablero.
	  int orientacion; /// 0 o 1 ; vertical y horizontal.
	  int habilidad; // puede tener una habilidad secundaria el barco. aparte de las municiones infinitas donde se ataca una sola posicion.
	  int tamano;
	  Position posiciones[5];
}Ship;


typedef struct{

	int cuadros_minimos;
	int cuadros_ship; 
	int cantidad_ship;
	int largo_arreglo_player;
	int cuadros_por_ocupar;
	Ship* arreglo_ship_cpu;
	Ship* arreglo_ship_player;

}Params;


//Board:
typedef struct{

	int fila;
	int columna;
	int dificultad;
	Params params;
	char** matriz0;
	char** matriz1;
	int actualPlayer;
	
}Board;


//Game:
typedef struct{

	Board board;
	Position* posiciones_atacadas_jugador;
	Position* posiciones_atacadas_cpu;

}Game;

//Para save y load un board:

typedef struct 
{
	char tipoReg[2];
	char f1;
	char fila[4];
	char f2;
	char columna[4];
	char f3;
	char cantidad_ship[3];
	char f4;
	char cuadros_ship[4];
	char f5;
	char cuadros_minimos[5];

}RegDimension;

typedef struct 
{
	char tipoReg[2];
	char f1;
	char tipo;
	char f2;
	char orientacion;
	char f3;
	char fila[4];
	char f4;
	char columna[4];

}RegShip;







#endif



//me perdonas por arruinar tu programa? 
//siiiiiiiiiiiiiii