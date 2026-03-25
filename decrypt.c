#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  (void)argc;

  size_t inicio = 7;
  char *linea = argv[1];
  size_t largo = strlen(linea);
  int j = 0;
  size_t largoResultado = (largo / 8) + 2;

  char *result = malloc(largoResultado * sizeof(char));

  printf("recibido: %s\n", linea);
  for (size_t i = inicio; i < largo; i += 8) {
    printf("%c", linea[i]);
    result[j] = linea[i];
    j++;
  }
  printf("resultado: %s\n", result);
  exit(EXIT_SUCCESS);
}
