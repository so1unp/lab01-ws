#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    
    srand((unsigned int)time(NULL)); 
    char byte_basura; 
    ssize_t bytes_leidos;

    if (argc > 1) {
        char *msg = argv[1];
        for (int j = 0; msg[j] != '\0'; j++) {
            for (int i = 0; i < 7; i++) {
                byte_basura = (char)(rand() % 256);
                write(STDOUT_FILENO, &byte_basura , 1);
            }
            write(STDOUT_FILENO, &msg[j], 1);
        }


    } else {
        char caracter_leido;
  
        while ((bytes_leidos = read(STDIN_FILENO, &caracter_leido, 1)) > 0) {
            for (int i = 0; i < 7; i++) {
                byte_basura = (char)(rand() % 256);
                if (write(STDOUT_FILENO, &byte_basura, 1) == -1) {
                    perror("Error");
                    exit(EXIT_FAILURE);
                }
            }
            if (write(STDOUT_FILENO, &caracter_leido, 1) == -1) {
                perror("Error");
                exit(EXIT_FAILURE);
            }
        }

        if (bytes_leidos == -1) {
            perror("Error");
            exit(EXIT_FAILURE); 
        }
    }

    exit(EXIT_SUCCESS);
} 