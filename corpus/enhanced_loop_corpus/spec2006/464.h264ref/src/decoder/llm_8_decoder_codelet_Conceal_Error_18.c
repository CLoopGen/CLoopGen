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
int i_start = pos_x;
int i_end = pos_x + 16;
for (j = j_start; j < j_end; j += 2)
    for (i = i_start; i < i_end; i += 2) {
        inY[j][i] = refY[ref_inx][j][i];
        if (i+1 < i_end) inY[j][i+1] = refY[ref_inx][j][i+1];
        if (j+1 < j_end) inY[j+1][i] = refY[ref_inx][j+1][i];
        if (j+1 < j_end && i+1 < i_end) inY[j+1][i+1] = refY[ref_inx][j+1][i+1];
    }
}
