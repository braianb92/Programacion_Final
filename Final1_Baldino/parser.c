#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "venta.h"
#include "producto.h"

int parser_clienteFromText(FILE* pFile , LinkedList* arrayList)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];
    int cantidadDatos;
    Cliente *pCliente;
    int retorno=-1;

    if(pFile != NULL && arrayList!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferApellido,
                                                  bufferDni);
        do
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferNombre,
                                                  bufferApellido,
                                                  bufferDni);
            if(cantidadDatos==4)
            {
                pCliente = cliente_newParametros(bufferNombre,bufferApellido,bufferDni);
                if(pCliente != NULL)
                {
                    if(!ll_add(arrayList,pCliente))
                    {
                        retorno=0;
                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}


int parser_ventaFromText(FILE* pFile , LinkedList* arrayList)
{
    char bufferIdVenta[1000];
    char bufferIdCliente[1000];
    char bufferCodigoProducto[1000];
    char bufferCantidad[1000];
    int cantidadDatos;
    Venta *pVenta;
    int retorno=-1;

    if(pFile != NULL && arrayList!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferIdVenta,
                                                  bufferIdCliente,
                                                  bufferCodigoProducto,
                                                  bufferCantidad);
        do
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferIdVenta,
                                                                    bufferIdCliente,
                                                                    bufferCodigoProducto,
                                                                    bufferCantidad);
            if(cantidadDatos==4)
            {
                pVenta = venta_newParametros(bufferIdCliente,bufferCodigoProducto,bufferCantidad);
                if(pVenta != NULL)
                {
                    if(!ll_add(arrayList,pVenta))
                    {
                        retorno=0;
                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}


int parser_productoFromText(FILE* pFile , LinkedList* arrayList)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferPrecioUnitario[4096];
    int cantidadDatos;
    Producto *pProducto;
    int retorno=-1;

    if(pFile != NULL && arrayList!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",  bufferId,
                                              bufferNombre,
                                              bufferPrecioUnitario);
        do
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bufferId,
                                                              bufferNombre,
                                                              bufferPrecioUnitario);
            if(cantidadDatos==3)
            {
                pProducto = producto_newParametros(bufferNombre,bufferPrecioUnitario);
                if(pProducto != NULL)
                {
                    if(!ll_add(arrayList,pProducto))
                    {
                        retorno=0;
                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}
