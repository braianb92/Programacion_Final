#ifndef BALDINO_STRING_GETERS_H_INCLUDED
#define BALDINO_STRING_GETERS_H_INCLUDED

///COMPILADO EN WINDOWS. AUTOR BRAIAN BALDINO.
int getString(char* pointerString, char* msg, char*msgE);
int getInt (int *pointerNumber, char* msg, char* msgE);
int getFloat (float *pointerNumber, char* msg, char* msgE);
int getIntInRange (int *pointerNumber,char *msg,char *msgE,int minimo,int maximo,int tries);
int getStringLetras (char* pointerString, char* msg, char* msgE,int tries);
int getStringNumeros (char* pointerString, char* msg, char* msgE,int tries);
int getStringNumerosFloat (char* pointerString, char* msg, char* msgE,int tries);
int getStringAlphanumeric (char* pointerString, char* msg, char* msgE,int tries);
int getTelephone (char* pointerString, char* msg, char* msgE,int tries);
int getDni (char* pointerString, char* msg, char* msgE,int tries);
int getCuit (char* pointerString, char* msg, char* msgE,int tries);
int getDate (int* day,int* month, int* year, char* msgE,int tries);
int getMail (char* pointerString, char* msg, char* msgE,int tries);
int getGender (char* pointerString, char* msg, char* msgE,int tries);


#endif // BALDINO_STRING_GETERS_H_INCLUDED
