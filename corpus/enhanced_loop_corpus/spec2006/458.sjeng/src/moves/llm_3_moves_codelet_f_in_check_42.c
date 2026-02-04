#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array
    // Precompute a lookup table of valid strided addresses starting from bking_loc - 13
    // and traverse using pointers stored in an array (indirect access).
    static int* indices[12];  // Assume max depth of 12 steps (sufficient for 144-element board)
    int count = 0;
    int loc = bking_loc - 13;

    // Build indirect access table
    while (loc >= 0 && loc < 144) {
        indices[count++] = &board[loc];
        loc -= 13;
    }

    // Traverse using indirect accesses
    for (int i = 0; i < count && *indices[i] == 13; ++i)
        ;
}
