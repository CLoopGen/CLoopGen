#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (x = 0; x < n; x += 2)
        vec[x] = 1. / (double)n;
    // Handle odd-sized n by filling the last element if needed
    if (n % 2 == 1)
        vec[n-1] = 1. / (double)n;
}
