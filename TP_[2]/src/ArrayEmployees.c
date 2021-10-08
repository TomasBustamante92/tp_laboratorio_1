/*
 * ArrayEmployees.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Tomas Sanchez de Bustamante
 */


#include "ArrayEmployees.h"



/// @fn int initEmployees(Employee*, int)
/// @brief 	To indicate that all position in the array are empty,
/// 		this function put the flag(isEmpty) in TRUE in all
/// 		position of the array
///
/// @param list Employee* Pointer to array of employees
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length or NULL pointer]  -  (0) if Ok
int initEmployees(Employee* list, int len)
{
	int comeback = -1;
	int i;

	for(i=0 ; i<len ; i++)
	{
		list[i].isEmpty = TRUE;
		list[i].id = 0;
		comeback = 0;
	}

	return comeback;
} // r = initEmployees(arrayEmployees, ELEMENTS);




/// @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// @brief 	add in an existing list of employees the values received as parameters
/// 		in the first empty position
///
/// @param list Employee*
/// @param len int
/// @param id int
/// @param name[] char
/// @param lastName[] char
/// @param salary float
/// @param sector int
/// @return int Return(-1) if Error [Invalid length or NULL pointer or without
/// 		free space]  -  (0) if Ok
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],
		float salary, int sector)
{
	int comeback = -1;
	int index = findEmployeeById(list, len, id);

	if(list != NULL && name!= NULL && lastName != NULL)
	{
		if(index != -1)
		{
			list[index].id = id;
			strcpy(list[index].name, name);
			strcpy(list[index].lastName, lastName);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = FALSE;

			comeback = 0;
		}
	}

	return comeback;
} // r = addEmployee(arrayEmployees, ELEMENTS, id, name, lastName, salary, sector);




int auxAddEmployee(Employee auxEmployee, Employee* list, int len, int lastId)
{
	int comeback = -1;

	auxEmployee.id = lastId +1;
	if(input_requestStringOnlyLetters(auxEmployee.name, "\nIngrese nombre del empleado: ", "\nERROR. Ingrese nombre del empleado: ", 51) == -1)
	{
		printf("ERROR FATAL!");
	}
	if(input_requestStringOnlyLetters(auxEmployee.lastName, "Ingrese apellido del empleado: ", "ERROR. Ingrese apellido del empleado: ", 51) == -1)
	{
		printf("ERROR FATAL!");
	}

	if(input_requestNumberFloat(&auxEmployee.salary, "Ingrese salario: ", "ERROR. Ingrese salario: ", 0, 1000000) == -1)
	{
		printf("ERROR FATAL!");
	}

	if(input_requestNumberInt(&auxEmployee.sector, "Ingrese sector: ", "ERROR. Ingrese sector: (1-100)", 1, 100) == -1)
	{
		printf("ERROR FATAL!");
	}

	printTopMenu();
	printEmployee(auxEmployee);

	if(verifyConfirmation("\n¿Agregar este usuario? [si/no]: ", "\nERROR. ¿Agregar este usuario? [si/no]: ") == 0)
	{
		if(addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector) == 0)
		{
			cleanScreen();
			printf(	"\nNuevo empleado agregado!\n");
			comeback = 0;
		}
		else
		{
			cleanScreen();
			printf(	"\nERROR. La lista de empleados esta llena\n");
		}
	}
	else
	{
		cleanScreen();
		printf(	"\nAlta de emplado cancelada!\n");
	}

	return comeback;
}




/// @fn int findEmployeeById(sEmployee*, int, int)
/// @brief 	find an Employee by Id in returns the index position in array.
///
/// @param list sEmployee*
/// @param len int
/// @param id int
/// @return Return employee index position or (-1) if [Invalid length or NULL
/// 		pointer or employee not found]
int findEmployeeById(Employee* list, int len, int id)
{
	int i;
	int index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}

	return index;
} // int index = findEmployeeById(arrayEmployees, ELEMENTS, 9);



