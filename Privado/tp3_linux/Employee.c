#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"



Employee* employee_new(void)
{
	{
		return malloc(sizeof(Employee));
	}
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();
    if(this != NULL)
    {
    	if(employee_setNombre(this,nombreStr)== 0 &&
    			employee_setId(this,atoi(idStr))== 0 &&
    			employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))== 0 &&
				employee_setSueldo(this, atoi(sueldoStr))== 0)
    	{
    		retorno = this;
    	}else
    	{
    		employee_delete(this);
    	}

    }
	return retorno;
}


void employee_delete(Employee* this)
{
    free(this);
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	static int maximoId = -1;
	if(this != NULL)
	{
		retorno = 0;
		if(id<0)
		{
			maximoId++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
			}
				this-> id = id;
		}
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		strncpy(this->nombre,nombre,128);
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL )
	{
		retorno = 0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas=this->horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		this->sueldo=sueldo;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo=this->sueldo;
	}
	return retorno;
}

int employee_sortID(void* employeeX, void* employeeY)
{
    int condicion,auxX, auxY;

    employee_getId(employeeX,&auxX);
    employee_getId(employeeY,&auxY);

        if(auxX > auxY)
        {
            condicion = 1;
        }
        else if(auxX == auxY)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}

int employee_sortHours(void* employeeX, void* employeeY)
{
    int condicion,auxX, auxY;

    employee_getHorasTrabajadas(employeeX,&auxX);
    employee_getHorasTrabajadas(employeeY,&auxY);

        if(auxX > auxY)
        {
            condicion = 1;
        }
        else if(auxX == auxY)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;

}

int employee_sortSalary(void* employeeX, void* employeeY)
{
    int condicion,auxX, auxY;

    employee_getSueldo(employeeX,&auxX);
    employee_getSueldo(employeeY,&auxY);

        if(auxX > auxY)
        {
            condicion = 1;
        }
        else if(auxX == auxY)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}

int employee_sortNombre(void* employeeX, void* employeeY)
{
    int condicion;
    char auxX[51], auxY[51];

    employee_getNombre(employeeX,auxX);
    employee_getNombre(employeeY,auxY);

        if(strcmp(auxX, auxY) > 0)
        {
            condicion = 1;
        }
        else if(strcmp(auxX, auxY) == 0)
        {
            condicion = 0;
        }
        else
        {
            condicion = -1;
        }

    return condicion;
}
