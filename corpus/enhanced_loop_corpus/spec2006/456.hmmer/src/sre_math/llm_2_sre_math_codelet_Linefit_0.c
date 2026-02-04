#include <stdio.h>

#include <inttypes.h>

extern float *x;
extern float *y;
extern int N;
extern float xavg;
extern float yavg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N; i += 2) {
        xavg += x[i];
        yavg += y[i];
    }
    // Handle odd N if needed by processing last element
    if (N % 2 == 1) {
        xavg += x[N - 1];
        yavg += y[N - 1];
    }
}
