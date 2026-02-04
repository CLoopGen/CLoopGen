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
for (i = 0; i < (bsx >> 2); i += 2) {
    for (j = 0; j < (bsy >> 2); j += 2) {
        all_mv[block_x + i][block_y + j][list][ref][blocktype][0] = mv_x;
        all_mv[block_x + i][block_y + j][list][ref][blocktype][1] = mv_y;
        if (i + 1 < (bsx >> 2)) {
            all_mv[block_x + i + 1][block_y + j][list][ref][blocktype][0] = mv_x;
            all_mv[block_x + i + 1][block_y + j][list][ref][blocktype][1] = mv_y;
        }
        if (j + 1 < (bsy >> 2)) {
            all_mv[block_x + i][block_y + j + 1][list][ref][blocktype][0] = mv_x;
            all_mv[block_x + i][block_y + j + 1][list][ref][blocktype][1] = mv_y;
        }
    }
}
}
