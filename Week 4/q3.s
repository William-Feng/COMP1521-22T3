# Recursive maximum of array function (provided solutions)

# Register usage:
# - `a' is in $a0 (only before function call)
# - `length' is in $a1 (only before function call)
# - `first_element' is in $s0
# - `max_so_far' is in $t0 (only after function call)

# s0 & s1 used for a and first_element because they need
# to keep their value across recursive call

max:
        # prologue
        begin
        push    $ra                     # push $ra to the stack so we can call a function
        push     $s0                    # push $s0 to the stack so it exists across recursive calls

        # function body
        lw    $s1, ($a0)                # load the value of a[0]

max_base_case:                          # base case of recursion
        li    $t0, 1
        bgt    $a1, $t0, max_rec_case   # if (length > 1), go to the recursive case
        lw    $v0, ($a0)                # load a[0] to return
        j    max_return                 # return a[0]

max_rec_case:                           # recursive case
    
        addi    $a0, $a0, 4             # Get the address of a[1] by adding 4 to &a[0]
                                        # Works because each element is 4 bytes in size
        addi    $a1, $a1, -1            # int length = length - 1;
        jal    max                      # recursive call: 
        move    $t0, $v0                # max_so_far = max(&a[1], length-1);

        ble    $s1, $t0, max_else       # if (a[0] < max_so_far), go to else
        move    $v0, $s1                # otherwise return max_so_far
        j    max_return

max_else:
        move    $v0, $t0                # return a[0] instead


max_return:
        # epilogue
        pop     $s0                     # pop $s0 from the stack
        pop     $ra                     # pop $ra from the stack
        end
        jr      $ra



# some test code which calls max
main:
        addi    $sp, $sp, -4            # create stack frame
        sw      $ra, 0($sp)             # save return address for after the function call

        la      $a0, array
        li      $a1, 10
        jal     max                     # call max(array, 10)

        move    $a0, $v0                # printf ("%d")
        li      $v0, 1
        syscall

        li      $a0, '\n'               # printf("%c", '\n');
        li      $v0, 11
        syscall

                                        # clean up stack frame
        lw      $ra, 0($sp)             # restore $ra
        addi    $sp, $sp, 4             # restore sp

        li      $v0, 0                  # return 0
        jr      $ra


.data
array:
    .word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1