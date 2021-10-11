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

/// @fn int auxAddEmployee(Employee, Employee*, int, int)
/// @brief ask the user for information about employee and to check it
///
/// @param auxEmployee one employee slot
/// @param list array of employees
/// @param len length of array employees
/// @param lastId the last id used
/// @return if confirmed by the user it returns [0] otherwise returns [-1]
int auxAddEmployee(Employee auxEmployee, Employee* list, int len, int lastId);

/// @fn void employee_printEmployee(Employee)
/// @brief it prints one employee
///
/// @param employee one employee
void employee_printEmployee(Employee employee);

/// @fn int verifyConfirmation(char*, char*)
/// @brief ask the user for a verification
///
/// @param message message for the user
/// @param error error message for the user
/// @return if confirmed by the user it returns [0] otherwise returns [-1]
int verifyConfirmation(char* message, char* error);

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
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary, int sector);

/// @fn int initEmployees(Employee*, int)
/// @brief 	To indicate that all position in the array are empty,
/// 		this function put the flag(isEmpty) in TRUE in all
/// 		position of the array
///
/// @param list Employee* Pointer to array of employees
/// @param len int Array length
/// @return int Return (-1) if Error [Invalid length or NULL pointer]  -  (0) if Ok
int initEmployees(Employee* list, int len);

/// @fn void printEmployee(Employee)
/// @brief print an employee
///
/// @param employee an employee
void printEmployee(Employee employee);

/// @fn int printEmployees(sEmployee*, int)
/// @brief print the content of employees array
///
/// @param list sEmployee*
/// @param length int
/// @return int
int printEmployees(Employee* list, int length);

/// @fn int findEmployeeById(sEmployee*, int, int)
/// @brief 	find an Employee by Id in returns the index position in array.
///
/// @param list Employee*
/// @param len int
/// @param id int
/// @return Return employee index position or (-1) if [Invalid length or NULL
/// 		pointer or employee not found]
int findEmployeeById(Employee* list, int len, int id);

/// @fn int removeEmployee(sEmployee*, int, int)
/// @brief  Remove a Employee by Id (put isEmpty Flag in 1)
///
/// @param list sEmployee*
/// @param len int
/// @param id int
/// @return int Return (-1) if Error [Invalid length or NULL pointer or id can't
/// 		find an employee]  -  (0) if Ok
int removeEmployee(Employee* list, int len, int id);

/// @fn int noEmployeesOnSystem(Employee*, int)
/// @brief it verifies if there is an employee on the array
///
/// @param list array of employees
/// @param len length of array employees
/// @return if the array is empty it returns [-1] otherwise returns [0]
int noEmployeesOnSystem(Employee* list, int len);

/// @fn int searchEmployeeById(Employee*, int, int)
/// @brief searches an employee checking the ID
///
/// @param list array of employees
/// @param len length of array employees
/// @param id ID to check
/// @return if the ID matches it returns the index, otherwise it returns [-1]
int searchEmployeeById(Employee* list, int len, int id);

/// @fn int removeEmployee(Employee*, int, int)
/// @brief ask the user for an employee to remove
///
/// @param list array of employees
/// @param len length of array employees
/// @param id ID to check
/// @return if confirmed by the user it returns [0] otherwise returns [-1]
int removeEmployee(Employee* list, int len, int id);

/// @fn void printTopMenu(void)
/// @brief print the top-bar of the employee display
///
void printTopMenu(void);

/// @fn int modifyEmployee(Employee*, int)
/// @brief ask the user the ID to modify
///
/// @param list array of employees
/// @param len length of array employees
/// @return if the employee has been modified it returns [0] otherwise [-1]
int modifyEmployee(Employee* list, int len);

/// @fn void cleanScreen(void)
/// @brief prints spaces and a bar to clean the screen
///
void cleanScreen(void);

/// @fn int informEmployees(Employee*, int)
/// @brief ask the user if he/she wants to sort the users or see the salaries
///
/// @param list array of employees
/// @param len length of array employees
/// @return if option 1 or 2 is selected it returns [0] otherwise [-1]
int informEmployees(Employee* list, int len);

/// @fn int showEmployees(Employee*, int)
/// @brief ask the user if he/she wants to sort the users up or down
///
/// @param list array of employees
/// @param len length of array employees
/// @return if option 1 or 2 is selected it returns [0] otherwise [-1]
int showEmployees(Employee* list, int len);

/// @fn int sortEmployees(sEmployee*, int, int)
/// @brief 	Sort the elements in the array of employees, the argument order
/// 		indicate UP or DOWN order
///
/// @param list	 Employee*
/// @param len int
/// @param order int [1] indicate UP  -  [0] indicate DOWN
/// @return int Return (-1) if Error [Invalid length or NULL pointer]  -  (0) if Ok
int sortEmployees(Employee* list, int len, int order);

/// @fn int salaries(Employee*, int)
/// @brief prints the salary information
///
/// @param list array of employees
/// @param len length of array employees
/// @return if employees found on array it returns [0] otherwise [-1]
int salaries(Employee* list, int len);

/// @fn float salariesTotal(Employee*, int)
/// @brief total amount of salary earn by all the employees
///
/// @param list array of employees
/// @param len length of array employees
/// @return if employees found on array it returns the total amount, otherwise [-1]
float salariesTotal(Employee* list, int len);

/// @fn float salariesAverage(Employee*, int)
/// @brief average salary earn by all the employees
///
/// @param list array of employees
/// @param len length of array employees
/// @return if employees found on array it returns the average salary, otherwise [-1]
float salariesAverage(Employee* list, int len);

/// @fn int quantityMoreThanAverage(Employee*, int, float)
/// @brief quantity of employees with salary more than average
///
/// @param list array of employees
/// @param len length of array employees
/// @param average average salary
/// @return if employees found on array it returns the quantity of employees, otherwise [-1]
int quantityMoreThanAverage(Employee* list, int len, float average);



#endif /* ARRAYEMPLOYEES_H_ */
