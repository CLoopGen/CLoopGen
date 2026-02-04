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
for (int i = 0; i < N; i++) {
    float xi = x[i];
    float yi = xi + mem[0];
    
    // Increased arithmetic complexity: add extra multiplications and accumulation
    float term1 = b[0] * xi - a[0] * yi;
    float term2 = b[1] * xi - a[1] * yi;
    float term3 = b[2 % N] * xi - a[2 % N] * yi;  // wrap-around access to increase computation
    float term4 = b[3 % N] * xi - a[3 % N] * yi;

    mem[0] = mem[1] + term1 + 0.5f * term3;
    mem[1] = term2 + 0.25f * term4;

    y[i] = yi + 0.1f * (term1 + term2); // Slight output perturbation with computational overhead
}
}
