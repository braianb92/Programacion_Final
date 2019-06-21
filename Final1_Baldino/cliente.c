#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

static int generarId(void);

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

Cliente* cliente_newParametros(char* nombreStr,char* apellidoStr,char* dniStr)
{

    Cliente* pCliente=cliente_new();
    if(pCliente!=NULL)
    {
        cliente_setNombre(pCliente,nombreStr);
        cliente_setApellido(pCliente,apellidoStr);
        cliente_setDni(pCliente,dniStr);
        pCliente->id=generarId();
    }
    return pCliente;
}

int cliente_delete(Cliente* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int cliente_setId(Cliente* this, char* value)
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

int cliente_setNombre(Cliente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        if(strlen(value)>=3)
        {
            strncpy(this->nombre,value,sizeof(this->nombre));
            retorno = 0;
        }
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        if(strlen(value)>=3)
        {
            strncpy(this->apellido,value,sizeof(this->apellido));
            retorno = 0;
        }
    }
    return retorno;
}


int cliente_setDni(Cliente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isDni(value))
    {
        strncpy(this->dni,value,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int cliente_getDni(Cliente* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int cliente_sortByNombre(void* clienteA,void* clienteB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Cliente* pClienteA;
    Cliente* pClienteB;

    pClienteA=(Cliente*)clienteA;
    pClienteB=(Cliente*)clienteB;
    if(strcmp(pClienteA->nombre,pClienteB->nombre)>0)
    {
        return mayor;
    }
    if(strcmp(pClienteA->nombre,pClienteB->nombre)<0)
    {
        return menor;
    }
    return igual;
}


static int generarId(void)
{
    static int idCliente=1;
    return idCliente++;
}
