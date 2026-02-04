#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *tmp;
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;
extern  uint8_t *order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling inner loop and adding arithmetic operations
    for (i = 0; i < stride; i++) {
        int base_idx = order[i] * N0;
        for (j = 0; j < N0 - 3; j += 4) {
            tmp[base_idx + j]     = X[j * stride + i] * 2.0f + 1.0f;
            tmp[base_idx + j + 1] = X[(j + 1) * stride + i] * 2.0f + 1.0f;
            tmp[base_idx + j + 2] = X[(j + 2) * stride + i] * 2.0f + 1.0f;
            tmp[base_idx + j + 3] = X[(j + 3) * stride + i] * 2.0f + 1.0f;
        }
        // Handle remaining elements
        for (; j < N0; j++) {
            tmp[order[i] * N0 + j] = X[j * stride + i] * 2.0f + 1.0f;
        }
    }
}
