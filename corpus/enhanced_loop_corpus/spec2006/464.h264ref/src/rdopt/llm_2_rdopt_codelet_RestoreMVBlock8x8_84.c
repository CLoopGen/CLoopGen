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
    // Variant 1: Consecutive memory access by reordering nested loops and flattening index calculation
    // This variant improves spatial locality by accessing memory in a more sequential pattern.
    int total_elements = (jj - j0) * (ii - i0);
    for (int idx = 0; idx < total_elements; idx++) {
        int local_j = j0 + (idx / (ii - i0));
        int local_i = i0 + (idx % (ii - i0));
        
        all_mv[local_i][local_j][1][bw_ref][mode][0] = all_mv8x8[dir][1][local_i][local_j][0];
        all_mv[local_i][local_j][1][bw_ref][mode][1] = all_mv8x8[dir][1][local_i][local_j][1];
        pred_mv[local_i][local_j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][local_i][local_j][0];
        pred_mv[local_i][local_j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][local_i][local_j][1];
    }
}
