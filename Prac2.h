#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 200
#define READ "r"
#define WRITE "w"

FILE *unirLenguajes(FILE *lenguaje1,FILE *lenguaje2);
FILE *concaLenguajes(FILE *lenguaje1,FILE *lenguaje2);
FILE *abrirArchivo(char *nombre_archivo);
FILE *poteLenguajes(FILE *lenguaje1,int potencia);
FILE *reLenguaje(FILE *lenguaje1);
void eliminaSalto(char cad[]);
char *invertirCadena(char *cad);
int menu();