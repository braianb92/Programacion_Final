#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int idVenta;
    int idCliente;
    int codigoProducto;
    int cantidad;
}Venta;

Venta* venta_new();
Venta* venta_newParametros(char* idClienteStr,char* codigoProductoStr,char* cantidadStr);
int venta_delete();

int venta_setIdVenta(Venta* this, char* value);
int venta_getIdVenta(Venta* this,int* value);

int venta_setIdCliente(Venta* this, char* value);
int venta_getIdCliente(Venta* this,int* value);

int venta_setCodigoProducto(Venta* this, char* value);
int venta_getCodigoProducto(Venta* this,int* value);

int venta_setCantidad(Venta* this, char* value);
int venta_getCantidad(Venta* this,int* value);

#endif // VENTA_H_INCLUDED
