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
    float dx = x[i] - xavg;
    float dy = y[i] - yavg;
    if (dx * dx > 1e-6) {
        sxx += dx * dx;
        syy += dy * (y[i] - xavg);
        sxy += dx * dy;
    }
}
}
