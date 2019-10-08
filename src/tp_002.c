/*
 ============================================================================
 Name        : tp_002.c
 Author      : Lorena Ristagno
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "empleados.h"
#define QTY_EMPLEADOS 1000



int main() {
    struct sEmpleados aEmpleado [QTY_EMPLEADOS] ;
    struct sEmpleados bEmpleado;
	int id=0;
	int opcion;
	char conBa;

	do{
		printf("1.Alta\n"
			   "2.Modificar\n"
			   "3.Baja\n"
			   "4.Listado\n"
			   "5.Total y promedio de salarios\n"
			   "6.Salir\n");

		getInt(&opcion, "Ingrese la opcion\n", "Error\n",0,6,2);

		switch (opcion)
		{
		case 1:
		      printf("Alta de Empleados\n");
		      if(buscarLugarLibreEmpleado(aEmpleado,QTY_EMPLEADOS)== -1)
		      {
		    	  printf("Error no hay mas lugar para cargar\n");
		    	  break;
		      }

		      if(getString(bEmpleado.nombre, "Ingrese el nombre\n","Error",1,49,2)== -1)
		      {
		    	  printf("Error en el nombre\n");
		    	  break;
		      }
              if(getString(bEmpleado.apellido, "Ingrese el apellido\n","Error",1,49,2)== -1)
              {
            	  printf("Error en el apellido\n");
            	  break;
              }
              if(getFloat(&bEmpleado.salario,"Ingrese el salario\n","Error",1,100000,2)== -1)
              {
            	  printf("Error en el salario\n");
            	  break;
              }
              if(getInt(&bEmpleado.sector, "Ingrese el sector\n","Error",1,50,2)== -1)
              {
            	  printf("Error en el sector");
            	  break;
              }
              if(altaEmpleadoPorId(aEmpleado,QTY_EMPLEADOS,bEmpleado)==0)
              {
            	  printf("Alta con exito\n");
              }else
              {
            	  printf("Error al hacer el alta\n");
              }
              break;

		case 2:
			printf("Modificar datos del empleado\n");
			getInt(&id,"Ingrese el id para modificar\n","Error\n",0,10000,2);
			if(buscarEmpleadoPorId(aEmpleado,QTY_EMPLEADOS,id)== -1)
			{
				printf("Error el id no existe\n");
				break;
			}

			bEmpleado.idEmpleados=id;
			if(getString(bEmpleado.nombre,"Ingrese el nombre\n","Error\n",1,49,2)== -1)
			{
				printf("Error en el nombre\n");
				break;
			}
			if(getString(bEmpleado.apellido,"Ingrese el apellido\n","Error\n",1,49,2)== -1)
			{
				printf("Error en el apellido\n");
				break;
			}
			if(getFloat(&bEmpleado.salario,"Ingrese el salario\n","Error\n",1,1000000,2)== -1)
			{
				printf("Error el salario\n");
				break;
		    }
			if(getInt(&bEmpleado.sector,"Ingrese el sector\n","Error\n",1,10000,2)== -1)
			{
				printf("Error el sector\n");
				break;
		    }
			if(modificarEmpleadoPorId(aEmpleado,QTY_EMPLEADOS,bEmpleado)==0)
			{
				printf("Modificacion con exito");
			}else
			{
				printf("Error al hacer la modificacion\n");
			}
			break;
		case 3:
			printf("Baja\n");

			getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);

			getChar(&conBa,"Ingrese s para confirmar la baja\n","Error\n",'a','z',2);

			if(conBa=='s')
			{
				if(bajaEmpleadoPorId(aEmpleado,QTY_EMPLEADOS,id)== 0)
				{
					printf("Baja exitosa\n");
				}else
				{
					printf("Error al dar la baja\n");
				}
			}
            break;

		case 4:
		    printf("Listado de empleados\n");
		    imprimirArrayEmpleados(aEmpleado,QTY_EMPLEADOS);
		    if(getFloat(&bEmpleado,"Ingrese id de empleado\n","Error",1,QTY_EMPLEADOS,2)== -1)
		    {
		       break;
		    }
		    break;

		case 5:
			printf("Total y promedio de empleados\n");

			totalPromedioEmpleado(aEmpleado,QTY_EMPLEADOS);
			if(getFloat(&aEmpleado,"Ingrese id de empleado\n","Error",1,QTY_EMPLEADOS,2)== -1)
			{
				printf("Error en el id");
			}
			break;
	    }
	}while(opcion != 6);

	return 0;
}
