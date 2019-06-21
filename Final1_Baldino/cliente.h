#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char dni[30];
}Cliente;

Cliente* cliente_new();
Cliente* cliente_newParametros(char* nombreStr,char* apellidoStr,char* dniStr);
int cliente_delete();

int cliente_setId(Cliente* this, char* value);
int cliente_getId(Cliente* this,int* value);

int cliente_setNombre(Cliente* this,char* value);
int cliente_getNombre(Cliente* this,char* value);

int cliente_setApellido(Cliente* this,char* value);
int cliente_getApellido(Cliente* this,char* value);

int cliente_setDni(Cliente* this,char* value);
int cliente_getDni(Cliente* this,char* value);

int cliente_sortByNombre(void* clienteA,void* clienteB);

#endif // CLIENTE_H_INCLUDED
