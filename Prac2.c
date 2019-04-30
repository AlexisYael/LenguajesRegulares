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
    FILE *conLenguajes=fopen("concatenacionLenguajes.txt",WRITE); 
    while(feof(lenguaje1)==0)
    {
        fgets(cad,TAM,lenguaje1);
        strcpy(aux,cad);
        eliminaSalto(aux);
        while(feof(lenguaje2)==0)
        {
            fgets(cad2,TAM,lenguaje2);
            strcat(aux,cad2);
            fputs(aux,conLenguajes);
            strcpy(aux,cad);
            eliminaSalto(aux);
        }
        rewind(lenguaje2);
    }
    fclose(lenguaje1);
    fclose(lenguaje2);
    fclose(conLenguajes);
    return conLenguajes;
}
FILE *poteLenguajes(FILE *lenguaje1,int potencia)
{
    char cad[TAM],cad2[TAM],aux[TAM],aux2[TAM];
    FILE *poLenguaje=fopen("potenciaLenguaje.txt","w+");
    FILE *copia=fopen("potenciaLenguaje.txt",READ);
    while(feof(lenguaje1)==0)
    {
        fgets(cad,TAM,lenguaje1);
        fputs(cad,poLenguaje);
    }
    rewind(poLenguaje);
    while(feof(poLenguaje)==0)
    {
        fgets(cad,TAM,poLenguaje);
        strcpy(aux,cad);
        eliminaSalto(aux);
        while(feof(copia)==0)
        {
            fgets(cad2,TAM,copia);
            strcat(aux,cad2);
            fputs(aux,poLenguaje);
            strcpy(aux,cad);
            eliminaSalto(aux); 
        }
        fseek(copia,0,SEEK_SET);
    }
    return poLenguaje;
}
FILE *cerraduraLenguaje(FILE *lenguaje1)
{

}
char *invertirCadena(char *cad)
{
    char *ptr=(char *)malloc(sizeof(char)),*ptr2=(char *)malloc(sizeof(char)),tem;
    ptr=cad;
    for(ptr2=ptr;*ptr2!='\0';ptr2++);
    ptr2--;
    for(;*ptr2!='\0';ptr++,ptr2--)
    {
        printf("ptr-%c  ptr2-%c\n",*ptr,*ptr2);
        tem=*ptr;
        *ptr=*ptr2;
        *ptr2=tem;
    }
    printf("%s",ptr);
    return "c";
}
void eliminaSalto(char cad[])
{
    for (int i = 0; i < strlen(cad); i++)
    {
        if(cad[i]=='\n')
        {
            cad[i]=' ';
        }
    }
}