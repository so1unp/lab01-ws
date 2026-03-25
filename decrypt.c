#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // Agregar código aquí.
    int clave = 3; // Clave de cifrado

    char linea[100];

    printf("Escribi algo: ");
    if (fgets(linea, sizeof(linea), stdin) != NULL) {
        printf("Leido: %s", linea);
    }
    
    char resultado = linea[0]; // Inicializar resultado con el primer carácter de la línea
     for (int i = 0; i < strlen(resultado); i++)
     {
            //resultado += resultado[i*clave + (i+1)];
        
     }
        printf("El resultado es: %s\n", resultado);
     


    // Termina la ejecución del programa.
    exit(EXIT_SUCCESS);
}
