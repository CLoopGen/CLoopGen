#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vector;
extern int32_t *prev_exc;
extern int pitch_lag;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access by unrolling and stepping in larger increments
    // Access pattern now jumps by 4 elements at a time (strided), with cleanup for remainder
    int stride = 4;
    int limit = (72 / stride) * stride;
    for (i = 0; i < limit; i += stride) {
        vector[i]     = prev_exc[pitch_lag - (i      % pitch_lag)];
        vector[i + 1] = prev_exc[pitch_lag - ((i + 1) % pitch_lag)];
        vector[i + 2] = prev_exc[pitch_lag - ((i + 2) % pitch_lag)];
        vector[i + 3] = prev_exc[pitch_lag - ((i + 3) % pitch_lag)];
    }
    // Handle remaining iterations
    for (; i < 72; i++) {
        vector[i] = prev_exc[pitch_lag - i % pitch_lag];
    }
}
