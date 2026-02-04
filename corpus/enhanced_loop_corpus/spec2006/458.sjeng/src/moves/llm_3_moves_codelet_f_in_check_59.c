#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer with pre-increment
    // Introduces pointer arithmetic to change access pattern
    int *ptr = &board[bking_loc + 1];
    for (l = bking_loc + 1; *ptr == 13; l++, ptr++)
        ;
}
