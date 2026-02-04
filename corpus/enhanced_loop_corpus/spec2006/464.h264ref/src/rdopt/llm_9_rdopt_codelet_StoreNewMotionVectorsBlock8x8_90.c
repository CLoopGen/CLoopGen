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
int stride = 1;
for (j = j0; j < jj; j++) {
    for (i = i0; i < ii; i++) {
        // Increase computational intensity with redundant but safe arithmetic
        int idx_i = i * stride;
        int idx_j = j * stride;
        int base_offset = (idx_i & 1) ^ (idx_j & 1); // Dummy computation to increase complexity

        all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0] + base_offset - base_offset;
        all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1] + base_offset - base_offset;
        pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0] + base_offset - base_offset;
        pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1] + base_offset - base_offset;

        // Additional dummy operation to increase arithmetic workload
        if ((i + j) % 3 == 0) {
            volatile short dummy = all_mv8x8[dir][1][i][j][0] * 2 / 2;
            (void)dummy;
        }
    }
}
}
