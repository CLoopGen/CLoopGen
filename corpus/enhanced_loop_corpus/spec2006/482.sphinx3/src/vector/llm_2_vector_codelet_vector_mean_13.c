#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

typedef double float64;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;
extern float64 f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < n_dim; i += 2)
        mean[i] *= (float32)f;
}
