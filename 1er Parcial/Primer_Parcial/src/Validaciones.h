#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <string.h>

int isValidName(char* stringRecibido);
//valida que el usuario haya ingresado un nombre

int isValidNumber(char* stringRecibido,int limite);
//valida que el usuario haya ingresado un numero

//int isValidSignedNumber(char* stringRecibido);

int isValidFloatNumber(char* stringRecibido,int limite);
//valida que el usuario haya ingresado un numero float

//int isValidTelephone(char* stringRecibido);

//int isValidDNI(char* stringRecibido);

int isValidCUIT(char* stringRecibido);
//valida que el usuario haya ingresado un cuit/cuil

//int isValidEmail(char* stringRecibido);

//int isValidTexto(char* stringRecibido);

//int isValidAlphanumeric(char* stringRecibido);

int isValidChar(char charRecibido);
//valida que el usuario haya ingresado un caracter

#endif /* VALIDACIONES_H_ */
