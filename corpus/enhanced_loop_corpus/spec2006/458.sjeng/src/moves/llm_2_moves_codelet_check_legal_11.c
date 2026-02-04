#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing consecutive elements, access every 2nd element
    for (l = wking_loc + 1; board[l] == 13; l += 2)
        ;
}
