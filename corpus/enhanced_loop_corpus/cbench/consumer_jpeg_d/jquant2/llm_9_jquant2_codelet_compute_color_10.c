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
    // Variant 2: Reduced computational intensity with collapsed loops and fewer iterations
    // Collapse c0 and c1 into a single loop with reduced effective trip count
    int range0 = c0max - c0min + 1;
    int range1 = c1max - c1min + 1;
    int total_outer = (range0 * range1 + 3) / 4; // Process 4 (c0,c1) pairs per iteration

    for (int idx = 0; idx < total_outer; idx++) {
        int base_c0 = c0min + (idx * 4) / range1;
        int base_c1 = c1min + (idx * 4) % range1;

        // Process up to 4 (c0, c1) combinations per outer iteration
        for (int offset = 0; offset < 4; offset++) {
            int curr_c0 = base_c0;
            int curr_c1 = base_c1 + offset;
            if (curr_c1 >= c1min + range1) {
                curr_c0++;
                curr_c1 -= range1;
            }
            if (curr_c0 > c0max) break;

            histp = &histogram[curr_c0][curr_c1][c2min];
            for (c2 = c2min; c2 <= c2max; c2++) {
                if ((count = *histp++) != 0) {
                    total += count;
                    // Simplified fixed-point shift (reduced precision)
                    c0total += (curr_c0 << 3) * count;
                    c1total += (curr_c1 << 1) * count;
                    c2total += (c2 << 3) * count;
                }
            }
        }
    }
}
