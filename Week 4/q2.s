FLAG_ROWS = 6
FLAG_COLS = 12


        .text
main:
        # Registers:
        # $t0 = row
        # $t1 = col
        # $t2 = &flag[0][0]
        # $t3 = &flag[row][col]
        
row_init:
        li      $t0, 0                          # int row = 0;
        
row_cond:
        bge     $t0, FLAG_ROWS, row_end        # if (row >= FLAG_ROWS) goto row_end;
        
        
row_body:        
        
col_init:
        li      $t1, 0                          # int col = 0;
        
col_cond: 
        bge     $t1, FLAG_COLS, col_end         # if (row >= FLAG_COLS) goto col_end;

col_body:
        # Formula for calculating offset for 2D arrays:
        # (row * NUM_COLS + col) * element_size
        
        la      $t2, flag                       # $t2 = &flag[0][0]
        mul     $t3, $t0, FLAG_COLS             # $t3 = row * FLAG_COLS
        add     $t3, $t3, $t1                   # $t3 += col (final offset)
        add     $t3, $t3, $t2                   # $t3 = &flag[row][col]
        
        lb      $a0, ($t3)                      # $a0 = flag[row][col]
        li      $v0, 11
        syscall

        addi    $t1, $t1, 1                     # col = col + 1;
        j       col_cond

col_end:
        li      $a0, '\n'                       # printf("%c", '\n');
        li      $v0, 11
        syscall
        
        addi    $t0, $t0, 1                     # row = row + 1;
        j       row_cond

row_end:
        li      $v0, 0                          # return 0;
        jr      $ra
        
        .data
flag:
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'