#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	pFile = fopen(path,"r");

	if(pFile == NULL)
	{
		printf("El archivo no existe");

	}else
	{
		parser_EmployeeFromText(pFile ,pArrayListEmployee);
	}
	fclose(pFile);
    return 1;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = fopen(path, "rb");
    int retorno;

    if(pFile == NULL)
    {
        printf("No se pudo cargar la esctructura...\n");
        retorno = 0;
        fclose(pFile);
    }
    else
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        retorno = 1;
    }
    fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee = employee_new();
    char auxID[51];
    char auxNombre[128];
    char auxHorasTrabajadas[51];
    char auxSueldo[51];
    int i;
    int retorno = 0;
    int cantidad;
    int getId;

    cantidad = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        getId = getInt(&getId,"Ingrese el id del nuevo empleado:","Error",1,10000,2);


        for(i=0; i<cantidad; i++)
        {
            newEmployee = (Employee*) ll_get(pArrayListEmployee, i);

            if(getId == newEmployee->id)
            {
                printf("Id existente...\n");
                retorno = 1;
                break;
            }
        }
        if(getId != newEmployee->id)
        {
            getString(auxNombre, "Ingrese el nombre\n", "Error", 1,127, 2);
            getString(auxHorasTrabajadas, "Ingrese las horas trabajadas\n", "Error", 1,100000, 2);
            getString(auxSueldo, "Ingrese el sueldo\n", "Error", 1,100000, 2);
            newEmployee = employee_newParametros(auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, newEmployee);
            printf("\n--Empleado dado de alta con exito--\n");
        }
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int auxID;
    int auxHorasTrabajadas;
    int auxSueldo;
    int i;
    int cantidad;
    int opcion = 0;
    int buffer = 0;
    char  auxNombre[128];

    cantidad = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        auxID = getInt(&auxID,"Ingrese el id del nuevo empleado:","Error",1,10000,2);

        for(i=0; i<cantidad; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

            if(auxID == auxEmployee->id)
            {

            	do
            	{
            		printf("1. Modificar nombre\n"
            				"2. Modificar horas trabajadas\n"
            				"3. Modificar sueldo\n"
            				"4. Salir\n");

            		getInt(&opcion, "Ingrese la opcion 0 a 9\n", "Error", 0, 4, 2);

            		switch(opcion)
            		{
            		case 1:
            			getString(auxNombre, "Ingrese el nombre\n", "Error", 1,127, 2);
            			employee_setNombre(auxEmployee, auxNombre);
            			break;
            		case 2:
                            auxHorasTrabajadas = getInt(&auxHorasTrabajadas, "Ingrese las horas trabajadas\n", "Error", 1,100000, 2);
                            employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
                            break;
                        case 3:
                            auxSueldo = getInt(&auxSueldo, "Ingrese el sueldo\n", "Error", 1,100000, 2);
                            employee_setSueldo(auxEmployee, auxSueldo);
                            break;
                        case 4:
                            opcion = 4;
                            break;
                        default:
                            printf("Opcion incorrecta...\n");
                            break;
                    }

                }while(opcion != 4);
                buffer = 1;
            }
        }
        if(buffer == 0)
        {
            printf("Empleado no encontrado...\n");
        }
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxID;
    int i;
    int cantidad;
    int buffer = 0;
    char opcion;
    Employee* auxEmployee;

    cantidad= ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        auxID = getInt(&auxID,"Ingrese el id del nuevo empleado:","Error",1,10000,2);
        for(i = 0; i < cantidad; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if( auxID == auxEmployee->id)
            {
                getInt(&auxID,"Ingrese el id del nuevo empleado:","Error",1,10000,2);
                printf("Desea dar de baja?: ");


                if(opcion == 's')
                {
                    ll_remove(pArrayListEmployee, i);
                    printf("\nEmpleado dado de baja\n");
                    employee_delete(auxEmployee);
                }
                else
                {
                    printf("El empleado no fue dado de baja\n");
                }
                buffer = 1;
                break;
            }
        }
    }
    if(buffer == 0)
    {
        printf("Ese ID no existe...\n");
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int cantidad;
    int auxID;
    int auxHorasTrabajadas;
    int auxSueldo;
    int buffer = 0;
    char auxNombre[128];
    Employee* auxEmployee;

    cantidad = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("---ID--------------NOMBRE--------------HORAS--------------SALARIO\n");
        for(i=0; i<cantidad; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &auxID);
            employee_getNombre(auxEmployee, auxNombre);
            employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
            employee_getSueldo(auxEmployee, &auxSueldo);
            printf("%5d %15s %20d %20d\n", auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
        }
        buffer = 1;
    }
    if(buffer == 0)
    {
        printf("No se pudo cargar la lista...\n");
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int opcion;

    if(pArrayListEmployee != NULL)
    {
    	printf("1.  Ordenar por ID\n"
    			"2. Ordenar por Nombre\n"
    			"3. Salir");

    	getInt(&opcion, "Ingrese la opcion 0 a 9\n", "Error", 0, 4, 2);

        switch(opcion)
        {
            case 1:
                ll_sort(pArrayListEmployee, employee_sortID, opcion);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_sortNombre,opcion);
                break;
            default:
                printf("Opcion Incorrecta...");
                break;
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmployee;
    int cantidad;

    pFile = fopen(path,"w");
    cantidad = ll_len(pArrayListEmployee);

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(int i = 1; i < cantidad; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        }
        printf("Datos guardados con exito. (txt)\n");
        fclose(pFile);
    }
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo...\n");
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmployee;
    int cantidad;

    pFile = fopen(path,"wb");
    cantidad = ll_len(pArrayListEmployee);

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        for(int i = 1; i < cantidad; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(auxEmployee, sizeof(Employee), 1, pFile);
        }
        printf("Datos guardados con exito.(binario)\n");
        fclose(pFile);
    }
    if(pFile == NULL)
    {
        printf("No se pudo abrir el archivo...\n");
    }

    return 1;
}

