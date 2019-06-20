#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "utn_strings.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_EmployeeFromText(pFile , pArrayListEmployee))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmp;
    char bufferId[4096];
    char bufferNombre[4096];
    char bufferHorasTrabajadas[4096];
    char bufferSueldo[4096];
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        if((!getStringNumeros(bufferId,"Ingrese ID:","DATO NO VALIDO\n",3))
           &&(!getStringLetras(bufferNombre,"Ingrese Nombre: ","DATO NO VALIDO",3))
           &&(!getStringNumeros(bufferHorasTrabajadas,"Ingrese Horas Trabajadas(int): ","DATO NO VALIDO",3))
           &&(!getStringNumeros(bufferSueldo,"Ingrese Sueldo(int): ","DATO NO VALIDO",3)))
        {
            newEmp=employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            if(newEmp!=NULL)
            {
                ll_add(pArrayListEmployee,newEmp);
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int retorno = -1;
    int tamLista;
    char bufferId[4096];
    int auxId;
    char bufferNombre [4096];
    char bufferHorasTrabajadas [4096];
    char bufferSueldo [4096];
    int i;
    int option;

    if (pArrayListEmployee != NULL)
    {
        tamLista = ll_len(pArrayListEmployee);
        if(!getStringNumeros(bufferId,"Ingrese el ID del empleado que desea modificar: ","DATO NO VALIDO\n",3))
        {
            auxId=atoi(bufferId);
            for (i=0;i<tamLista;i++)
            {
                pEmployee=ll_get(pArrayListEmployee,i);
                if(auxId == pEmployee->id)
                {
                    do
                    {
                        printf("Elija que desea modificar: \n");
                        printf("1- Nombre del empleado\n2- Horas que trabajo el empleado\n"
                               "3- Sueldo del empleado\n4- Salir\n");
                        getIntInRange(&option,"Ingrese Opcion: ","DATO NO VALIDO\n",1,4,3);
                        switch (option)
                        {
                            case 1:
                                if(!getStringLetras(bufferNombre,"Ingrese Nuevo Nombre: ","DATO NO VALIDO\n",3))
                                {
                                    employee_setNombre(pEmployee,bufferNombre);
                                    retorno=0;
                                }
                                break;
                            case 2:
                                if(!getStringNumeros(bufferHorasTrabajadas,"Ingrese Horas Trabajadas: ","DATO NO VALIDO\n",3))
                                {
                                    employee_setHorasTrabajadas(pEmployee,bufferHorasTrabajadas);
                                    retorno=0;
                                }
                                break;
                            case 3:
                                if(!getStringNumeros(bufferSueldo,"Ingrese Nuevo Sueldo: ","DATO NO VALIDO\n",3))
                                {
                                    employee_setSueldo(pEmployee,bufferSueldo);
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

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int tamLista;
    char bufferId[4096];
    int auxId;
    int i;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        tamLista=ll_len(pArrayListEmployee);
        if(!getStringNumeros(bufferId,"Ingrese ID empleado a eliminar: ","DATO NO VALIDO\n",3))
        {
            auxId=atoi(bufferId);
            if(auxId>=0&&tamLista>0)
            {
                for (i = 0; i < tamLista; i++)
                {
                    pEmployee=ll_get(pArrayListEmployee,i);
                    if (pEmployee->id == auxId)
                    {
                        ll_remove(pArrayListEmployee, i);
                        employee_delete(pEmployee);
                        retorno=0;
                        break;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[4096];
    int size;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
            employee_getId(pE,&auxId);
            employee_getNombre(pE,auxNombre);
            employee_getSueldo(pE,&auxSueldo);
            employee_getHorasTrabajadas(pE,&auxHoras);
            if(pE!=NULL)
            {
                printf("%d,%s,%d,%d\n",auxId,
                                        auxNombre,
                                        auxSueldo,
                                        auxHoras);
            }
        }
    }
   return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_sortByNombre,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char auxNombre[4096];
    int size;
    int i;

    FILE* fp=fopen(path,"w");
    if(fp!=NULL && pArrayListEmployee!=NULL)
    {
        fprintf(fp,"id,nombre,horasTrabajadas,sueldo\n");
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
            employee_getId(pE,&auxId);
            employee_getNombre(pE,auxNombre);
            employee_getSueldo(pE,&auxSueldo);
            employee_getHorasTrabajadas(pE,&auxHoras);
            if(pE!=NULL)
            {
                fprintf(fp,"%d,%s,%d,%d\n",auxId,
                                        auxNombre,
                                        auxHoras,
                                        auxSueldo);
            }
        }
        fclose(fp);
        return 0;
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pE;
    int size;
    int i;

    FILE* fp=fopen(path,"wb");
    if(fp!=NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0;i<size;i++)
        {
            pE=ll_get(pArrayListEmployee,i);
            fwrite(pE,sizeof(Employee),1,fp);
        }

        fclose(fp);
        return 0;
    }

    return 1;
}

