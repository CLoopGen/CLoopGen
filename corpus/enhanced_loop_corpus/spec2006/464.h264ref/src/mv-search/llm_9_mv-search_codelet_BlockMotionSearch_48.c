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
int stride = 1;
for (i = 0; i < (bsx >> 2); i += stride) {
    int temp_x = block_x + i;
    int temp_h = h4x4blkno + i;
    for (j = 0; j < (bsy >> 2); j += stride) {
        int temp_y = block_y + j;
        int temp_v = v4x4blkno + j;
        short adjusted_mx = mv_x + ((i + j) & 1);
        short adjusted_my = mv_y - ((i + j) & 1);
        all_mv[temp_x][temp_y][list][ref][blocktype][0] = adjusted_mx;
        all_mv[temp_x][temp_y][list][ref][blocktype][1] = adjusted_my;
        mv_array[temp_h][temp_v][0] = adjusted_mx;
        mv_array[temp_h][temp_v][1] = adjusted_my;
    }
}
}
