#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int resY_tmp[16][16];
extern int i0;
extern int i1;
extern int _usr_j0;
extern int _usr_j1;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // We transpose the loop order to access memory sequentially in row-major order.
    // Since resY_tmp[j][i] becomes resY_tmp[row][col], we swap loop bounds and indexing
    // to write in row-major sequence, improving cache locality.

    for (j = j0; j < j1; j++)
        for (i = i0; i < i1; i++) {
            resY_tmp[j][i] = 0;
        }
}
