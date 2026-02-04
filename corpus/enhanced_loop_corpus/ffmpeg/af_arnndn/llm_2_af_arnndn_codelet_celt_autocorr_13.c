#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern int n;
extern float xx[864];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This accesses every second element in both arrays, forward traversal
    int stride = 2;
    for (int i = 0; i < n; i += stride) {
        if (i < n) xx[i] = x[i];
        if (i + 1 < n) xx[i + 1] = x[i + 1];
    }
}
