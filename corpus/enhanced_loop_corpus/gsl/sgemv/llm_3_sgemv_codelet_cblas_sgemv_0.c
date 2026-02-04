#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via index array (simulating gather-like pattern)
    int *indices = (int*)malloc(lenY * sizeof(int));
    for (i = 0; i < lenY; i++) {
        indices[i] = iy + i * incY; // Precompute strided indices
    }
    for (i = 0; i < lenY; i++) {
        Y[indices[i]] = 0.0f;
    }
    free(indices);
}
