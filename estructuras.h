//Board:
typedef struct{
	/*dimenciones de nxm donde n debe ser par!! 
	dificultad :

	*/
	int fila;
	int columna;
	int dificultad;


}Board;


//Game:
typedef struct{


}Game;


//Params:
typedef struct{
	/*cantidad de cada tipo de barco en solo una mitad
	calamares gigantes, tormentas, etc
	*/	
	int basico;
	int 


}Params;


//Position
typedef struct{
	int fila;
	int columna;
	Ship ship;


}Position;



// Ship:
typedef struct{
	/*Armamento: teledirigido, onda expansiva, revelacion de terreno etc
	  resistencia
	  blindaje
	  tamaño de la embarcacion (cuantos cuadritos ocupa)*/
	  int tipo_ship;
	  int tamaño;
	  int blindaje;




}Ship;
