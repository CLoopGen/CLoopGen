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
    float temp_sxx = 0.0f, temp_syy = 0.0f, temp_sxy = 0.0f;
    for (i = 0; i < N; i++) {
        float dx = x[i] - xavg;
        float dy = y[i] - yavg;
        temp_sxx += dx * dx;
        temp_syy += dy * dy;
        temp_sxy += dx * dy;
    }
    sxx += temp_sxx;
    syy += temp_syy;
    sxy += temp_sxy;
}
