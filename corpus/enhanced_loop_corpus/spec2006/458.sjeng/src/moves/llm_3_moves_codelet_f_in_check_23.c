#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer with bounds check
    int *ptr = &board[wking_loc - 1];
    for (l = wking_loc - 1; ptr >= board && *ptr == 13; ptr--, l--) {
        // Traverse using pointer arithmetic instead of direct indexing
    }
}
