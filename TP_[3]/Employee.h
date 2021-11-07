#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio_ext.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_printTopMenu(void);
void employee_printEmployee(Employee employee);

int employee_sortByName(void* employee1,void* employee2);
int employee_sortBySalary(void* employee1,void* employee2);

int employee_requestNewEmployee(Employee* pEmployee, int* id);

int employee_getUltimoId(void);
int employee_setUltimoId(int ultimoId);

int employee_searchIndex(LinkedList* pArrayListEmployee, int* id);

void employee_askName(Employee* this);
void employee_askHorasTrabajadas (Employee* this);
void employee_askSueldo(Employee* this);


#endif // employee_H_INCLUDED
