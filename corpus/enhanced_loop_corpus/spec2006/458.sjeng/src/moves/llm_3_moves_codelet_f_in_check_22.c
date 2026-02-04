#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    int *index_ptr = &board[wking_loc + 1];
    for (l = wking_loc + 1; *index_ptr == 13; l++, index_ptr++)
        ;
}
