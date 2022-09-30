N_SIZE = 10                             # DEFINE N_SIZE 10
        
        .text
main:
        # Registers
        # $t0 = i
        # $t1 = numbers = &numbers[0]
        # $t2 = N_SIZE = 10
        # $t3 is the array offset
        # $t4 = &numbers[i] (the address of each array element)
        # $t5 = numbers[i] (this is the actual value of each array element)

        li      $t0, 0
        la      $t1, numbers
        li      $t2, N_SIZE

add_if_neg_cond:
        bge     $t0, $t2, epilogue      # if (i >= N_SIZE) goto epilogue;

add_if_neg_body:
        mul     $t3, $t0, 4             # $t3 = i * 4 (offset)
        add     $t4, $t1, $t3           # $t4 = &numbers[i]       
        lw      $t5, ($t4)              # $t5 = numbers[i]

        bge     $t5, 0, print           # if (numbers[i] >= 0) goto print;
        
        addi    $t5, $t5, 42            # numbers[i] = numbers[i] + 42;
        sw      $t5, ($t4)              # This is to modify the array
        
print:
        move    $a0, $t5                # printf("%d", numbers[i]);
        li      $v0, 1
        syscall 

        li      $a0, '\n'               # printf("%c", '\n');
        li      $v0, 11
        syscall
        
add_if_neg_end:
        addi    $t0, $t0, 1             # i = i + 1;
        j       add_if_neg_cond

epilogue:
        li      $v0, 0                  # return 0;
        jr      $ra


        .data
numbers:
        .word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9