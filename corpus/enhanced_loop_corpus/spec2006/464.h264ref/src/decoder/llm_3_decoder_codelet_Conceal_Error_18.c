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
    // Variant 2: Strided memory access with increased stride in the inner loop
    // Instead of sequential access, we access every second element in a tiled pattern,
    // then fill in the gaps — this creates a non-unit stride access pattern.
    // The full 16x16 block is still covered using two passes with offset starts.
    int stride = 2;
    for (int pass = 0; pass < stride; pass++) {
        for (j = 0; j < 16; j++) {
            for (i = pass; i < 16; i += stride) {
                inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
            }
        }
    }
}
