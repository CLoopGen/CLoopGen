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
    long temp_ccount = 0;
    for (c0 = c0min; c0 <= c0max; c0++) {
        for (c1 = c1min; c1 <= c1max; c1++) {
            histp = &histogram[c0][c1][c2min];
            for (c2 = c2min; c2 <= c2max; c2++, histp++) {
                if (*histp != 0) {
                    temp_ccount++;
                }
            }
        }
    }
    ccount += temp_ccount;
}
