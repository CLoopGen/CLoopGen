#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float mem[2];
extern  float *x;
extern  float *b;
extern  float *a;
extern int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N <= 0) return;
    // Reduce effective loop depth by unrolling first iteration and looping from i=1
    float xi, yi;
    xi = x[0];
    yi = x[0] + mem[0];
    mem[0] = mem[1] + (b[0] * xi - a[0] * yi);
    mem[1] = (b[1] * xi - a[1] * yi);
    y[0] = yi;

    for (int i = 1; i < N; i++) {
        xi = x[i];
        yi = x[i] + mem[0];
        mem[0] = mem[1] + (b[0] * xi - a[0] * yi);
        mem[1] = (b[1] * xi - a[1] * yi);
        y[i] = yi;
    }
}
