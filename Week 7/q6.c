#include <stdio.h>
#include <stdint.h>

uint32_t six_middle_bits(uint32_t u) {
    // Method 1
    
    /*
    ____ ____ ____ ____ ____ ____ ____ ____ 
    ____ ____ ____ _XXX XXX_ ____ ____ ____
    0000 0000 0000 0XXX XXX0 0000 0000 0000
    0000 0000 0000 0000 0000 0000 00XX XXXX
    */
    
    // mask: 0000 0000 0111 1110 0000 0000 0000
    // mask: 0x7E000
    // mask: 0000 0000 0000 0000 0000 0011 1111 << 13
    uint32_t mask = 0x3F << 13;
    return (u & mask) >> 13;
    
    // Method 2
    // mask: 0000 0000 0000 0000 0000 0011 1111
    uint32_t mask = 0x3F;
    return (u >> 13) & mask;
    
    // Method 3
    return (u << 13) >> 26;
}