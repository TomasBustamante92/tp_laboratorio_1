/*
 * input.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Tomas Sanchez de Bustamante
 */

#ifndef INPUT_H_
#define INPUT_H_


#include <stdio_ext.h>
#include <stdlib.h>



/// @fn void input_systemPause(void)
/// @brief pide al usuario que ingrese enter para continuar
///
void input_systemPause(void);


/// @fn void input_limpiarPantalla(void)
/// @brief imprime espacios y una barra para hacer el menu mas prolijo
///
void input_limpiarPantalla(void);


/// @fn int input_getNumero(int*, char*, char*, int, int)
/// @brief imprime mensaje pidiendo un numero entero al usuario, en caso de que se respete el minimo y el maximo, se devolvera un numero int,
/// 		 caso contrario se imprime un mensaje de error con su reintento
///
/// @param pResultado devuelve numero int en caso de que lo que se haya ingresado este correcto
/// @param mensaje mensaje para que el usuario ingrese un numero entero
/// @param error mensaje para que el usuario en caso de que haya contestado con un error
/// @param min numero minimo que pueda ingresar el usuario
/// @param max numero minimo que pueda ingresar el usuario
/// @return devuelve [0] en caso de que se haya ingresado un numero correctamente, caso contrario se devolvera un [-1]
int input_getNumero(int* pResultado, char* mensaje, char* error, int min, int max);

/// @fn int input_getFloat(float*, char*, char*, int, int)
/// @brief imprime mensaje pidiendo un numero flotante al usuario, en caso de que se respete el minimo y el maximo, se devolvera un numero flotante,
/// 		 caso contrario se imprime un mensaje de error con su reintento
///
/// @param pResultado devuelve numero flotante en caso de que lo que se haya ingresado este correcto
/// @param mensaje mensaje para que el usuario ingrese un numero flotante
/// @param error mensaje para que el usuario en caso de que haya contestado con un error
/// @param min numero minimo que pueda ingresar el usuario
/// @param max numero minimo que pueda ingresar el usuario
/// @return devuelve [0] en caso de que se haya ingresado un numero correctamente, caso contrario se devolvera un [-1]
int input_getFloat(float* pResultado, char* mensaje, char* error, int min, int max);



#endif /* INPUT_H_ */
