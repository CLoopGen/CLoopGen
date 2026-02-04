#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using an offset array to simulate indirect indexing
    static const int offsets[] = { -13, -26, -39, -52 }; // Predefined offsets for consecutive access
    int idx = 0;
    l = wking_loc + offsets[idx];
    for (; idx < 4 && board[l] == 13; ++idx) {
        l = wking_loc + offsets[idx];
    }
    // Final adjustment to match original exit state (l holds last valid accessed index)
    if (idx > 0 && idx < 4) l = wking_loc + offsets[idx]; // Simulate post-loop value
}
