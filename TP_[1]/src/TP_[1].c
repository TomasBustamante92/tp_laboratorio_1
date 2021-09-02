/*
 ============================================================================

	Alumno: Tomas Sanchez de Bustamante
	Div: D
	TP: 1

 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>

int sumar(int numero1, int numero2);
int restar(int numero1, int numero2);
int multiplicar(int numero1, int numero2);
float dividir(int numero1, int numero2);
int factorial (int numero);


int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	char opcionLetra;
	int numeroA;
	int numeroB;
	int flagA = 0;
	int flagB = 0;
	int flagSuma = 0;
	int flagResta = 0;
	int flagMultiplicar = 0;
	int flagDividir = 0;
	int flagFactorial = 0;

	do{

		if(flagA == 0)
		{
			printf("1. Ingresar 1er operando (A=x)\n");
		} else if (flagA == 1)
		{
			printf("1. Ingresar 1er operando (A=%d)\n",numeroA);
		}
		if(flagB == 0)
		{
			printf("2. Ingresar 2do operando (B=y)\n");
		} else if (flagB == 1)
		{
			printf("2. Ingresar 2do operando (B=%d)\n",numeroB);
		}
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");

		printf("\nOpcion 1-5: ");
		__fpurge(stdin);
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			printf("Numero A: ");
			__fpurge(stdin);
			scanf("%d",&numeroA);
			flagA = 1;
			break;
		case 2:
			printf("Numero B: ");
			__fpurge(stdin);
			scanf("%d",&numeroB);
			flagB = 1;
			break;
		case 3:
			if(flagA == 1 && flagB == 1)
			{
				printf("3. Calcular todas las operaciones:\n");
				printf("\ta) Calcular la suma\n");
				printf("\tb) Calcular la resta\n");
				printf("\tc) Calcular la division\n");
				printf("\td) Calcular la multiplicacion\n");
				printf("\te) Calcular el factorial\n");
			}

			printf("\nOpcion a-e: ");
			__fpurge(stdin);
			scanf("%c",&opcionLetra);

			// AGREGAR LOS FLAGS PARA CADA CUENTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!!!!

			break;
		case 4:
			if(flagA == 1 && flagB == 1)
			{
				printf("4. Informar resultados\n");
				if(flagSuma == 0)
				{
					printf("\ta) El resultado de %d+%d es: ?\n",numeroA,numeroB);
				} else if (flagSuma == 1)
				{
					// AGREGAR FUNCION SUMAAAA!!!!!
				}
				if(flagResta == 0)
				{
					printf("\tb) El resultado de %d-%d es: ?\n",numeroA,numeroB);
				} else if (flagResta == 1)
				{
					// AGREGAR FUNCION RESTAAAR!!!!!
				}
				if(flagDividir == 0)
				{
					printf("\tc) El resultado de %d/%d es: ? o No es posible dividir por cero\n",numeroA,numeroB);
				} else if (flagDividir == 1)
				{
					// AGREGAR FUNCION DIVIDIR!!!!!
				}
				if(flagMultiplicar == 0)
				{
					printf("\td) El resultado de %d*%d es: ?\n",numeroA,numeroB);
				} else if (flagMultiplicar == 1)
				{
					// AGREGAR FUNCION MULTIPLICAR!!!!!
				}
				if(flagFactorial == 0)
				{
					printf("\te) El factorial de %d es: r1 y el factorial de %d es: r2\n\n",numeroA,numeroB);
				} else if (flagFactorial == 1)
				{
					// AGREGAR FUNCION FACTORIAL!!!!!
				}
			} else {
				printf("ERROR. no se ingreso alguno de los numeros.\n");
			}
			break;
		case 5:
			printf("\n\tAdios!");
			break;

		} // fin switch

	} while (opcion != 5);

	// ----- FIN DEL WHILE ----- //


	return EXIT_SUCCESS;
} // fin main



int sumar(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 + numero2;

	return resultado;
} // fin sumar



int restar(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 - numero2;

	return resultado;
} // fin restar



int multiplicar(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 / numero2;

	return resultado;
} // fin multiplicar



float dividir(int numero1, int numero2)
{
	float resultado;

	resultado = (float)numero1 / numero2;

	return resultado;
} // fin dividir

int factorial (int numero)
{
	int resultado;

	resultado = numero;

	for(int i=1 ; i<numero ; i++)
	{
		resultado = resultado * i;
	}

	return resultado;
} // fin factorial














