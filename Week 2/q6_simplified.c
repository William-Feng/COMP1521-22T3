// Simple program using && and if statements - using goto

#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    
    if (x <= 100) goto print_small_big;
    if (x >= 100) goto print_small_big;

print_medium:
    printf("medium\n");
    goto epilogue;

print_small_big:
    printf("small/big\n");

//     if (x > 100 && x < 1000) goto print_medium;
    
// print_small_big:
//     printf("small/big\n");
//     goto epilogue;

// print_medium:
//     printf("medium\n");

epilogue:
    return 0;
}