/*
 * validaciones.h
 *
 *  Created on: Sep 8, 2021
 *      Author: user
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio_ext.h>
#include <stdlib.h>


int pedirNumeroEntero(char* mensaje, char* mensajeError, int min, int max);
float pedirNumeroFloat(char* mensaje, char* mensajeError, int min, int max);
void limpiarConsola(void);
void menuOpcionUno(int flagA, float numeroA);
void menuOpcionDos(int flagB, float numeroB);
void menuOpcionTres(float numeroA, float numeroB, int flagA, int flagB);
void menuOpcionCuatro(float numeroA, float numeroB, int flagA, int flagB, float suma, float resta, float multiplicacion, float division, long factorizacionA, long factorizacionB);


#endif /* MENU_H_ */
