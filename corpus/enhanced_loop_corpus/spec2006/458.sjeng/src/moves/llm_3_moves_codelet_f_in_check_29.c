#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-uniform strided access
    static const int stride_lookup[] = {13, 26, 39, 52}; // Example indirect strides
    int idx = 0;
    l = wking_loc + 13;
    for (; board[l] == 13; ) {
        idx = (idx + 1) % 4;
        l += stride_lookup[idx];
    }
}
