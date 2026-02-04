#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int fw_ref;
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
    // Variant 2: Reduced trip count with higher nesting depth and conditional computation
    // Simulates irregular access pattern and reduced iterations but more complex control flow
    int step_i = 1;
    int step_j = 1;

    for (j = j0; j < jj; j += step_j) {
        for (i = i0; i < ii; i += step_i) {
            // Introduce conditional data dependency to vary effective computation
            short base_val_a = all_mv[i][j][0][fw_ref][4][0];
            short base_val_b = all_mv[i][j][0][fw_ref][4][1];
            short base_pred_a = pred_mv[i][j][0][fw_ref][4][0];
            short base_pred_b = pred_mv[i][j][0][fw_ref][4][1];

            // Additional micro-loop to simulate sub-computations
            for (int k = 0; k < 2; k++) {
                if (k == 0) {
                    all_mv8x8[dir][0][i][j][k] = base_val_a + k;
                    pred_mv8x8[dir][0][i][j][k] = base_pred_a + k;
                } else {
                    all_mv8x8[dir][0][i][j][k] = base_val_b ^ (k << 4);
                    pred_mv8x8[dir][0][i][j][k] = base_pred_b ^ (k << 4);
                }
            }
        }
    }
}
