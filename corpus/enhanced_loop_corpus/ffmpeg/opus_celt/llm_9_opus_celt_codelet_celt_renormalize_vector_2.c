#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N;
extern int i;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride-2 access and simplified operation
    // Loop runs half as many iterations with increased memory stride
    for (i = 0; i < N; i += 2) {
        X[i] *= g;
    }
}