int modifyEmployee(Employee* list, int len)
{
	int comeback = -1;
	int index;
	int auxId;
	int option;
	Employee auxEmployee;

	printEmployees(list, len);
	if(input_requestNumberInt(&auxId, "Ingrese ID para modificar: ", "ERROR. Ingrese ID para modificar [1000-2000]: ", 1000, 2000) == -1)
	{
		printf("ERROR FATAL!");
	}

	index = searchEmployeeById(list, len, auxId);

	if(index != -1)
	{
		printTopMenu();
		printEmployee(list[index]);
		printf("\n");

		do
		{
			auxEmployee = list[index];
			if(input_requestNumberInt(&option,
									"-------------------------------------\n"
									"1. Modificar NOMBRE\n"
									"2. Modificar APELLIDO\n"
									"3. Modificar SALARIO\n"
									"4. Modificar SECTOR\n"
									"5. ATRAS\n"
									"-------------------------------------\n"
									"Ingrese opcion: ",
									"-------------------------------------\n"
									"1. Modificar NOMBRE\n"
									"2. Modificar APELLIDO\n"
									"3. Modificar SALARIO\n"
									"4. Modificar SECTOR\n"
									"5. ATRAS\n"
									"-------------------------------------\n"
									"ERROR. Ingrese opcion: ", 1, 5) == -1)
			{
				printf("ERROR FATAL!");
			}

			switch(option)
			{
				case 1:
					printTopMenu();
					printEmployee(list[index]);
					if(input_requestString(auxEmployee.name, "\nIngrese NUEVO nombre de empleado: ", "\nERROR. Ingrese NUEVO nombre de empleado: ", 51) == -1)
					{
						printf("ERROR FATAL!");
					}

					cleanScreen();
					printTopMenu();
					printEmployee(auxEmployee);

					if(verifyConfirmation("\n¿Modificar este usuario? [si/no]: ", "\nERROR. ¿Modificar este usuario? [si/no]: ") == 0)
					{
						strcpy(list[index].name, auxEmployee.name);
						cleanScreen();
						printf("\nEl empleado %s %s ha sido modificado!!\n\n", list[index].name, list[index].lastName);
						comeback = 0;
					}
					else
					{
						cleanScreen();
						printf("\nModificacion de empleado cancelada!\n\n");
					}

					break;
				case 2:
					printTopMenu();
					printEmployee(list[index]);
					if(input_requestString(auxEmployee.lastName, "\nIngrese NUEVO apellido de empleado: ", "\nERROR. Ingrese NUEVO apellido de empleado: ", 51) == -1)
					{
						printf("ERROR FATAL!");
					}

					cleanScreen();
					printTopMenu();
					printEmployee(auxEmployee);

					if(verifyConfirmation("\n¿Modificar este usuario? [si/no]: ", "\nERROR. ¿Modificar este usuario? [si/no]: ") == 0)
					{
						strcpy(list[index].lastName, auxEmployee.lastName);
						cleanScreen();
						printf("\nEl empleado %s %s ha sido modificado!!\n\n", list[index].name, list[index].lastName);
						comeback = 0;
					}
					else
					{
						cleanScreen();
						printf("\nModificacion de empleado cancelada!\n\n");
					}
					break;

				case 3:
					printTopMenu();
					printEmployee(list[index]);
					if(input_requestNumberFloat(&auxEmployee.salary, "\nIngrese NUEVO salario: ", "\nERROR. Ingrese NUEVO salario: ", 0, 1000000) == -1)
					{
						printf("ERROR FATAL!");
					}

					cleanScreen();
					printTopMenu();
					printEmployee(auxEmployee);

					if(verifyConfirmation("\n¿Modificar este usuario? [si/no]: ", "\nERROR. ¿Modificar este usuario? [si/no]: ") == 0)
					{
						list[index].salary = auxEmployee.salary;
						cleanScreen();
						printf("\nEl empleado %s %s ha sido modificado!!\n\n", list[index].name, list[index].lastName);
						comeback = 0;
					}
					else
					{
						cleanScreen();
						printf("\nModificacion de empleado cancelada!\n\n");
					}
					break;

				case 4:
					printTopMenu();
					printEmployee(list[index]);
					if(input_requestNumberInt(&auxEmployee.sector, "\nIngrese NUEVO sector: ", "\nERROR. Ingrese NUEVO sector: ", 1, 100) == -1)
					{
						printf("ERROR FATAL!");
					}

					cleanScreen();
					printTopMenu();
					printEmployee(auxEmployee);

					if(verifyConfirmation("\n¿Modificar este usuario? [si/no]: ", "\nERROR. ¿Modificar este usuario? [si/no]: ") == 0)
					{
						list[index].sector = auxEmployee.sector;
						cleanScreen();
						printf("\nEl empleado %s %s ha sido modificado!!\n\n", list[index].name, list[index].lastName);
						comeback = 0;
					}
					else
					{
						cleanScreen();
						printf("\nModificacion de empleado cancelada!\n\n");
					}
					break;

				case 5:
					printf("\n");
					break;
			}
		}while(option != 5);
	}
	else
	{
		cleanScreen();
		printf("\nError. Empleado no encontrado...\n\n");
	}

	return comeback;
}


