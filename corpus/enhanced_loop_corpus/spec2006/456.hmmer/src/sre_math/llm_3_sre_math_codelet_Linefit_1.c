#include <stdio.h>

#include <inttypes.h>

extern float *x;
extern float *y;
extern int N;
extern float xavg;
extern float yavg;
extern float sxx;
extern float syy;
extern float sxy;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (accessing arrays from end to start)
    for (i = N - 1; i >= 0; i--) {
        sxx += (x[i] - xavg) * (x[i] - xavg);
        syy += (y[i] - yavg) * (y[i] - xavg);
        sxy += (x[i] - xavg) * (y[i] - yavg);
    }
}
