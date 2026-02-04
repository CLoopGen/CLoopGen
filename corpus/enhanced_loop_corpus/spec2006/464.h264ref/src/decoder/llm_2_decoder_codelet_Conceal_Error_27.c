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
    // Variant 1: Strided Memory Access Pattern
    // Access memory with a stride of 2, then handle remaining elements in a second pass for completeness.
    // This changes the access pattern to non-consecutive, touching every other element first.
    int stride = 2;
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i += stride) {
            inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
            if (i + 1 < 16) {
                inY[pos_y + j][pos_x + i + 1] = refY[ref_inx][pos_y + j][pos_x + i + 1];
            }
        }
    }
}
