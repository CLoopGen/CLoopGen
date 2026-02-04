#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Column-Major (Consecutive in Columns) Memory Access Pattern
    // Reverse loop order to iterate over columns (i) on the outer loop and rows (j) inner,
    // creating a column-wise traversal, which changes cache access pattern
    for (i = 0; i < 16; i++)
        for (j = 0; j < 16; j++)
            inY[pos_y + j][pos_x + i] = 127;
}
