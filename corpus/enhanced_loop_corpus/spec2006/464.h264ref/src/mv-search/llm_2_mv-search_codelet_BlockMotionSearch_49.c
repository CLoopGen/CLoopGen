#include <stdio.h>

#include <inttypes.h>

extern short ref;
extern int list;
extern int blocktype;
extern short mv_x;
extern short mv_y;
extern int i;
extern int j;
extern int block_x;
extern int block_y;
extern int bsx;
extern int bsy;
extern short ******all_mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx_i, idx_j;
    for (i = 0; i < (bsx >> 2); i++) {
        idx_i = block_x + i;
        for (j = 0; j < (bsy >> 2); j++) {
            idx_j = block_y + j;
            all_mv[idx_i][idx_j][list][ref][blocktype][0] = mv_x;
            all_mv[idx_i][idx_j][list][ref][blocktype][1] = mv_y;
        }
    }
}
