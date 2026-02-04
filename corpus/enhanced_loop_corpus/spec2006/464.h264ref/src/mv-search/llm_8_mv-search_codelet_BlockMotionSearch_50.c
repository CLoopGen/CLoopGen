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
int i_start = 0;
int i_end = (bsx >> 2);
int j_step = 2;
for (i = i_start; i < i_end; i++) {
    for (j = 0; j < (bsy >> 2); j += j_step) {
        int idx_i = block_x + i;
        int idx_j = block_y + j;
        int iter_flip = iterlist == 0 ? 1 : 0;

        bipred_mv[idx_i][idx_j][iterlist][0][blocktype][0] = mv_x;
        bipred_mv[idx_i][idx_j][iterlist][0][blocktype][1] = mv_y;
        bipred_mv[idx_i][idx_j][iter_flip][0][blocktype][0] = bimv_x;
        bipred_mv[idx_i][idx_j][iter_flip][0][blocktype][1] = bimv_y;

        if (j + 1 < (bsy >> 2)) {
            int idx_j_next = block_y + j + 1;
            bipred_mv[idx_i][idx_j_next][iterlist][0][blocktype][0] = mv_x;
            bipred_mv[idx_i][idx_j_next][iterlist][0][blocktype][1] = mv_y;
            bipred_mv[idx_i][idx_j_next][iter_flip][0][blocktype][0] = bimv_x;
            bipred_mv[idx_i][idx_j_next][iter_flip][0][blocktype][1] = bimv_y;
        }
    }
}
}
