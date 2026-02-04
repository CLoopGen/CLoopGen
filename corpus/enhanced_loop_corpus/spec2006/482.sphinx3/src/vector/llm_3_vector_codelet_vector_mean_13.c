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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = n_dim - 1; i >= 0; i--)
        mean[i] *= (float32)f;
}
