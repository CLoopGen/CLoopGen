#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic to avoid extra storage)
    // Simulate indirect traversal by precomputing a sequence of indices in reverse order with fixed offset pattern
    int base = bking_loc - 1;
    int offset = 0;
    int max_steps = 144; // Reasonable upper bound based on board size
    for (int i = 0; i < max_steps; ++i) {
        l = base - offset;
        if (board[l] != 13) break;
        offset += 1; // Linear indirect progression
    }
}
