
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);
