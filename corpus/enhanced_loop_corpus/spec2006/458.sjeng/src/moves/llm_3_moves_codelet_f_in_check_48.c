#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer array (simulated index indirection)
    // Create a local indirect index mapping (reverse traversal order from bking_loc-1 down to 0)
    int indices[144];
    int size = bking_loc > 144 ? 144 : bking_loc;
    for (int i = 0; i < size; i++) {
        indices[i] = bking_loc - 1 - i;  // reverse order indices
    }
    int idx = 0;
    for (l = indices[idx]; idx < size && board[l] == 13; idx++) {
        l = indices[idx];
    }
    // Final adjustment: after loop, l holds the last accessed value; if exited due to condition,
    // it already satisfies the original semantics
}
