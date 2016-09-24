#include "constantes.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define sizeofBoard sizeof(Board)


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
void inicializarArregloPosition(Position* posiciones){
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
void cargarShip(Ship* ship,char tipo){
	ship->tipo=tipo;
	inicializarArregloPosition(ship->posiciones);

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


}

void imprimirShip(Ship ship){
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

void cargarArregloShip(Ship* arreglo,int lancha, int submarino,int crucero,int destructor,int portaviones){
	int i,posicion;
	posicion=0;
	i=0;
	while(i<lancha){
		cargarShip(&arreglo[i],'L');
		i++;
		posicion++;
	}
	i=0;
	while(i<submarino){
		cargarShip(&arreglo[i],'S');
		i++;
		posicion++;
	}
	i=0;
	while(i<crucero){
		cargarShip(&arreglo[i],'C');
		i++;
		posicion++;
	}
	i=0;
	while(i<destructor){
		cargarShip(&arreglo[i],'D');
		i++;
		posicion++;
	}
	i=0;
	while(i<portaviones){
		cargarShip(&arreglo[i],'P');
		i++;
		posicion++;
	}

}

//mias!!:
void  cargarParams(Params* params,int lancha, int submarino,int crucero,int destructor,int portaviones){

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
		cargarShip(&params->arreglo_ship_cpu[posicion],'L');
		i++;
		posicion++;
	}
	i=0;
	while(i<submarino){
		cargarShip(&params->arreglo_ship_cpu[posicion],'S');
		i++;
		posicion++;
	}
	i=0;
	while(i<crucero){
		cargarShip(&params->arreglo_ship_cpu[posicion],'C');
		i++;
		posicion++;
	}
	i=0;
	while(i<destructor){
		cargarShip(&params->arreglo_ship_cpu[posicion],'D');
		i++;
		posicion++;
	}
	i=0;
	while(i<portaviones){
		cargarShip(&params->arreglo_ship_cpu[posicion],'P');
		i++;
		posicion++;
	}

	/*for (i=0;i<params->cantidad_ship;i++){
		imprimirShip(params->arreglo_ship_cpu[i]);
	}*/
}

void liberarParams(Params* params){
	printf("1\n");
	free(params->arreglo_ship_cpu);
	printf("2\n");
	free(params->arreglo_ship_player);
	printf("3\n");
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
		board->actualPlayer=1;
		//board->params.arreglo_ship_cpu=params.arreglo_ship_cpu;
		//board->params.arreglo_ship_player=params.arreglo_ship_player;
		//imprimirShip(board->params.arreglo_ship_cpu[3]);
		//printf("imprimir un ship dentro de inicialziar board\n");
		board->matriz0=(char**)crearMatriz(n,m);
		board->matriz1=(char**)crearMatriz(n,m);
		//printf("termino inicializar board\n");
		//poniendo los barcos creados
		int i;
		for (i=0;i<board->params.cantidad_ship;i++){
			positionRandomShip(&board->params.arreglo_ship_cpu[i],board->fila,board->columna);

			while(verificarArregloPositionShipCpu(board->params.arreglo_ship_cpu,board->params.cantidad_ship,i)){
				positionRandomShip(&board->params.arreglo_ship_cpu[i],board->fila,board->columna);
			}
		}
		ponerShipCPU(board);

		printf("\nTablero creado\n");
		return board;
	}
}
void liberarBoard(Board* board){
	int i;
	printf("4\n");
	for (i=0;i<board->fila;i++){
		printf("adsf: %d\n",i );
		free(board->matriz0[i]);
		free(board->matriz1[i]);
	}
	printf("5\n");
	free(board->matriz0);
	printf("6\n");
	free(board->matriz0);
	printf("7\n");
	free(board);
	printf("8\n");
	//printf("liberarBoar: OK\n");
}

