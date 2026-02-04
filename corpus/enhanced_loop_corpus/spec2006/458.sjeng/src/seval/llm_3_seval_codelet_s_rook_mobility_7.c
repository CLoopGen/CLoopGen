#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic
    // Use a pointer that walks through the array with fixed stride
    // This emphasizes pointer-based traversal which may enable different compiler optimizations
    int* ptr = &board[square + 12];
    for (; *ptr == 13; ptr += 12) {
        m++;
        if (ptr >= &board[143]) break; // Prevent out-of-bounds
    }
}
