#include "Prac2.h"

FILE *abrirArchivo(char *nombre_archivo)
{
    FILE *archivo=fopen(nombre_archivo,READ);
    return archivo;
}
void mostarContenidoArchivo(FILE *archivo)
{
    char cad[TAM];
    while(feof(archivo)==0)
    {
        fgets(cad,TAM,archivo);
        printf("%s",cad);
    }
}
int menu()
{
    int opcion;
    printf("1.- Unir dos lenguajes.\n2.- Concatenar dos lenguajes.\n3.- Potenciar un lenguaje.\n4.- Reflexion de un lenguaje.\n5.- Cerradura positiva.\n6.- Cerradura normal.\n7.- Salir.\nSelecciones su opcion: ");
    scanf("%d",&opcion);
    return opcion;
}
FILE *unirLenguajes(FILE *lenguaje1,FILE *lenguaje2)
{
    char cadena[TAM],aux[TAM];
    FILE *unionLenguajes=fopen("unionLenguajes.txt",WRITE);
    while (feof(lenguaje1)==0)
    {
        fgets(cadena,TAM,lenguaje1);
        fputs(cadena,unionLenguajes);
    }  
    rewind(unionLenguajes);
    while (feof(lenguaje2)==0)
    {
        fgets(cadena,TAM,lenguaje2);
        fgets(aux,TAM,unionLenguajes);
        if (strcmp(cadena,aux)!=0)
        {
            fputs(cadena,unionLenguajes);
        }  
    }
    fclose(lenguaje1);
    fclose(lenguaje2);
    fclose(unionLenguajes);
    return unionLenguajes;
}
FILE *concaLenguajes(FILE *lenguaje1,FILE *lenguaje2)
{
    char cad[TAM],cad2[TAM],aux[TAM];
    FILE *conLenguajes=fopen("concatenacionLenguajes.txt","w"); 
    while(feof(lenguaje1)==0)
    {
        fgets(cad,TAM,lenguaje1);
        strcpy(aux,cad);
        while(feof(lenguaje2)==0)
        {
            fgets(cad2,TAM,lenguaje2);
            strcat(aux,cad2);
            fputs(aux,conLenguajes);
            strcpy(aux,cad);
        }
        rewind(lenguaje2);
    }
    fclose(lenguaje1);
    fclose(lenguaje2);
    fclose(conLenguajes);
    return conLenguajes;
}

