#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern int dir;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 2: Strided memory access with reversed loop order (j-loop outside becomes inside)
    // Introduces column-major traversal, creating a strided access pattern across 'all_mv8x8'
    for (i = i0; i < ii; i++) {
        for (j = j0; j < jj; j++) {
            short* ptr = &all_mv8x8[dir][1][i][j][0];
            *(ptr + 0) = 0;  // Equivalent to [0]
            *(ptr + 1) = 0;  // Equivalent to [1]
        }
    }
}
