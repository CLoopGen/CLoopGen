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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N; i += 2) {
        sxx += (x[i] - xavg) * (x[i] - xavg);
        syy += (y[i] - yavg) * (y[i] - xavg);
        sxy += (x[i] - xavg) * (y[i] - yavg);
        
        // Handle remaining element if N is odd
        if (i + 1 < N) {
            sxx += (x[i+1] - xavg) * (x[i+1] - xavg);
            syy += (y[i+1] - yavg) * (y[i+1] - xavg);
            sxy += (x[i+1] - xavg) * (y[i+1] - yavg);
        }
    }
}
