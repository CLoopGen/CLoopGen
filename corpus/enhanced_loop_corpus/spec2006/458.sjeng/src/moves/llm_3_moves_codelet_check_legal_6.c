#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with an auxiliary index array
    // Access pattern is now indirect: indices are read from a dynamically computed list
    int *indices[12];
    int base = bking_loc - 11;
    // Precompute address locations in a strided manner but store pointers
    for (int i = 0; i < 12; i++) {
        indices[i] = &board[base - i * 11];
    }
    int i = 0;
    for (l = bking_loc - 11; i < 12 && *indices[i] == 13; i++) {
        l = base - i * 11;
    }
}
