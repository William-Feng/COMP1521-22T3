// Correcting error in program

#include <stdio.h>

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    // Must null terminate strings
    str[2] = '\0';
    printf("%s", str);
    return 0;
}