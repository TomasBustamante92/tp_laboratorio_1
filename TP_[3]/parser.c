
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	char id[10];
	char nombre[128];
	char horasTrabajadas[100];
	char sueldo[100];
	Employee* pEmployee = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, nombre, horasTrabajadas, sueldo);
			pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListEmployee, pEmployee);
		}

		retorno = 1;
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee employeeAux;
	Employee* pEmployee = NULL;


	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(fread(&employeeAux, sizeof(employeeAux), 1, pFile))
		{
			pEmployee = employee_new();
			*pEmployee = employeeAux;
			ll_add(pArrayListEmployee, pEmployee);
		}

		retorno = 1;
	}

    return retorno;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	int len = ll_len(pArrayListEmployee);
	Employee* pEmployee = NULL;

	if(pFile != NULL && pArrayListEmployee != NULL && len > 0)
	{
		fprintf(pFile, "%s,%s,%s,%s\n", "ID", "Nombre", "HorasTrabajadas", "Sueldo");
		for(i=0 ; i<len ; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			fprintf(pFile, "%d,%s,%d,%d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);
		}

		retorno = 1;
	}

    return retorno;
}


int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int i;
	int len = ll_len(pArrayListEmployee);
	Employee* employee;

	if(pFile != NULL && pArrayListEmployee != NULL && len > 0)
	{

		for(i=0 ; i<len ; i++)
		{
			employee = (Employee*)ll_get(pArrayListEmployee, i);
			fwrite(employee, sizeof(*employee), 1, pFile);
		}

		retorno = 1;
	}

    return retorno;
}
