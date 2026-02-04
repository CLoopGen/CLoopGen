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
    if (j0 < jj && i0 < ii) {  // Reduced loop nesting by collapsing into conditional and single loop
        int idx = 0;
        int total_elements = (jj - j0) * (ii - i0);
        for (idx = 0; idx < total_elements; idx++) {
            int local_i = i0 + idx / (jj - j0);
            int local_j = j0 + idx % (jj - j0);
            if (local_i < ii) {
                all_mv8x8[dir][0][local_i][local_j][0] = all_mv[local_i][local_j][0][fw_ref][4][0];
                all_mv8x8[dir][0][local_i][local_j][1] = all_mv[local_i][local_j][0][fw_ref][4][1];
                pred_mv8x8[dir][0][local_i][local_j][0] = pred_mv[local_i][local_j][0][fw_ref][4][0];
                pred_mv8x8[dir][0][local_i][local_j][1] = pred_mv[local_i][local_j][0][fw_ref][4][1];
            }
        }
    }
}
