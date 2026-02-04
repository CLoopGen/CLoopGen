#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access using a pointer with pre-computed range
    int *ptr = &board[square - 13];
    for (l = 0; *(ptr + l) == 13; l += 13)
        m++;
}
