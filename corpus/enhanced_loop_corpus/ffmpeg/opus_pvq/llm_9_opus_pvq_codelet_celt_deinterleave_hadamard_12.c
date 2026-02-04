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
    // Variant 2: Reduced trip count with increased outer work and modified loop bounds
    int half_stride = (stride + 1) / 2;
    for (i = 0; i < half_stride; i++) {
        int idx1 = order[i] * N0;
        int idx2 = (i * 2 < stride - 1) ? order[stride - 1 - i] * N0 : -1;
        for (j = 0; j < N0; j++) {
            tmp[idx1 + j] = X[j * stride + i];
            if (idx2 != -1 && (i * 2) < stride - 1) {
                tmp[idx2 + j] = X[j * stride + (stride - 1 - i)];
            }
        }
    }
}
