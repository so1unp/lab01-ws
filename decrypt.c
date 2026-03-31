
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  char buf[4096];
  size_t inicio = 7;
  ssize_t n = read(0, buf, sizeof(buf));

  printf("recibido: %s\n", buf);

  for (size_t i = inicio; i < (size_t)n; i += 8) {
    write(1, &buf[i], 1);
  }
  write(1, "\n", 1);

  exit(EXIT_SUCCESS);
}