void saveBoard(Board* board, int *id, code*statusCode){
	FILE *fp;
   	int i;
   	char valor[6];
   	char registro[255];
   	char hora[10];
    char nombre_archivo[30];
    char fecha[13];
    char fecha_hora[32];
    char aaaa[5];
    time_t ltime;
    struct tm *time_tm;
    //char idNueva[20];
    int idNuevaInt;



    time(&ltime);
    time_tm=localtime(&ltime);
    sprintf(aaaa,"%d",1900+time_tm->tm_year);
    sprintf(fecha,"%02d-%02d-%s",time_tm->tm_mday,time_tm->tm_mon+1,aaaa);
    //hora:


     sprintf(hora,"%02d:%02d:%02d",time_tm->tm_hour,time_tm->tm_min,time_tm->tm_sec);
     idNuevaInt=(time_tm->tm_hour*time_tm->tm_hour)+(time_tm->tm_min*time_tm->tm_sec)+(time_tm->tm_sec*time_tm->tm_sec)+19+3+1997; //fecha de cumpleaños :D
     //sprintf(idNueva,"%04d",idNuevaInt);
     //idNuevaInt=atoi(idNueva);
     *id=idNuevaInt;
     //printf("ID dentro save:%d \n", *id);

     //printf("idNueva: %s\n",idNueva );
     sprintf(nombre_archivo,"Board/Board%d.txt",idNuevaInt);
     //printf("nombre_archivo%s\n",nombre_archivo );
     //printf("nombre_archivo: %s\n",nombre_archivo );

    //fecha

    //fecha_hora
    sprintf(fecha_hora,"00/%s %s\n",fecha,hora);



   fp = fopen(nombre_archivo,"w");
   if(fp == NULL)
   {
      perror("Error in opening file");
      //errror al cargar
   }
   fputs(fecha_hora,fp);
   RegDimension rd;
   rd.f1='/';
   rd.f2='/';
   rd.f3='/';
   rd.f4='/';
   rd.f5='/';
   memset(valor,0,sizeof(valor));

   memcpy(rd.tipoReg,"01",2);
   sprintf(valor,"%04d",board->fila);
   memcpy(rd.fila,valor,4);

   sprintf(valor,"%04d",board->columna);
   memcpy(rd.columna,valor,4);
   sprintf(valor,"%03d",board->params.cantidad_ship);
   memcpy(rd.cantidad_ship,valor,3);
   sprintf(valor,"%04d",board->params.cuadros_ship);
   memcpy(rd.cuadros_ship,valor,4);
   sprintf(valor,"%05d",board->params.cuadros_minimos);
   memcpy(rd.cuadros_minimos,valor,5);


   memset(registro,0,sizeof(registro));
   memcpy(registro,&rd,sizeof(RegDimension));
   strcat(registro,"\n");
   fputs(registro,fp);

   RegShip rs;
   rs.f1='/';
   rs.f2='/';
   rs.f3='/';
   rs.f4='/';
   memcpy(rs.tipoReg,"02",2);
   int largo;
   largo=board->params.cantidad_ship;
   for (i=0;i<largo;i++){
   		sprintf(valor,"%04d",board->params.arreglo_ship_cpu[i].posiciones[0].fila);
   		memcpy(rs.fila,valor,4);

   		sprintf(valor,"%04d",board->params.arreglo_ship_cpu[i].posiciones[0].columna);
   		memcpy(rs.columna,valor,4);
   		rs.tipo=board->params.arreglo_ship_cpu[i].tipo;
   		sprintf(valor,"%d",board->params.arreglo_ship_cpu[i].orientacion);
   		rs.orientacion=valor[0];

   		memset(registro,0,sizeof(registro));
		memcpy(registro,&rs,sizeof(RegShip));
		strcat(registro,"\n");
		fputs(registro,fp);


   }




   fclose(fp);

	//FILE* archivo=fopen("Tableros/tablero.txt","w");
}

