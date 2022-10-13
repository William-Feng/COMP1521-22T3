#include <stdio.h>
#include <assert.h>

typedef unsigned int Word;

/*

e.g. 1010 --> reverseBits() --> 0101

input = 1010
output (initially) = 0000

1. Extract each bit
2. Check if result is 0 or 1
3. If result is not 0, set it in the return value

1010
0001 &
------
0000 == 0 --> rightmost bit is a 0 (we don't need to do anything)

// Extracting
1010
0010 &
------
0010 != 0 --> second rightmost bit is a 1

// Setting
0000
0100 |
--------
0100 (new output)

1010
0100 & 
-------
0000 == 0 --> third rightmost bit is a 0 (we don't need to do anything)

// Extracting
1010
1000 &
--------
1000 != 0 --> fourth rightmost bit (leftmost bit) is a 1

// Setting
0100
0001 |
--------
0101 --> Final Answer

*/

// Note:
// If you want to check/extract something, use the bitwise AND operator, &
// If you want to set/update something, use the bitwise OR operator, |

Word reverseBits(Word w) {

    // Initially the output is 0
    Word output = 0;
    
    // Loop through each bit one by one (by the way, use #define for these programs)
    for (int i = 0; i < 32; i++) {
        // Shift mask to the left by 1 on each iteration (checking from right to left)
        Word extractingMask = 1u << i;
        
        // i = 0
        // Extracting mask: 0000 0000 .... 0001
        // Setting mask: 1000 0000 .... 0000   Left shift 1 by 31
        
        // i = 1
        // Extracting mask: 0000 0000 .... 0010
        // Setting mask: 0100 0000 .... 0000   Left shift 1 by 30
        
        // i = 31
        // Extracting mask: 1000 0000 .... 0000
        // Setting mask: 0000 0000 .... 0001   Left shift 1 by 0
        
        
        // If the original bit is a 1 (i.e. the bitwise AND result is not 0),
        // update the output with the reverse of the mask above
        if (w & extractingMask) {            
            Word settingMask = 1u << (31 - i);
            output = output | settingMask;
        }
    }

    return output;
}



// Testing
int main(void) {
    Word w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}
