#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-uniform strides
    static const int8_t offsets[] = {13, 26, 39, 52}; // Example indirect step pattern
    int idx = 0;
    l = bking_loc + 13;
    for (; idx < 4 && board[l] == 13; ++idx) {
        l = bking_loc + offsets[idx];
    }
}
