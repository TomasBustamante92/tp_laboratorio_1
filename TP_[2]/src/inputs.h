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
#include <ctype.h>

/// @fn void stringToLowerCase(char*)
/// @brief Change all the characters to lower case
///
/// @param string string to verify
void stringToLowerCase(char* string);

/// @fn int validateLetters(char*, int)
/// @brief checks that the string only contains letters
///
/// @param string
/// @param len
/// @return it returns [0] in case user has enter only letters, otherwise it returns [-1]
int validateLetters(char* string, int len);

/// @fn int input_requestStringOnlyLetters(char*, char*, char*, int)
/// @brief Prints a message asking a string to the user, in case everything is correct it returns a string validating its only letters.
/// 		Otherwise it prints a error message and asks for a retry.
///
/// @param string returns a string in case everything is correct
/// @param message message asking the user to enter a string
/// @param errorMessage message in case the user has made a mistake
/// @param max maximum number of characters of the string
/// @return it returns [0]in case user has enter the string correctly, otherwise it returns [-1]
int input_requestStringOnlyLetters(char* string, char* message, char* errorMessage, int max);

/// @fn int input_getNumero(int*, char*, char*, int, int)
/// @brief prints a message asking an int number to the user, in case the min and max is correct it returns an int number.
/// 		 Otherwise it prints a error message and asks for a retry.
///
/// @param pResult returns an int number in case everything is correct
/// @param message message asking the user to enter an int number
/// @param error message in case the user has made a mistake
/// @param min minimum number the user can enter
/// @param max minimum number the user can enter
/// @return it returns [0]in case user has enter the number correctly, otherwise it returns [-1]
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
