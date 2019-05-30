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
    char cadena[TAM],aux[TAM],cad[TAM];
    FILE *unionLenguajes=fopen("unionLenguajes.txt","w+");
    while (feof(lenguaje1)==0)
    {
        fgets(cadena,TAM,lenguaje1);
        strcpy(cad,cadena);
        fputs(cad,unionLenguajes);
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
FILE *reLenguaje(FILE *lenguaje1)
{
    FILE *reflexion=fopen("reflexionLenguaje.txt",WRITE);
    char *aux,cad[TAM];
    while(feof(lenguaje1)==0)
    {
        fgets(cad,TAM,lenguaje1);
        aux=invertirCadena(cad);
        fputs(aux,reflexion);
    }
    return reflexion;
}
char *invertirCadena(char *cad)
{
    char *ptr,*ptr2=(char *)malloc(sizeof(char));
    for(ptr=cad;*ptr!='\0';ptr++);
    ptr--;
    for(int i=strlen(cad);i>0;ptr--,i--,ptr2++)
        *ptr2=*ptr;
    for(int i=strlen(cad);i>0;ptr2--,i--);
    return ptr2;
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
/* FILE *poteLenguajes(FILE *lenguaje1,int potencia)
{
    char cad[TAM],aux[TAM],aux2[TAM],mem[TAM];
    FILE *poteLenguaje=fopen("potenciaLenguaje.txt","w+");
    FILE *movimiento=fopen("potenciaLenguaje.txt","w+");
    long int pos=0;
    if(potencia==0)
    {
        fclose(poteLenguaje);
        return poteLenguaje;
    }
    else if(potencia==1)
    {
        while(feof(lenguaje1)==0)
        {
            fgets(cad,TAM,lenguaje1);
            strcpy(aux,cad);
            fputs(aux,poteLenguaje);
        }
        fclose(poteLenguaje);
        return poteLenguaje;
    }
    else
    {
        while(feof(lenguaje1)==0)
        {
            fgets(cad,TAM,lenguaje1);
            strcpy(aux,cad);
            fputs(aux,poteLenguaje);
        }
        rewind(poteLenguaje);
        for(int i=1;i<potencia;i++)
        {
            while(feof(poteLenguaje)==0)
            {
                fgets(cad,TAM,poteLenguaje);
                strcpy(mem,cad);
                eliminaSalto(cad);
                while(feof(movimiento)==0)
                {
                    fgets(aux,TAM,movimiento);
                    strcat(cad,aux);
                    fputs(cad,poteLenguaje);
                    strcpy(cad,mem);
                    eliminaSalto(cad);
                } 
                fseek(movimiento,0,SEEK_SET);
            }
        }
        fclose(poteLenguaje);
        return poteLenguaje;
    }
}  */
FILE *poteLenguajes(FILE *lenguaje1,int potencia)
{
    FILE *aux=fopen("potenciaLenguaje.txt","w+");
    char cad[TAM];
    while (feof(lenguaje1)==0)
    {
        fgets(cad,TAM,lenguaje1);
        fputs(cad,aux);
    }
    rewind(aux);
    for(int i=1;i<potencia;i++)
    {
        while(feof(aux)==0)
        {
            fgets(cad,TAM,aux);
            printf("%s - %d",cad,fseek(aux,0L,SEEK_SET));
        }
    }
    fclose(aux);
}