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
	  char tipo; //lancha, submarino, crucero , destructor, portaviones; L,S,C,D,P
	  int vida; // 1, 2, 3, 4, 5. esto ademas nos sirve para saber cuanto espacio ocupa en el tablero.
	  int orientacion; /// 0 o 1 ; vertical y horizontal.
	  int habilidad; // puede tener una habilidad secundaria el barco. aparte de las municiones infinitas donde se ataca una sola posicion.

}Ship;

typedef struct{
	Position* position;
	Ship* ship;
}Info;




//Board:
typedef struct{
	/*dimenciones de nxm donde n debe ser par!! 
	dificultad :

	*/
	int fila;
	int columna;
	int dificultad;
	//Params paramsCPU;
	//Params paramsPlayer;
	/*int cantidadShip;
	Ship** ships;*/
	int largo_arreglo_ship_player_1;
	Ship* arreglo_ship_player_1;

	int largo_arreglo_ship_player_2;
	Ship* arreglo_ship_player_2;


	int largo_arreglo_info_player_1;
	Info* arreglo_info_player_1;

	int largo_arreglo_info_player_2;
	Info* arreglo_info_player_2;
	

}Board;


//Game:
typedef struct{

	Board board;
	Position** posiciones_atacadas_jugador;
	Position** posiciones_atacadas_cpu;

}Game;


//Params:
typedef struct{
	/*cantidad de cada tipo de barco en solo una mitad
	calamares gigantes, tormentas, etc
	*/

	int lancha; // 1 vida
	int submarino;// 2 vidas
	int crucero; // 3 vidas
	int destructor; //4 vidas 
	int portaviones; // 5 vidas 
	int cuadros_minimos;
	int cuadros_ship; 
	int cantidad_ship;
	//Ship*

}Params;


#endif



//me perdonas por arruinar tu programa? 
//siiiiiiiiiiiiiii