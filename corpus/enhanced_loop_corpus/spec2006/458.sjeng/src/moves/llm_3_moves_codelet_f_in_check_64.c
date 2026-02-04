#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access by precomputing a local array-like traversal
    int temp[144];
    for (int i = 0; i < 144; ++i) {
        temp[i] = board[i];  // local copy to enable consecutive access pattern
    }
    int local_idx = bking_loc - 11;
    for (l = local_idx; l >= 0 && temp[l] == 13; l--)  // now scanning consecutively downward
        ;
}
