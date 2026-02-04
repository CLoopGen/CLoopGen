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
    for (int idx = 0; idx < 256; idx++) {
        int j = idx / 16;
        int i = idx % 16;
        inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
    }
}
