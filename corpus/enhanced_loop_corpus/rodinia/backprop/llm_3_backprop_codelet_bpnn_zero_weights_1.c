#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **w;
extern int m;
extern int n;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic to simulate array indexing
    float *base = w[0];
    ptrdiff_t row_stride = (char*)w[1] - (char*)w[0]; // Compute byte stride between rows
    ptrdiff_t float_size = sizeof(float);
    for (int i_idx = 0; i_idx <= m; i_idx++) {
        float *row_ptr = (float*)((char*)base + i_idx * row_stride);
        for (int j_idx = 0; j_idx <= n; j_idx++) {
            row_ptr[j_idx] = 0.0f;
        }
    }
}