/// @fn int removeEmployee(sEmployee*, int, int)
/// @brief  Remove a Employee by Id (put isEmpty Flag in 1)
///
/// @param list sEmployee*
/// @param len int
/// @param id int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or id can't
/// 		find an employee]  -  (0) if Ok
int removeEmployee(Employee* list, int len, int id)
{
	int index;
	int comeback = -1;

	index = searchEmployeeById(list, len, id);

	if(index != -1)
		{
			cleanScreen();
			printTopMenu();
			printEmployee(list[index]);

			if(verifyConfirmation("\n¿Eliminar este usuario? [si/no]: ", "\nERROR. ¿Eliminar este usuario? [si/no]: ") == 0)
			{
				list[index].isEmpty = TRUE;
				cleanScreen();
				printf("\nEl empleado %s %s ha sido eliminado!!\n", list[index].name, list[index].lastName);
				comeback = 0;
			}
			else
			{
				cleanScreen();
				printf("\nEliminacion de empleado cancelada!\n");
			}
		}
		else
		{
			cleanScreen();
			printf("\nERROR. Empleado no encontrado...\n\n");
		}


	return comeback;
} // r= removeEmployee(arrayEmployees, ELEMENTS, 20);



/// @fn int sortEmployees(sEmployee*, int, int)
/// @brief 	Sort the elements in the array of employees, the argument order
/// 		indicate UP or DOWN order
///
/// @param list	 sEmployee*
/// @param len int
/// @param order int [1] indicate UP  -  [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer]  -  (0) if Ok
int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int flagSwap;
	int newLen = len - 1;
	Employee auxEmployee;

	if(list != NULL)
	{
		do{
			flagSwap = 0;

			for(i=0 ; i<newLen ; i++)
			{
				if(list[i].isEmpty == FALSE && order == UP && strcmp(list[i].lastName, list[i+1].lastName) == 0) // If names are equal with UP order, sort by sector
				{
					if(list[i].sector < list[i+1].sector)
					{
						auxEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = auxEmployee;
						flagSwap = 1;
					}
				}
				else if (list[i].isEmpty == FALSE && order == UP && strcmp(list[i].lastName, list[i+1].lastName) < 0)
				{
					auxEmployee = list[i];
					list[i] = list[i+1];
					list[i+1] = auxEmployee;
					flagSwap = 1;
				}

				if(list[i].isEmpty == FALSE && order == DOWN && strcmp(list[i].lastName, list[i+1].lastName) == 0) // If names are equal with DOWN order, sort by sector
				{
					if(list[i].sector > list[i+1].sector)
					{
						auxEmployee = list[i];
						list[i] = list[i+1];
						list[i+1] = auxEmployee;
						flagSwap = 1;
					}
				}
				else if (list[i].isEmpty == FALSE && order == DOWN && strcmp(list[i].lastName, list[i+1].lastName) > 0)
				{
					auxEmployee = list[i];
					list[i] = list[i+1];
					list[i+1] = auxEmployee;
					flagSwap = 1;
				}
			} // fin for
			newLen--;
		}while(flagSwap);
	}
	return 0;
} // r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);



/// @fn int printEmployees(sEmployee*, int)
/// @brief print the content of employees array
///
/// @param list sEmployee*
/// @param length int
/// @return int
int printEmployees(Employee* list, int length)
{
	int comeback = -1;
	int i;

	printTopMenu();

	for(i=0 ; i<length ; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			printEmployee(list[i]);
			comeback = 0;
		}
	}

	printf(	"\n");

	return comeback;
} // r = printEmployees(arrayEmployees, ELEMENTS);  // SI DEVUELVE -1 HACER UN PRINT Q DIGA Q NO HAY NADIE



void printEmployee(Employee employee)
{
	printf("%-4d | %-19s | %-19s | %-19.2f | %-19d\n", employee.id, employee.name, employee.lastName, employee.salary, employee.sector);
}




int verifyConfirmation(char* message, char* error)
{
	int comeback = -1;
	char response[5];

	if(input_requestString(response, message, error, 5) == -1)
	{
		printf("ERROR FATAL!");
	}

	if(strcmp(response, "si") == 0)
	{
		comeback = 0;
	}


	return comeback;
}

int noEmployeesOnSystem(Employee* list, int len)
{
	int i;
	int noEmployees = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			noEmployees = 0;
			break;
		}
	}

	return noEmployees;
} // int index = findEmployeeById(arrayEmployees, ELEMENTS, 9);




