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
extern short ***mv_array;
extern short ******all_mv;
extern int h4x4blkno;
extern int v4x4blkno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total = (bsx >> 2) * (bsy >> 2);
for (i = 0; i < total; i++) {
    int idx_i = i / (bsy >> 2);
    int idx_j = i % (bsy >> 2);
    all_mv[block_x + idx_i][block_y + idx_j][list][ref][blocktype][0] = mv_x;
    all_mv[block_x + idx_i][block_y + idx_j][list][ref][blocktype][1] = mv_y;
    mv_array[h4x4blkno + idx_i][v4x4blkno + idx_j][0] = mv_x;
    mv_array[h4x4blkno + idx_i][v4x4blkno + idx_j][1] = mv_y;
}
}
