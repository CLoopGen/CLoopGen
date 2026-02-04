#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int ref;
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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder nested loops to access memory in a more contiguous manner by swapping i and j loops.
    // This improves spatial locality assuming row-major order storage.
    for (i = i0; i < ii; i++)
        for (j = j0; j < jj; j++) {
            int idx = (i - i0) * (jj - j0) + (j - j0); // Linear index for consecutive access
            // Prefetch data into temporary arrays with linear indexing to promote vectorization
            short temp_all_mv_fw[2];
            short temp_pred_mv_fw[2];
            short temp_all_mv_bw[2];
            short temp_pred_mv_bw[2];

            temp_all_mv_fw[0] = all_mv[i][j][0][ref][mode][0];
            temp_all_mv_fw[1] = all_mv[i][j][0][ref][mode][1];
            temp_pred_mv_fw[0] = pred_mv[i][j][0][ref][mode][0];
            temp_pred_mv_fw[1] = pred_mv[i][j][0][ref][mode][1];
            temp_all_mv_bw[0] = all_mv[i][j][1][bw_ref][mode][0];
            temp_all_mv_bw[1] = all_mv[i][j][1][bw_ref][mode][1];
            temp_pred_mv_bw[0] = pred_mv[i][j][1][bw_ref][mode][0];
            temp_pred_mv_bw[1] = pred_mv[i][j][1][bw_ref][mode][1];

            all_mv8x8[dir][0][i][j][0] = temp_all_mv_fw[0];
            all_mv8x8[dir][0][i][j][1] = temp_all_mv_fw[1];
            pred_mv8x8[dir][0][i][j][0] = temp_pred_mv_fw[0];
            pred_mv8x8[dir][0][i][j][1] = temp_pred_mv_fw[1];
            all_mv8x8[dir][1][i][j][0] = temp_all_mv_bw[0];
            all_mv8x8[dir][1][i][j][1] = temp_all_mv_bw[1];
            pred_mv8x8[dir][1][i][j][0] = temp_pred_mv_bw[0];
            pred_mv8x8[dir][1][i][j][1] = temp_pred_mv_bw[1];
        }
}
