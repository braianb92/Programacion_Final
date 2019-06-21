#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

///COMPILADO EN WINDOWS. AUTOR BRAIAN BALDINO.

/** \brief  Validates if sting contains only numbers (integer).
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isNumber (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if(pointerString[i]<'0' || pointerString[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
/** \brief  Validates if sting contains only numbers (float).
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isNumberFloat (char* pointerString)
{
    int i=0;
    int contadorPuntos=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]<'0' || pointerString[i]>'9')
           &&(pointerString[i]!='.'))
        {
            return 0;
        }
        if(pointerString[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only letters.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isLetter (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!=' ')&&(pointerString[i]<'a'||pointerString[i]>'z')
           &&(pointerString[i]<'A'||pointerString[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only letters,
*           numbers, spaces or a dot.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isAlphanumeric (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!=' ')&&(pointerString[i]!='.')
           &&(pointerString[i]<'a'||pointerString[i]>'z')
           &&(pointerString[i]<'A'||pointerString[i]>'Z')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only numbers,
*           spaces or a dash(only one).
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isTelephone (char* pointerString)
{
    int i=0;
    int contadorGuion=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!=' ')
           &&(pointerString[i]!='-')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        if(pointerString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1 || contadorGuion==0)
        {
            return 1;
        }
    return 0;
}

/** \brief  Validates if sting contains only numbers
*           and if its lengh is 7 as minimun accepted
*           or 8 as maximum accepted for a DNI.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isDni (char* pointerString)
{
    int i=0;
    while(pointerString[i]!='\0')
    {
        if(!isNumber(pointerString))
        {
            return 0;
        }
        if(strlen(pointerString)<7 || strlen(pointerString)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/** \brief  Validates if sting contains only numbers,
*           and two dashes in fixed position.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isCuit (char* pointerString)
{
    int ret=0;
    int i=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!='-')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        else if((pointerString[2]=='-')
                &&(pointerString[10]=='-' || pointerString[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}

/** \brief  Validates a range of years,
*           month and day with appropriate
*           amount of days corresponding to
*           different months.
* \param    day value to be validated.
* \param    mont value to be validated.
* \param    year value to be validated.
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isDate (int day,int month,int year)
{
    int ret=0;
    if((year<1800 || year>2090)
       ||(month<1 || month>12)
       ||(day<1 || day>31))
    {
        return 0;
    }
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ret=1;
            break;
        case 2:
            if(day<=29)
            {
                ret=1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day<=30)
            {
                ret=1;
            }
            break;
    }

    return ret;
}

/** \brief  Validates if sting contains only letters,
*           numbers, one '@' or a dot.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isMail (char* pointerString)
{
    int i=0;
    int contadorPunto=0;
    int contadorArroba=0;
    int retorno=0;
    while(pointerString[i]!='\0')
    {
        if((pointerString[i]!='@')&&(pointerString[i]!='.')
           &&(pointerString[i]<'a'||pointerString[i]>'z')
           &&(pointerString[i]<'A'||pointerString[i]>'Z')
           &&(pointerString[i]<'0' || pointerString[i]>'9'))
        {
            return 0;
        }
        if(pointerString[i]=='.')
        {
            contadorPunto++;
        }
        if(pointerString[i]=='@')
        {
            contadorArroba++;
        }
        i++;
    }
    if(contadorPunto>=1&&contadorArroba==1)
    {
        retorno=1;
    }
    return retorno;
}

/** \brief  Validates if sting contains only one
*           character. Only F or M.
* \param    pointerString Pointer to string array
* \return   return (1) if VALID, (0) if NO VALID.
**/
int isGender (char* pointerString)
{
    int retorno=0;
    if(strlen(pointerString)==1)
    {
        if((strcmp(pointerString,"F")==0)
           ||(strcmp(pointerString,"M")==0))
        {
            retorno=1;
        }
    }
    return retorno;
}
