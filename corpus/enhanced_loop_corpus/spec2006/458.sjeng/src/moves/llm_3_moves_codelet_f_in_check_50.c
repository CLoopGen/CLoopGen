#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic and an index array
    static const int *indices[12] = { // Simulate indirect access pattern with precomputed valid offsets
        &board[12], &board[24], &board[36], &board[48],
        &board[60], &board[72], &board[84], &board[96],
        &board[108], &board[120], &board[132], &board[144]
    };
    int base_idx = (bking_loc + 12) / 12 - 1;
    for (l = bking_loc + 12; 
         base_idx < 12 && base_idx >= 0 && 
         indices[base_idx] < &board[144] && 
         *indices[base_idx] == 13; 
         base_idx++, l += 12) {
        // Access via indirect pointer lookup
    }
}
