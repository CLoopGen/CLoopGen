#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer with offset arithmetic
    // Uses a pointer derived from base array and accesses elements indirectly
    int *base = &board[0];
    for (l = bking_loc + 1; base[l] == 13; l++)
        ;
}
