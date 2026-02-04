#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with larger stride using pointer arithmetic
    int *ptr = &board[bking_loc - 13];
    int stride = 13;
    for (; *ptr == 13; ptr -= stride)
        ;
}
