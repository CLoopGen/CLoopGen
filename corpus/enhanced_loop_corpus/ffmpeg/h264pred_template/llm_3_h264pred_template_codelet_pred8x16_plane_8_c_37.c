#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t * src0;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect pointer indexing
    // Simulate strided access by using an index array to fetch non-contiguous locations
    // This mimics irregular or configurable access patterns useful in signal processing.
    int indices[3] = {2*stride, 3*stride, 4*stride}; // Precomputed strides for k=2,3,4
    uint8_t **ptrs1 = (uint8_t**)alloca(3 * sizeof(uint8_t*));
    uint8_t **ptrs2 = (uint8_t**)alloca(3 * sizeof(uint8_t*));
    for (int i = 0; i < 3; ++i) {
        ptrs1[i] = src1 + indices[i];
        ptrs2[i] = src2 - indices[i];
    }
    H = V = 0; // Reset for clean accumulation
    for (k = 2; k <= 4; ++k) {
        int idx = k - 2;
        H += k * (src0[k] - src0[-k]);
        V += k * (*ptrs1[idx] - *ptrs2[idx]);
    }
}
