#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with fixed offset array
    const int offset = -11;
    int *base = &board[bking_loc];
    for (l = bking_loc + offset; *(base + offset) == 13; base -= 11, l -= 11)
        ;
}
