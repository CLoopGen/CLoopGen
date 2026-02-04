#include <stdio.h>

#include <inttypes.h>

typedef unsigned short UINT16;

typedef UINT16 histcell;

typedef histcell hist1d[32];

typedef hist1d *hist2d;

typedef hist2d *hist3d;

typedef histcell *histptr;

extern hist3d histogram;
extern histptr histp;
extern int c0;
extern int c1;
extern int c2;
extern int c0min;
extern int c0max;
extern int c1min;
extern int c1max;
extern int c2min;
extern int c2max;
extern long ccount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity by collapsing three nested loops into two,
    // using manual indexing arithmetic to simulate 3D traversal in 2D loop structure.
    // Trip count is reduced logically by merging c0 and c1 into a single loop variable,
    // while still visiting all valid (c0,c1,c2) points. This reduces nesting depth and
    // total number of loop increment/compare operations, lowering control overhead.
    int total_c0 = c0max - c0min + 1;
    int total_c1 = c1max - c1min + 1;
    int total_c2 = c2max - c2min + 1;
    int total_outer = total_c0 * total_c1;

    for (int idx = 0; idx < total_outer; idx++) {
        c0 = c0min + idx / total_c1;
        c1 = c1min + idx % total_c1;
        histp = &histogram[c0][c1][c2min];
        for (c2 = 0; c2 < total_c2; c2++, histp++) {
            if (*histp != 0) {
                ccount++;
            }
        }
    }
}
