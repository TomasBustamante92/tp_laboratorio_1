/*
 ============================================================================

	Alumno: Tomas Sanchez de Bustamante
	Div: D
	TP: 2
	OS: Linux

 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "inputs.h"

int main(void) {
	setbuf(stdout,NULL);

	Employee employees[ELEMENTS];
	Employee auxEmployee;
	int option;
	int id;
	int lastId = 1002;

	initEmployees(employees, ELEMENTS);
	producto_hardCodear(employees, ELEMENTS); // BORRARRRR

	do{
		input_requestNumberInt(&option,	"-------------------------------------\n"
										"1. ALTAS \n"
										"2. MODIFICAR \n"
										"3. BAJA \n"
										"4. INFORMAR \n"
										"5. SALIR \n"
										"-------------------------------------\n"
										"Opcion: ",
										"-------------------------------------\n"
										"1. ALTAS \n"
										"2. MODIFICAR \n"
										"3. BAJA \n"
										"4. INFORMAR \n"
										"5. SALIR \n"
										"-------------------------------------\n"
										"ERROR. Opcion: ",
										1, 5);
		cleanScreen();

		switch(option)
		{
			case 1:
				if (auxAddEmployee(auxEmployee, employees, ELEMENTS, lastId) == 0)
				{
					lastId++;
				}
				break;
			case 2:

				if(noEmployeesOnSystem(employees, ELEMENTS) == 0)
				{
					modifyEmployee(employees, ELEMENTS);
				}
				else
				{
					cleanScreen();
					printf("\nNo hay empleados en el sistema\n");
				}

				break;
			case 3:
				if(noEmployeesOnSystem(employees, ELEMENTS) == 0)
				{
					printEmployees(employees, ELEMENTS);
					if(input_requestNumberInt(&id, "Ingrese ID para eliminar: ", "ERROR. Ingrese ID para eliminar [1000-2000]: ", 1000, 2000) == 0)
					{
						removeEmployee(employees, ELEMENTS, id);
					}
					else
					{
						cleanScreen();
						printf("\nERROR. ID no encontrado\n");
					}
				}
				else
				{
					cleanScreen();
					printf("\nNo hay empleados en el sistema\n");
				}
				break;
			case 4:
				if(noEmployeesOnSystem(employees, ELEMENTS) == 0)
				{
					informEmployees(employees, ELEMENTS);

				}
				else
				{
					cleanScreen();
					printf("\nNo hay empleados en el sistema\n");
				}
				break;
			case 5:
				cleanScreen();
				printf("\nAdios!");
				break;
		}

	}while(option != 5);





	return EXIT_SUCCESS;
}
