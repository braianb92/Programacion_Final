#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "validaciones.h"
#include "LinkedList.h"

#define PRECIO_HASTA_120H 180
#define PRECIO_HASTA_160H 240
#define PRECIO_HASTA_240H 350
#define PRIMERAS_HORAS 120
#define INTERMEDIO_HORAS 160
#define MAXIMO_HORAS 240
#define SUELDO_MAXIMO 30000
#define MINIMO_HORAS_TRABAJADAS 100

int em_minimoHorasTrabajadas(void* p)
{
    Empleado* pEmpleado=p;
    int horasTrabajadas;
    int retorno=-1;

    em_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
    if(horasTrabajadas<MINIMO_HORAS_TRABAJADAS)
    {
        retorno=0;
    }
    return retorno;
}

int em_sueldosMayorA(void* p)
{
    Empleado* pEmpleado=p;
    int sueldo;
    int retorno=-1;

    em_getSueldo(pEmpleado,&sueldo);
    if(sueldo>=SUELDO_MAXIMO)
    {
        retorno=0;
    }
    return retorno;
}

int em_calcularSueldo(void* p)
{
    Empleado* pEmpleado=p;
    int horasTrabajadas;
    int resultado;
    int horasRestantes;
    int retorno=-1;

    em_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
    if(horasTrabajadas>=80&&horasTrabajadas<=PRIMERAS_HORAS)
    {
        resultado=horasTrabajadas*PRECIO_HASTA_120H;
        em_setSueldoInt(pEmpleado,resultado);
        retorno=0;
    }
    else if(horasTrabajadas>=PRIMERAS_HORAS&&horasTrabajadas<=INTERMEDIO_HORAS)
    {
        horasRestantes=horasTrabajadas-PRIMERAS_HORAS;
        resultado=(horasRestantes*PRECIO_HASTA_160H)+(PRIMERAS_HORAS*PRECIO_HASTA_120H);
        em_setSueldoInt(pEmpleado,resultado);
        retorno=0;
    }
    else if(horasTrabajadas>=INTERMEDIO_HORAS&&horasTrabajadas<=MAXIMO_HORAS)
    {
        horasRestantes=horasTrabajadas-INTERMEDIO_HORAS;
        resultado=(horasRestantes*PRECIO_HASTA_240H)+(PRIMERAS_HORAS*PRECIO_HASTA_120H)+
                    ((INTERMEDIO_HORAS-PRIMERAS_HORAS)*PRECIO_HASTA_160H);
        em_setSueldoInt(pEmpleado,resultado);
        retorno=0;
    }
    return retorno;
}

Empleado* em_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* em_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{

    Empleado* emp=em_new();
    if(emp!=NULL)
    {
        em_setId(emp,idStr);
        em_setNombre(emp,nombreStr);
        em_setHorasTrabajadas(emp,horasTrabajadasStr);
    }
    return emp;
}

int em_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int em_setId(Empleado* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }
    return retorno;
}


int em_setSueldoChar(Empleado* this,char* value)
{
    int auxSueldo;
    int retorno = -1;
    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxSueldo=atoi(value);
        if(auxSueldo>=0)
        {
            this->sueldo = auxSueldo;
            retorno = 0;
        }
    }
    return retorno;
}

int em_setSueldoInt(Empleado* this,int value)
{
    int retorno = -1;
    if(this != NULL&& value>=0)
    {
        this->sueldo = value;
        retorno = 0;
    }
    return retorno;
}

int em_setNombre(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        if(strlen(value)>0)
        {
            strncpy(this->nombre,value,sizeof(this->nombre));
            retorno = 0;
        }
    }
    return retorno;
}


int em_setHorasTrabajadas(Empleado* this,char* value)
{
    int auxHoras;
    int retorno = -1;
    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxHoras=atoi(value);
        if(auxHoras>=0)
        {
            this->horasTrabajadas = auxHoras;
            retorno = 0;
        }
    }
    return retorno;
}


int em_getNombre(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int em_getSueldo(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int em_getHorasTrabajadas(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int em_getId(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int em_sortByNombre(void* empleadoA,void* empleadoB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Empleado* pEmpleadoA;
    Empleado* pEmpleadoB;

    pEmpleadoA=(Empleado*)empleadoA;
    pEmpleadoB=(Empleado*)empleadoB;
    if(strcmp(pEmpleadoA->nombre,pEmpleadoB->nombre)>0)
    {
        return mayor;
    }
    if(strcmp(pEmpleadoA->nombre,pEmpleadoB->nombre)<0)
    {
        return menor;
    }
return igual;

}

int em_ListEmployee(LinkedList* listaEmpleados)
{
    Empleado* pE;
    int auxId;
    int auxHoras;
    char auxNombre[4096];
    int size;
    int i;

    if(listaEmpleados!=NULL)
    {
        size=ll_len(listaEmpleados);
        for(i=0;i<size;i++)
        {
            pE=ll_get(listaEmpleados,i);
            em_getId(pE,&auxId);
            em_getNombre(pE,auxNombre);
            em_getHorasTrabajadas(pE,&auxHoras);
            if(pE!=NULL)
            {
                printf("%d,%s,%d\n",auxId,auxNombre,auxHoras);
            }
        }
    }
   return 1;
}
