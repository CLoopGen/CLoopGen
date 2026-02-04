#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access by adjusting index locally to simulate dense traversal
    int temp_offset = -11;
    for (l = wking_loc + temp_offset; board[l] == 13; temp_offset--, l = wking_loc + temp_offset)
        ;
}
