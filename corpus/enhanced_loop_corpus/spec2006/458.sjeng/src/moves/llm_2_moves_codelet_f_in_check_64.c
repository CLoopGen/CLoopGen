#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with larger stride using pointer arithmetic
    int *base = board;
    int offset = bking_loc - 11;
    for (l = offset; *(base + l) == 13; l -= 22)  // doubled stride
        ;
}
