#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[4096];
    float precioUnitario;
}Producto;

Producto* producto_new();
Producto* producto_newParametros(char* nombreStr,char* precioUnitarioStr);
int producto_delete();

int producto_setId(Producto* this, char* value);
int producto_getId(Producto* this,int* value);

int producto_setNombre(Producto* this,char* value);
int producto_getNombre(Producto* this,char* value);

int producto_setPrecioUnitario(Producto* this, char* value);
int producto_getPrecioUnitario(Producto* this,float* value);
#endif // PRODUCTO_H_INCLUDED
