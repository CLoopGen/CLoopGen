#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Index Remapping via Pointer Arithmetic
    int* base = &board[bking_loc + 12];
    int stride = 12;
    for (l = bking_loc + 12; *base == 13; base += stride, l += stride) {
        // Strided traversal using direct pointer arithmetic
    }
}
