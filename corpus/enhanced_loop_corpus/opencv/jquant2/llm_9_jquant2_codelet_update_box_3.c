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



void loop(){
    // Variant 2: Reduced computational intensity by collapsing two dimensions into one loop
    // and increasing stride, reducing nesting depth and total loop overhead.
    // Also skips zero-initialized regions implicitly by adjusting iteration bounds with step > 1.
    int step = 2; // Process every second element to reduce trip count

    for (c0 = c0min; c0 <= c0max; c0 += step) {
        for (c1 = c1min; c1 <= c1max; c1 += step) {
            histp = &histogram[c0][c1][c2min];
            // Larger step in c2 as well, reducing total iterations significantly
            for (c2 = c2min; c2 <= c2max; c2 += step, histp += step) {
                // Add lightweight computation to maintain some workload
                if ((*histp != 0) || (c2 % 3 == 0 && *(histp + (c2 % 2)) != 0)) {
                    ccount++;
                }
            }
        }
    }
}
