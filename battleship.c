#include "constantes.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(){


	imprimirTitulo();
	int id;
	id=0;
	code* statusCode;
	Params params;
	Board* board=NULL;

	int menu=0;
	while (menu!=8){
		imprimirMenu();
		scanf("%d",&menu);
		if(menu==1){
			int l,s,c,d,p;
			int fila,columna;
			int cuadros_minimos;

			do{

				printf("Ingrese la cantidad de cada tipo de barco: \n");
				printf("Lanchas     : ");
				fflush(stdin);
				scanf("%d",&l);
				printf("Submarinos  : ");
				fflush(stdin);
				scanf("%d",&s);
				printf("Cruceros    : ");
				fflush(stdin);
				scanf("%d",&c);
				printf("Destructores: ");
				fflush(stdin);
				scanf("%d",&d);
				printf("Portaviones : ");
				fflush(stdin);
				scanf("%d",&p);
				printf("\nIngrese las dimensiones del tablero: \n");
				printf("Fila    : ");
				fflush(stdin);
				scanf("%d",&fila);
				printf("Columna : ");
				fflush(stdin);
				scanf("%d",&columna);
				printf("\n");
				//printf("Lanchas: %d \n",l);
				//printf("Submarinos: %d \n",s);
				//printf("Cruceros: %d \n",c);
				//printf("Destructores: %d\n ",d);
				//printf("Portaviones: %d \n",p);
				//printf("Fila: %d\n",fila);
				//printf("Columna: %d\n",columna );
				cuadros_minimos = (l*2)+(s*4)+(c*9)+(d*16)+(p*25);
				if (cuadros_minimos>((fila/2)*columna)){
					printf("Dimensiones invalidas\n");
					printf("Ingrese los datos nuevamente \n\n");
				}
			}while(cuadros_minimos>((fila/2)*columna));

			cargarParams(&params,l,s,c,d,p);
			board=(Board*)createBoard(fila,columna,params,statusCode);
			printf("\n");
			//print(board,1,statusCode);
			//system("pause");
		}
		else if(menu==2){
			if (board!=NULL){
				saveBoard(board,&id,statusCode);
				printf("Tablero guardado, id : %d\n\n",id);
			}
			else{
				printf("Debe crear o cargar un tablero previamente\n");
			}

		}
		else if(menu==3){
			int idBoard;
			printf("Ingrese el id del tablero: ");
			scanf("%d",&idBoard);
			printf("hola\n");
			board=(Board*)loadBoard(idBoard,statusCode);
			printf("hola\n");

		}
		else if(menu==4){
			if (board!=NULL){
				printf("\n");
				if (checkBoard(board,statusCode)){
					printf("El tablero esta bien\n");
				}
			}
			else{
				printf("Debe crear o cargar un tablero previamente\n");
			}

		}
		else if(menu==5){
			if (board!=NULL){

				Position position;
				do{
							printf("Fila   : [0,%d]\n",(board->fila/2)-1 );
							printf("Columna: [0,%d]\n",board->columna-1);
							printf("Ingrese la posicion: \n");
							printf("Fila   : ");
							fflush(stdin);
							scanf("%d",&position.fila);

							printf("Columna: ");
		 					fflush(stdin);
							scanf("%d",&position.columna);
							if(!verificarPositionPlayer(board,position)){
								printf("Posicion fuera de la matriz\n");
							}
						}while(!(verificarPositionPlayer(board,position)) );



				int valor=play(board,&board->params.arreglo_ship_cpu[0],&position,statusCode);
				if (valor ==2){
					printf("Haz destruido un barco\n");
				}
				else if(valor==1){
					printf("Haz dado en una parte de un barco\n");
				}
				else if (valor ==0){
					printf("Haz fallado el disparo\n");
				}
			}
			else{
				printf("Debe crear o cargar un tablero previamente\n");
			}


		}
		else if(menu==6){
			if (board!=NULL){

				char tipo;
				int orientacion;
				Position position;
				Ship ship;
				if(board->params.cuadros_por_ocupar>0){//verifico si puede poner varcos 
					int cuadros;
					do{//perdir el tipo de barcoo

						imprimirInfoShip();
						printf("Ingrese el tipo de barco: ");
						fflush(stdin);
						scanf("%c",&tipo);
						if(!verificarLetraShip(tipo)){
							printf("Letra ingresada no es valdia...\n");
							printf("Ingrese el tipo de barco nuevamente \n\n");

						}
						// saber cuantos cuadros ocupa el tipo de barco ingresado
						if(tipo=='L' || tipo=='l'){
							cuadros=1;
							tipo='L';
						}
						if(tipo=='S' || tipo=='s'){
							cuadros=2;
							tipo='S';
						}
						if(tipo=='C' || tipo=='c'){
							cuadros=3;
							tipo='C';
						}
						if(tipo=='D' || tipo=='d'){
							cuadros=4;
							tipo='D';
						}
						if(tipo=='P' || tipo=='p'){
							cuadros=5;
							tipo='P';
						}
						if(verificarLetraShip(tipo) && cuadros>board->params.cuadros_por_ocupar){
							printf("El tipo de barco sobrepasa los cuadros ocupados por los barcos enemigos\n");
							printf("Ingrese el tipo de barco nuevamente \n\n");
						}
						printf("cuadros: %d\n",cuadros);
						printf("cuadros por ocupar: %d\n",board->params.cuadros_por_ocupar );

					}while(!(verificarLetraShip(tipo)) || (cuadros>board->params.cuadros_por_ocupar));

					do{ //verificando la orientacion del barco


						printf("Vertical   : 0\n");
						printf("Horizontal : 1\n");
						printf("Ingrese la orientacion (0/1): ");
						fflush(stdin);
						scanf("%d",&orientacion);
						printf("\n");
						//printf("tipo: %c\n",tipo );
						//printf("orientacion: %d\n",orientacion);
						//imprimirPosition(position);
						if( (orientacion!=0 && orientacion!=1) ){
							printf("La orientacion ingresada no es valida...\n");
							printf("Ingrese la orientacion del barco nuevamente \n\n");

						}



					}while((orientacion!=0 && orientacion!=1) );

					do{
						printf("Fila   : [0,%d]\n",(board->fila/2)-1 );
						printf("Columna: [0,%d]\n",board->columna-1);
						printf("Ingrese la posicion: \n");
						printf("Fila   : ");
						fflush(stdin);
						scanf("%d",&position.fila);

						printf("Columna: ");
	 					fflush(stdin);
						scanf("%d",&position.columna);
						//printf("tipo: %c\n",tipo );
						//printf("orientacion: %d\n",orientacion);
						//imprimirPosition(position);
						//verificar si cabe en el tablero...
						if(!verificarPositionPlayer(board,position)){
							printf("no se puede ubicar el barco\n");
						}
						//verificar si no sobrepone a otro barco en el tablero...
						
						/*printf("valor if y while %d\n", verificarArregloPositionShipPlayer(board->params.arreglo_ship_player,board->params.largo_arreglo_player,ship));
						printf("valor if y while %d\n", !(verificarPositionPlayer(board,position)));*/
					}while(!(verificarPositionPlayer(board,position)) );
					//printf("tipo: %c\n",tipo );
					//printf("orientacion: %d\n",orientacion);
					position.fila+=(board->fila/2);
					cargarShip(&ship,tipo);
					putPositionToShip(&ship,position.fila,position.columna,orientacion);
					if(verificarArregloPositionShipPlayer(board->params.arreglo_ship_player,board->params.largo_arreglo_player,ship)){
							printf("No se pudo ubicar el barco debido a que ya existe un barco en esa posicion\n");
					}
					else{
						putShip(board,position,ship,statusCode);
						board->params.cuadros_por_ocupar-=ship.tamano;

					}
					
					
				}
				else{
					printf("No se pueden ingresar mas barcos\n");
				}
				//imprimirPosition(position);
				//cargarParams(&params,1,0,0,0,0,id);
				//board=(Board*)createBoard(30,30,params,statusCode);
				//print(board,1,statusCode);
				
				//printf("fila:%d \n",board->fila );
				//printf("posicion a poner: \n");
				//imprimirPosition(position);
				//imprimirShip(board->params.arreglo_ship_cpu[0]);
				
				//print(board,0,statusCode);

				//printf("fila:%d \n",board->fila );
				//imprimirShip(board->params.arreglo_ship_cpu[0]);
				


				//print(board,0,statusCode);

				//system("pause");
			}
			else{
				printf("Debe crear o cargar un tablero previamente\n");
			}
		}
		else if (menu==7){
			if (board!=NULL){
				int opcion;
				printf("Mostrar los barcos enemigos?...\n");
				printf("1) No\n");
				printf("2) Si\n");
				printf("Opcion: ");
				scanf("%d",&opcion);
				if(opcion==1){
					print(board,0,statusCode);
				}
				else if(opcion==2){
					print(board,1,statusCode);
				}
			}
			else{
				printf("Debe crear o cargar un tablero previamente\n");
			}
			//system("pause");
		}
	}
	//imprimirShip(board->params.arreglo_ship_cpu[0]);	
	//printf("jugador: %d\n",board->actualPlayer );
	//terminarTurno(board);
	//printf("jugador: %d\n",board->actualPlayer );
	//print(board,1,statusCode);
	

	
	//print(board,0,statusCode);
	
	//print(board,1,statusCode);
	/*if (board!=NULL){
		liberarBoard(board);
		liberarParams(&params);
	}*/
	


	//printf("id: %d \n",*id );

	//Params params;

	//printf("hola antes params\n");

	//cargarParams(&params,1,1,1,1,4,id);

	//printf("inicio print params\n");


	/*int i;
	for (i=0;i<params.cantidad_ship;i++){
		imprimirShip(params.arreglo_ship_cpu[i]);
	}*/
	//printf("fin print params\n");
	//printf("creando board...");

	//Board* board=(Board*)createBoard(12,20,params,statusCode);
	//printf("\n");

	//board->matriz0[3][4]='L';
	//board->matriz0[3][5]='L';
	//board->matriz1[1][1]='*';

	//print(board,0,statusCode);

	//printf("otro tablero!!\n");
	//print(board,1,statusCode);
	//printf("posiciones random!!:\n");
	/*int i;
	for (i=0;i<board->params.cantidad_ship;i++){
		imprimirShip(board->params.arreglo_ship_cpu[i]);
	}*/


	//positionRandomShip(&params.arreglo_ship_cpu[2],board->fila,board->columna);
	//int random;

	/*printEnemigo(board);
	printf("-------\n");
	printPlayer(board);*/
	//*****memcpy(&arreglo[1].posiciones[1],&position,sizeof(Position));



	return 0;
}



//https://github.com/micodigo/Principiante-N1/blob/master/Programas/batalla%20nabal.cpp
//yapo yapo yapooo



//void cargarShip(Ship* ship,char tipo){
//void putPositionToShip(Ship* ship,int fila, int columna, int orientacion){