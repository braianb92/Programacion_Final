#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados);
int parser_loadFromText(FILE* pFile, LinkedList* listaEmpleados);


#endif // PARSER_H_INCLUDED
