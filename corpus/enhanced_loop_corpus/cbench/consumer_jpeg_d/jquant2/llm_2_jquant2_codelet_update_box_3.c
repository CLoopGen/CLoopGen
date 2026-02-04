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
    // Variant 1: Consecutive memory access using pointer arithmetic with precomputed stride
    histptr base_ptr = &histogram[c0min][c1min][c2min];
    int c0_extent = c0max - c0min + 1;
    int c1_extent = c1max - c1min + 1;
    int c2_extent = c2max - c2min + 1;
    int total_size_2d = 32 * 32;  // Assuming fixed size for inner dimensions
    long index = 0;

    for (c0 = 0; c0 < c0_extent; c0++) {
        for (c1 = 0; c1 < c1_extent; c1++) {
            histp = base_ptr + (c0 * 32 + c1) * 32 + (c2min - 0);
            for (c2 = 0; c2 < c2_extent; c2++) {
                if (*(histp + c2) != 0) {
                    ccount++;
                }
            }
        }
    }
}
