main:
        # Registers:
        # n in $t0
        # fac in $t1
        # i in $t2
        
        li      $t0, 0                          # int n = 0;
        
        la      $a0, initial_prompt             # printf("n  = ");
        li      $v0, 4
        syscall
        
        li      $v0, 5                          # scanf("%d", &n);
        syscall
        move    $t0, $v0                        # $t0 = $v0
        
        li      $t1, 1                          # int fac = 1;

factorial_init:
        li      $t2, 1                          # int i = 1;

factorial_cond:
        bgt     $t2, $t0, print_output          # if (i > n) goto print_output;

factorial_body:
        mul     $t1, $t1, $t2                   # fac = fac * i;
        addi    $t2, $t2, 1                     # i = i + 1;
        j       factorial_cond
         
print_output:
        la      $a0,  output_prompt             # printf("n! = ");
        li      $v0, 4
        syscall
        
        move    $a0, $t1                        # printf("%d", fac);
        li      $v0, 1
        syscall
        
        li      $a0, '\n'                       # printf("%c", '\n');
        li      $v0, 11
        syscall

epilogue:
        li      $v0, 0                          # return 0;
        jr      $ra
        
        .data
initial_prompt:
        .asciiz "n  = "
output_prompt:
        .asciiz "n! = "