#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

static int generarId(void);

Producto* producto_new()
{
    return (Producto*) malloc(sizeof(Producto));
}

Producto* producto_newParametros(char* nombreStr,char* precioUnitarioStr)
{

    Producto* pProducto=producto_new();
    if(pProducto!=NULL)
    {
        producto_setNombre(pProducto,nombreStr);
        producto_setPrecioUnitario(pProducto,precioUnitarioStr);
        pProducto->id=generarId();
    }
    return pProducto;
}

int producto_delete(Producto* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int producto_setId(Producto* this, char* value)
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

int producto_getId(Producto* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int producto_getNombre(Producto* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int producto_setNombre(Producto* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isAlphanumeric(value))
    {
        if(strlen(value)>=3)
        {
            strncpy(this->nombre,value,sizeof(this->nombre));
            retorno = 0;
        }
    }
    return retorno;
}

int producto_setPrecioUnitario(Producto* this, char* value)
{
    float auxPrecio;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumberFloat(value))
    {
        auxPrecio=atof(value);
        if(auxPrecio>0)
        {
            this->precioUnitario = auxPrecio;
            retorno = 0;
        }
    }
    return retorno;
}

int producto_getPrecioUnitario(Producto* this,float* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}


int producto_sortByNombre(void* productoA,void* productoB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Producto* pProductoA;
    Producto* pProductoB;

    pProductoA=(Producto*)productoA;
    pProductoB=(Producto*)productoB;
    if(strcmp(pProductoA->nombre,pProductoB->nombre)>0)
    {
        return mayor;
    }
    if(strcmp(pProductoA->nombre,pProductoB->nombre)<0)
    {
        return menor;
    }
    return igual;
}


static int generarId(void)
{
    static int idProducto=1000;
    return idProducto++;
}
