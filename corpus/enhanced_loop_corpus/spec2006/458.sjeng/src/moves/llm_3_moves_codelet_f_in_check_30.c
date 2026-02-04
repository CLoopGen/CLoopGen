#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using an offset array to simulate indirect but dense access
    int indices[10]; // Assume maximum depth to avoid dynamic allocation
    int count = 0;
    int addr = wking_loc - 13;
    
    // Precompute access addresses (indirect access pattern)
    while (addr >= 0 && count < 10) {
        indices[count++] = addr;
        addr -= 13;
    }

    // Traverse using consecutive access over precomputed indices
    for (int i = 0; i < count && board[indices[i]] == 13; ++i)
        l = indices[i];
}
