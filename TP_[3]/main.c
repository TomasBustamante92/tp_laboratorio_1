#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	input_getNumero(&option, 	"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n"
    								"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n"
    								"3. Alta de empleado \n"
    								"4. Modificar datos de empleado \n"
    								"5. Baja de empleado \n"
    								"6. Listar empleados \n"
    								"7. Ordenar empleados \n"
    								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n"
    								"9. Guardar los datos de los empleados en el archivo data.csv (modo binario) \n"
    								"10. Salir \n"
    								"- - - - - - - - - - - - - - - - - - - \n"
    								"Ingrese opcion: ",
									"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n"
									"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n"
									"3. Alta de empleado \n"
    								"4. Modificar datos de empleado \n"
    								"5. Baja de empleado \n"
    								"6. Listar empleados \n"
    								"7. Ordenar empleados \n"
    								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n"
    								"9. Guardar los datos de los empleados en el archivo data.csv (modo binario) \n"
    								"10. Salir \n"
    								"- - - - - - - - - - - - - - - - - - - \n"
    								"ERROR. Ingrese opcion: ", 1, 10);
        switch(option)
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
				{
                	input_limpiarPantalla();
                	printf("Lista cargada con exito! \n");
                	input_systemPause();
				}
                else
                {
                	input_limpiarPantalla();
                	printf("Error al cargar la lista! \n");
                	input_systemPause();
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.csv", listaEmpleados))
				{
                	input_limpiarPantalla();
                	printf("Lista cargada con exito! \n");
                	input_systemPause();
				}
                else
                {
                	input_limpiarPantalla();
                	printf("Error al cargar la lista! \n");
                	input_systemPause();
                }
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados))
				{
                	input_limpiarPantalla();
                	printf("Empleado agregado con exito! \n");
                	input_systemPause();
				}
                else
                {
                	input_limpiarPantalla();
                	printf("Error al cargar el empleado! \n");
                	input_systemPause();
                }
            	break;
            case 4:
            	if(controller_editEmployee(listaEmpleados))
				{
                	input_limpiarPantalla();
                	printf("Empleado modificado con exito! \n");
                	input_systemPause();
				}
                else
                {
                	input_limpiarPantalla();
                	printf("Error al modificar el empleado! \n");
                	input_systemPause();
                }
            	break;
            case 5:
            	if(controller_removeEmployee(listaEmpleados))
				{
                	input_limpiarPantalla();
                	printf("Empleado eliminado con exito! \n");
                	input_systemPause();
				}
                else
                {
                	input_limpiarPantalla();
                	printf("Error al eliminar el empleado! \n");
                	input_systemPause();
                }
            	break;
            case 6:
            	if(controller_ListEmployee)
				{
                	input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
                	printf("No hay empleados cagados! \n");
                	input_systemPause();
				}
            	break;
            case 7:
            	if(controller_sortEmployee)
				{
					input_limpiarPantalla();
                	printf("Empleados ordenados con exito! \n");
                	input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
                	printf("Error al ordenar la lista! \n");
                	input_systemPause();
				}
            	break;
            case 8:
            	if(controller_saveAsText("data.csv", listaEmpleados))
				{
					input_limpiarPantalla();
                	printf("Lista guardada con exito! \n");
                	input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
                	printf("Error al guardar la lista! \n");
                	input_systemPause();
				}
            	break;
            case 9:
            	if(controller_saveAsBinary("data.csv", listaEmpleados))
				{
					input_limpiarPantalla();
                	printf("Lista guardada con exito! \n");
                	input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
                	printf("Error al guardar la lista! \n");
                	input_systemPause();
				}
            	break;
            case 10:
            	input_limpiarPantalla();
            	printf("Adios! \n");
            	break;
        }
    }while(option != 10);

    return 0;
}

