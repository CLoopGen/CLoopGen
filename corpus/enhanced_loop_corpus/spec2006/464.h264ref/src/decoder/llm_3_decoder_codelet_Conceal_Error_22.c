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
    // Variant 2: Strided memory access - process columns first with fixed column index, stepping through rows
    // This creates a strided access pattern in memory, potentially less cache-efficient but shows different traversal
    for (i = 0; i < 16; i++)
        for (j = 0; j < 16; j++)
            inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
}
