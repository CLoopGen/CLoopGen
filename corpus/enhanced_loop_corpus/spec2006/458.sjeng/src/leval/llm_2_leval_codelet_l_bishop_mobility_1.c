#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with increased stride (simulating cache-friendly pattern)
    int base = square - 11;
    int step = 11;
    for (l = base; board[l] == 13; l -= step * 2) {
        m++;
        if (l < step * 2) break; // Prevent underflow or invalid access
    }
}
