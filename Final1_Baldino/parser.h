#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_clienteFromText(FILE* pFile , LinkedList* arrayList);
int parser_ventaFromText(FILE* pFile , LinkedList* arrayList);
int parser_productoFromText(FILE* pFile , LinkedList* arrayList);

#endif // PARSER_H_INCLUDED
