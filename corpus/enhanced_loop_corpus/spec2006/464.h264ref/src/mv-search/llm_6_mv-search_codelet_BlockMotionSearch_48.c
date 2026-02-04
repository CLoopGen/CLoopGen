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
    short temp_mv_x, temp_mv_y;
    for (i = 0; i < (bsx >> 2); i++) {
        temp_mv_x = mv_x + i; // Introduce temporary variables with loop index dependency
        temp_mv_y = mv_y + i;
        for (j = 0; j < (bsy >> 2); j++) {
            // Introduce WAR and WAW dependencies by reordering and overwriting
            mv_array[h4x4blkno + i][v4x4blkno + j][1] = temp_mv_y;
            all_mv[block_x + i][block_y + j][list][ref][blocktype][1] = temp_mv_y;
            all_mv[block_x + i][block_y + j][list][ref][blocktype][0] = temp_mv_x;
            mv_array[h4x4blkno + i][v4x4blkno + j][0] = temp_mv_x;
        }
    }
}
