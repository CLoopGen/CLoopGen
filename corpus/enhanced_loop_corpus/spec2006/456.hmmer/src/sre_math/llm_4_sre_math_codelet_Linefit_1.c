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
for (i = 0; i < N; i++) {
    if (x[i] == xavg) continue;
    sxx += (x[i] - xavg) * (x[i] - xavg);
    syy += (y[i] - yavg) * (y[i] - xavg);
    sxy += (x[i] - xavg) * (y[i] - yavg);
}
}
