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
for (i = 0; i < (bsx >> 2); i++) {
    for (j = 0; j < (bsy >> 2); j++) {
        if ((block_x + i) % 3 == 0 && (block_y + j) % 3 == 0) {
            bipred_mv[block_x + i][block_y + j][iterlist][0][blocktype][0] = mv_x;
            bipred_mv[block_x + i][block_y + j][iterlist][0][blocktype][1] = mv_y;
        } else {
            bipred_mv[block_x + i][block_y + j][iterlist == 0 ? 1 : 0][0][blocktype][0] = bimv_x;
            bipred_mv[block_x + i][block_y + j][iterlist == 0 ? 1 : 0][0][blocktype][1] = bimv_y;
        }
    }
}
}
