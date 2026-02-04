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



void loop() {
    // Variant 1: Increased computational intensity with unrolled inner loop and additional arithmetic operations
    for (c0 = c0min; c0 <= c0max; c0++) {
        for (c1 = c1min; c1 <= c1max; c1++) {
            histp = &histogram[c0][c1][c2min];
            c2 = c2min;
            // Unroll by 2 to increase arithmetic per iteration
            for (; c2 <= c2max - 1; c2 += 2) {
                long count1 = histp[0];
                long count2 = histp[1];
                histp += 2;

                if (count1 != 0) {
                    total += count1;
                    long c0val = (c0 << 3) + 4;
                    long c1val = (c1 << 2) + 2;
                    long c2val = (c2 << 3) + 4;
                    c0total += c0val * count1;
                    c1total += c1val * count1;
                    c2total += c2val * count1;
                }
                if (count2 != 0) {
                    total += count2;
                    long c0val = (c0 << 3) + 4;
                    long c1val = (c1 << 2) + 2;
                    long c2val = ((c2 + 1) << 3) + 4;
                    c0total += c0val * count2;
                    c1total += c1val * count2;
                    c2total += c2val * count2;
                }
            }
            // Handle remaining element
            if (c2 <= c2max) {
                if ((count = *histp++) != 0) {
                    total += count;
                    c0total += ((c0 << 3) + 4) * count;
                    c1total += ((c1 << 2) + 2) * count;
                    c2total += ((c2 << 3) + 4) * count;
                }
            }
        }
    }
}
