// Program that prints the contents of the file $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Construct the pathname $HOME/.diary
    
    // Get the environment variable for $HOME
    char *home_pathname = getenv("HOME");
    
    char *diary_filename = ".diary";
    
    // Total length needs to cover the slash and the null terminator
    int pathname_length = strlen(home_pathname) + strlen(diary_filename) + 1 + 1;
    
    // The 'pathname' string is going to hold the final output
    // Either do this OR dynamically allocate memory
    
    // char *pathname = malloc(pathname_length);
    char pathname[pathname_length];
    
    // Construct the pathname using snprintf
    // Note that the second argument can be as follows or even sizeof(pathname)
    snprintf(pathname, pathname_length, "%s/%s", home_pathname, diary_filename);
    
    // Open the file at that pathname for reading
    FILE *fp = fopen(pathname, "r");
    if (fp == NULL) {
        perror(pathname);
    }
    
    // Loop through the file byte by byte
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
    }
    
    fclose(fp);
    // free(pathname);
    
    return 0;
}
