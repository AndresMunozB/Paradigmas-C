#ifndef _STRUCTS_H_
#define _STRUCTS_H_


//Position
typedef struct{

	int fila;
	int columna; 

}Position;

// Ship:
typedef struct{
	/*Armamento: teledirigido, onda expansiva, revelacion de terreno etc
	  resistencia
	  blindaje
	  tamaño de la embarcacion (cuantos cuadritos ocupa)*/
	  int id;
	  char tipo; //lancha, submarino, crucero , destructor, portaviones; L,S,C,D,P
	  int vida; // 1, 2, 3, 4, 5. esto ademas nos sirve para saber cuanto espacio ocupa en el tablero.
	  int orientacion; /// 0 o 1 ; vertical y horizontal.
	  int habilidad; // puede tener una habilidad secundaria el barco. aparte de las municiones infinitas donde se ataca una sola posicion.
	  int tamano;
	  Position posiciones[5];
}Ship;


typedef struct{
	/*cantidad de cada tipo de barco en solo una mitad
	calamares gigantes, tormentas, etc
	*/

	int cuadros_minimos;
	int cuadros_ship; 
	int cantidad_ship;
	int largo_arreglo_player;
	int cuadros_por_ocupar;
	Ship* arreglo_ship_cpu;
	Ship* arreglo_ship_player;
	
	

	//Ship*

}Params;


//Board:
typedef struct{
	/*dimenciones de nxm donde n debe ser par!! 
	dificultad :*/
	int fila;
	int columna;
	int dificultad;
	Params params;
	char** matriz0;
	char** matriz1;


}Board;


//Game:
typedef struct{

	Board board;
	Position* posiciones_atacadas_jugador;
	Position* posiciones_atacadas_cpu;

}Game;

//Para save y load un board:

/*typedef struct 
{
	char tipo;
	char orientacion;
	char tipo;
	char fila[6];
	char columna[6];

	

}ShipTxt;*/





#endif



//me perdonas por arruinar tu programa? 
//siiiiiiiiiiiiiii