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
for (i = 0; i < (bsx >> 2); i++) {
    all_mv[block_x + i][block_y][list][ref][blocktype][0] = mv_x;
    all_mv[block_x + i][block_y][list][ref][blocktype][1] = mv_y;
    mv_array[h4x4blkno + i][v4x4blkno][0] = mv_x;
    mv_array[h4x4blkno + i][v4x4blkno][1] = mv_y;
}
for (j = 1; j < (bsy >> 2); j++) {
    all_mv[block_x][block_y + j][list][ref][blocktype][0] = mv_x;
    all_mv[block_x][block_y + j][list][ref][blocktype][1] = mv_y;
    mv_array[h4x4blkno][v4x4blkno + j][0] = mv_x;
    mv_array[h4x4blkno][v4x4blkno + j][1] = mv_y;
}
}
