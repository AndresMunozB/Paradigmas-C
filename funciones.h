#include "constantes.h"
#include "estructuras.h"

#ifndef _FUNCIONES_H
#define _FUNCIONES_H


//creadas por mi;
//Params* crearParams(int lancha, int submarino,int crucero,int destructor,int portaviones);

//Mias:
int intrandom(int desde,int hasta);
void cargarPosition(Position* position,int fila,int columna);
void imprimirPosition(Position position);
int compararPosition(Position position1,Position position2);
void inicialiarArregloPosiciones(Position* posiciones);

void putPositionToShip(Ship* ship,int fila, int columna, int orientacion);
int sobreponeShip(Ship ship1, Ship ship2);
void cargarShip(Ship* ship,char tipo);
void imprimirShip(Ship ship);
void cargarArregloShip(Ship* arreglo,int lancha, int submarino,int crucero,int destructor,int portaviones);
void  cargarParams(Params* params,int lancha, int submarino,int crucero,int destructor,int portaviones);
void liberarParams(Params* params);
void positionRandomShip(Ship* ship,int fila,int columna);
int verificarArregloPositionShipCpu(Ship* arreglo,int largo,int posicion); //retorna 1 si se sobrepone en alguno y 0 si no se sobrepone
int verificarArregloPositionShipPlayer(Ship* arreglo,int largo,Ship ship); //retorna 1 si se sobrepone en alguno y 0 si no se sobrepone
void imprimirParams(Params params);
char** crearMatriz(int n,int m);
void ponerShipCPU(Board* board);
Board* createBoard(int n,int m, Params params,code *statusCode);
void liberarBoard(Board* board);
void saveBoard(Board* board, int *id, code*statusCode);
Board* loadBoard(int id, code*statusCode);
int checkBoard(Board* board, code* statusCode);
int play(Board* board,Ship* ship, Position* pArray, code* statusCode);
void putShip(Board* board,Position position,Ship ship,code* statusCode);
void printEnemigo(Board* board,int showComplete);
void printPlayer(Board* board);
void print(Board* board,int showComplete,code* statusCode);
void imprimirTitulo();
void imprimirMenu();
void imprimirInfoShip();
int verificarLetraShip(char tipo); //verifica si el char tipo es una de las letras de los barcos en mayusculas o minusculas
int verificarPositionPlayer(Board* board,Position position);
int verificarGanador(Board* b); // 0->CPU ; 1->Player ; 2->No hay ganador ; 3 error
void terminarTurno(Board* b);
int batalla(Board* board);






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