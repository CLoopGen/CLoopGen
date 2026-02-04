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
    // Variant 1: Consecutive memory access by flattening the 2D iteration into a 1D stride
    // This accesses memory in a more sequential pattern by precomputing offsets
    int idx = 0;
    int width = 4;
    int height = 4;
    short (*base)[2] = &all_mv8x8[dir][1][0][0];  // Base pointer to [i][j][0]
    
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            int linear_idx = (i * width + j) * 2;  // Each element has 2 components
            base[linear_idx][0] = 0;
            base[linear_idx][1] = 0;
        }
    }
}
