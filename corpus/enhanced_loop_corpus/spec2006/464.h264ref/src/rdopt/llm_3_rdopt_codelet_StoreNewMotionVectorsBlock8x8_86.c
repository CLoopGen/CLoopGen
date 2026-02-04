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
    // Variant 2: Strided memory access with reversed loop order and fixed stride pattern
    // Iterate over the fastest-changing index first (j), then i, but unroll manually to create stride
    // This variant reverses loop nesting and accesses memory with a predictable stride
    for (i = i0; i < ii; i++) {
        for (j = j0; j < jj; j++) {
            // Access both [0] and [1] in the second index with explicit strided offsets
            // Increases stride across the second dimension (0 -> 1) while keeping i,j fixed
            all_mv8x8[dir][0][i][j][0] = 0;
            all_mv8x8[dir][1][i][j][0] = 0;
            all_mv8x8[dir][0][i][j][1] = 0;
            all_mv8x8[dir][1][i][j][1] = 0;
        }
    }
}
