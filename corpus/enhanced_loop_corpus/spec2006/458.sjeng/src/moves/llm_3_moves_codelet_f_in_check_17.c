#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using an offset array to simulate indirect indexing
    static const int offsets[] = { -13, -26, -39, -52, -65, -78, -91, -104, -117, -130 };
    int idx = 0;
    l = wking_loc + offsets[0];
    for (; idx < 10 && board[l] == 13; ++idx) {
        l = wking_loc + offsets[idx];
    }
    if (idx == 10) l = wking_loc + offsets[9]; // Ensure l holds last accessed location
}
