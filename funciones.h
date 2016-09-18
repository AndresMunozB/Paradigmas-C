#include "constantes.h"
#include "estructuras.h"

#ifndef _FUNCIONES_H
#define _FUNCIONES_H


//creadas por mi;
//Params* crearParams(int lancha, int submarino,int crucero,int destructor,int portaviones);


//minimas pedidas:
Board* createBoard(int n,int m, Params params,code *statusCode); 
void saveBoar(Board* board, int *id, code*statusCode);
Board* loadBoard(int id, code*statusCode);
int checkBoard(Board* board, code* statusCode);
int play(Board* board,Ship* ship, Position* pArray, code* statusCode);
void putShip(Board* board,Position p,Ship ship,code* statusCode); //ver lo de la posision y de el ship
void print(Board* board,int showComplete,code* statusCode);

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