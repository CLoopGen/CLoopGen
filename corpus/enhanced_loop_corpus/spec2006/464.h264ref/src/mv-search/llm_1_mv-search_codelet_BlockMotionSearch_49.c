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
for (i = 0; i < (bsx >> 2); i++) {
    for (j = 0; j < (bsy >> 2); j++) {
        for (int k = 0; k < 1; k++) {
            all_mv[block_x + i][block_y + j][list][ref][blocktype][k] = (k == 0) ? mv_x : mv_y;
        }
    }
}
}
