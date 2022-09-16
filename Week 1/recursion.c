// Using recursion instead of for loop to print array

#include <stdio.h>

void print_array_element(int nums[], int len, int index) {  
    // Base case (When should we exit??)
    if (index == 10) {
        return;
    }
    
    // Recursive case (What are we actually doing? Then call function again)
    printf("%d\n", nums[index]);
    print_array_element(nums, 10, index + 1);
}

int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    print_array_element(nums, 10, 0);

    return 0;
}


/*
print_array(nums, 10, 0);
printf("%d\n", nums[0]);     3
print_array(nums, 10, 1);
printf("%d\n", nums[1]);     1
print_array(nums, 10, 2);
printf("%d\n", nums[2]);     4
...
...
print_array(nums, 10, 9);
printf("%d\n", nums[9]);     3 (last digit in array)
print_array(nums, 10, 10)    return (exit the recursive function)
*/