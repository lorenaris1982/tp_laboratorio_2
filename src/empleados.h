/*
 * empleados.h
 *
 *  Created on: 6 oct. 2019
 *      Author: lorena
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#define UTN_H_

#define QTY_EMPLEADOS 1000
#define QTY_CARACTERES 50


struct sEmpleados
{
	int idEmpleados;
	int status;
	char nombre[50];
	char apellido[50];
	int salario;
	int sector;
};

int generarId(void);
int initLugarLibreEmpleado(struct sEmpleados *aArray, int cantidad);
int buscarLugarLibreEmpleado(struct sEmpleados *aArray, int cantidad);
int buscarEmpleadoPorId(struct sEmpleados *aArray, int cantidad, int id);
int ordenarArrayEmpleados(struct sEmpleados *aEmpleado, int cantidad);
int imprimirArrayEmpleados(struct sEmpleados *aArray, int cantidad);
int altaEmpleadoPorId(struct sEmpleados *aArray, int cantidad, struct sEmpleados empleado);
int modificarEmpleadoPorId(struct sEmpleados *aArray, int cantidad, struct sEmpleados empleado);
int bajaEmpleadoPorId(struct sEmpleados *aArray, int cantidad, int id);
int totalPromedioEmpleado(struct sEmpleados *aArray, int cantidad);




#endif /* EMPLEADOS_H_ */
