#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < n; i += 2)
        if (vec[i] > vec[best])
            best = i;
}
