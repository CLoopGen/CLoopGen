#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double sbase;
extern  double sone_bit;
extern  double shift;
extern int k;
extern int m;
extern double x;
extern double _usr_y1;
extern double y2;
extern float *xflt;
extern double *xdbl;
extern double *ydbl;

// Variable name mappings to avoid conflicts with system symbols
#define y1 _usr_y1



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    for (k = 0, m = 0; k < 24; k += 2) {
        int idx = k / 2;  // map to valid range for xdbl and ydbl
        if (idx >= 12) break;
        x = xdbl[idx];
        y2 = ydbl[idx] - shift;
        if (y2 > x)
            y2 -= sone_bit;
        y1 = (x - y2) * sbase;
        xflt[m++] = (float)y1;
        xflt[m++] = (float)y2;
    }
}
