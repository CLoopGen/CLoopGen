#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access (l += 13), use consecutive indices but map them to original positions via lookup
    int index = 0;
    int stride_offset = wking_loc + 13;
    int consecutive[12]; // Assume maximum reasonable length for consecutive buffer

    // Precompute the access pattern: l, l+13, l+26, ...
    for (int i = 0; i < 12; ++i) {
        consecutive[i] = stride_offset + i * 13;
    }

    // Traverse using consecutive indices into our precomputed array
    for (index = 0; index < 12; ++index) {
        l = consecutive[index];
        if (board[l] != 13) break;
    }
}
