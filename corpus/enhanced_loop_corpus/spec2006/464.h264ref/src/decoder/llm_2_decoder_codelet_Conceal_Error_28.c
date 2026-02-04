#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major order, access elements with a stride by iterating over i first and then j,
    // effectively writing in column-major fashion to create a strided access pattern in memory.
    for (i = 0; i < 16; i++)
        for (j = 0; j < 16; j++)
            inY[pos_y + j][pos_x + i] = 127;
}
