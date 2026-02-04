#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    // Inner loop unrolled by factor of 4, reducing loop overhead and increasing arithmetic per iteration
    for (j = 0; j < 16; j += 2) {
        for (i = 0; i < 16; i += 4) {
            inY[pos_y + j    ][pos_x + i    ] = 127;
            if (i + 1 < 16) inY[pos_y + j    ][pos_x + i + 1] = 127;
            if (i + 2 < 16) inY[pos_y + j    ][pos_x + i + 2] = 127;
            if (i + 3 < 16) inY[pos_y + j    ][pos_x + i + 3] = 127;
            if (j + 1 < 16) {
                inY[pos_y + j + 1][pos_x + i    ] = 127;
                if (i + 1 < 16) inY[pos_y + j + 1][pos_x + i + 1] = 127;
                if (i + 2 < 16) inY[pos_y + j + 1][pos_x + i + 2] = 127;
                if (i + 3 < 16) inY[pos_y + j + 1][pos_x + i + 3] = 127;
            }
        }
    }
}
