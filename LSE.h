#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define item char

typedef struct nodo
{
	item dato;
	struct nodo *siguiente;
}NODO;

NODO *CrearNodo(item , NODO *);
void mostrarLSE(NODO *);
void insertarCabLSE(item , NODO **);
void insertarLSE(item , NODO *);
NODO *buscarLSE(item , NODO *);
void eliminarLSE(NODO **, item );
void invertir(NODO **);
NODO *quitarConsecutivo(NODO **);
