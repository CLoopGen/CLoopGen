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



void loop(){
    // Variant 1: Increased computational intensity by unrolling the innermost loop by a factor of 4
    // and reducing conditional branching with batch checking. This increases arithmetic operations
    // per iteration and reduces loop overhead, increasing computational intensity.
    for (c0 = c0min; c0 <= c0max; c0++) {
        for (c1 = c1min; c1 <= c1max; c1++) {
            histp = &histogram[c0][c1][c2min];
            int remaining = c2max - c2min + 1;
            int full_unroll_count = remaining / 4;
            int remainder = remaining % 4;

            // Unroll by 4
            for (int i = 0; i < full_unroll_count; i++) {
                if (histp[0] != 0) ccount++;
                if (histp[1] != 0) ccount++;
                if (histp[2] != 0) ccount++;
                if (histp[3] != 0) ccount++;
                histp += 4;
            }

            // Handle remainder
            for (int i = 0; i < remainder; i++, histp++) {
                if (*histp != 0) {
                    ccount++;
                }
            }
        }
    }
}
