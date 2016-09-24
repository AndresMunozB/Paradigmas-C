#include "constantes.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef _FUNCIONES_H
#define _FUNCIONES_H


//creadas por mi;
//Params* crearParams(int lancha, int submarino,int crucero,int destructor,int portaviones);

//Mias:

/**funcion que retorna un numero random entre los numeros entregados como parametro
*/
int		intrandom					(int desde,int hasta);
/** Funcion que carga una estructura posicion con fila y columna
*/
void 	cargarPosition				(Position* position,int fila,int columna);
/**Funcion que imprime una estructura Position en pantalla
*/
void 	imprimirPosition			(Position position);
/**Funcion que compara dos estructura Position (verifica si la fila y columna son iguales)
entrega 0 si no son iguales y 1 si son iguales
*/
int 	compararPosition			(Position position1,Position position2);
/**Funcion que inicializa las posiciones de un barco con fila y columna igual a -1
*/
void 	inicializarArregloPosition	(Position* posiciones);
/**Funcion que recorre el arreglo de posiciones de  un barco y le cambia la posicion segun la posicion entregada
*/
void 	putPositionToShip			(Ship* ship,int fila, int columna, int orientacion);
/**Funcion verifica si se sobreponen dos ship 
entrega 0 si es falso y 1 si se sobreponen 
*/
int 	sobreponeShip				(Ship ship1, Ship ship2);
/**Funcion inicializa un ship segun el tipo
*/
void 	cargarShip 					(Ship* ship,char tipo);
/**Funcion que imprime por consola las caracteristicas de un ship 
*/
void 	imprimirShip 				(Ship ship);
/**Funcion  utilizada en la funcion cargar params para cargar el arreglo con todos los barcos ingresados
*/
void 	cargarArregloShip 			(Ship* arreglo,int lancha, int submarino,int crucero,int destructor,int portaviones);
/**Funcion  inicializa params con los datos entregados
*/
void  	cargarParams 				(Params* params,int lancha, int submarino,int crucero,int destructor,int portaviones);
/**Funcion  que libera params
*/
void 	liberarParams  				(Params* params);
/**Funcion  que rellena las posiciones de un barco de forma random
*/
void 	positionRandomShip 			(Ship* ship,int fila,int columna);
/**Funcion  que verifica si dentro de un arreglo se sobrepone el barco de la posicion entregada
entrega 0 si es falso y 1 si se sobrepone
*/
int 	verificarArregloPositionShipCpu(Ship* arreglo,int largo,int posicion); //retorna 1 si se sobrepone en alguno y 0 si no se sobrepone
/**Funcion  que verifica si se sobrepone el barco entregado como parametro
entrega 0 si es falso y 1 si se sobrepone
*/
int 	verificarArregloPositionShipPlayer(Ship* arreglo,int largo,Ship ship); //retorna 1 si se sobrepone en alguno y 0 si no se sobrepone
/** Funciones que imprime por consola las caracteristicas de params
*/
void 	imprimirParams 				(Params params);
/** Funcion que retorna un arreglo bidimensional de caracteres 
recibe como parametro la cantidad de filas y columnas
*/
char** 	crearMatriz					(int n,int m);
/** Funcion que recorre el arreglo de barcos de la CPU y los posiciona en el tablero  co su respectivo caracter
*/
void 	ponerShipCPU				(Board* board);
/**Funcion que retorna un tablero en el cual se puede jugar
*/
Board* 	createBoard					(int n,int m, Params params,code *statusCode);

void 	liberarBoard 				(Board* board);
void 	saveBoard 					(Board* board, int *id, code*statusCode);
Board* 	loadBoard 					(int id, code*statusCode);
int 	checkBoard 					(Board* board, code* statusCode);
int 	play 						(Board* board,Ship* ship, Position* pArray, code* statusCode);
void 	putShip 					(Board* board,Position position,Ship ship,code* statusCode);
void 	printEnemigo 				(Board* board,int showComplete);
void 	printPlayer 				(Board* board);
void 	print 						(Board* board,int showComplete,code* statusCode);
void 	imprimirTitulo 				();
void 	imprimirMenu				();
void 	imprimirInfoShip 			();
int 	verificarLetraShip 			(char tipo); //verifica si el char tipo es una de las letras de los barcos en mayusculas o minusculas
int 	verificarPositionPlayer 	(Board* board,Position position);
int 	verificarGanador 			(Board* b); // 0->CPU ; 1->Player ; 2->No hay ganador ; 3 error
void 	terminarTurno 				(Board* b);
int 	batalla 					(Board* board);






//minimas pedidas:
/*Board* createBoard(int n,int m, Params params,code *statusCode); 
void saveBoard(Board* board, int *id, code*statusCode);
Board* loadBoard(int id, code*statusCode);
int checkBoard(Board* board, code* statusCode);
int play(Board* board,Ship* ship, Position* pArray, code* statusCode);
void putShip(Board* board,Position p,Ship ship,code* statusCode); //ver lo de la posision y de el ship
void print(Board* board,int showComplete,code* statusCode);*/

//extras!: 
void saveGame(Game* game, int* id, code* statusCode);
Game* loadGame(int id,code* statusCode);
void saveGameHistory(int id,code* statusCode);
Game* loadGameHistory(int id,code* statusCode);
int getScore(Game* game);




void imprimir(char **p);
char** inicio();


#endif
//mamorcito te quiero muuuuuuuuuucho 