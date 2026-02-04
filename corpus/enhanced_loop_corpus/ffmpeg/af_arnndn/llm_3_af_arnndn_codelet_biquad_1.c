#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float mem[2];
extern  float *x;
extern  float *b;
extern  float *a;
extern int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) access using an index map
    int *indices = (int*)malloc(N * sizeof(int));
    if (!indices) return; // Handle allocation failure
    // Assume indices are set to natural order for realism, but allows for arbitrary access
    for (int i = 0; i < N; i++) {
        indices[i] = i;
    }
    for (int i = 0; i < N; i++) {
        int idx = indices[i]; // Indirect access via index array
        float xi, yi;
        xi = x[idx];
        yi = xi + mem[0];
        mem[0] = mem[1] + (b[0] * xi - a[0] * yi);
        mem[1] = (b[1] * xi - a[1] * yi);
        y[idx] = yi;
    }
    free(indices);
}
