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
extern long count;
extern long total;
extern long c0total;
extern long c1total;
extern long c2total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Linear Indexing
    // Instead of using 3D array indexing, we compute a flat index to access histogram data
    // assuming row-major layout and known dimensions. We assume c2 dimension is fixed at 32.
    histptr base = &histogram[0][0][0];
    for (c0 = c0min; c0 <= c0max; c0++) {
        for (c1 = c1min; c1 <= c1max; c1++) {
            int base_idx = (c0 * 32 + c1) * 32 + c2min; // precompute starting index
            histp = base + base_idx;
            for (c2 = c2min; c2 <= c2max; c2++) {
                if ((count = *histp++) != 0) {
                    total += count;
                    c0total += ((c0 << (8 - 5)) + ((1 << (8 - 5)) >> 1)) * count;
                    c1total += ((c1 << (8 - 6)) + ((1 << (8 - 6)) >> 1)) * count;
                    c2total += ((c2 << (8 - 5)) + ((1 << (8 - 5)) >> 1)) * count;
                }
            }
        }
    }
}
