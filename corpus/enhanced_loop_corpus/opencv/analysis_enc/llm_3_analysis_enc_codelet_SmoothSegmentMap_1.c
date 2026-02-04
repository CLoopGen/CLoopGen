#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern  int w;
extern  int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (linearized) access pattern using a single loop
    // Simulate row-major traversal with consecutive indexing, mapping 1D index to 2D coordinates
    int idx;
    for (idx = w + 1; idx < (h - 1) * w + (w - 1); ++idx) {
        y = idx / w;
        x = idx % w;
        // Skip invalid positions to stay within inner bounds (equivalent to original nested loop)
        if (x >= w - 1 || x < 1 || y >= h - 1 || y < 1) continue;
    }
}
