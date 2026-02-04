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
    // Variant 2: Reduced trip count with increased stride and simplified operations
    // Simulates early termination and coarse-grained traversal
    int step_i = 2;
    int step_j = 2;
    for (j = j0; j < jj; j += step_j)
        for (i = i0; i < ii; i += step_i) {
            // Only write one component, reducing memory operations
            all_mv8x8[dir][0][i][j][0] = 0;
            // Skip assignment to [1] component to reduce work
        }
}
