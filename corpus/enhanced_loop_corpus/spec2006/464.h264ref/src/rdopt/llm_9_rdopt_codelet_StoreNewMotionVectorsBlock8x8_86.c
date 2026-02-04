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
    // Variant 2: Reduced trip count with increased nesting depth to simulate finer granularity computation
    // The original loop bounds are halved, and an additional inner loop over a new virtual index 'k' is introduced
    int k;
    for (j = j0; j < jj; j += 2) {  // Process every other j
        for (i = i0; i < ii; i += 2) {  // Process every other i
            for (int di = 0; di < 2 && (i + di) < ii; di++) {
                for (int dj = 0; dj < 2 && (j + dj) < jj; dj++) {
                    int ci = i + di;
                    int cj = j + dj;
                    // Perform initialization for each sub-element in 2x2 block
                    all_mv8x8[dir][0][ci][cj][0] = 0;
                    all_mv8x8[dir][0][ci][cj][1] = 0;
                    all_mv8x8[dir][1][ci][cj][0] = 0;
                    all_mv8x8[dir][1][ci][cj][1] = 0;
                }
            }
        }
    }
}
