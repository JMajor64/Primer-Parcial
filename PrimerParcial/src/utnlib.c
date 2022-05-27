#include "utnlib.h"

int Get_Int(char mensaje [100])
{
	int aux;
	printf(mensaje);
	printf("\n");
	scanf("%d",&aux);
	return aux;
}

float Get_Float(char mensaje [100])
{
	float aux;
	printf(mensaje);
	printf("\n");
	scanf("%f",&aux);
	return aux;
}


int Utn_getInt(char mensaje [100], int min, int max, int* Num)
{
	int validate=0;
	int aux;
	aux=Get_Int(mensaje);
	if(aux>min&&aux<max)
	{
		*Num=aux;
		validate = 1;
	}
	return validate;
}

int Utn_getFloat(char mensaje [100], float min, float max, float* Num)
{
	int validate=0;
	float aux;
	aux=Get_Float(mensaje);
	if(aux>min&&aux<max)
	{
		*Num=aux;
		validate = 1;
	}
	return validate;
}


int Utn_getString(char mensaje[],char input [],int tamString)
{
	int validate=0;
    printf("%s", mensaje);
    printf("\n");
    fflush(stdin);
    fgets(input, tamString,stdin);
    if(input!=NULL)
    {
    	validate=1;
    }
    return validate;
}
