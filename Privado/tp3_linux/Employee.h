#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief  Ordena los Id
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortID(void* employeeX, void* employeeY);
/** \brief Ordena los Nombre
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortNombre(void* employeeX, void* employeeY);
/** \brief Ordena las horas
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortHours(void* employeeX, void* employeeY);
/** \brief Ordenas los salarios
 *
 * \param employeeX void*
 * \param employeeY void*
 * \return int
 *
 */
int employee_sortSalary(void* employeeX, void* employeeY);


#endif // employee_H_INCLUDED
