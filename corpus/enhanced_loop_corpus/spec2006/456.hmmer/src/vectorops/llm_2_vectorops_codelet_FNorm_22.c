#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int x;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (x = 0; x < n; x += stride)
        vec[x] /= sum;
    for (x = 1; x < n; x += stride)
        vec[x] /= sum;
}
