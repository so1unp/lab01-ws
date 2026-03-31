#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buf[100];
  size_t inicio = 7;
  ssize_t n = read(0, buf, sizeof(buf));



  printf("recibido: %s\n", buf);
  for (size_t i = inicio; i < n; i += 8) {
    write(1, &buf[i],1);
  }


  exit(EXIT_SUCCESS);
}