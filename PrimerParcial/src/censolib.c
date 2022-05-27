/*
 * censolib.c
 *
 *  Created on: 24 may 2022
 *      Author: Mansilla Agustin
 */
#include "censolib.h"

void printVivienda(VIVIENDA vivienda)
{
	printf("ID: %d\n",vivienda.idVivienda);
	printf("Direccion: %s",vivienda.calle);
	printf("Cantidad de habitantes: %d\n",vivienda.habitantes);
	printf("Cantidad de habitaciones: %d\n",vivienda.cantidadHabitaciones);
	print_type(vivienda.tipoVivienda);
}

void print_type(int tipoVivienda)
{
	printf("Tipo: ");
	switch(tipoVivienda)
	{
	case 1:
		printf("Casa\n");
		break;
	case 2:
		printf("Departamento\n");
		break;
	case 3:
		printf("Casilla\n");
		break;
	case 4:
		printf("Rancho\n");
		break;
	default:
		printf("***Error, tipo invalido***\n");
		break;
	}
}

int InitVivienda(VIVIENDA* Arrayviviendas,int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		(Arrayviviendas+i)->idVivienda=2000+i;
		(Arrayviviendas+i)->legajoCensista=0;
	}
	return 1;
}

void Censolib_PrintViviendas(VIVIENDA* Arrayviviendas,int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		if((Arrayviviendas+i)->legajoCensista)
		{
			printVivienda(*(Arrayviviendas+i));
			printf("\n");
		}
	}
}

void PrintCensista(CENSISTA censista)
{
	printf("Legajo: %d\n",censista.legajoCensista);
	printf("Nombre: %s\n",censista.nombre);
	printf("Edad: %d\n",censista.edad);
	printf("Telefono: %s\n",censista.telefono);
	printf("\n");
	printf("Viviendas Censadas: %d\n",censista.cantViviendas);
}

void Get_Direccion(VIVIENDA* vivienda)
{
	int i=0;
	while(i==0)
	{
		i= Utn_getString("ingrese la direccion: ",vivienda->calle,sizeof(vivienda->calle));
	}

}
void Get_Habitantes(VIVIENDA* vivienda)
{
	int i=0;
	while(i==0)
	{
		i = Utn_getInt("Ingrese la cantidad de Habitantes",0,50,&vivienda->habitantes);
	}

}
void Get_Habitaciones(VIVIENDA* vivienda)
{
	int i=0;
	while(i==0)
	{
		i=Utn_getInt("Ingrese la cantidad de habitaciones",0,50,&vivienda->cantidadHabitaciones);
	}
}
void Get_tipoVivienda(VIVIENDA* vivienda)
{
	int i=0;
	while(i==0)
	{
		i=Utn_getInt("Ingrese el tipo de vivienda:\n1: Casa \n2: Departamento \n3: Casilla \n4: Rancho",0,5,&vivienda->tipoVivienda);
	}
}

int Get_Legajo(CENSISTA* listC,int tamC)
{
	int i;
	int validate=0;
	int Censista;
	int legajo;
	ingresar:
	printf("Seleccione al censista de la vivienda: \n");
	for(i=0;i<tamC;i++)
	{
		printf("\n");
		PrintCensista(*(listC+i));
	}
	validate=Utn_getInt("",0,tamC+1,&Censista);
	if(validate==0)
	{
		printf("****Error, Censista invalido****\n");
		getch();
		goto ingresar;
	}else{
		(listC+Censista-1)->cantViviendas = (listC+Censista-1)->cantViviendas + 1;
		legajo=(listC+Censista-1)->legajoCensista;
	}
	return legajo;
}

int Censolib_AltaVivienda(VIVIENDA* listVivienda,int tam,CENSISTA* listCensista,int tamC)
{
	int validate=0;
	CENSISTA* auxC;
	int i;
	int j;
	for (i=0;i<tam;i++)
	{
		if((listVivienda+i)->legajoCensista==0)
		{
			Get_Direccion((listVivienda+i));
			Get_tipoVivienda((listVivienda+i));
			Get_Habitantes((listVivienda+i));
			Get_Habitaciones((listVivienda+i));
			printf("\n");

			(listVivienda+i)->legajoCensista=Get_Legajo(listCensista,tamC);

			BuscarCensista(listCensista,tamC,(listVivienda+i)->legajoCensista,&auxC);

			for(j=0;j<50;j++)
			{
				if(auxC->ArrayIds[j]==0)
				{
					auxC->ArrayIds[j]=(listVivienda+i)->idVivienda;
					break;
				}
			}


			validate=1;
			break;
		}
	}
	return validate;
}

