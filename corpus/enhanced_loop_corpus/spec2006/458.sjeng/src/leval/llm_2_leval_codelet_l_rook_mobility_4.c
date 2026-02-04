#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride (simulating a different traversal pattern)
    // Instead of subtracting 12 each time, subtract 24 (double stride), still checking every 12th element indirectly
    for (l = square - 12; board[l] == 13 && (l - 12) >= 0; l -= 24)
        m++;
}
