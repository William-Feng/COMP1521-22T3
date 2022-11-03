#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Usage: ./first_line secret.txt
    
    // Handle incorrect number of command line arguments
    if (argc != 2) {
        fprintf(stderr, "You provided the wrong number of arguments\n");
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    
    // Handle error with opening desired file
    if (fp == NULL) {
        fprintf(stderr, "An error has occurred\n");
        perror(argv[1]);
        return 1;
    }
    
    // Loop through the file byte by byte
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
        // Exit loop (stop reading) once we see a newline character
        if (ch == '\n') {
            break;
        }
    }
    
    fclose(fp);

    return 0;
}