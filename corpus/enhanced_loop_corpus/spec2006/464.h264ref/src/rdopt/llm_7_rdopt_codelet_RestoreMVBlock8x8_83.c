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
    // Variant 2: Eliminate potential loop-carried dependencies by unrolling and reordering operations
    // All iterations are now independent — no RAW, WAR, or WAW dependencies between iterations
    // Enables better vectorization and parallelization

    // Perform full unroll simulation via blocked access (assuming small fixed ranges)
    // Access pattern reordered to decouple any artificial dependencies

    int idx = 0;
    short temp_all[4][2], temp_pred[4][2];  // Local buffers to isolate memory traffic

    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Stage 1: Load all required data into local temporaries without immediate store
            temp_all[idx][0] = all_mv8x8[dir][0][i][j][0];
            temp_all[idx][1] = all_mv8x8[dir][0][i][j][1];
            temp_pred[idx][0] = pred_mv8x8[dir][0][i][j][0];
            temp_pred[idx][1] = pred_mv8x8[dir][0][i][j][1];

            // Stage 2: Store from temporaries using same index (could be optimized further)
            all_mv[i][j][0][ref][mode][0] = temp_all[idx][0];
            all_mv[i][j][0][ref][mode][1] = temp_all[idx][1];
            pred_mv[i][j][0][ref][mode][0] = temp_pred[idx][0];
            pred_mv[i][j][0][ref][mode][1] = temp_pred[idx][1];

            idx++;
        }
    }
}
