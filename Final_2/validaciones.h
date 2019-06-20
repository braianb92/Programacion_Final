#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

///COMPILADO EN WINDOWS. AUTOR BRAIAN BALDINO.
int isNumber (char* pointerString);
int isNumberFloat (char* pointerString);
int isLetter (char* pointerString);
int isAlphanumeric (char* pointerString);
int isTelephone (char* pointerString);
int isDni (char* pointerString);
int isCuit (char* pointerString);
int isDate (int day,int month,int year);
int isMail (char* pointerString);
int isGender (char* pointerString);

#endif // VALIDACIONES_H_INCLUDED
