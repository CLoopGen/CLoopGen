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



void loop() {
    // Variant 1: Consecutive memory access with flattened indexing
    // Instead of using 3D array notation, we calculate a linear index
    // assuming row-major layout and stride-based traversal for better spatial locality.
    histptr base = &histogram[0][0][0];
    int stride_c2 = 1;
    int stride_c1 = (c2max - c2min + 1);
    int stride_c0 = (c1max - c1min + 1) * stride_c1;

    ccount = 0;
    for (c0 = c0min; c0 <= c0max; c0++) {
        int offset_c0 = (c0 - 0) * stride_c0;
        for (c1 = c1min; c1 <= c1max; c1++) {
            int offset_c1 = (c1 - 0) * stride_c1;
            int base_offset = offset_c0 + offset_c1 + (c2min - 0);
            for (c2 = c2min; c2 <= c2max; c2++) {
                if (*(base + base_offset + (c2 - c2min)) != 0) {
                    ccount++;
                }
            }
        }
    }
}
