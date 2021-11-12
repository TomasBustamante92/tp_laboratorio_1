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

/// @fn int employee_sortBySalary(void*, void*)
/// @brief organiza la lista de empleados por salario
///
/// @param pEmployee1
/// @param pEmployee2
/// @return
int employee_sortBySalary(void* pEmployee1, void* pEmployee2);

/// @fn int employee_sortByWorkedHours(void*, void*)
/// @brief organiza la lista de empleados por horasTrabajadas
///
/// @param pEmployee1
/// @param pEmployee2
/// @return
int employee_sortByWorkedHours(void* pEmployee1, void* pEmployee2);

/// @fn Employee employee_new*()
/// @brief Crea un empleado en memoria
///
/// @return devuelve direccion de memoria de un empleado
Employee* employee_new();

/// @fn Employee employee_newParametros*(char*, char*, char*, char*)
/// @brief Carga los datos a un empleado nuevo
///
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldoStr
/// @return si sale bien devuelve un empleado, caso contrario NULL
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/// @fn void employee_delete(Employee*)
/// @brief Elimina un empleado de la lista
///
/// @param this
void employee_delete(Employee* this);


/// @fn int employee_setId(Employee*, int)
/// @brief Transfiere el contenido de ID al empleado
///
/// @param this
/// @param id
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_setId(Employee* this,int id);

/// @fn int employee_getId(Employee*, int*)
/// @brief Transfiere el contenido de un empleado al ID y lo devuelve
///
/// @param this
/// @param id
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_getId(Employee* this,int* id);


/// @fn int employee_setNombre(Employee*, char*)
/// @brief Transfiere el contenido de nombre al empleado
///
/// @param this
/// @param nombre
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_setNombre(Employee* this,char* nombre);

/// @fn int employee_getNombre(Employee*, char*)
/// @brief Transfiere el contenido de un empleado al nombre y lo devuelve
///
/// @param this
/// @param nombre
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_getNombre(Employee* this,char* nombre);

/// @fn int employee_setHorasTrabajadas(Employee*, int)
/// @brief Transfiere el contenido de horasTrabajadas al empleado
///
/// @param this
/// @param horasTrabajadas
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/// @fn int employee_getHorasTrabajadas(Employee*, int*)
/// @brief Transfiere el contenido de un empleado a horasTrabajadas y lo devuelve
///
/// @param this
/// @param horasTrabajadas
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// @fn int employee_setSueldo(Employee*, int)
/// @brief Transfiere el contenido de sueldo al empleado
///
/// @param this
/// @param sueldo
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_setSueldo(Employee* this,int sueldo);

/// @fn int employee_getSueldo(Employee*, int*)
/// @brief Transfiere el contenido de un empleado a horasTrabajadas y lo devuelve
///
/// @param this
/// @param sueldo
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_getSueldo(Employee* this,int* sueldo);

/// @fn void employee_printTopMenu(void)
/// @brief Imprime los datos de los empleados
///
void employee_printTopMenu(void);

/// @fn void employee_printEmployee(Employee)
/// @brief Imprime un empleado
///
/// @param employee
void employee_printEmployee(Employee employee);

/// @fn int employee_sortByName(void*, void*)
/// @brief organiza la lista de empleados por nombre
///
/// @param employee1
/// @param employee2
/// @return
int employee_sortByName(void* employee1,void* employee2);

/// @fn int employee_requestNewEmployee(Employee*, int*)
/// @brief Pide datos para agregar un nuevo empleado
///
/// @param pEmployee
/// @param id
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_requestNewEmployee(Employee* pEmployee, int* id);

/// @fn int employee_getUltimoId(void)
/// @brief Devuelve el ID del ultimo empleado
///
/// @return Devuelve el ID del ultimo empleado
int employee_getUltimoId(void);

/// @fn int employee_setUltimoId(int)
/// @brief Actualiza el ID del ultimo empleado
///
/// @param ultimoId
/// @return si salio bien devuelve [0] caso contrario [-1]
int employee_setUltimoId(int ultimoId);

/// @fn int employee_searchIndex(LinkedList*, int*)
/// @brief Busca ID en la lista de empleados y devuelve el indice
///
/// @param pArrayListEmployee
/// @param id
/// @return devuelve el indice del empleado encontrado
int employee_searchIndex(LinkedList* pArrayListEmployee, int* id);

/// @fn void employee_askName(Employee*)
/// @brief Pide un nombre al usuario
///
/// @param this
void employee_askName(Employee* this);

/// @fn void employee_askHorasTrabajadas(Employee*)
/// @brief Pide horasTrabajadas al usuario
///
/// @param this
void employee_askHorasTrabajadas (Employee* this);

/// @fn void employee_askSueldo(Employee*)
/// @brief Pide sueldo al usuario
///
/// @param this
void employee_askSueldo(Employee* this);


#endif // employee_H_INCLUDED
