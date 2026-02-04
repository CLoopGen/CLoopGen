#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
    int c0_extent = (c0max - c0min + 1);
    int c1_extent = (c1max - c1min + 1);
    int c2_extent = (c2max - c2min + 1);
    int total_c2 = 32;  // Assuming fixed second dimension size
    int total_c1c2 = 32 * 32;

    ccount = 0;
    for (c0 = 0; c0 < c0_extent; c0++) {
        for (c1 = 0; c1 < c1_extent; c1++) {
            histptr row_start = base_ptr + c0 * total_c1c2 + c1 * total_c2 + (c2min);
            for (c2 = 0; c2 < c2_extent; c2++) {
                if (*(row_start + c2) != 0) {
                    ccount++;
                }
            }
        }
    }
}
