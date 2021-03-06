/*
 ============================================================================

	Alumno: Tomas Sanchez de Bustamante
	Div: D
	TP: 1
	OS: Linux

 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "ecuaciones.h"
#include "menu.h"
#include "input.h"


int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	float numeroA;
	float numeroB;
	int flagA = 0;
	int flagB = 0;
	int opcionTres = 0;
	int opcionCuatro = 0;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	long factorialA;
	long factorialB;


	do{
		// ---- MENU ---- //
		menuOpcionUno(flagA, numeroA);
		menuOpcionDos(flagB, numeroB);

		if(opcionTres == 0)
		{
			printf("3. Calcular todas las operaciones\n");
		}
		else
		{
			menuOpcionTres(numeroA, numeroB, flagA, flagB);
		}

		if(opcionCuatro == 0)
		{
			printf("4. Informar resultados\n");
		}
		else
		{
			if(opcionTres == 1)
			{
				menuOpcionCuatro(numeroA, numeroB, flagA, flagB, suma, resta, multiplicacion, division, factorialA, factorialB);
			}
			else
			{
				printf("!!!ERROR: falta calcular las operaciones\n");
			}
		}
		printf("5. Salir\n");

		input_getNumero(&opcion, "\nOpcion 1-5: ", "Error. Opcion 1-5:", 1, 5);

		printf("\n--------------\n");

		switch(opcion)
		{
		case 1:
			input_getFloat(&numeroA, "Numero A: ", "Error. Numero A:", -10000, 10000);
			flagA = 1;
			opcionTres = 0;
			opcionCuatro = 0;
			input_limpiarPantalla();
			break;
		case 2:
			input_getFloat(&numeroB, "Numero B: ", "Error. Numero B:", -10000, 10000);
			flagB = 1;
			opcionTres = 0;
			opcionCuatro = 0;
			input_limpiarPantalla();
			break;
		case 3:
			suma = sumar(numeroA, numeroB);
			resta = restar(numeroA, numeroB);
			multiplicacion = multiplicar(numeroA, numeroB);
			division = dividir(numeroA, numeroB);
			if(evaluarFactorial(numeroA) == 1)
			{
				factorialA = factorial(numeroA);
			}
			if(evaluarFactorial(numeroB) == 1)
			{
				factorialB = factorial(numeroB);
			}
			opcionTres = 1;
			input_limpiarPantalla();
			break;
		case 4:
			opcionCuatro = 1;
			input_limpiarPantalla();
			break;
		case 5:
			printf("\nAdios!");
			break;
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
} // fin main









