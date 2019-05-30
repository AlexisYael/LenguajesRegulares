#include "LSE.h"

NODO *CrearNodo(item x, NODO *enlace)
{
	NODO *nuevo=(NODO *)malloc(sizeof(NODO));
	nuevo->dato=x;
	nuevo->siguiente=enlace;
	return nuevo;
}
void mostrarLSE(NODO *cab)
{
	NODO *ptr;
	for (ptr=cab;ptr;ptr=ptr->siguiente)
		printf("%d, ",ptr->dato);
}
void insertarCabLSE(item x, NODO **cab)
{
	NODO *nuevo=CrearNodo(x,NULL);
	nuevo->siguiente=*cab;
	*cab=nuevo;
}
void insertarLSE(item x, NODO *anterior)
{
	NODO *nuevo=CrearNodo(x,NULL);
	nuevo->siguiente=anterior->siguiente;
	anterior->siguiente=nuevo;
}
NODO *buscarLSE(item x, NODO *cab)
{
	NODO *aux;
	for (aux=cab;aux;aux->siguiente)
		return aux;
	return NULL;
}
void eliminarLSE(NODO **cab, item x)
{
	NODO *act=*cab;
	NODO *ant=NULL;
	int encontrado;
	while(act && !encontrado)
	{
		ant=act;
		act=act->siguiente;
	}
	if (act)
	{
		if (act==*cab)
			*cab=act->siguiente;
		else
			ant->siguiente=act->siguiente;
		free(act);
	}
}
/*ESTA FUNCION QUITA UN DATO DE LA LISTA PERO EL CONSECUTIVO NO UNO A BUSCAR*/
NODO *quitarConsecutivo(NODO **cab)
{
	NODO *aux=NULL;
	if (*cab)
	{
		aux=*cab;
		*cab=(*cab)->siguiente;
	}
	return aux;
}
//ESTA FUNCION INVIERTE UNA LISTA QUITANDO LOS DATOS Y VOLVIENDOLOS A INSERTAR PERO AL RAVEZ 
void invertir(NODO **cab)
{
	NODO *ant=NULL;;
	NODO *act;
	while((act=quitarConsecutivo(cab)))
	{
		act->siguiente=ant;
		ant=act;
	}
	*cab=ant;
}
