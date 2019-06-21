#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_clienteLoadFromText(char* path , LinkedList* arrayList);
int controller_ventaLoadFromText(char* path , LinkedList* arrayList);
int controller_productoLoadFromText(char* path , LinkedList* arrayList);

int controller_clienteSaveAsText(char* path , LinkedList* arrayList);
int controller_ventaSaveAsText(char* path , LinkedList* arrayList);

int controller_addCliente(LinkedList* arrayList);
int controller_editCliente(LinkedList* arrayList);
int controller_removeCliente(LinkedList* arrayList);
int controller_ListCliente(LinkedList* arrayList);

int controller_addVenta(LinkedList* arrayListVenta,LinkedList* arrayListCliente);
int controller_removeVenta(LinkedList* arrayList);
int controller_ListVenta(LinkedList* arrayList);

int controller_ListProducto(LinkedList* arrayList);


#endif // CONTROLLER_H_INCLUDED
