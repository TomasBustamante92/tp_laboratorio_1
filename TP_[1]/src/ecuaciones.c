/*
 * ecuaciones.c
 *
 *  Created on: Sep 4, 2021
 *      Author: user
 */

#include <stdio_ext.h>
#include <stdlib.h>


/// @fn float sumar(float, float)
/// @brief suma 2 numeros flotantes
///
/// @param numero1
/// @param numero2
/// @return devuelve la suma de ambos numeros
float sumar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 + numero2;

	return resultado;

} // fin sumar


/// @fn float restar(float, float)
/// @brief resta 2 numeros flotantes
///
/// @param numero1
/// @param numero2
/// @return devuelve la resta de ambos numeros
float restar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 - numero2;

	return resultado;
} // fin restar


/// @fn float multiplicar(float, float)
/// @brief multiplica 2 numeros flotantes
///
/// @param numero1
/// @param numero2
/// @return devuelve la multiplicacion de ambos numeros
float multiplicar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 * numero2;

	return resultado;
} // fin multiplicar


/// @fn float dividir(float, float)
/// @brief divide 2 numeros flotantes
///
/// @param numero1
/// @param numero2
/// @return devuelve la division de ambos numeros
float dividir(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 / numero2;

	return resultado;
} // fin dividir


/// @fn long factorial(int)
/// @brief factorial de un numero entero
///
/// @param numero
long factorial(int numero)
{
	long resultado = 1;

	if (numero != 0 && numero != 1)
	{
		resultado = (long)numero * factorial(numero-1);
	}

	return resultado;

} // fin factorial

/// @fn int evaluarFactorial(float)
/// @brief evalua si se puede calcular el factorial
///
/// @param numero
/// @return devuelve un 1 si se puede calcular el factorial
int evaluarFactorial(float numero)
{
	int retorno = 0;
	int numeroInt = (int)numero;

	if(numeroInt == numero && numeroInt >= 0 && numeroInt < 21)
	{
		retorno = 1;
	}


	return retorno;
}




