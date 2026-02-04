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
    // Variant 2: Eliminate all loop-carried dependencies by unrolling and reordering
    // Split into two independent loops with no data reuse or dependencies between iterations
    // First pass: zero out the region (independent writes - WAW only within same location, but no carry)
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            inY[pos_y + j][pos_x + i] = 0;
        }
    }
    // Second pass: copy from reference (RAW only, no loop-carried deps)
    // Since there's no reuse of computed values across iterations, no dependency chains exist
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
        }
    }
}
