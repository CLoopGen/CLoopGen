#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern unsigned short ***refY;
extern int i;
extern int j;
extern int ref_inx;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j_start = pos_y;
    int j_end = pos_y + 16;
    int i_step = 2;
    for (j = 0; j < 16; j++) {
        int row_offset = j_start + j;
        for (i = 0; i < 16; i += i_step) {
            // Unroll loop partially: two assignments per iteration
            inY[row_offset][pos_x + i] = refY[ref_inx][row_offset][pos_x + i];
            if (i + 1 < 16) {
                inY[row_offset][pos_x + i + 1] = refY[ref_inx][row_offset][pos_x + i + 1];
            }
        }
    }
}
