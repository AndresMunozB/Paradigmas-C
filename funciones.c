#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "constantes.h"
#include "funciones.h"
#include <time.h>


int intRandom(int desde,int hasta){
	srand(time(NULL));
	int random;
	/*hasta+=1;
	while (!(random>=desde && random<=hasta)){
		random = rand()% hasta;
	}	
	return random;*/
	random = rand () % (hasta-desde+1) + desde;
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
void putPositionToShip(Ship* ship,int fila, int columna, int orientacion){
	int i;
	ship->orientacion=orientacion;
	for (i=0;i<ship->tamano;i++){
		if (orientacion==1){ //si es que es horizontal
			cargarPosition(&ship->posiciones[i],fila,columna+i);
		}
		else{
			cargarPosition(&ship->posiciones[i],fila+i,columna);
		}
	}
}
int sobreponeShip(Ship ship1, Ship ship2){ //si se sobrepone el barco retorna 1, si no se sobrepone returma 0;
	int i,j;
	//printf("%d \n",ship1.tamano );
	//printf("%d \n",ship2.tamano );
	for (i=0;i<ship1.tamano;i++){
		//printf("sobrepone for i\n");
		//printf("%d \n",ship2.tamano );
		for(j=0;j<ship2.tamano;j++){
			//printf("sobrepone for j\n");
			if(compararPosition(ship1.posiciones[i],ship2.posiciones[j])){
				//imprimirPosition(ship1.posiciones[i]);
				//imprimirPosition(ship2.posiciones[j]);
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

void cargarArregloShip(Ship* arreglo,int lancha, int submarino,int crucero,int destructor,int portaviones, int* id){
	int i,posicion;
	posicion=0;
	i=0;
	while(i<lancha){
		cargarShip(&arreglo[i],'L',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<submarino){
		cargarShip(&arreglo[i],'S',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<crucero){
		cargarShip(&arreglo[i],'C',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<destructor){
		cargarShip(&arreglo[i],'D',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<portaviones){
		cargarShip(&arreglo[i],'P',id);
		i++;
		posicion++;
	}

}

//mias!!:
void  cargarParams(Params* params,int lancha, int submarino,int crucero,int destructor,int portaviones,int* id){
	
	params->cuadros_minimos = (lancha*2)+(submarino*4)+(crucero*9)+(destructor*16)+(portaviones*25);
	params->cuadros_ship=(lancha*1)+(submarino*2)+(crucero*3)+(destructor*4)+(portaviones*5);
	params->cantidad_ship=lancha+submarino+crucero+destructor+portaviones;
	params->cuadros_por_ocupar=params->cuadros_ship;
	//printf("antes pedir memoria\n");
	params->arreglo_ship_cpu=(Ship*)malloc(sizeof(Ship)*(params->cantidad_ship));
	params->arreglo_ship_player=(Ship*)malloc(sizeof(Ship)*(params->cuadros_ship+1));
	params->largo_arreglo_player=0;
	int i,posicion;
	posicion=0;
	i=0;
	while(i<lancha){
		cargarShip(&params->arreglo_ship_cpu[posicion],'L',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<submarino){
		cargarShip(&params->arreglo_ship_cpu[posicion],'S',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<crucero){
		cargarShip(&params->arreglo_ship_cpu[posicion],'C',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<destructor){
		cargarShip(&params->arreglo_ship_cpu[posicion],'D',id);
		i++;
		posicion++;
	}
	i=0;
	while(i<portaviones){
		cargarShip(&params->arreglo_ship_cpu[posicion],'P',id);
		i++;
		posicion++;
	}
	
	/*for (i=0;i<params->cantidad_ship;i++){
		imprimirShip(params->arreglo_ship_cpu[i]);
	}*/
}
void liberarParams(Params* params){
	free(params->arreglo_ship_cpu);
	free(params->arreglo_ship_player);
}
void positionRandomShip(Ship* ship,int fila,int columna){
	int orientacionRand,filaRand,columnaRand;
	if (ship->tamano<=columna && ship->tamano<=(fila/2)){

		orientacionRand=intRandom(0,1);
		if (orientacionRand==0){
			/*printf("fil 0 : %d\n",(fila/2)-1-ship->tamano );
			printf("col 0 : %d\n",columna-1);*/
					
			filaRand=intRandom(0,(fila/2)-ship->tamano);
			columnaRand=intRandom(0,columna-1);
		}
		else if(orientacionRand==1){
			/*printf("fil 1 : %d\n",(fila/2)-1);
			printf("col 1 : %d\n",columna-ship->tamano-1);*/
			filaRand=intRandom(0,(fila/2)-1);
			columnaRand=intRandom(0,columna-ship->tamano);
			
		}
		//printf("Estoy aqui rand\n");
		
		/*printf("oientacion: %d\n",orientacionRand );
		printf("filaRand: %d\n",filaRand );
		printf("columnaRand: %d\n",columnaRand);
		printf("\n");*/
		
	}
	else{
		if (ship->tamano>columna){
			orientacionRand=0;
			filaRand=intRandom(0,(fila/2)-ship->tamano);
			columnaRand=intRandom(0,columna-1);
		}
		else{
			orientacionRand=1;
			filaRand=intRandom(0,(fila/2)-1);
			columnaRand=intRandom(0,columna-ship->tamano);
		}
	}

	
	putPositionToShip(ship,filaRand,columnaRand,orientacionRand);
}
int verificarArregloPositionShipCpu(Ship* arreglo,int largo,int posicion){ //retorna 1 si se sobrepone en alguno y 0 si no se sobrepone
	int i;																					
	for (i=0;i<largo;i++){
		if(i!=posicion){
			if(sobreponeShip(arreglo[i],arreglo[posicion])){
			//imprimirShip(arreglo[i]);
			//imprimirShip(ship);
			//printf("termino verificacion arreglo \n");

			return 1;
			}

		}
		
	}
	return 0;
}
int verificarArregloPositionShipPlayer(Ship* arreglo,int largo,Ship ship){ //retorna 1 si se sobrepone en alguno y 0 si no se sobrepone
	int i;																					
	for (i=0;i<largo;i++){

			if(sobreponeShip(arreglo[i],ship)){
			//imprimirShip(arreglo[i]);
			//imprimirShip(ship);
			//printf("termino verificacion arreglo \n");

			return 1;
			}

		
		
	}
	return 0;
}


void imprimirParams(Params params){

	printf("cuadros_minimos: %d\n",params.cuadros_minimos );
	printf("cuadros_ship: %d\n",params.cuadros_ship );
	printf("cantidad_ship: %d \n",params.cantidad_ship);
}



char** crearMatriz(int n,int m){
	char** matriz=(char**)malloc(sizeof(char*)*n);//filas
	int i,j;
	for (i=0;i<n;i++){
		matriz[i]=(char*)malloc(sizeof(char)*m); //columnas
	}
	
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			matriz[i][j]='#';
		}
	}
	return matriz;
}

void ponerShipCPU(Board* board){
	int i,j;
	for (i=0;i<board->params.cantidad_ship;i++){
		for(j=0;j<board->params.arreglo_ship_cpu[i].tamano;j++){
			board->matriz1[board->params.arreglo_ship_cpu[i].posiciones[j].fila][board->params.arreglo_ship_cpu[i].posiciones[j].columna]=board->params.arreglo_ship_cpu[i].tipo;
		}
	}
}

Board* createBoard(int n,int m, Params params,code *statusCode){
	if ((n%2)!=0){ //verificando que el numero de filas es un numero par:
		//printf("n no es par\n");		
		return NULL;
	}
	//printf("cuadros_minimos dentro de inicializar: %d \n",params.cuadros_minimos);
	//printf("n y m: %d %d \n",n,m );
	//imprimirParams(&params);
	if (params.cuadros_minimos>((n/2)*m)){ //verificando si se pueden poner todos los barcos
		//printf("dimensiones invalidas\n");
		printf("dimensiones invalidas\n");
		return NULL;
	}
	//printf("entreeee\n");

	Board* board=(Board*) malloc(sizeof(Board)); //verificando si hay memoria para el board
	if (board==NULL){
		return NULL;
	}

	else{
		//printf("entreee\n");
		printf("Creando tablero...");
		board->fila=n;
		board->columna=m;
		board->params=params;
		//board->params.arreglo_ship_cpu=params.arreglo_ship_cpu;
		//board->params.arreglo_ship_player=params.arreglo_ship_player;
		//imprimirShip(board->params.arreglo_ship_cpu[3]);
		//printf("imprimir un ship dentro de inicialziar board\n");
		board->matriz0=(char**)crearMatriz(n,m);
		board->matriz1=(char**)crearMatriz(n,m);
		//printf("termino inicializar board\n");
		//poniendo los barcos creados
		int i,j,k,l;
		for (i=0;i<board->params.cantidad_ship;i++){
			//printf("estoy aqui!\n");
			positionRandomShip(&board->params.arreglo_ship_cpu[i],board->fila,board->columna);
		
			while(verificarArregloPositionShipCpu(board->params.arreglo_ship_cpu,board->params.cantidad_ship,i)){
				positionRandomShip(&board->params.arreglo_ship_cpu[i],board->fila,board->columna);
				//printf("estoy dentro del while\n");
			}
			//imprimirShip(board->params.arreglo_ship_cpu[i]);
		}
		ponerShipCPU(board);
		printf("\nTablero creado\n");
		return board;
	}
} 
void liberarBoard(Board* board){
	int i;
	for (i=0;i<board->fila;i++){
		free(board->matriz0[i]);
		free(board->matriz1[i]);
	}
	free(board->matriz0);
	free(board->matriz0);
	free(board);
	//printf("liberarBoar: OK\n");
}

void saveBoar(Board* board, int *id, code*statusCode){
	FILE *fp;
   	int c;
  
   fp = fopen("file.txt","w");
   if(fp == NULL) 
   {
      perror("Error in opening file");

   }

   
  
   fclose(fp);

	//FILE* archivo=fopen("Tableros/tablero.txt","w");
}

Board* loadBoard(int id, code*statusCode){

	FILE *fp;
   	int c;
  
   fp = fopen("file.txt","r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
   }
   
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      { 
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);

}
int checkBoard(Board* board, code* statusCode){
	if(board==NULL){
		printf("Tablero no ingresado\n");
		return 0;
	}
	if ((board->fila%2)!=0){
		printf("Dimension de fila invalida\n");
		return 0;
	}
	if (board->params.cuadros_minimos>(board->fila*board->columna)){
		printf("No cumple los requisitos para ubicar los barcos\n");
		return 0;
	}
	if (board->fila<0){
		printf("Dimension negativa\n");
		return 0;
	}
	if (board->columna<0){
		printf("Dimension negativa\n");
		return 0;
	}
	return 1;
}

int play(Board* board,Ship* ship, Position* pArray, code* statusCode){
	printf("funciones play para el board\n");

}


void putShip(Board* board,Position position,Ship ship,code* statusCode){

	int i;	
	int fila,columna;

	for (i=0;i<ship.tamano;i++){

		fila=ship.posiciones[i].fila;
		columna=ship.posiciones[i].columna;

		board->matriz0[fila][columna]=ship.tipo;
		board->matriz1[fila][columna]=ship.tipo;

	}
	int largo= board->params.largo_arreglo_player;
	board->params.arreglo_ship_player[largo]=ship;	
	board->params.largo_arreglo_player++;


}

void printEnemigo(Board* board,int showComplete){
	int i,j;
	for (i=0;i<(board->fila)/2;i++){
		for (j=0;j<board->columna;j++){
			if (showComplete==0){
				printf("%c",board->matriz0[i][j] );
			}
			else if(showComplete==1){
				printf("%c",board->matriz1[i][j] );
			}
		}
		printf("\n");
	}
}
void printPlayer(Board* board){
	int i,j;
	//printf("fila:%d \n",(board->fila));
	for (i=(board->fila)/2;i<(board->fila);i++){
		for (j=0;j<board->columna;j++){
			printf("%c",board->matriz1[i][j] );
		}
		printf("\n");
	}
}

void print(Board* board,int showComplete,code* statusCode){
	//printf("funciones print para el board\n");
	printf("TABLERO ENEMIGO\n");
	if (showComplete==0){
		printEnemigo(board,showComplete);
	}
	else if( showComplete==1){
		printEnemigo(board,showComplete);
	}
	
	int i;
	for (i=0;i<board->columna;i++){
		printf("%c",'-');
	}
	printf("\n");
	printPlayer(board);
	printf("TABLERO JUGADOR\n");

}

void imprimirTitulo(){
	printf(" ____            _     _     _                _       _        \n");
	printf("| __ )    __ _  | |_  | |_  | |   ___   ___  | |__   (_)  _ __  \n");	
	printf("|  _ \\   / _` | | __| | __| | |  / _ \\ / __| | '_ \\  | | | '_ \\ \n");
	printf("| |_) | | (_| | | |_  | |_  | | |  __/ \\__ \\ | | | | | | | |_) |\n");
	printf("|____/   \\__,_|  \\__|  \\__| |_|  \\___| |___/ |_| |_| |_| | .__/ \n");
	printf("                                                         |_|  \n");
	printf("\n\n\n");
}
void imprimirMenu(){
	printf("\t\tMENU\n\n");
	printf("1) Crear tablero\n");
	printf("2) Grabar tablero\n");
	printf("3) Cargar tablero\n");
	printf("4) Verificar tablero\n");
	printf("5) Jugar\n");
	printf("6) Posicionar embarcaciones\n");
	printf("7) Visualizar tablero\n");
}
void imprimirInfoShip(){
	printf("Lancha      : L  --  Vida/Largo: 1\n");
	printf("Submarino   : S  --  Vida/Largo: 2\n");
	printf("Crucero     : C  --  Vida/Largo: 3\n");
	printf("Destructor  : D  --  Vida/Largo: 4\n");
	printf("Portaviones : P  --  Vida/Largo: 5\n");
}
int verificarLetraShip(char tipo){ //verifica si el char tipo es una de las letras de los barcos en mayusculas o minusculas
									// retorna 1 si es una de las letras
									// retorna 0 si no es una de las letras
	if(tipo=='L' || tipo=='l'||
		tipo=='S' || tipo=='s'||
		tipo=='C' || tipo=='c'||
		tipo=='D' || tipo=='d'||
		tipo=='P' || tipo=='p'){
		return 1;	
	}
	else {
		return 0;
	}
}
int verificarPositionPlayer(Board* board,Position position){
	if((position.fila>=0) && (position.fila<=(board->fila/2-1))
		&& (position.columna>=0) && (position.columna<=board->columna-1)){
		return 1;		
	}
	else {
		return 0;
	}
}