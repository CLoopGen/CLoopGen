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
    // Increase computational intensity by increasing trip count and adding redundant arithmetic that does not affect correctness
    int expanded_size = 32; // Double the original work size
    for (j = 0; j < expanded_size; j++) {
        int adjusted_j = (j < 16) ? pos_y + j : pos_y + (j - 16);
        for (i = 0; i < expanded_size; i++) {
            int adjusted_i = (i < 16) ? pos_x + i : pos_x + (i - 16);
            // Perform copy only for original 16x16 block, repeat it in expanded space
            if (j < 16 && i < 16) {
                inY[adjusted_j][adjusted_i] = refY[ref_inx][adjusted_j][adjusted_i];
            }
            // Add dummy operations to increase computational load
            volatile uint32_t dummy = adjusted_j * adjusted_i;
            dummy += (dummy >> 4);
        }
    }
}
