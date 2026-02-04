#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2)
    for (x = 0; x < n; x += 2)
        vec[x] = value;
}
