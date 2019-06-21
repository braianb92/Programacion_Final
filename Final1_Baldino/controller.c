#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "venta.h"
#include "producto.h"
#include "Controller.h"
#include "parser.h"
#include "Baldino_String_Geters.h"

int controller_clienteLoadFromText(char* path , LinkedList* arrayList)
{
    FILE* pFile;
    int retorno=-1;
    if(arrayList!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_clienteFromText(pFile , arrayList))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_ventaLoadFromText(char* path , LinkedList* arrayList)
{
    FILE* pFile;
    int retorno=-1;
    if(arrayList!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_ventaFromText(pFile , arrayList))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_productoLoadFromText(char* path , LinkedList* arrayList)
{
    FILE* pFile;
    int retorno=-1;
    if(arrayList!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_productoFromText(pFile , arrayList))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_clienteSaveAsText(char* path , LinkedList* arrayList)
{
    Cliente* pCliente;
    int auxId;
    char auxNombre[4096];
    char auxApellido[4096];
    char auxDni[4096];
    int size;
    int i;
    int retorno=-1;

    FILE* fp=fopen(path,"w");
    if(fp!=NULL && arrayList!=NULL)
    {
        fprintf(fp,"id,nombre,apellido,dni\n");
        size=ll_len(arrayList);
        for(i=0;i<size;i++)
        {
            pCliente=ll_get(arrayList,i);
            cliente_getId(pCliente,&auxId);
            cliente_getNombre(pCliente,auxNombre);
            cliente_getApellido(pCliente,auxApellido);
            cliente_getDni(pCliente,auxDni);
            if(pCliente!=NULL)
            {
                fprintf(fp,"%d,%s,%s,%s\n", auxId,
                                            auxNombre,
                                            auxApellido,
                                            auxDni);
            }
        }
        fclose(fp);
        retorno=0;
    }
    return retorno;
}

int controller_ventaSaveAsText(char* path , LinkedList* arrayList)
{
    Venta* pVenta;
    int auxIdVenta;
    int auxIdCliente;
    int auxCodigoProducto;
    int auxCantidad;
    int size;
    int i;

    FILE* fp=fopen(path,"w");
    if(fp!=NULL && arrayList!=NULL)
    {
        fprintf(fp,"id_venta,id_cliente,cod_prod,cantidad\n");
        size=ll_len(arrayList);
        for(i=0;i<size;i++)
        {
            pVenta=ll_get(arrayList,i);
            venta_getIdVenta(pVenta,&auxIdVenta);
            venta_getIdCliente(pVenta,&auxIdCliente);
            venta_getCodigoProducto(pVenta,&auxCodigoProducto);
            venta_getCantidad(pVenta,&auxCantidad);
            if(pVenta!=NULL)
            {
                fprintf(fp,"%d,%d,%d,%d\n", auxIdVenta,
                                            auxIdCliente,
                                            auxCodigoProducto,
                                            auxCantidad);
            }
        }
        fclose(fp);
        return 0;
    }
    return 1;
}

int controller_productoSaveAsText(char* path , LinkedList* arrayList)
{
    Producto* pProducto;
    int auxId;
    char auxNombre[4096];
    float auxPrecioUnitario;
    int size;
    int i;

    FILE* fp=fopen(path,"w");
    if(fp!=NULL && arrayList!=NULL)
    {
        fprintf(fp,"id_producto,nombre,precio_unitario\n");
        size=ll_len(arrayList);
        for(i=0;i<size;i++)
        {
            pProducto=ll_get(arrayList,i);
            producto_getId(pProducto,&auxId);
            producto_getNombre(pProducto,auxNombre);
            producto_getPrecioUnitario(pProducto,&auxPrecioUnitario);
            if(pProducto!=NULL)
            {
                fprintf(fp,"%d,%s,%2.f\n",  auxId,
                                            auxNombre,
                                            auxPrecioUnitario);
            }
        }
        fclose(fp);
        return 0;
    }
    return 1;
}

//CONTROLLER CLIENTE

int controller_addCliente(LinkedList* arrayList)
{
    Cliente* newCliente;
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];
    int retorno=-1;

    if(arrayList!=NULL)
    {
        if((!getStringLetras(bufferNombre,"Ingrese Nombre: ","DATO NO VALIDO",3))
           &&(!getStringLetras(bufferApellido,"Ingrese Apellido: ","DATO NO VALIDO",3))
           &&(!getDni(bufferDni,"Ingrese Dni: ","DATO NO VALIDO",3)))
        {
            newCliente=cliente_newParametros(bufferNombre,bufferApellido,bufferDni);
            if(newCliente!=NULL)
            {
                ll_add(arrayList,newCliente);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_editCliente(LinkedList* arrayList)
{
    Cliente* pCliente;
    int retorno = -1;
    int tamLista;
    char bufferId[4096];
    int auxId;
    char bufferNombre [4096];
    char bufferApellido[4096];
    char bufferDni [4096];
    int i;
    int option;

    if (arrayList != NULL)
    {
        tamLista = ll_len(arrayList);
        if(!getStringNumeros(bufferId,"Ingrese el ID del cliente que desea modificar: ","DATO NO VALIDO\n",3))
        {
            auxId=atoi(bufferId);
            for (i=0;i<tamLista;i++)
            {
                pCliente=ll_get(arrayList,i);
                if(pCliente!=NULL&&auxId == pCliente->id)
                {
                    do
                    {
                        printf("Elija que desea modificar: \n");
                        printf("1- Nombre\n2- Apellido\n"
                               "3- Dni\n4- Salir\n");
                        getIntInRange(&option,"Ingrese Opcion: ","DATO NO VALIDO\n",1,4,3);
                        switch (option)
                        {
                            case 1:
                                if(!getStringLetras(bufferNombre,"Ingrese Nuevo Nombre: ","DATO NO VALIDO\n",3))
                                {
                                    cliente_setNombre(pCliente,bufferNombre);
                                    retorno=0;
                                }
                                break;
                            case 2:
                                if(!getStringLetras(bufferApellido,"Ingrese Nuevo Apellido: ","DATO NO VALIDO\n",3))
                                {
                                    cliente_setApellido(pCliente,bufferApellido);
                                    retorno=0;
                                }
                                break;
                            case 3:
                                if(!getDni(bufferDni,"Ingrese Nuevo Dni: ","DATO NO VALIDO\n",3))
                                {
                                    cliente_setDni(pCliente,bufferDni);
                                    retorno=0;
                                }
                                break;
                        }
                    }while (option != 4);
                }
            }
        }
    }
    return retorno;
}


int controller_removeCliente(LinkedList* arrayList)
{
    Cliente* pCliente;
    int tamLista;
    char bufferId[4096];
    int auxId;
    int i;
    int retorno = -1;

    if(arrayList != NULL)
    {
        tamLista=ll_len(arrayList);
        if(!getStringNumeros(bufferId,"Ingrese ID empleado a eliminar: ","DATO NO VALIDO\n",3))
        {
            auxId=atoi(bufferId);
            if(auxId>=0&&tamLista>0)
            {
                for (i = 0; i < tamLista; i++)
                {
                    pCliente=ll_get(arrayList,i);
                    if (pCliente!=NULL&&pCliente->id == auxId)
                    {
                        ll_remove(arrayList, i);
                        cliente_delete(pCliente);
                        retorno=0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int controller_ListCliente(LinkedList* arrayList)
{
    Cliente* pCliente;
    int auxId;
    char bufferNombre[4096];
    char bufferApellido[4096];
    char bufferDni[4096];
    int size;
    int i;
    int retorno=-1;

    if(arrayList!=NULL)
    {
        size=ll_len(arrayList);
        for(i=0;i<size;i++)
        {
            pCliente=ll_get(arrayList,i);
            cliente_getId(pCliente,&auxId);
            cliente_getNombre(pCliente,bufferNombre);
            cliente_getApellido(pCliente,bufferApellido);
            cliente_getDni(pCliente,bufferDni);
            if(pCliente!=NULL)
            {
                printf("%d,%s,%s,%s\n", auxId,
                                        bufferNombre,
                                        bufferApellido,
                                        bufferDni);
                retorno=0;
            }
        }
    }
   return retorno;
}

//CONTROLLER VENTA

int controller_addVenta(LinkedList* arrayListVenta,LinkedList* arrayListCliente)
{
    Venta* newVenta;
    Cliente* pCliente;
    char bufferIdCliente[4096];
    char bufferCodigoProducto[4096];
    char bufferCantidad[4096];
    int auxIdCliente;
    int i;
    int retorno=-1;

    if(arrayListVenta!=NULL&&arrayListCliente!=NULL)
    {
        if((!getStringNumeros(bufferIdCliente,"Ingrese ID de Cliente:","DATO NO VALIDO\n",3))
           &&(!getStringNumeros(bufferCodigoProducto,"Ingrese Codigo de Producto: ","DATO NO VALIDO",3))
           &&(!getStringNumeros(bufferCantidad,"Ingrese Cantidad: ","DATO NO VALIDO",3)))
        {
            auxIdCliente=atoi(bufferIdCliente);
            for(i=0;i<ll_len(arrayListCliente);i++)
            {
                pCliente=ll_get(arrayListCliente,i);
                if(pCliente->id==auxIdCliente)
                {
                    newVenta=venta_newParametros(bufferIdCliente,bufferCodigoProducto,bufferCantidad);
                    if(newVenta!=NULL)
                    {
                        ll_add(arrayListVenta,newVenta);
                        retorno=0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int controller_removeVenta(LinkedList* arrayList)
{
    Venta* pVenta;
    int tamLista;
    char bufferId[4096];
    int auxId;
    int i;
    int retorno = -1;

    if(arrayList != NULL)
    {
        tamLista=ll_len(arrayList);
        if(!getStringNumeros(bufferId,"Ingrese ID de venta a eliminar: ","DATO NO VALIDO\n",3))
        {
            auxId=atoi(bufferId);
            if(auxId>=0&&tamLista>0)
            {
                for (i = 0; i < tamLista; i++)
                {
                    pVenta=ll_get(arrayList,i);
                    if (pVenta->idVenta == auxId)
                    {
                        ll_remove(arrayList, i);
                        venta_delete(pVenta);
                        retorno=0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

int controller_ListVenta(LinkedList* arrayList)
{
    Venta* pVenta;
    int auxIdVenta;
    int auxIdCliente;
    int auxCodigoProducto;
    int auxCantidad;
    int size;
    int i;

    if(arrayList!=NULL)
    {
        size=ll_len(arrayList);
        for(i=0;i<size;i++)
        {
            pVenta=ll_get(arrayList,i);
            venta_getIdVenta(pVenta,&auxIdVenta);
            venta_getIdCliente(pVenta,&auxIdCliente);
            venta_getCodigoProducto(pVenta,&auxCodigoProducto);
            venta_getCantidad(pVenta,&auxCantidad);
            if(pVenta!=NULL)
            {
                printf("%d,%d,%d,%d\n",  auxIdVenta,
                                            auxIdCliente,
                                            auxCodigoProducto,
                                            auxCantidad);
            }
        }
    }
   return 1;
}

//CONTROLLER PRODUCTO
int controller_ListProducto(LinkedList* arrayList)
{
    Producto* pProducto;
    int auxIdProducto;
    char bufferNombre[4096];
    float auxPrecioUnitario;
    int size;
    int i;

    if(arrayList!=NULL)
    {
        size=ll_len(arrayList);
        for(i=0;i<size;i++)
        {
            pProducto=ll_get(arrayList,i);
            producto_getId(pProducto,&auxIdProducto);
            producto_getNombre(pProducto,bufferNombre);
            producto_getPrecioUnitario(pProducto,&auxPrecioUnitario);
            if(pProducto!=NULL)
            {
                printf("%d,%s,%.2f\n", auxIdProducto,
                                        bufferNombre,
                                        auxPrecioUnitario);
            }
        }
    }
   return 1;
}
