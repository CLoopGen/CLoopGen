#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **h;
extern int *len;
extern float phase;
extern float *work;
extern int i;
extern int work_len;
extern int begin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via an index map (simulates irregular/indirect pattern)
    int *indices = (int*)alloca(*len * sizeof(int));
    // Precompute scrambled indices: reverse order with offset modulation
    for (int k = 0; k < *len; k++) {
        indices[k] = (phase > 50.F ? *len - 1 - k : k);
    }
    for (i = 0; i < *len; i++) {
        int mapped_index = indices[i];
        int wrapped_addr = (begin + mapped_index + work_len) & (work_len - 1);
        (*h)[i] = work[wrapped_addr];
    }
}
