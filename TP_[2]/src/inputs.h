/*
 * inputs.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Tomas Sanchez de Bustamante
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#include <string.h>




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
int input_requestNumberInt(int* pResult, char* message, char* error, int min, int max);


/// @fn int input_requestNumberFloat(float*, char*, char*, int, int)
/// @brief prints a message asking a float number to the user, in case the min and max is correct it returns a float number.
/// 		 Otherwise it prints a error message and asks for a retry.
///
/// @param pResult returns a float number in case everything is correct
/// @param message message asking the user to enter a float number
/// @param error message in case the user has made a mistake
/// @param min minimum number the user can enter
/// @param max minimum number the user can enter
/// @return it returns [0]in case user has enter the number correctly, otherwise it returns [-1]
int input_requestNumberFloat(float* pResult, char* message, char* error, int min, int max);


/// @fn int input_getString(char*, char*, char*, int)
/// @brief Prints a message asking a string to the user, in case everything is correct it returns a string.
/// 		Otherwise it prints a error message and asks for a retry.
///
/// @param string returns a string in case everything is correct
/// @param message message asking the user to enter a string
/// @param errorMessage message in case the user has made a mistake
/// @param max maximum number of characters of the string
/// @return it returns [0]in case user has enter the string correctly, otherwise it returns [-1]
int input_requestString(char* string, char* message, char* errorMessage, int max);

#endif /* INPUTS_H_ */
