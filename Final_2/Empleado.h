#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

int em_minimoHorasTrabajadas(void* p);
int em_sueldosMayorA(void* p);
int em_calcularSueldo(void* p);

Empleado* em_new();
Empleado* em_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
int em_delete();

int em_setId(Empleado* this, char* value);
int em_getId(Empleado* this,int* value);

int em_setNombre(Empleado* this,char* value);
int em_getNombre(Empleado* this,char* value);

int em_setHorasTrabajadas(Empleado* this,char* value);
int em_getHorasTrabajadas(Empleado* this,int* value);

int em_setSueldoChar(Empleado* this,char* value);
int em_setSueldoInt(Empleado* this,int value);
int em_getSueldo(Empleado* this,int* value);

int em_sortByNombre(void* empleadoA,void* empleadoB);
int em_ListEmployee(LinkedList* listaEmpleados);

#endif // EMPLEADO_H_INCLUDED
