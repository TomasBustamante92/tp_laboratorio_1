/*
 * validaciones.c
 *
 *  Created on: Sep 8, 2021
 *      Author: user
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "ecuaciones.h"



/// @fn void menuOpcionUno(int, float)
/// @brief Muestra la opcion 1 del menu con una 'x' si no ingreso el numero
///
/// @param flagA si esta en 0 imprime A=x, si esta en 1 devuelve A= numero ingresado
/// @param numeroA numero ingresado
void menuOpcionUno(int flagA, float numeroA)
{
	int numeroInt = (int)numeroA;

	if(flagA == 0)
	{
		printf("1. Ingresar 1er operando (A=x)\n");
	} else if (flagA == 1)
	{

	    if(numeroA == numeroInt)
	    {
	        printf("1. Ingresar 1er operando (A=%d)\n",numeroInt);
	    }
	    else
	    {
	        printf("1. Ingresar 1er operando (A=%.2f)\n",numeroA);
	    }
	}
}


/// @fn void menuOpcionDos(int, float)
/// @brief Muestra la opcion 2 del menu con una 'x' si no ingreso el numero
///
/// @param flagB si esta en 0 imprime B=x, si esta en 1 devuelve B= numero ingresado
/// @param numeroB numero ingresado
void menuOpcionDos(int flagB, float numeroB)
{
	int numeroInt = (int)numeroB;

	if(flagB == 0)
	{
		printf("2. Ingresar 2do operando (B=y)\n");
	} else if (flagB == 1)
	{
	    if(numeroB == numeroInt)
	    {
	        printf("2. Ingresar 2do operando (B=%d)\n",numeroInt);
	    }
	    else
	    {
	        printf("2. Ingresar 2do operando (B=%.2f)\n",numeroB);
	    }
	}
}

/// @fn void menuOpcionTres(float, float, int, int)
/// @brief Muestra la opcion 3 del menu evaluando que calculos se pueden hacer
///
/// @param numeroA numero ingresado A
/// @param numeroB numero ingresado B
/// @param flagA en caso de que se haya ingresado el numero A devuelve 1
/// @param flagB en caso de que se haya ingresado el numero B devuelve 1
void menuOpcionTres(float numeroA, float numeroB, int flagA, int flagB)
{
	int numeroIntA = (int)numeroA;
	int numeroIntB = (int)numeroB;
	int sePuedeFactorialA = evaluarFactorial(numeroA);
	int sePuedeFactorialB = evaluarFactorial(numeroB);


	printf("3. Calcular todas las operaciones\n");

	if(flagA == 0 && flagB == 0)	// no se ingresa ningun numero
	{
		printf("\tNo se ingreso ningun numero\n");
	}
	else if (flagA == 1 && flagB == 0)	// se ingresa solo A
	{
		if(sePuedeFactorialA == 1)
		{
			printf("\t!!! falta valor de B\n\n");
			printf("\tCalcular el factorial (%d!)\n",numeroIntA);
		}
		else
		{
			printf("\t!!! falta valor de B\n\n");
			printf("\t!!!ERROR: No se puede calcular el factorial\n");
		}

	}
	else if (flagA == 0 && flagB == 1) // Se ingresa solo B
	{
		if(sePuedeFactorialB == 1)
		{
			printf("\t!!! falta valor de A\n\n");
			printf("\tCalcular el factorial (%d!)\n",numeroIntB);
		}
		else
		{
			printf("\t!!! falta valor de A\n\n");
			printf("\t!!!ERROR: No se puede calcular el factorial\n");
		}

	}
	else if (flagA == 1 && flagB == 1)	// Se ingresan los 2 numeros
	{
		if(numeroA == numeroIntA && numeroB == numeroIntB) // Num A = Int  //  Num B = Int
		{
			printf("\ta) Calcular la suma(%d+%d)\n",numeroIntA,numeroIntB);
			printf("\tb) Calcular la resta(%d-%d)\n",numeroIntA,numeroIntB);

			if(numeroIntB == 0)
			{
				printf("\tc) !!!ERROR: No se puede dividir por 0\n");
			}
			else
			{
				printf("\tc) Calcular la division(%d/%d)\n",numeroIntA,numeroIntB);
			}

			printf("\td) Calcular la multiplicacion(%d*%d)\n",numeroIntA,numeroIntB);
			printf("\te) Calcular el factorial A(%d!) B(%d!)\n",numeroIntA,numeroIntB);
		}
		else if(numeroA == numeroIntA && numeroB != numeroIntB) // Num A = Int  //  Num B = Float
		{
			printf("\ta) Calcular la suma(%d+%.2f)\n",numeroIntA,numeroB);
			printf("\tb) Calcular la resta(%d-%.2f)\n",numeroIntA,numeroB);
			printf("\tc) Calcular la division(%d/%.2f)\n",numeroIntA,numeroB);
			printf("\td) Calcular la multiplicacion(%d*%.2f)\n",numeroIntA,numeroB);
			printf("\te) Calcular el factorial A(%d!) B(No se puede)\n",numeroIntA);
		}
		else if(numeroA != numeroIntA && numeroB == numeroIntB) // Num A = Float  //  Num B = Int
		{
			printf("\ta) Calcular la suma(%.2f+%d)\n",numeroA,numeroIntB);
			printf("\tb) Calcular la resta(%.2f-%d)\n",numeroA,numeroIntB);

			if(numeroIntB == 0)
			{
				printf("\tc) !!!ERROR: No se puede dividir por 0\n");
			}
			else
			{
				printf("\tc) Calcular la division(%.2f/%d)\n",numeroA,numeroIntB);
			}

			printf("\td) Calcular la multiplicacion(%.2f*%d)\n",numeroA,numeroIntB);
			printf("\te) Calcular el factorial A(No se puede) B(%d!)\n",numeroIntB);
		}
		else if(numeroA != numeroIntA && numeroB != numeroIntB) // Num A = Float  //  Num B = Float
		{
			printf("\ta) Calcular la suma(%.2f+%.2f)\n",numeroA,numeroB);
			printf("\tb) Calcular la resta(%.2f-%.2f)\n",numeroA,numeroB);
			printf("\tc) Calcular la division(%.2f/%.2f)\n",numeroA,numeroB);
			printf("\td) Calcular la multiplicacion(%.2f*%.2f)\n",numeroA,numeroB);
			printf("\te) Calcular el factorial A(No se puede) B(No se puede)\n");
		}
	}

}

/// @fn void menuOpcionCuatro(float, float, int, int, float, float, float, float, long, long)
/// @brief Muestra la opcion 4 del menu con las respuestas de las ecuaciones
///
/// @param numeroA numero ingresado A
/// @param numeroB numero ingresado B
/// @param flagA flagA en caso de que se haya ingresado el numero A devuelve 1
/// @param flagB flagB en caso de que se haya ingresado el numero B devuelve 1
/// @param suma pasa el valor de la suma
/// @param resta pasa el valor de la resta
/// @param multiplicacion pasa el valor de la multiplicacion
/// @param division pasa el valor de la division
/// @param factorialA pasa el valor del factorial A
/// @param factorialB pasa el valor del factorial B
void menuOpcionCuatro(float numeroA, float numeroB, int flagA, int flagB, float suma, float resta, float multiplicacion, float division, long factorialA, long factorialB)
{
	int sumaInt = (int)suma;
	int restaInt = (int)resta;
	int multiplicacionInt = (int)multiplicacion;
	int divisionInt = (int)division;
	int sePuedeFactorialA = evaluarFactorial(numeroA);
	int sePuedeFactorialB = evaluarFactorial(numeroB);

	printf("4. Informar resultados\n");

	if (flagA == 1 && flagB == 0)	// se ingresa solo A
	{
		if(sePuedeFactorialA == 1)
		{
			printf("\ta) El factorial de A es: %ld\n",factorialA);
		}
		else
		{
			printf("\t!!!ERROR: No se puede calcular el factorial\n");
		}
	}
	else if (flagA == 0 && flagB == 1) // Se ingresa solo B
	{
		if(sePuedeFactorialB == 1)
		{
			printf("\ta) El factorial de B es: %ld\n",factorialB);
		}
		else
		{
			printf("\t!!!ERROR: No se puede calcular el factorial\n");
		}

	}
	else if (flagA == 1 && flagB == 1)	// Se ingresan los 2 numeros
	{
		if(suma == sumaInt)
		{
			printf("\ta) El resultado de A+B es: %d\n",sumaInt);
		}
		else
		{
			printf("\ta) El resultado de A+B es: %.2f\n",suma);
		}

		if(resta == restaInt)
		{
			printf("\tb) El resultado de A-B es: %d\n",restaInt);
		}
		else
		{
			printf("\tb) El resultado de A-B es: %.2f\n",resta);
		}


		if(division == divisionInt)
		{
			printf("\tc) El resultado de A/B es: %d\n",divisionInt);
		}
		else
		{
			if((int)numeroB == 0)
			{
				printf("\tc) !!!ERROR: No se puede dividir por 0\n");
			}
			else
			{
				printf("\tc) El resultado de A/B es: %.2f\n",division);
			}
		}

		if(multiplicacion == multiplicacionInt)
		{
			printf("\td) El resultado de A*B es: %d\n",multiplicacionInt);
		}
		else
		{
			printf("\td) El resultado de A*B es: %.2f\n",multiplicacion);
		}

		if(sePuedeFactorialA == 1 && sePuedeFactorialB == 1) // los 2 son Int
		{
			printf("\ta) El factorial de A es: %ld y el factorial de B es: %ld\n",factorialA,factorialB);
		}
		else if(sePuedeFactorialA == 1 && sePuedeFactorialB == 0) // solo A es Int
		{
			printf("\ta) El factorial de A es: %ld y el factorial de B es: (No se puede)\n",factorialA);
		}
		else if(sePuedeFactorialA == 0 && sePuedeFactorialB == 1) // solo B es Int
		{
			printf("\ta) El factorial de A es: (No se puede) y el factorial de B es: %ld\n",factorialB);
		}
		else
		{
			printf("\t!!!ERROR: No se puede calcular el factorial\n");
		}
	}
}










