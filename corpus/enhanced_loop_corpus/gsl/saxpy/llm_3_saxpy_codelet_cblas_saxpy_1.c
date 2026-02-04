#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern  float *X;
extern float *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using a local array-like view via pointer arithmetic (simulating vectorization-friendly pattern)
    float *x_ptr = &X[m];
    float *y_ptr = &Y[m];
    int offset = 0;
    for (i = m; i + 3 < N; i += 4, offset += 4) {
        y_ptr[offset]     += alpha * x_ptr[offset];
        y_ptr[offset + 1] += alpha * x_ptr[offset + 1];
        y_ptr[offset + 2] += alpha * x_ptr[offset + 2];
        y_ptr[offset + 3] += alpha * x_ptr[offset + 3];
    }
}
