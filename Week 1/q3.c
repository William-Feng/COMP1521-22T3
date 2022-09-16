// Identifying error with function

#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

int main(void) {
    int *num = get_num_ptr();

    printf("%d\n", *num);

    free(num);
}

int *get_num_ptr(void) {
    // Do not return addresses of variables that
    // will not persist after the function call
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}