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
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < N; i += 2) {
        float xi0, yi0, xi1, yi1;
        // Process two elements with stride 2
        if (i < N) {
            xi0 = x[i];
            yi0 = xi0 + mem[0];
            mem[0] = mem[1] + (b[0] * xi0 - a[0] * yi0);
            mem[1] = (b[1] * xi0 - a[1] * yi0);
            y[i] = yi0;
        }
        if (i + 1 < N) {
            xi1 = x[i + 1];
            yi1 = xi1 + mem[0];
            mem[0] = mem[1] + (b[0] * xi1 - a[0] * yi1);
            mem[1] = (b[1] * xi1 - a[1] * yi1);
            y[i + 1] = yi1;
        }
    }
}
