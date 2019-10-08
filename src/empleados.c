/*
 * empleados.c
 *
 *  Created on: 6 oct. 2019
 *      Author: lorena
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"

#define EXIT_ERROR -1

#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1

/** \brief  Esta funcion crea el id
 * \return int > 0
 */

int generarId(void)
{
	static int id = 0;
	id++;
	return id;
}

/** \brief  Para indicar que todas las posiciones en la matriz están vacías,
 * \param aArray sEmpleados puntero a la matriz de empleados
 * \param cantidad int cantidad de aArray
 * \return int Return (-1) si es  Error (0) si es Ok
 *
 */
int initLugarLibreEmpleado(struct sEmpleados *aArray, int cantidad)
{
	int i;
	int retorno = -1;

	if(aArray != NULL && cantidad >0)
	{
		for(i=0; i<cantidad; i++)
		{
			aArray[i].status  = STATUS_EMPTY;
		}

		  retorno = 0;
	}
	return retorno;
}

/** \brief Busca un lugar libre en el array de empleados
 * \param aArray sEmpleados*
 * \param cantidad int
 * \return int Return (-1) si es Error  - (0) si es Ok
 *
 */
int buscarLugarLibreEmpleado(struct sEmpleados *aArray, int cantidad)
{
	int i;
	int retorno = -1;

	if(aArray != NULL && cantidad >0)
	{
		for(i=0; i<cantidad; i++)
		{
			if(aArray[i].status == STATUS_EMPTY)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Busca a los empleados por id
 * \param aArray sEmpleados*
 * \param cantidad int
 * param id int
 * \return int Return (-1) si es Error  - (0) si es Ok
 *
 */
int buscarEmpleadoPorId(struct sEmpleados *aArray, int cantidad, int id)
{
	int i;
	int retorno = -1;

	if(aArray!=NULL && cantidad>0)
	{
		for(i=0; i<cantidad; i++)
		{
			if(aArray[i].idEmpleados == id)
			{
				retorno=id;
				break;
			}
		}
	}
	return retorno;
}

/** \brief Ordena a los empleados por apellido y sector
 * \param aArray sEmpleados*
 * \param cantidad int
 * \return int Return (-1) si es Error  - (0) si es Ok
 *
 */
int ordenarArrayEmpleados(struct sEmpleados *aEmpleado, int cantidad)
{
	int i;
	int retorno = -1;
	struct sEmpleados bEmpleado;
	int fSwap;

	if(aEmpleado != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0; i<cantidad-1; i++)
			{
				if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bEmpleado=aEmpleado[i];
					aEmpleado[i]=aEmpleado[i+1];
					aEmpleado[i+1]=bEmpleado;
				}
				else if(strncmp(aEmpleado[i].apellido,aEmpleado[i+1].apellido,QTY_CARACTERES)==0)
				{
					if(strncmp(aEmpleado[i].sector,aEmpleado[i+1].sector,QTY_CARACTERES)>0)
					{
						fSwap = 1;
						bEmpleado = aEmpleado[i];
						aEmpleado[i] = aEmpleado[i+1];
						aEmpleado[i+1] = bEmpleado;
					}
				}
			}
		}while(fSwap);
	}
	return retorno;
}

/** \brief Imprime los datos del array  de empleados
 * \param aArray sEmpleados*
 * \param cantidad int
 * \return int Return (-1) si es Error  - (0) si es Ok
 *
 */

int imprimirArrayEmpleados(struct sEmpleados *aArray, int cantidad)
{
	int i;
	int retorno = -1;

	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		for(i=0; i<cantidad; i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY)
			{
			printf("Id: %d - Nombre: %s - Apellido: %s - Salario: %f - Sector: %d\n",aArray[i].idEmpleados,aArray[i].nombre,aArray[i].apellido,aArray[i].salario,aArray[i].sector);
			}
		}
	}
	return retorno;
}

/** \brief agregar en una lista existente de empleados los valores recibidos como parámetros
 *     en la primera posición vacía
 * \param aArray sEmpleados*
 * \param cantidad int
 * \param empleado sEmpleados
 * \return int Return (-1) si es Error  - (0) si es Ok
 *
 */
int altaEmpleadoPorId(struct sEmpleados *aArray, int cantidad, struct sEmpleados empleado)
{
	int i;
	int retorno = -1;

	if(aArray != NULL && cantidad>0)
	{
		i=buscarLugarLibreEmpleado(aArray, cantidad);
		if(i >= 0)
		{
			aArray[i] = empleado;
			aArray[i].status = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Modifica los datos del empleados
*
* \param aArray sEmpleados*
* \param cantidad int
* \param empleado sEmpleados
* \return int Return (-1) si es Error  - (0) si es Ok
*
*/
int modificarEmpleadoPorId(struct sEmpleados *aArray, int cantidad, struct sEmpleados empleado)
{
	int i;
	int retorno = -1;

	if(aArray!=NULL && cantidad>0)
	{
		i=buscarEmpleadoPorId(aArray, cantidad,empleado.idEmpleados);
		if(i!=NULL)
		{
			aArray[i] = empleado;
			aArray[i].status = STATUS_NOT_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}


/** \brief Dar de baja a un empleado
*
* \param aArray sEmpleados*
* \param cantidad int
* \param id int
* \return int Return (-1) si es Error  - (0) si es Ok
*
*/
int bajaEmpleadoPorId(struct sEmpleados *aArray, int cantidad, int id)
{
	int i;
	int retorno = -1;

	if(aArray != NULL && cantidad >0)
	{
		i=buscarEmpleadoPorId(aArray, cantidad, id);

		if(i!=-1)
		{
			aArray[i].status = STATUS_EMPTY;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Saca el total y promedio del salario de los empleados
*
* \param aArray sEmpleados*
* \param cantidad int
* \return int Return (-1) si es Error  - (0) si es Ok
*
*/
int totalPromedioEmpleado(struct sEmpleados *aArray, int cantidad)
{

int i;
int retorno = -1;
float promedio = 0;
float total = 0;
int contador = 0;
int mayorPromedio = 0;

if(aArray != NULL && cantidad>0)
{
	retorno = 0;
	for (i=0; i<cantidad; i++)
	{
		if(aArray[i].status==STATUS_NOT_EMPTY)
		{
			contador ++;
			total += aArray[i].salario;
		}
	}
	promedio = total / contador;
	for(i=0; i<cantidad; i++)
	{
		if(aArray[i].status == STATUS_NOT_EMPTY && aArray[i].salario>promedio)
		{
		mayorPromedio++;
		}
	}
	printf("Total de empleados %d \n", "con un total  de salario $%f\n""y un promedio de $%f\n"
					" hay un total de %d empleados que superan el promedio.\n"
	,contador,total,promedio,mayorPromedio);
}
 return retorno;
}


