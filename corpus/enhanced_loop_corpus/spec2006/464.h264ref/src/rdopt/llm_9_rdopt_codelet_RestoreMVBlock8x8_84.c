#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int bw_ref;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;
extern short ******all_mv;
extern short ******pred_mv;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 2: Reduced computational intensity with coalesced outer loop and fewer memory accesses
    // Combine both loops into a single loop with linear index, reduce effective trip count by skipping every other element
    int total_iterations = (jj - j0) * ((ii - i0 + 1) / 2); // Approximate reduced trip count
    for (int idx = 0; idx < total_iterations; idx++) {
        i = i0 + (idx * 2) % (ii - i0); // Step by 2 in i to reduce work
        j = j0 + (idx * 2) / (ii - i0);

        if (i >= ii) continue;

        // Only one assignment per dimension, reducing total memory operations by half
        all_mv[i][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i][j][0];
        pred_mv[i][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i][j][0];
    }
}
