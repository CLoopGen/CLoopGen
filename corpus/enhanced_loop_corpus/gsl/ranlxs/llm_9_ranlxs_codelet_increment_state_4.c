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
for (k = 0, m = 0; k < 6; ++k) {
    int idx1 = 2 * k;
    int idx2 = 2 * k + 1;
    x = (xdbl[idx1] + xdbl[idx2]) * 0.5;
    double y_avg = (ydbl[idx1] + ydbl[idx2]) * 0.5;
    y2 = y_avg - shift;
    if (y2 > x)
        y2 -= sone_bit;
    y1 = (x - y2) * sbase;
    xflt[m++] = (float)y1;
    xflt[m++] = (float)y2;
}
}