int BuscarViviendaPorId(VIVIENDA* list,int tam,int id,CENSISTA* listC, int tamC)
 {
	 int i;
	 int j;
	 int Return=-1;
	 for(i=0;i<tam;i++)
	 	 {
	 		 if((list+i)->idVivienda==id)
	 		 {
	 			 for(j=0;j<tamC;j++)
	 			 {
	 				if((list+i)->legajoCensista==(listC+j)->legajoCensista)
	 				{
	 					 Return=i;
	 					 break;
	 				}
	 			 }
	 			 if(Return==i)
	 			 {
	 				 break;
	 			 }
	 		 }
	 	 }
	 	 return Return;
 }

int BuscarVivienda(VIVIENDA* list,int tam,VIVIENDA **pVivienda,CENSISTA* listC, int tamC)
{
	int idVivienda;
	int valido;
	retorno:
	Utn_getInt("Ingrese el Id de la vivienda a Buscar",0,tam+2000,&idVivienda);

	valido=BuscarViviendaPorId(list,tam,idVivienda,listC,tamC);
	if(valido!=-1)
	{
		*pVivienda=(list+valido);
	}
	else{
		printf("***Error, Id no encontrado***\n");
		getch();
		system("@cls||clear");
		goto retorno;
	}
	return valido;
}

void BuscarCensista(CENSISTA* listCensista,int tamC,int Legajo,CENSISTA **pCensista)
{
	int i;
	for(i=0;i<tamC;i++)
	{
		if((listCensista+i)->legajoCensista==Legajo)
		{
			*pCensista=(listCensista+i);
		}
	}
}

int Modificar(VIVIENDA* pVivienda,CENSISTA* listC,int tamC)
 {
	 int  i;
	 CENSISTA* auxC;
	 int aux;
	 do
	 {
		 BuscarCensista(listC,tamC,pVivienda->legajoCensista,&auxC);
		 system("@cls||clear");

		 printf("\n");
		 printf("****************************************************************\n");
		 printf("Vista previa de la Vivienda:\n");
		 printf("\n");
		 printVivienda(*pVivienda);
		 printf("\n");
		 printf("Censista Asignado\n");
		 PrintCensista(*auxC);
		 printf("\n");
		 printf("****************************************************************\n");
		 printf("\n");
		 printf("Ingrese el campo que desea modificar:\n");
		 printf("1: Direccion\n");
		 printf("2: Tipo de vivienda\n");
		 printf("3: Cantidad de habitantes\n");
		 printf("4: Cantidad de habitaciones\n");
		 printf("5: Censista:\n");
		 printf("6: Salir\n");

		 Utn_getInt("",0,7,&i);

		 system("@cls||clear");

		 switch(i)
		 {
		 	 case 1:
		 		Get_Direccion((pVivienda));
		 		 break;
		 	 case 2:
		 		Get_tipoVivienda((pVivienda));
		 		 break;
		 	 case 3:
		 		Get_Habitantes((pVivienda));
		 		 break;
		 	 case 4:
		 		Get_Habitaciones((pVivienda));
		 		 break;
		 	 case 5:
				aux=Get_Legajo(listC,tamC);
		 		(pVivienda)->legajoCensista=aux;
		 		 break;
		 }
	 }while(i!=6);
	 return i;
 }

void Censolib_Modificar(VIVIENDA* aViviendas,int tam,CENSISTA* aCensistas,int tamC)
{
	VIVIENDA* aux;

	BuscarVivienda(aViviendas,tam,&aux,aCensistas,tamC);

	Modificar(aux,aCensistas,tamC);
}

