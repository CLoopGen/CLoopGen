#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float **dmx;
extern float *halfmin;
extern int idx;
extern int i;
extern float min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via an index map
    // Simulate non-contiguous access using a strided offset pattern
    int *index_map = (int*)__builtin_alloca(nseq * sizeof(int));
    // Create a simple strided index pattern (e.g., reverse order to change access stride)
    for (i = 0; i < nseq; i++) {
        index_map[i] = nseq - 1 - i;
    }
    for (idx = 0; idx < nseq; idx++) {
        min = 1.0f;
        for (i = 0; i < nseq; i++) {
            int mapped_i = index_map[i];  // Indirect, strided-like access
            if (mapped_i == idx)
                continue;
            if (dmx[idx][mapped_i] < min)
                min = dmx[idx][mapped_i];
        }
        halfmin[idx] = min / 2.0f;
    }
}
