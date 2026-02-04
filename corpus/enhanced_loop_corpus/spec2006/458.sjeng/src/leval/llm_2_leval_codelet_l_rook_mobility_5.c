#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element backward)
    for (l = square - 1; l >= 0 && board[l] == 13; l -= 2) {
        m++;
        if (l == 0) break; // Prevent underflow in case of odd step
    }
}
