
#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "r");

	if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "rb");

	if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* pEmployeeAux = employee_new();
	int id;

	if(pArrayListEmployee != NULL && pEmployeeAux != NULL)
	{
		retorno = 1;

		if(employee_requestNewEmployee(pEmployeeAux, &id) != -1)
		{
			// CONFIRMAR
			employee_printTopMenu();
			employee_printEmployee(*pEmployeeAux);
			if(input_confirmacion("Confirmar alta de empleado [si/no]: ", "ERROR. Confirmar alta de empleado [si/no]: ") != -1)
			{
				ll_add(pArrayListEmployee, pEmployeeAux);
				employee_setUltimoId(id);
				input_limpiarPantalla();
				printf("Empleado agregado con exito! \n");
				input_systemPause();
			}
			else
			{
				input_limpiarPantalla();
				printf("Alta cancelada! \n");
				input_systemPause();
			}
		}

	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int id;
	int ultimoId;
	int indice;
	int option;
	Employee* pEmployee = NULL;
	Employee employeeAux;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ListEmployee(pArrayListEmployee))
		{
			ultimoId = employee_getUltimoId();

			input_getNumero(&id, "Ingrese ID a modificar: ", "ERROR. Ingrese ID a modificar: ", 1, ultimoId);

			indice = employee_searchIndex(pArrayListEmployee, &id);

			if(indice != -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indice);

				if(pEmployee != NULL)
				{
					do{
						employeeAux = *pEmployee;
						employee_printTopMenu();
						employee_printEmployee(employeeAux);
						input_getNumero(&option, 	"\n\n"
													"1. Modificar Nombre \n"
													"2. Modificar horas trabajadas \n"
													"3. Modificar sueldo \n"
													"4. Atras \n"
													"- - - - - - - - - - - - - - \n"
													"Ingrese opcion: ",
													"\n\n"
													"1. Modificar Nombre \n"
													"2. Modificar horas trabajadas \n"
													"3. Modificar sueldo \n"
													"4. Atras \n"
													"- - - - - - - - - - - - - - \n"
													"ERROR. Ingrese opcion: ", 1, 4);

						switch(option)
						{
							case 1:
								employee_askName(&employeeAux);

								employee_printTopMenu();
								employee_printEmployee(employeeAux);
								if(input_confirmacion("Confirmar cambio de nombre [si/no]: ", "ERROR. Confirmar cambio de nombre [si/no]: ") != -1)
								{
									*pEmployee = employeeAux;
									input_limpiarPantalla();
									printf("Empleado modificado! \n");
									input_systemPause();
								}

								break;
							case 2:
								employee_askHorasTrabajadas(&employeeAux);

								employee_printTopMenu();
								employee_printEmployee(employeeAux);
								if(input_confirmacion("Confirmar cambio de horas trabajadas [si/no]: ", "ERROR. Confirmar cambio de horas trabajadas [si/no]: ") != -1)
								{
									*pEmployee = employeeAux;
									input_limpiarPantalla();
									printf("Empleado modificado! \n");
									input_systemPause();
								}
								break;
							case 3:
								employee_askSueldo(&employeeAux);

								employee_printTopMenu();
								employee_printEmployee(employeeAux);
								if(input_confirmacion("Confirmar cambio de sueldo [si/no]: ", "ERROR. Confirmar cambio de sueldo [si/no]: ") != -1)
								{
									*pEmployee = employeeAux;
									input_limpiarPantalla();
									printf("Empleado modificado! \n");
									input_systemPause();
								}
								break;
							case 4:
								input_limpiarPantalla();
								break;
						}

					} while(option != 4);
				}
				else
				{
					input_limpiarPantalla();
					printf("Error al cargar Empleado! \n");
					input_systemPause();
				}
			}
			else
			{
				input_limpiarPantalla();
				printf("ID no encontrado! \n");
				input_systemPause();
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int id;
	int ultimoId;
	int indice;
	Employee* pEmployee = NULL;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ListEmployee(pArrayListEmployee))
		{
			ultimoId = employee_getUltimoId();

			input_getNumero(&id, "Ingrese ID a eliminar: ", "ERROR. Ingrese ID a eliminar: ", 1, ultimoId);

			indice = employee_searchIndex(pArrayListEmployee, &id);

			if(indice != -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indice);

				if(pEmployee != NULL)
				{
					employee_printTopMenu();
					employee_printEmployee(*pEmployee);
					if(input_confirmacion("Confirmar baja de empleado [si/no]: ", "ERROR. Confirmar baja de empleado [si/no]: ") != -1)
					{
						retorno = -1;
						ll_remove(pArrayListEmployee, indice);
						input_limpiarPantalla();
						printf("Empleado eliminado con exito! \n");
						input_systemPause();
					}
					else
					{
						input_limpiarPantalla();
						printf("Baja cancelada! \n");
						input_systemPause();
					}
				}
				else
				{
					input_limpiarPantalla();
					printf("Error al cargar Empleado! \n");
					input_systemPause();
				}
			}
			else
			{
				input_limpiarPantalla();
				printf("ID no encontrado! \n");
				input_systemPause();
			}
		}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int len = ll_len(pArrayListEmployee);
	int i;
	Employee* pEmployeeAux;

	if(pArrayListEmployee != NULL && len > 0)
	{
		employee_printTopMenu();

		for(i=0 ; i<len ; i++)
		{
			pEmployeeAux = (Employee*) ll_get(pArrayListEmployee, i);
			employee_printEmployee(*pEmployeeAux);
		}
		retorno = 1;
	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		input_limpiarPantalla();
		printf("Cargando... \n");
		if(ll_sort(pArrayListEmployee, employee_sortByName, 1) == 0)
		{
			retorno = 1;
		}

	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "w");

	if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
	{
		parser_EmployeeToText(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "wb");

	if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
	{
		parser_EmployeeToBinary(pFile, pArrayListEmployee);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

