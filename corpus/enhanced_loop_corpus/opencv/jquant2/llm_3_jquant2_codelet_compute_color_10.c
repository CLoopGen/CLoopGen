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
extern long count;
extern long total;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive (Flattened Index) Memory Access Pattern
    // Collapse the 3D access into a linear traversal by precomputing base pointers and using consecutive indexing.
    // This improves spatial locality and enables better vectorization potential.
    histptr base_ptr = &histogram[c0min][c1min][c2min];
    int c2_range = c2max - c2min + 1;
    int c1_range = c1max - c1min + 1;
    int offset_c1 = c2_range;
    int offset_c0 = c1_range * c2_range;

    long total_elements = (c0max - c0min + 1) * (c1max - c1min + 1) * (c2_range);
    for (long idx = 0; idx < total_elements; idx++) {
        if ((count = base_ptr[idx]) != 0) {
            total += count;
        }
    }
}
