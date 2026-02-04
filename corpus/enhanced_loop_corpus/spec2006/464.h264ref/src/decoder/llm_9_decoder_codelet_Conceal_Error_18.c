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
for (j = 0; j < 8; j++)
    for (i = 0; i < 32; i++) {
        int y_idx = pos_y + j;
        int x_idx = pos_x + i;
        if (i < 16) 
            inY[y_idx][x_idx] = refY[ref_inx][y_idx][x_idx];
        else 
            inY[y_idx][x_idx - 16] = refY[ref_inx][y_idx][x_idx - 16];
    }
}
