#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  void *X;
extern  int incX;
extern void *Y;
extern  int incY;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using index array (indirect addressing via precomputed indices)
    int *indices = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++) {
        indices[i] = i;
    }
    const float *x_base = (const float *)X;
    float *y_base = (float *)Y;
    for (i = 0; i < N; i++) {
        int idx = indices[i]; // Simulate indirect access pattern
        int x_offset = 2 * (ix + idx * incX);
        int y_offset = 2 * (iy + idx * incY);
        y_base[y_offset]     = x_base[x_offset];
        y_base[y_offset + 1] = x_base[x_offset + 1];
    }
    free(indices);
}
