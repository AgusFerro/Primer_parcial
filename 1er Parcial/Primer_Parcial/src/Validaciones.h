#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <string.h>

int isValidName(char* stringRecibido);
int isValidNumber(char* stringRecibido,int limite);
int isValidSignedNumber(char* stringRecibido);
int isValidFloatNumber(char* stringRecibido,int limite);
int isValidTelephone(char* stringRecibido);
int isValidDNI(char* stringRecibido);
int isValidCUIT(char* stringRecibido);
int isValidEmail(char* stringRecibido);
int isValidTexto(char* stringRecibido);
int isValidAlphanumeric(char* stringRecibido);
int isValidChar(char charRecibido);

#endif /* VALIDACIONES_H_ */
