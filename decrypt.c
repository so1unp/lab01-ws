#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  (void)argc;
  char buf[100];
  size_t inicio = 7;
  ssize_t n = read(0, buf, sizeof(buf));
  buf[n] = '\0'; 
  char *linea = buf;

 
  size_t largo = strlen(linea);
  int j = 0;
  size_t largoResultado = (largo / 8) + 1;

  char *result = malloc(largoResultado * sizeof(char));

  printf("recibido: %s\n", linea);
  for (size_t i = inicio; i < largo; i += 7) {
    write(1, &linea[i],1);
    j++;
  }
  result[j] = '\0';    
   write(1, result,j);
   write(1, "\n", 1);
  exit(EXIT_SUCCESS);
}