#include "Employee.h"


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* employeeAux = NULL;
	int id;
	int horasTrabajadas;
	int sueldo;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		employeeAux = employee_new();

		if(employeeAux != NULL)
		{
			id = atoi(idStr);
			horasTrabajadas = atoi(horasTrabajadasStr);
			sueldo = atoi(sueldoStr);

			employee_setId(employeeAux, id);
			employee_setNombre(employeeAux, nombreStr);
			employee_setHorasTrabajadas(employeeAux, horasTrabajadas);
			employee_setSueldo(employeeAux, sueldo);
		}
	}

	return employeeAux;
}


void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}


Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}


void employee_printTopMenu(void)
{
	input_limpiarPantalla();
	printf("%-6s %-20s %-20s %-20s \n"
			"--------------------------------------------------------- \n","ID", "Nombre", "Horas Trabajadas", "Sueldo");
}

void employee_printEmployee(Employee employee)
{
	printf("%-6d %-20s %-20d %-20d \n", employee.id, employee.nombre, employee.horasTrabajadas, employee.sueldo);
}

int employee_sortByName(void* employee1,void* employee2)
{
	int retorno;
	Employee* employeeAux1 = (Employee*)employee1;
	Employee* employeeAux2 = (Employee*)employee2;
	char nombre1[128];
	char nombre2[128];

	if(employee1 != NULL && employee2 != NULL && employeeAux1 != NULL && employeeAux2 != NULL)
	{
		if(employee_getNombre(employeeAux1, nombre1) == 0 && employee_getNombre(employeeAux2, nombre2) == 0 )
		{
			retorno = strcmp(nombre1, nombre2);

			if(retorno < 0)
			{
				retorno = -1;
			}
			else if(retorno > 0)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int employee_sortBySalary(void* pEmployee1, void* pEmployee2)
{
	int retorno = 0;
	Employee* pEmployeeAux1 = NULL;
	Employee* pEmployeeAux2 = NULL;
	pEmployeeAux1 = (Employee*)pEmployee1;
	pEmployeeAux2 = (Employee*)pEmployee2;
	int sueldo1;
	int sueldo2;

	if(pEmployeeAux1 != NULL && pEmployeeAux2 != NULL)
	{

		if(employee_getSueldo(pEmployeeAux1, &sueldo1) == 0 && employee_getSueldo(pEmployeeAux2, &sueldo2) == 0)
		{
			if(sueldo1 > sueldo2)
			{
				retorno = 1;
			}
			else if(sueldo1 < sueldo2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_sortByWorkedHours(void* pEmployee1, void* pEmployee2)
{
	int retorno = 0;
	Employee* pEmployeeAux1 = NULL;
	Employee* pEmployeeAux2 = NULL;
	pEmployeeAux1 = (Employee*)pEmployee1;
	pEmployeeAux2 = (Employee*)pEmployee2;
	int horas1;
	int horas2;

	if(pEmployeeAux1 != NULL && pEmployeeAux2 != NULL)
	{

		if(employee_getHorasTrabajadas(pEmployeeAux1, &horas1) == 0 && employee_getHorasTrabajadas(pEmployeeAux2, &horas2) == 0)
		{
			if(horas1 > horas2)
			{
				retorno = 1;
			}
			else if(horas1 < horas2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_requestNewEmployee(Employee* pEmployee, int* id)
{
	int retorno = -1;

	if(pEmployee != NULL)
	{
		retorno = 0;
		// ID
		*id = employee_getUltimoId() + 1;
		pEmployee->id = *id;

		// NOMBRE
		employee_askName(pEmployee);

		// HORAS TRABAJADAS
		employee_askHorasTrabajadas(pEmployee);

		// SUELDO
		employee_askSueldo(pEmployee);
	}

	return retorno;
}

void employee_askName(Employee* this)
{
	if(this != NULL)
	{
		input_limpiarPantalla();
		input_pedirStringNombreApellido(this->nombre, "Ingrese nombre: ", "ERROR. Ingrese nombre: ", 128);
	}
}

void employee_askHorasTrabajadas (Employee* this)
{
	if(this != NULL)
	{
		input_limpiarPantalla();
		input_getNumero(&this->horasTrabajadas, "Horas trabajadas: ", "ERROR. Horas trabajadas [0-100000]: ", 0, 100000);
	}
}

void employee_askSueldo(Employee* this)
{
	if(this != NULL)
	{
		input_limpiarPantalla();
		input_getNumero(&this->sueldo, "Sueldo: ", "ERROR. Sueldo [0-100000]: ", 0, 100000);
	}
}

int employee_getUltimoId(void)
{
	int ultimoId = -1;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", ultimoIdStr);
		ultimoId = atoi(ultimoIdStr);
	}
	fclose(pFile);

	return ultimoId;
}

int employee_setUltimoId(int ultimoId)
{
	int retorno = -1;

	FILE* pFile = fopen("ultimoId.txt", "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d \n", ultimoId);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}

int employee_searchIndex(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = -1;
	int i;
	int len = ll_len(pArrayListEmployee);
	int idAux;
	Employee* pEmployeeAux = NULL;

	if(pArrayListEmployee != NULL && id != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(pEmployeeAux, &idAux);

			if(*id == idAux)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}





