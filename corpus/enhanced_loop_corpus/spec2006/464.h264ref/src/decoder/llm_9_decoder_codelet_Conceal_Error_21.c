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
for (j = 0; j < 8; j++) {
    int offset_y = pos_y + j * 2;
    for (i = 0; i < 8; i++) {
        int offset_x = pos_x + i * 2;
        inY[offset_y][offset_x] = refY[ref_inx][offset_y][offset_x];
        inY[offset_y + 1][offset_x] = refY[ref_inx][offset_y + 1][offset_x];
        inY[offset_y][offset_x + 1] = refY[ref_inx][offset_y][offset_x + 1];
        inY[offset_y + 1][offset_x + 1] = refY[ref_inx][offset_y + 1][offset_x + 1];
    }
}
}
