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
    for (j = 0; j < (bsy >> 2); j += 2) {
        if (block_x + i < 64 && block_y + j < 64) {
            all_mv[block_x + i][block_y + j][list][ref][blocktype][0] = mv_x;
            all_mv[block_x + i][block_y + j][list][ref][blocktype][1] = mv_y;
            mv_array[h4x4blkno + i][v4x4blkno + j][0] = mv_x;
            mv_array[h4x4blkno + i][v4x4blkno + j][1] = mv_y;
        }
        if (j + 1 < (bsy >> 2) && block_x + i < 64 && block_y + j + 1 < 64) {
            all_mv[block_x + i][block_y + j + 1][list][ref][blocktype][0] = mv_x + 1;
            all_mv[block_x + i][block_y + j + 1][list][ref][blocktype][1] = mv_y + 1;
            mv_array[h4x4blkno + i][v4x4blkno + j + 1][0] = mv_x + 1;
            mv_array[h4x4blkno + i][v4x4blkno + j + 1][1] = mv_y + 1;
        }
    }
}
}