Board* loadBoard(int id, code*statusCode){
	//printf("hola\n");
	FILE *fp;
	char buffer[255];
	RegDimension rd;
	RegShip rs;
	int fila,columna,orientacion,filaBoard,columnaBoard;
	char tipo_ship;
	Params params;
	
	char tipo[3];
	char valor[6];
	char nombre_archivo[30];
	//printf("ID dentr load: %d\n",id );

	memset(tipo,0,sizeof(tipo));
	memset(valor,0,sizeof(valor));
	sprintf(nombre_archivo,"Board/Board%d.txt",id);
	printf("nombre_archivo: %s\n",nombre_archivo );
   fp = fopen(nombre_archivo,"r");
   if(fp == NULL)
   {
      printf("archivo no existe\n");
      return NULL;
   }

   while (!feof(fp)){
		fgets(buffer,255,fp);
		memcpy(tipo,buffer,2);
		//printf("tipo string : %s\n",tipo );

		if (atoi(tipo)==1){
			memcpy(&rd,buffer,sizeof(RegDimension));
			break;
		}
	}

	memcpy(valor,rd.cantidad_ship,sizeof(rd.cantidad_ship));
	params.cantidad_ship=atoi(valor);
	memcpy(valor,rd.fila,sizeof(rd.fila));
	filaBoard=atoi(valor);
	memcpy(valor,rd.columna,sizeof(rd.columna));
	columnaBoard=atoi(valor);
	memcpy(valor,rd.cuadros_ship,sizeof(rd.cuadros_ship));
	params.cuadros_ship=atoi(valor);
	memcpy(valor,rd.cuadros_minimos,sizeof(rd.cuadros_minimos));
	params.cuadros_minimos=atoi(valor);
	params.cuadros_por_ocupar=params.cuadros_ship;

	params.arreglo_ship_cpu=(Ship*)malloc(sizeof(Ship)*(params.cantidad_ship));
	params.arreglo_ship_player=(Ship*)malloc(sizeof(Ship)*(params.cuadros_ship+1));
	params.largo_arreglo_player=0;
	

	memset(tipo,0,sizeof(tipo));
	int contador=0;
	Ship ship;
	while (!feof(fp)){
		fgets(buffer,255,fp);
		memcpy(tipo,buffer,2);
		if (atoi(tipo)==2){
			memset(valor,0,sizeof(valor));
			memcpy(&rs,buffer,sizeof(RegShip));
			tipo_ship=rs.tipo;
			memcpy(valor,&rs.orientacion,sizeof(rs.orientacion));
			orientacion=atoi(valor);
			memcpy(valor,rs.fila,sizeof(rs.fila));
			fila=atoi(valor);
			memcpy(valor,rs.columna,sizeof(rs.columna));
			columna=atoi(valor);
			cargarShip(&ship,tipo_ship);
			putPositionToShip(&ship,fila,columna,orientacion);
			params.arreglo_ship_cpu[contador]=ship;
			contador++;
		}
	}
	Board* b;
	if (b==NULL){
		printf("null1asd\n");
		return NULL;
	}
	b=(Board*) malloc(sizeofBoard); //verificando si hay memoria para el board
	if (b==NULL){
		printf("No se pudo cargar el archivo, error desconocido\n");

		return NULL;
	}

	else{
		printf("Cargando tablero...");
		b->fila=filaBoard;
		b->columna=columnaBoard;
		b->params=params;
		b->actualPlayer=1;
		b->matriz0=(char**)crearMatriz(filaBoard,columnaBoard);
		b->matriz1=(char**)crearMatriz(filaBoard,columnaBoard);
		ponerShipCPU(b);
		printf("\nTablero cargado\n");

		return b;
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
	int fila=pArray[0].fila;
	int columna=pArray[0].columna;
	if (board->matriz0[fila][columna]=='#'){
		board->matriz0[fila][columna]='X';
		board->matriz1[fila][columna]='X';
		int i,j;
		int ships=board->params.cantidad_ship;
		int tamano;
		//printf("hola cpu\n");
		for(i=0;i<ships;i++){
			tamano=board->params.arreglo_ship_cpu[i].tamano;
			for (j=0;j<tamano;j++){
				if(compararPosition(board->params.arreglo_ship_cpu[i].posiciones[j],pArray[0])){
					if(board->params.arreglo_ship_cpu[i].vida>=0){
						board->params.arreglo_ship_cpu[i].vida-=1;
						if(board->params.arreglo_ship_cpu[i].vida==0){
							return 2;
						}
					}
					return 1;

				}
			}
		}
		//printf("hola player\n");
		ships=board->params.largo_arreglo_player;
		for(i=0;i<ships;i++){
			tamano=board->params.arreglo_ship_player[i].tamano;
			for (j=0;tamano;j++){
				if(compararPosition(board->params.arreglo_ship_cpu[i].posiciones[j],pArray[0])){
					if(board->params.arreglo_ship_cpu[i].vida>=0){
						board->params.arreglo_ship_cpu[i].vida-=1;
						if(board->params.arreglo_ship_cpu[i].vida<=0){
							return 2;
						}
					}
					return 1;

				}
			}
		}
		//printf("casi final\n");
		board->matriz0[fila][columna]='M';
		board->matriz1[fila][columna]='M';
		//printf("final\n");
		return 0;
	}




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
		printf("\t\t");
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
		printf("\t\t");
		for (j=0;j<board->columna;j++){
			printf("%c",board->matriz1[i][j] );
		}
		printf("\n");
	}
}

void print(Board* board,int showComplete,code* statusCode){
	//printf("funciones print para el board\n");
	printf("\t\tTABLERO ENEMIGO\n");
	if (showComplete==0){
		printEnemigo(board,showComplete);
	}
	else if( showComplete==1){
		printEnemigo(board,showComplete);
	}

	int i;
	printf("\t\t");
	for (i=0;i<board->columna;i++){
		printf("%c",'-');
	}
	printf("\n");
	printPlayer(board);
	printf("\t\tTABLERO JUGADOR\n");

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
	printf("\t\t\t\tMENU\n\n");
	printf("\t\t1) Crear tablero\n");
	printf("\t\t2) Grabar tablero\n");
	printf("\t\t3) Cargar tablero\n");
	printf("\t\t4) Verificar tablero\n");
	printf("\t\t5) Atacar\n");
	printf("\t\t6) Posicionar embarcaciones\n");
	printf("\t\t7) Visualizar tablero\n");
	printf("\t\t8) Salir\n");
	printf("\t\t\nOpcion:");
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

int verificarGanador(Board* b){ // 0->CPU ; 1->Player ; 2->No hay ganador ; 3 error
	int i,j;
	if(b->actualPlayer==0){ //verificar computadora
		for (i=0;i<(b->fila)/2;i++){
			for (j=0;j<b->columna;j++){
				if (verificarLetraShip(b->matriz0[i][j])){
					return 2;
				}
			}
		}
		return 0;
	}
	else if(b->actualPlayer==1){
		for (i=(b->fila)/2;i<(b->fila);i++){
			for (j=0;j<b->columna;j++){
				if (verificarLetraShip(b->matriz0[i][j])){
					return 2;
				}
			}
		}
		return 1;
	}
	return 3;
}
void terminarTurno(Board* b){
	if(b->actualPlayer==0){
		b->actualPlayer=1;
	}
	else{
		b->actualPlayer=0;
	}

}
int batalla(Board* board){

	while((verificarGanador(board))==2){
		int fila,columna;
		if(board->actualPlayer==0){
			//fila
		}
	}

}

