#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate all data dependencies to enable full parallelization
    // Remove any potential loop-carried dependencies by unrolling and using independent writes
    // Each assignment is independent (no reuse of values), so no RAW, WAR, or WAW dependencies across iterations
    int idx;
    for (idx = 0; idx < 256; idx++) {
        int local_j = idx / 16;
        int local_i = idx % 16;
        inY[pos_y + local_j][pos_x + local_i] = 127;
    }
}
