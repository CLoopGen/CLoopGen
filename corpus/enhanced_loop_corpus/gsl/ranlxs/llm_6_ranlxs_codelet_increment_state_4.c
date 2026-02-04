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
    double temp_y2;
    for (k = 0, m = 0; k < 12; ++k) {
        x = xdbl[k];
        temp_y2 = ydbl[k] - shift;
        if (temp_y2 > x)
            temp_y2 -= sone_bit;
        y1 = (x - temp_y2) * sbase;
        xflt[m] = (float)y1;
        xflt[m + 1] = (float)temp_y2;
        m += 2;
    }
}
