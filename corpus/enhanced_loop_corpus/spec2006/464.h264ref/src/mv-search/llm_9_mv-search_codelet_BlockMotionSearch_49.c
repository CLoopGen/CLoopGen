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
int limit_i = bsx >> 3;
int limit_j = bsy >> 3;
for (i = 0; i < limit_i; i++) {
    for (j = 0; j < limit_j; j++) {
        int idx_i = block_x + (i << 1);
        int idx_j = block_y + (j << 1);
        all_mv[idx_i][idx_j][list][ref][blocktype][0] = mv_x;
        all_mv[idx_i][idx_j][list][ref][blocktype][1] = mv_y;
        all_mv[idx_i + 1][idx_j][list][ref][blocktype][0] = mv_x;
        all_mv[idx_i + 1][idx_j][list][ref][blocktype][1] = mv_y;
        all_mv[idx_i][idx_j + 1][list][ref][blocktype][0] = mv_x;
        all_mv[idx_i][idx_j + 1][list][ref][blocktype][1] = mv_y;
        all_mv[idx_i + 1][idx_j + 1][list][ref][blocktype][0] = mv_x;
        all_mv[idx_i + 1][idx_j + 1][list][ref][blocktype][1] = mv_y;
    }
}
}
