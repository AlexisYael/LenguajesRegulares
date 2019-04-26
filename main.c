#include "Prac2.c"

int main(int argc, char const *argv[])
{
    char *nombre_archivo="lenguaje1.txt";
    char *nombre_archivo2="lenguaje2.txt";
    FILE *lenguaje1=abrirArchivo(nombre_archivo);
    FILE *lenguaje2=abrirArchivo(nombre_archivo2);
    FILE *unionLenguajes,*conLenguajes;
    switch(menu())
    {
        case 1:
            unionLenguajes=unirLenguajes(lenguaje1,lenguaje2);
            break;
        case 2:
            conLenguajes=concaLenguajes(lenguaje1,lenguaje2); 
            break;
    }
    return 0;
}
