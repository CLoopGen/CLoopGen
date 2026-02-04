#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern int sz;
extern int bit_depth;
extern double ind[1024];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc((sz * sz) * sizeof(int));
    for (int i = 0; i < sz * sz; i++) {
        indices[i] = i;
    }
    // Reverse access pattern (indirect access via index array in reverse)
    for (n = 0; n < sz * sz; n++) {
        int idx = indices[sz * sz - 1 - n]; // reverse indexing
        if (bit_depth == 8)
            ind[idx] = buf[idx];
        else
            ind[idx] = ((int32_t *)buf)[idx];
    }
    free(indices);
}
