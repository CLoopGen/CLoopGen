#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing consecutive elements (l += 1), use a fixed stride of 2
    for (l = square + 2; l < 144 && board[l] == 13; l += 2)
        m++;
}
