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
    // Variant 2: Strided memory access – traverse in a non-consecutive pattern across c0 for better cache behavior under certain access patterns
    // We reverse the loop order to c2 -> c1 -> c0 and use strided access through histogram
    ccount = 0;
    for (c2 = c2min; c2 <= c2max; c2++) {
        for (c1 = c1min; c1 <= c1max; c1++) {
            for (c0 = c0min; c0 <= c0max; c0++) {
                // Access is now strided in c0 dimension: each iteration jumps by a large stride in memory
                if (histogram[c0][c1][c2] != 0) {
                    ccount++;
                }
            }
        }
    }
}
