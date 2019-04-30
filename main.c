#include "Prac2.c"

int main(int argc, char const *argv[])
{
    char *nombre_archivo="lenguaje1.txt";
    char *nombre_archivo2="lenguaje2.txt";
    char *cad;
    FILE *lenguaje1=abrirArchivo(nombre_archivo);
    FILE *lenguaje2=abrirArchivo(nombre_archivo2);
    FILE *unionLenguajes,*conLenguajes,*potLenguajes;
    switch(menu())
    {
        case 1:
            unionLenguajes=unirLenguajes(lenguaje1,lenguaje2);
            break;
        case 2:
            conLenguajes=concaLenguajes(lenguaje1,lenguaje2); 
            break;
        case 3:
            potLenguajes=poteLenguajes(lenguaje1,3);
            break;
        case 4:
            invertirCadena("hola");
            break;
    }
    return 0;
}
