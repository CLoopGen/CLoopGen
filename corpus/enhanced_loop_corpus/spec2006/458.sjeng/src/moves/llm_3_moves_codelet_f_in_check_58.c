#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with intermediate index array simulation
    int *ptr = &board[bking_loc - 1];
    int index_offset = 0;
    int indices[72]; // Simulated small buffer of possible indices, though not fully populated
    // Precompute indirect offsets (in practice this could come from a lookup)
    for (int i = 0; i < 72; i++) {
        indices[i] = -i; // descending index offsets
    }
    for (l = bking_loc - 1; ptr + indices[index_offset] >= board && *(ptr + indices[index_offset]) == 13; index_offset++) {
        l = (ptr + indices[index_offset]) - board; // update l to current accessed index
    }
}
