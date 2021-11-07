
/*
 ============================================================================
	Alumno: Tomas Sanchez de Bustamante
	Div: D
	TP: 3
	OS: Linux
 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    int cargoEmpleadosTexto = 0;
    int cargoEmpleadosBinario = 0;
    int guardoEmpleadosTexto = 0;
    int guardoEmpleadosBinario = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	input_getNumero(&option, 	"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n"
    								"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario) \n"
    								"3. Alta de empleado \n"
    								"4. Modificar datos de empleado \n"
    								"5. Baja de empleado \n"
    								"6. Listar empleados \n"
    								"7. Ordenar empleados \n"
    								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n"
    								"9. Guardar los datos de los empleados en el archivo data.bin (modo binario) \n"
    								"10. Salir \n"
    								"- - - - - - - - - - - - - - - - - - - \n"
    								"Ingrese opcion: ",
									"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n"
									"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario) \n"
									"3. Alta de empleado \n"
    								"4. Modificar datos de empleado \n"
    								"5. Baja de empleado \n"
    								"6. Listar empleados \n"
    								"7. Ordenar empleados \n"
    								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n"
    								"9. Guardar los datos de los empleados en el archivo data.bin (modo binario) \n"
    								"10. Salir \n"
    								"- - - - - - - - - - - - - - - - - - - \n"
    								"ERROR. Ingrese opcion: ", 1, 10);

        switch(option)
        {
            case 1:
            	if(cargoEmpleadosTexto == 0 && cargoEmpleadosBinario == 0)
            	{
					if(controller_loadFromText("data.csv",listaEmpleados))
					{
						input_limpiarPantalla();
						printf("Lista cargada con exito! \n");
						cargoEmpleadosTexto = 1;
						input_systemPause();
					}
					else
					{
						input_limpiarPantalla();
						printf("Error al cargar la lista! \n");
						input_systemPause();
					}
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! No se puede cargar mas de una lista \n");
                	input_systemPause();
            	}
                break;
            case 2:
            	if(cargoEmpleadosTexto == 0 && cargoEmpleadosBinario == 0)
            	{
					if(controller_loadFromBinary("data.bin", listaEmpleados))
					{
						input_limpiarPantalla();
						printf("Lista cargada con exito! \n");
						cargoEmpleadosBinario = 1;
						input_systemPause();
					}
					else
					{
						input_limpiarPantalla();
						printf("Error al cargar la lista! \n");
						input_systemPause();
					}
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! No se puede cargar mas de una lista \n");
                	input_systemPause();
            	}
            	break;
            case 3:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
					if(!controller_addEmployee(listaEmpleados))
					{
						input_limpiarPantalla();
						printf("Error al cargar el empleado! \n");
						input_systemPause();
					}
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 4:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
					controller_editEmployee(listaEmpleados);
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 5:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
					controller_removeEmployee(listaEmpleados);
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 6:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
                	if(controller_ListEmployee(listaEmpleados))
    				{
                    	input_systemPause();
    				}
    				else
    				{
    					input_limpiarPantalla();
                    	printf("No hay empleados cagados! \n");
                    	input_systemPause();
    				}
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 7:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
                	if(controller_sortEmployee(listaEmpleados))
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
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 8:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
                	if(controller_saveAsText("data.csv", listaEmpleados))
    				{
    					input_limpiarPantalla();
                    	printf("Lista guardada con exito! \n");
                    	guardoEmpleadosTexto = 1;
                    	input_systemPause();
    				}
    				else
    				{
    					input_limpiarPantalla();
                    	printf("Error al guardar la lista! \n");
                    	input_systemPause();
    				}
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 9:
            	if(cargoEmpleadosTexto == 1 || cargoEmpleadosBinario == 1)
            	{
                	if(controller_saveAsBinary("data.bin", listaEmpleados))
    				{
    					input_limpiarPantalla();
                    	printf("Lista guardada con exito! \n");
                    	guardoEmpleadosBinario = 1;
                    	input_systemPause();
    				}
    				else
    				{
    					input_limpiarPantalla();
                    	printf("Error al guardar la lista! \n");
                    	input_systemPause();
    				}
            	}
            	else
            	{
                	input_limpiarPantalla();
                	printf("ERROR! Cargar lista primero \n");
                	input_systemPause();
            		break;
            	}
            	break;
            case 10:
            	if(guardoEmpleadosTexto == 0 && guardoEmpleadosBinario == 0)
            	{
            		input_limpiarPantalla();
            		if(input_confirmacion("No se guardo en ninguna lista, ¿Desea salir igual? [si/no]: \n",
            				"ERROR. No se guardo en ninguna lista, ¿Desea salir igual? [si/no]: \n") == 0)
            		{
            			option = 11;
            		}
            	}
            	else if(guardoEmpleadosTexto == 0)
            	{
                	input_limpiarPantalla();
                	if(input_confirmacion("No se guardo en la lista de TEXTO, ¿Desea salir igual? [si/no]: \n",
                			"ERROR. No se guardo en la lista de TEXTO, ¿Desea salir igual? [si/no]: \n") == 0)
                	{
                    	option = 11;
                	}
            	}
            	else if(guardoEmpleadosBinario == 0)
            	{
                	input_limpiarPantalla();
                	if(input_confirmacion("No se guardo en la lista de BINARIO, ¿Desea salir igual? [si/no]: \n",
                			"ERROR. No se guardo en la lista de BINARIO, ¿Desea salir igual? [si/no]: \n") == 0)
                	{
                    	option = 11;
                	}
            	}
            	else
            	{
                	option = 11;
            	}

				if(option == 11)
				{
					if(ll_clear(listaEmpleados) != 1)
					{
						if(ll_deleteLinkedList(listaEmpleados) != 1)
						{
							input_limpiarPantalla();
							printf("Adios! \n");
						}
						else
						{
							input_limpiarPantalla();
							printf("Error al eliminar LinkedList! \n");
							input_systemPause();
						}
					}
					else
					{
						input_limpiarPantalla();
						printf("Error al limpiar lista de empleados! \n");
						input_systemPause();
					}
				}
            	break;
        }

    }while(option != 11);

    return 0;
}

