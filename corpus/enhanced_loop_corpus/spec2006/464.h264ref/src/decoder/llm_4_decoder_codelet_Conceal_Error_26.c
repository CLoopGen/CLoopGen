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
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            if (!(pos_y + j >= 0 && pos_x + i >= 0)) continue;
            inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
        }
    }
}
