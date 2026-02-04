#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an auxiliary array to define access order (simulating indirect or irregular access)
    // Assume a precomputed stride pattern with offset 11, stored in indices
    static const int indices[12] = {11,22,33,44,55,66,77,88,99,110,121,132}; // example offsets
    int base = square;
    for (l = 0; l < 12; l++) {
        int addr = base + indices[l];
        if (addr >= 144) break;
        if (board[addr] != 13) break;
        m++;
    }
}
