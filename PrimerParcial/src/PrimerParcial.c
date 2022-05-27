/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "censolib.h"

#define TAM 4
#define TAMC 3


VIVIENDA ArrayVivienda[TAM];
CENSISTA ArrayCensitas[TAMC]={{100,"Ana", 34, "1203-2345",0},
	 	 	 	 	 	     {101,"Juan", 24,"4301-54678",0},
	                         {102,"Sol", 47, "5902-37487",0}};
int main(void) {
	setbuf(stdout, NULL);
		int loaded=0;
		int operacion;
		int verificar=0;

		InitVivienda(ArrayVivienda,TAM);

		InicializarArrayId(ArrayCensitas,TAMC,50);

		do
		{
		    printf("\n");
		    printf("****************************************************************\n");
		    printf("\n");
			printf("1_Alta de Vivienda\n");
			printf("2_Modificar Vivienda\n");
			printf("3_Dar de baja Vivienda\n");
			printf("4_Mostrar Lista de Vivienda\n");
			printf("5_Mostrar Lista de Censistas\n");
			printf("6_Salir\n");
		    printf("\n");
		    printf("7_Censista con mas censos\n");
		    printf("\n");
		    printf("****************************************************************\n");
		    printf("\n");

		    Utn_getInt("Elija una opcion:\n",0,1000,&operacion);

		    system("@cls||clear");
			switch(operacion)
			{

		    case 1:
		    	verificar=Censolib_AltaVivienda(ArrayVivienda,TAM,ArrayCensitas,TAMC);
		    	if(verificar==0)
		    	{
		    		printf("***Error, no se ha encontrado lugar disponible***\n");
		    	}
		    	loaded=1;
		        break;

		    case 2:
		    	if(loaded){
		    		Censolib_Modificar(ArrayVivienda,TAM,ArrayCensitas,TAMC);
		    	}

		        break;

		    case 3:
		    	if(loaded){
		    		Censolib_BajaVivienda(ArrayVivienda,TAM,ArrayCensitas,TAMC);
		    		if(isEmpty(ArrayVivienda,TAM))
		    		{
		    			loaded=0;
		    		}
		    	}
		        break;

		    case 4:
		    	if(loaded){
		    		Ordenar_Viviendas(ArrayVivienda,TAM);

		    		Censolib_PrintViviendas(ArrayVivienda,TAM);
		    	}
					getch();
		        break;

		    case 5:
		    	Censolib_PrintCensistas(ArrayCensitas,TAMC,ArrayVivienda,TAM);
		    	getch();
		        break;

		    case 6:
		    	printf("Godbye!\n");
		    	getch();
		    	break;

		    case 7:
		    	CalcularMayor(ArrayCensitas,TAMC);
		    	getch();
		    	break;

		    default:
		    	printf("Opcion Invalida\n");
		    	getch();
		    	break;
			}
			system("@cls||clear");
		}while(operacion!=6);
	return EXIT_SUCCESS;
}