void Censolib_BajaVivienda(VIVIENDA* aViviendas,int tam,CENSISTA* aCensistas,int tamC)
{
	VIVIENDA* aux;
	CENSISTA* auxC;
	int opcion=0;
	int validacion=0;

	BuscarVivienda(aViviendas,tam,&aux,aCensistas,tamC);

	//(para decrementar la cantidad de viviendas censadas)
	BuscarCensista(aCensistas,tamC,aux->legajoCensista,&auxC);

	 system("@cls||clear");

	 printf("\n");
	 printf("****************************************************************\n");
	 printf("Vista previa de la Vivienda:\n");
	 printf("\n");
	 printVivienda(*aux);
	 printf("\n");
	 printf("****************************************************************\n");
	 printf("\n");
	 printf("Desea dar esta vivienda de baja?\n");
	 printf("1: Si\n");
	 printf("2: No\n");

	 while(validacion==0)
	 {
		 validacion=Utn_getInt("",0,3,&opcion);
	 }
	 switch(opcion)
	 {
		 case 1:
			 aux->legajoCensista=0;
			 auxC->cantViviendas=auxC->cantViviendas-1;
			 printf("Vivienda eliminada\n");
			 getch();
			 break;
		 case 2:
			 printf("Eliminacion cancelada\n");
			 getch();
			 break;
	 }
}

int isEmpty(VIVIENDA* list,int tam)
{
	int i;
	int isEmpty=1;
	for(i=0;i<tam;i++)
	{
		if((list+i)->legajoCensista)
		{
			isEmpty=0;
			break;
		}
	}
	return isEmpty;
}

void PrintViviendasCensadas(VIVIENDA* listV,int tam,CENSISTA* listC,int tamC,CENSISTA censista,int CantArrayId)
{
	int i;
	int index;
	for(i=0;i<CantArrayId;i++)
	{
		index=BuscarViviendaPorId(listV,tam,censista.ArrayIds[i],listC,tamC);
		if((listV+index)->legajoCensista!=0)
		{
			printf("\n");
			printVivienda(*(listV+index));
		}
	}
}


void InicializarArrayId(CENSISTA* listC,int tamC,int tamArrray)
{
	int i;
	int j;
	for(i=0;i<tamC;i++)
	{
		for(j=0;j<tamArrray;j++)
		{
			(listC+i)->ArrayIds[j]=0;
		}
	}
}

void Censolib_PrintCensistas(CENSISTA* listC,int tamC,VIVIENDA* listV,int tamV)
{
	int i;
	for(i=0;i<tamC;i++)
	{
		printf("*****************************************");
		printf("\n");
		PrintCensista(*(listC+i));
		printf("\n");
		PrintViviendasCensadas(listV,tamV,listC,tamC,*(listC+i),50);
		printf("*****************************************");
	}
}


void Swap_Viviendas(VIVIENDA* Vivienda1, VIVIENDA* Vivienda2)
{
	VIVIENDA Aux;

	Aux=*Vivienda1;
	*Vivienda1=*Vivienda2;
	*Vivienda2=Aux;
}

void Ordenar_Viviendas(VIVIENDA* list,int tam)
{
	int i;
	int j;
	for(i=0;i<tam;i++)
	{
		for(j=i+1;j<tam;j++)
		{
			if((list+i)->legajoCensista!=0 && (list+j)->legajoCensista!=0)
			{
				if(strcmp((list+i)->calle,(list+j)->calle)>0)
				{
					Swap_Viviendas((list+i),(list+j));
				}
				else
				{
					if(strcmp((list+i)->calle,(list+j)->calle)==0)
					{
						if((list+i)->habitantes>(list+j)->habitantes)
						{
							Swap_Viviendas((list+i),(list+j));
						}
					}
				}
			}

		}
	}
}

void CalcularMayor(CENSISTA* ListaC,int tamC)
{
	int i;
	CENSISTA mayor;
	mayor.cantViviendas=0;
	for(i=0;i<tamC-1;i++)
	{
		if((ListaC+i)->cantViviendas>(ListaC+i+1)->cantViviendas && (ListaC+i)->cantViviendas>mayor.cantViviendas)
		{
			mayor=*(ListaC+i);
		}
		else{
			if((ListaC+i+1)->cantViviendas>(ListaC+i)->cantViviendas && (ListaC+i+1)->cantViviendas>mayor.cantViviendas)
			{
				mayor=*(ListaC+i+1);
			}
		}
	}
	printf("El Censista con mas censos realizados es:\n");
	PrintCensista(mayor);
}
