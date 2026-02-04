#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with larger stride (simulating a different traversal pattern)
    // Instead of fixed -12 step, use a computed index with same effective stride but expressed differently
    int base = bking_loc;
    for (int offset = -12; base + offset >= 0 && board[base + offset] == 13; offset -= 12)
        ;
}
