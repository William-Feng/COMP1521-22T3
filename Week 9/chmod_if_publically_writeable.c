// If a file or directory is publically writeable,
// this program should change it so that it is no longer publically-writeable

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_publically_writeable(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_publically_writeable(argv[arg]);
    }
    return 0;
}

void chmod_if_publically_writeable(char *pathname) {
    struct stat s;
    int output = stat(pathname, &s);
    
    // Error checks
    if (output != 0) {
        printf("Cannot stat the file");
        perror(pathname);
    }
    
    // At this point, we can expect the metadata about the pathname
    // to be stored within the struct 's'
    
    mode_t mode = s.st_mode;
    
    // E.g. mode = 111 110 100 -rwxrw-r--    
    
    // We want to use a mask of 2, since we are checking if the second last bit is a 1
    // S_IWOTH == 000 000 010
    if (mode & S_IWOTH) {
        // The file IS publically writeable
        // Change it so that it's not publically writeable (set the second last bit to a 0)
        
            // 111 110 110
            // 000 000 010 &
            // --------------
            // 000 000 000
        
        // Either use the following line or XOR
        // mode = mode ^ S_IWOTH;
        mode_t new_mode = mode & ~S_IWOTH;
        
        output = chmod(pathname, new_mode);
        
        if (output != 0) {
            perror(pathname);
            exit(1);
        }
        
        printf("The file permissions have been changed so that it's not publically writeable anymore\n");
        
    } else {
        printf("The file is NOT publically writeable\n");
        printf("The permissions has not changed\n");
    }

}