#include <stdio.h>
#include <stdlib.h>
#include "Baldino_String_Geters.h"
#include "LinkedList.h"
#include "controller.h"
#include "venta.h"
#include "cliente.h"
#include "producto.h"

int main()
{
    int option = 0;
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas= ll_newLinkedList();
    LinkedList* listaProductos=ll_newLinkedList();

    controller_clienteLoadFromText("clientes.txt",listaClientes);
    controller_ventaLoadFromText("ventas.txt",listaVentas);
    controller_productoLoadFromText("productos.txt",listaProductos);
    do
    {
        getIntInRange(&option,  "\n1)Alta Cliente\n"
                                "2)Modificacion Cliente\n"
                                "3)Baja Cliente\n"
                                "4)Listar Clientes\n"
                                "\n----------------------\n"
                                "5)Realizar Venta\n"
                                "6)Anular Venta\n"
                                "7)Informar Ventas\n"
                                "\n----------------------\n"
                                "8)Informar ventas por producto\n"
                                "9)Generar informe de ventas\n"
                                "10)Informar cantidad de ventas por cliente\n"
                                "11)SALIR\n","\nERROR\n",1,11,3);

        switch(option)
        {
            case 1:
                if(!controller_addCliente(listaClientes))
                {
                    controller_clienteSaveAsText("clientes.txt",listaClientes);
                    printf("\n--El cliente se dio de alta!--\n");
                }
                else
                {
                    printf("\n--No pudo realizarse el alta--\n");
                }
                break;
            case 2:
                if(!controller_editCliente(listaClientes))
                {
                    controller_clienteSaveAsText("clientes.txt",listaClientes);
                    printf("\n--Se modifico exitosamente!--\n");
                }
                else
                {
                    printf("\n--No pudo realizarse la modificacion--\n");
                }
                break;
            case 3:
                if(!controller_removeCliente(listaClientes))
                {
                    controller_clienteSaveAsText("clientes.txt",listaClientes);
                    printf("\n--Se dio de baja correctamente!--\n");
                }
                else
                {
                    printf("\n--No pudo realizarse la baja--\n");
                }
                break;
            case 4:
                controller_ListCliente(listaClientes);
                break;
            case 5:
                printf("\n-------------\n");
                controller_ListProducto(listaProductos);
                printf("\n-------------\n");
                controller_ListCliente(listaClientes);
                printf("\n-------------\n");
                if(!controller_addVenta(listaVentas,listaClientes))
                {
                    controller_ventaSaveAsText("ventas.txt",listaVentas);
                    printf("\n--Se realizo la venta!--\n");
                }
                else
                {
                    printf("\n--No pudo realizarse la venta--\n");
                }
                break;
            case 6:
                if(!controller_removeVenta(listaVentas))
                {
                    controller_ventaSaveAsText("ventas.txt",listaVentas);
                    printf("\n--Se anulo la venta!--\n");
                }
                else
                {
                    printf("\n--No pudo anularse la venta--\n");
                }
                break;
            case 7:
                controller_ListVenta(listaVentas);
                break;
            case 8:

                break;
            case 9:

                break;
            case 10:

                break;
        }
    }while(option != 11);
    return 0;
}
