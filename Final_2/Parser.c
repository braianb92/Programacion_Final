#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_loadFromText(FILE* pFile, LinkedList* listaEmpleados)
{
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    int cantidadDatos;
    Empleado *pEmpleado;
    int retorno=-1;

    if(pFile != NULL && listaEmpleados!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n", bufferId,
                                                bufferNombre,
                                                bufferHorasTrabajadas);
        do
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^\n]\n",   bufferId,
                                                                    bufferNombre,
                                                                    bufferHorasTrabajadas);
            if(cantidadDatos==3)
            {
                pEmpleado = em_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas);
                if(pEmpleado != NULL)
                {
                    if(!ll_add(listaEmpleados,pEmpleado))
                    {
                        retorno=0;
                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pFile;
    int retorno=-1;
    if(listaEmpleados!=NULL)
    {
        pFile = fopen(fileName,"r");
        if(pFile!=NULL)
        {
            if(!parser_loadFromText(pFile,listaEmpleados))
            {
                fclose(pFile);
                retorno=1;
            }
        }
    }
    return retorno;
}

int parser_ListEmployee(LinkedList* listaEmpleados)
{
    Empleado* pE;
    int auxId;
    int auxHoras;
    char auxNombre[4096];
    int size;
    int i;

    if(listaEmpleados!=NULL)
    {
        size=ll_len(listaEmpleados);
        for(i=0;i<size;i++)
        {
            pE=ll_get(listaEmpleados,i);
            em_getId(pE,&auxId);
            em_getNombre(pE,auxNombre);
            em_getHorasTrabajadas(pE,&auxHoras);
            if(pE!=NULL)
            {
                printf("%d,%s,%d\n",auxId,auxNombre,auxHoras);
            }
        }
    }
   return 1;
}

