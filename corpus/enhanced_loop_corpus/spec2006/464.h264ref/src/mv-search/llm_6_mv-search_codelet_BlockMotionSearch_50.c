#include <stdio.h>

#include <inttypes.h>

extern int blocktype;
extern short mv_x;
extern short mv_y;
extern int i;
extern int j;
extern int block_x;
extern int block_y;
extern int bsx;
extern int bsy;
extern short ******bipred_mv;
extern short bimv_x;
extern short bimv_y;
extern short iterlist;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short temp_mv_x, temp_mv_y, temp_bimv_x, temp_bimv_y;
    int idx_i, idx_j, list_index;
    
    for (i = 0; i < (bsx >> 2); i++) {
        idx_i = block_x + i;
        temp_mv_x = mv_x;
        temp_mv_y = mv_y;
        temp_bimv_x = bimv_x;
        temp_bimv_y = bimv_y;

        for (j = 0; j < (bsy >> 2); j++) {
            idx_j = block_y + j;
            list_index = iterlist == 0 ? 1 : 0;

            // Introduce temporary variables to eliminate repeated computation of ternary
            // This removes redundant calculations (eliminates some WAW on condition evaluation)
            // Also introduces local data dependency within the iteration (RAW via temp vars)

            bipred_mv[idx_i][idx_j][iterlist][0][blocktype][0] = temp_mv_x;
            bipred_mv[idx_i][idx_j][iterlist][0][blocktype][1] = temp_mv_y;
            bipred_mv[idx_i][idx_j][list_index][0][blocktype][0] = temp_bimv_x;
            bipred_mv[idx_i][idx_j][list_index][0][blocktype][1] = temp_bimv_y;
        }
    }
}
