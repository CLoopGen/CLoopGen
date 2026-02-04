#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int ref;
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
    // Variant 2: Reduced computational intensity with coalesced outer loop and increased stride
    // Increase loop stride to reduce trip count and skip some elements, simulating lower resolution processing
    int stride = 2;
    for (j = j0; j < jj; j += stride) {
        for (i = i0; i < ii; i += stride) {
            // Only update one component with minimal arithmetic to reduce intensity
            all_mv[i][j][0][ref][mode][0] = all_mv8x8[dir][0][i][j][0];
            // Skip other assignments to reduce work per iteration
        }
    }
    // Perform a second pass with offset to maintain coverage (if needed), but simplified
    for (j = j0 + 1; j < jj; j += stride) {
        for (i = i0 + 1; i < ii; i += stride) {
            pred_mv[i][j][0][ref][mode][0] = pred_mv8x8[dir][0][i][j][0];
        }
    }
}
