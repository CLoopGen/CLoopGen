#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with indirect indexing via an index array (simulated stride pattern)
    // Assuming a precomputed index array is not available, we simulate indirect access using a stride lookup
    int *indices = (int*)malloc(lenY * sizeof(int));
    float *y_ptr = (float *)Y;
    for (i = 0; i < lenY; i++) {
        indices[i] = 2 * (iy + i * incY);
    }
    for (i = 0; i < lenY; i++) {
        int idx = indices[i];
        y_ptr[idx]     = 0.0f;
        y_ptr[idx + 1] = 0.0f;
    }
    free(indices);
}