int searchEmployeeById(Employee* list, int len, int id)
{
	int i;
	int index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE && list[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}


void producto_hardCodear(Employee productos[], int tam)
{
	int i;
	int ids[] = {1000, 1001, 1002};
	char descripciones[][51] = {"IPhone 12", "IPhone 13", "IPad Pro"};
	char apellido[][51] = {"jorge", "jamon", "alberto"};
	int nacionalidades[] = {2, 5, 7};
	int tipos[] = {3, 7, 4};

	for(i=0; i<3; i++)
	{
		productos[i].id = ids[i];
		strcpy(productos[i].name, descripciones[i]);
		strcpy(productos[i].lastName, apellido[i]);
		productos[i].salary = nacionalidades[i];
		productos[i].sector = tipos[i];
		productos[i].isEmpty = FALSE;
	}
}

void printTopMenu(void)
{
	printf(	"\n-----|---------------------|---------------------|---------------------|---------------------"
			"\n%-4s | %-19s | %-19s | %-19s | %-19s"
			"\n-----|---------------------|---------------------|---------------------|---------------------\n", "ID", "Nombre", "Apellido", "Salario", "Sector");
}

void cleanScreen(void)
{
	printf("\n\n\n\n--------------\n\n\n\n");
}

int informEmployees(Employee* list, int len)
{
	int comeback = -1;
	int option;

	do{
		if(input_requestNumberInt(&option, "-------------------------------------\n"
										"1. Ordenar empleados \n"
										"2. Salarios\n"
										"3. ATRAS\n"
										"-------------------------------------\n"
										"Ingrese opcion: ",
										"-------------------------------------\n"
										"1. Ordenar empleados\n"
										"2. Salarios\n"
										"3. ATRAS\n"
										"-------------------------------------\n"
										"ERROR. Ingrese opcion: ", 1, 3) == -1)
		{
			printf("ERROR FATAL!");
		}

		switch(option)
		{
			case 1:
				cleanScreen();
				showEmployees(list, len);
				comeback = 0;
				break;
			case 2:
				cleanScreen();
				salaries(list, len);
				comeback = 0;
				break;
			case 3:
				break;
		}
	} while (option != 3);

	cleanScreen();

	return comeback;
}

int showEmployees(Employee* list, int len)
{
	int comeback = -1;
	int option;


	do{
		if(input_requestNumberInt(&option, "-------------------------------------\n"
										"1. Orden ascendente\n"
										"2. Orden descendente\n"
										"3. ATRAS\n"
										"-------------------------------------\n"
										"Ingrese opcion: ",
										"-------------------------------------\n"
										"1. Orden ascendente\n"
										"2. Orden descendente\n"
										"3. ATRAS\n"
										"-------------------------------------\n"
										"ERROR. Ingrese opcion: ", 1, 3) == -1)
		{
			printf("ERROR FATAL!");
		}

		switch(option)
		{
			case 1:
				cleanScreen();
				sortEmployees(list, len, 1);
				printEmployees(list, len);
				comeback = 0;
				break;
			case 2:
				cleanScreen();
				sortEmployees(list, len, 0);
				printEmployees(list, len);
				comeback = 0;
				break;
			case 3:
				break;
		}

	} while (option != 3);

	cleanScreen();

	return comeback;
}

int salaries(Employee* list, int len)
{
	int comeback = -1;
	float total = salariesTotal(list, len);
	float average = salariesAverage(list, len);
	int quantity = quantityMoreThanAverage(list, len, average);

	printf(	"\n----------------|-----------------|------------------------------------------"
			"\n%-15s | %-15s | %-15s "
			"\n----------------|-----------------|------------------------------------------", "Total", "Promedio", "Empleados que superan el salario promedio");

	printf(	"\n%-15.2f | %-15.2f | %-15d "
			"\n----------------|-----------------|------------------------------------------\n", total, average, quantity);


	return comeback;
}

float salariesTotal(Employee* list, int len)
{
	float totalAux = 0;
	float total = -1;
	int count = 0;
	int i;

	for(i=0; i<len ; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			totalAux += list[i].salary;
			count++;
		}
	}

	if(count > 0)
	{
		total = totalAux;
	}

	return total;
}

float salariesAverage(Employee* list, int len)
{
	float totalAux = 0;
	float total = -1;
	int count = 0;
	int i;

	for(i=0; i<len ; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			totalAux += list[i].salary;
			count++;
		}
	}

	if(count > 0)
	{
		total = totalAux / count;
	}

	return total;
}

int quantityMoreThanAverage(Employee* list, int len, float average)
{
	int quantity = 0;
	int result = -1;
	int i;

	for(i=0; i<len ; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].salary > average)
			{
				quantity++;
			}
		}

		if(quantity > 0)
		{
			result = quantity;
		}

	return result;
}






