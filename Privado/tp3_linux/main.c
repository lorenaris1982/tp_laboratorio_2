#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#define DATACSV "data.csv"
#define DATABIN "data.bin"

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



/*int f1(int *a, int b,int (*foo)(int,int)) {
	*a = *a * 2;
	*a = foo(*a,b);
	return (*a);
}

int f2(int a, int b) {
	 a = b*b;
	 return a;
}


enum colors {lets,find,course};
int main()
{
	printf("%d %d %d",course,lets,find);
	return 0;
}*/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

        option = showMainMenu();

        switch(option)
        {
            case 1:
                controller_loadFromText(DATACSV ,listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary(DATABIN ,listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText(DATACSV ,listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary(DATABIN, listaEmpleados);
                break;
            case 10:
                printf("Saliendo...\n");
                option = 10;
                break;
        }
        system("pause");
        system("cls");

    }while(option != 10);
    return 0;
}
