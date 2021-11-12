
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeToText(FILE*, LinkedList*)
/// @brief Parsea los datos de los empleados hacia el archivo data.csv (modo texto)
///
/// @param pFile
/// @param pArrayListEmployee
/// @return si sale bien devuelve [1] caso contrario devuelve [0]
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

/// @fn int parser_EmployeeToBinary(FILE*, LinkedList*)
/// @brief Parsea los datos de los empleados hacia el archivo data.bin (modo binario)
///
/// @param pFile
/// @param pArrayListEmployee
/// @return si sale bien devuelve [1] caso contrario devuelve [0]
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);
