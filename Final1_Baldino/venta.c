#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

static int generarId(void);

Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

Venta* venta_newParametros(char* idClienteStr,char* codigoProductoStr,char* cantidadStr)
{
    Venta* pVenta=venta_new();
    if(pVenta!=NULL)
    {
       if(!venta_setIdCliente(pVenta,idClienteStr)
           &&!venta_setCodigoProducto(pVenta,codigoProductoStr)
           &&!venta_setCantidad(pVenta,cantidadStr))
        {
            pVenta->idVenta=generarId();
        }
        else
        {
            pVenta=NULL;
        }
    }
    return pVenta;
}

int venta_delete(Venta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int venta_setIdVenta(Venta* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->idVenta = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->idVenta;
        retorno = 0;
    }
    return retorno;
}

int venta_setIdCliente(Venta* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=1)
        {
            this->idCliente = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getIdCliente(Venta* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->idCliente;
        retorno = 0;
    }
    return retorno;
}

int venta_setCodigoProducto(Venta* this, char* value)
{
    int auxCodigo;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxCodigo=atoi(value);
        if(auxCodigo>=1000)
        {
            this->codigoProducto = auxCodigo;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getCodigoProducto(Venta* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->codigoProducto;
        retorno = 0;
    }
    return retorno;
}

int venta_setCantidad(Venta* this, char* value)
{
    int auxCantidad;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxCantidad=atoi(value);
        if(auxCantidad>0)
        {
            this->cantidad = auxCantidad;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getCantidad(Venta* this,int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cantidad;
        retorno = 0;
    }
    return retorno;
}


static int generarId(void)
{
    static int idVenta=1;
    return idVenta++;
}
