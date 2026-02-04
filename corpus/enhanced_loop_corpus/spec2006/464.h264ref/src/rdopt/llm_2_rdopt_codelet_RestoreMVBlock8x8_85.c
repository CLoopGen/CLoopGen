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
    // Variant 1: Consecutive Memory Access via Loop Interchange and Linear Indexing
    // Reorder loop for better spatial locality and use flattened indexing to promote consecutive access
    int idx = 0;
    for (i = i0; i < ii; i++) {
        for (j = j0; j < jj; j++) {
            short *src_mv_8x8_fw_d0 = &all_mv8x8[dir][0][i][j][0];
            short *src_mv_8x8_bw_d1 = &all_mv8x8[dir][1][i][j][0];
            short *src_pred_8x8_fw_d0 = &pred_mv8x8[dir][0][i][j][0];
            short *src_pred_8x8_bw_d1 = &pred_mv8x8[dir][1][i][j][0];

            all_mv[i][j][0][ref][mode][0] = src_mv_8x8_fw_d0[0];
            all_mv[i][j][0][ref][mode][1] = src_mv_8x8_fw_d0[1];
            pred_mv[i][j][0][ref][mode][0] = src_pred_8x8_fw_d0[0];
            pred_mv[i][j][0][ref][mode][1] = src_pred_8x8_fw_d0[1];

            all_mv[i][j][1][bw_ref][mode][0] = src_mv_8x8_bw_d1[0];
            all_mv[i][j][1][bw_ref][mode][1] = src_mv_8x8_bw_d1[1];
            pred_mv[i][j][1][bw_ref][mode][0] = src_pred_8x8_bw_d1[0];
            pred_mv[i][j][1][bw_ref][mode][1] = src_pred_8x8_bw_d1[1];
        }
    }
}
