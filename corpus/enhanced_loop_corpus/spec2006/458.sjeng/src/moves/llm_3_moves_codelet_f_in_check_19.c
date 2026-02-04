#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-regular access
    // Precomputed indices based on original pattern but accessed indirectly
    // Assuming a small lookup table for demonstration (real use might involve dynamic indexing)
    static const int8_t offsets[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132};
    int i;
    for (i = 0; i < 12; ++i) {
        l = wking_loc - offsets[i];
        if (l < 0 || board[l] != 13) break;
    }
}
