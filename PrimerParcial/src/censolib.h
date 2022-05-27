/*
 * censolib.h
 *
 *  Created on: 24 may 2022
 *      Author: Mansilla Agustin
 */

#include "utnlib.h"

typedef struct{
	int idVivienda;
	char calle[25];//direccion del domicilio
	int habitantes;
	int cantidadHabitaciones;
	int tipoVivienda;//(1: casa; 2: dpto; 3: casilla; 4: Rancho)
	int legajoCensista;
}VIVIENDA;

typedef struct{
	int legajoCensista;
	char nombre[16];
	int edad;
	char telefono[11];
	int cantViviendas;
	int ArrayIds[50];
}CENSISTA;

/************************************Funciones de menu*******************************************/

/*Funciones Censolib:
 * Son las funciones que van el en main y permiten el manejo de la informacion
 * AltaVivienda: Busca una posicion vacia en el array y solicita los campos con las funciones Get, si no encuentra espacio, retorna un 0
 * PrintViviendas: Recibe la lista de Viviendas e imprime aquellas que tengan contenido, lo cual es verificado por el campo LegajoCensista
 * Modificar: solicita una vivienda que es buscada por su Id y despliega un menu para seleccionar el campo que se desea cambiar
 * BajaVivienda:Igual que Modificar, Busca la vivenda por Id y elimina su legajo, haciendo que no sea contemplada por las demas funciones
 * PrintCensistas: Imprime todos los censistas cargados*/
int Censolib_AltaVivienda(VIVIENDA* listVivienda,int tam,CENSISTA* listCensista,int tamC);
void Censolib_PrintViviendas(VIVIENDA* Arrayviviendas,int tam);
void Censolib_Modificar(VIVIENDA* aViviendas,int tam,CENSISTA* aCensistas,int tamC);
void Censolib_BajaVivienda(VIVIENDA* aViviendas,int tam,CENSISTA* aCensistas,int tamC);
void Censolib_PrintCensistas(CENSISTA* listC,int tamC,VIVIENDA* listV,int tamV);

/*************************************************************************************************/

/**********************************Funciones de manejo de datos***********************************/

//Funciones Print
void printVivienda(VIVIENDA vivienda);
void print_type(int tipoVivienda);
void PrintCensista(CENSISTA censista);


/*InitVivienda:
 * La funcion InitVivienda inicializa el Array de Viviendas escribiendo el numero de Id en cada espacio
 * La funcion tambien escribe un 0 en el campo LegajoCensista, el cual tambien se utiliza para validar si la vivienda esta vacia*/
int InitVivienda(VIVIENDA* Arrayviviendas,int tam);

/*Funciones Get:
 * Las funciones Get reciben como patametro el puntero a la vivienda y piden el ingreso del campo
 * Una vez el dato ingresado es validado, le asignan el valor al campo de la vivienda
 * La funcion Get_legajo recibe como parametro la lista de censistas y retorna el legajo del censista solicitado*/
void Get_Direccion(VIVIENDA* vivienda);
void Get_Habitantes(VIVIENDA* vivienda);
void Get_Habitaciones(VIVIENDA* vivienda);
void Get_tipoVivienda(VIVIENDA* vivienda);
int Get_Legajo(CENSISTA* censista,int tamC);

/*Funciones Search:
 * BuscarViviendaPorId: Recibe la lista de censistas, de viviendas y el id deseado, busca el id de la vivienda y luego verifica que su LegajoCensista sea valido y retorna el indice de la vivienda
 * BuscarVivienda: Solicita el ingreso del Id que debe buscar y emplea la funcion BuscarViviendaPorId, en caso de no encontrarlo, vuelve a solicitarlo, si lo encuentra devuelve un puntero por referencia a la direccion de memoria de la vivienda que se pidió buscar
 * BuscarCensista: Al igual que BuscarVivienda, BuscarCensista devuelve un puntero por referencia a la direccion del censista solicitado*/
int BuscarViviendaPorId(VIVIENDA* list,int tam,int id,CENSISTA* listC, int tamC);
int BuscarVivienda(VIVIENDA* list,int tam,VIVIENDA **pVivienda,CENSISTA* listC, int tamC);
void BuscarCensista(CENSISTA* listCensista,int tamC,int Legajo,CENSISTA **pCensista);


//isEmpty: Se usa luego de BajaVivienda para verificar si todos los elementos fueron removidos
int isEmpty(VIVIENDA* list,int tam);


void Swap_Viviendas(VIVIENDA* Vivienda1, VIVIENDA* Vivienda2);

void Ordenar_Viviendas(VIVIENDA* list,int tam);

void CalcularMayor(CENSISTA* ListaC,int tamC);

void InicializarArrayId(CENSISTA* listC,int tamC,int tamArrray);

/*************************************************************************************************/
