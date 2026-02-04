#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic with intermediate array indexing
    // Use a pointer that walks backward in strides of 12 via pre-decrement
    int* ptr = &board[bking_loc - 12];
    for (; (*ptr) == 13 && ptr >= board + 12; ptr -= 12)
        ;
}
