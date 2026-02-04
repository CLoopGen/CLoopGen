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
    long temp_total = 0;
    long temp_weighted_c0 = 0;
    long temp_weighted_c1 = 0;
    long temp_weighted_c2 = 0;

    for (c0 = c0min; c0 <= c0max; c0++) {
        long base_c0_contrib = ((c0 << 3) + 4);
        for (c1 = c1min; c1 <= c1max; c1++) {
            long base_c1_contrib = ((c1 << 2) + 2);
            histp = &histogram[c0][c1][c2min];
            for (c2 = c2min; c2 <= c2max; c2++) {
                count = *(histp++);
                if (count == 0) continue;
                long base_c2_contrib = ((c2 << 3) + 4);

                temp_total += count;
                temp_weighted_c0 += base_c0_contrib * count;
                temp_weighted_c1 += base_c1_contrib * count;
                temp_weighted_c2 += base_c2_contrib * count;
            }
        }
    }

    total = temp_total;
    c0total = temp_weighted_c0;
    c1total = temp_weighted_c1;
    c2total = temp_weighted_c2;
}
