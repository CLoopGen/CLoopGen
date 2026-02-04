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
    // Variant 1: Introduce loop-carried dependency (WAW hazard) by reordering writes and introducing a temporary accumulation
    // This creates a WAW (Write-After-Write) dependence on j, making the loop carry a dependency across iterations
    unsigned short temp[16][16];
    for (j = 0; j < 16; j++)
        for (i = 0; i < 16; i++)
            temp[j][i] = refY[ref_inx][pos_y + j][pos_x + i];
    // Second loop introduces WAW if both loops wrote directly to inY; here we simulate delayed write
    for (j = 0; j < 16; j++)
        for (i = 0; i < 16; i++)
            inY[pos_y + j][pos_x + i] = temp[j][i];
}
