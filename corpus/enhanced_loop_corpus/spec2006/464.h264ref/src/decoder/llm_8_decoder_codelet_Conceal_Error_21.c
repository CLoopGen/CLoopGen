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
for (j = 0; j < 32; j += 2)
    for (i = 0; i < 32; i += 2) {
        inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
        if (j + 1 < 32) inY[pos_y + j + 1][pos_x + i] = refY[ref_inx][pos_y + j + 1][pos_x + i];
        if (i + 1 < 32) inY[pos_y + j][pos_x + i + 1] = refY[ref_inx][pos_y + j][pos_x + i + 1];
        if (j + 1 < 32 && i + 1 < 32) 
            inY[pos_y + j + 1][pos_x + i + 1] = refY[ref_inx][pos_y + j + 1][pos_x + i + 1];
    }
}
