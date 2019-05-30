#include "Prac2.c"
#include "LSE.c"

int main(int argc, char const *argv[])
{
    char *nombre_archivo="lenguaje1.txt";
    char cad[TAM],aux[TAM];
    NODO *lista=NULL;
    char *nombre_archivo2="lenguaje2.txt";
    FILE *lenguaje1=abrirArchivo(nombre_archivo);
    FILE *lenguaje2=abrirArchivo(nombre_archivo2);
    FILE *unionLenguajes,*conLenguajes,*potLenguajes,*refleLenguajes;
    switch(menu())
    {
        case 1:
            unionLenguajes=unirLenguajes(lenguaje1,lenguaje2);
            break;
        case 2:
            conLenguajes=concaLenguajes(lenguaje1,lenguaje2); 
            break;
        case 3:
            potLenguajes=poteLenguajes(lenguaje1,2);
        case 4:
            refleLenguajes=reLenguaje(lenguaje1);
            break;
    }
    return 0;
}
