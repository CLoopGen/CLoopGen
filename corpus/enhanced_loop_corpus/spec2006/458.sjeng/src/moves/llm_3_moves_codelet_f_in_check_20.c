#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic with stride
    // Use a moving pointer instead of index to access memory in strided pattern
    int *ptr = board + wking_loc + 12;
    for (l = wking_loc + 12; *ptr == 13; ptr += 12, l += 12)
        ;
}
