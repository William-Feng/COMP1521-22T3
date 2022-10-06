        .text
main:
        # Registers:
        # $t0 = x
        # $t1 = y
        # $t2 = sum
        
        begin
        push    $ra
        push    $s0
        
        li      $s0, 10         # int x = 10;
        li      $t1, 5          # int y = 5;
        
        # 1. Load the arguments into the $a registers
        # 2. Call 'jal function_name' to execute the function
        # 3. Restore the return value from $v0 (if necessary)
               
        move    $a0, $s0
        move    $a1, $t1
        jal     add_nums
        
        move    $t2, $v0        # Ensure the return value does not get overriden
        
        move    $a0, $t2        # printf("%d", sum);
        li      $v0, 1
        syscall
        
        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall
        
        move    $a0, $s0        # printf("%d", x);
        li      $v0, 1
        syscall
        
        li      $a0, '\n'       # printf("%c", '\n');
        li      $v0, 11
        syscall
        
        pop     $s0
        pop     $ra
        end
        
        li      $v0, 0          # return 0;
        jr      $ra

add_nums:
        add     $t0, $a0, $a1   # sum = $t0
        move    $v0, $t0
        jr      $ra     
        