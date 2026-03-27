#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  unsigned char caracteres[8]; // array para almacenar los 8 bytes del mensaje cifrado (unsigned porque guardara valores positivos)

  // Leé de a 8 bytes desde la entrada mientras haya datos disponibles
  while (read(STDOUT_FILENO, caracteres, 8) > 0){
    
    /*condicional para verificar que se han leído 8 bytes correctamente
      el write en la salida estandar (STDOUT_FILENO), ignorara los 7 bytes y solo escribira el ultimo bytes [8]
    */
     if (write(STDOUT_FILENO, &caracteres[7], 1) < 0){
      perror("Error en write"); // manejo de errores en caso de que write falle
      return 1;
    }
    
  }
  

  exit(EXIT_SUCCESS);
}
