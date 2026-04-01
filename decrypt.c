
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  char buf[4096];
  size_t global_pos = 0; // Posición global para rastrear el byte actual en la secuencia de entrada 
  ssize_t n; // Variable para almacenar el número de bytes leídos
  
  while ((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
    for (size_t i = 0; i < (size_t)n; i++) {
      // Solo escribimos el byte si es el 8º byte (índice 7, 15, 23, etc.)
      if ((global_pos + i) % 8 == 7) {
        if (write(STDOUT_FILENO, &buf[i], 1) == -1) {
          perror("Error. No se pudo escribir en la salida estándar.");
          exit(EXIT_FAILURE);
        }
      }
    }
    // Actualizamos la posición global después de procesar el buffer
    global_pos += (size_t)n;
  }

  if (n == -1) {
    perror("Error. No se pudo leer de la entrada estándar.");
    exit(EXIT_FAILURE);
  }

  if (write(STDOUT_FILENO, "\n", 1) == -1) {
    perror("Error. No se pudo escribir el salto de línea.");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}