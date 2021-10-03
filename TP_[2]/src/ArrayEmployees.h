/*
 * ArrayEmployees.h
 *
 *  Created on: Sep 23, 2021
 *      Author: Tomas Sanchez de Bustamante
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#include <string.h>

#define TRUE 1
#define FALSE 0

#define UP 1
#define DOWN 0

#define ELEMENTS 1000

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;


int auxAddEmployee(Employee auxEmployee, Employee* list, int len, int lastId);
void employee_printEmployee(Employee employee);
int verifyConfirmation(char* message, char* error);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary, int sector);
int initEmployees(Employee* list, int len);
void printEmployee(Employee employee);
int printEmployees(Employee* list, int length);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int noEmployeesOnSystem(Employee* list, int len);
int searchEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
void printTopMenu(void);
int modifyEmployee(Employee* list, int len);
void cleanScreen(void);
int informEmployees(Employee* list, int len);
int showEmployees(Employee* list, int len);
int sortEmployees(Employee* list, int len, int order);
int sortEmployeeBySector(Employee* list, int len, int order);
int salaries(Employee* list, int len);
float salariesTotal(Employee* list, int len);
float salariesAverage(Employee* list, int len);
int quantityMoreThanAverage(Employee* list, int len, float average);



void producto_hardCodear(Employee productos[], int tam); // BORRARRR



#endif /* ARRAYEMPLOYEES_H_ */
