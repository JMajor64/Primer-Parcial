#include <stdio.h>
#include <string.h>
/*
 * utnlib.h
 *
 *  Created on: 8 abr 2022
 *      Author: Agus
 */


#ifndef UTNLIB_H_
#define UTNLIB_H_

int Get_Int(char mensaje [100]);
float Get_Float(char mensaje [100]);
int Utn_getInt(char mensaje [100], int min, int max, int* Num);
int Utn_getFloat(char mensaje [100], float min, float max, float* Num);
int Utn_getString(char mensaje[],char input [],int tamString);


#endif /* UTNLIB_H_ */
