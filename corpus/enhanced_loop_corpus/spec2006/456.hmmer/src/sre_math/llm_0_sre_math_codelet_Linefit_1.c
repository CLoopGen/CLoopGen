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
int i1;
for (i1 = 0; i1 < N; i1++) {
    i = i1;
    sxx += (x[i] - xavg) * (x[i] - xavg);
    syy += (y[i] - yavg) * (y[i] - xavg);
    sxy += (x[i] - xavg) * (y[i] - yavg);
}
}
