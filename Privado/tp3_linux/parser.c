#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
	int i = 0;
    Employee* newEmployee = employee_new();
    char auxID[51];
    char auxNombre[128];
    char auxHorasTrabajadas[51];
    char auxSueldo[51];

    if(pFile == NULL)
    {
        return -1;
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHorasTrabajadas, auxSueldo);

        if(r == 4)
        {
            newEmployee = employee_newParametros(auxID, auxNombre, auxHorasTrabajadas, auxSueldo);
            ll_add(pArrayListEmployee, newEmployee);
            i++;
        }
        else
        {
            break;
        }
    }while(!feof(pFile));

    printf("Se cargaron %d datos de empleados (modo txt)\n", i);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i = 0;
    Employee auxEmployee;

    if(pFile == NULL)
    {
        return -1;
    }
    else
    {
         do
        {
            Employee* newEmployee = employee_new();
            employee_setId(newEmployee, auxEmployee.id);
            employee_setNombre(newEmployee, auxEmployee.nombre);
            employee_setHorasTrabajadas(newEmployee, auxEmployee.horasTrabajadas);
            employee_setSueldo(newEmployee, auxEmployee.sueldo);

            ll_add(pArrayListEmployee, newEmployee);
            fread(&auxEmployee,sizeof(Employee),1,pFile);
            i++;
        }while(!feof(pFile));

    }

    printf("Se cargaron %d datos de empleados (modo binario)\n", i);

    return 1;
}
