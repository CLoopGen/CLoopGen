#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t stride;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (gather-style access)
    int *data = (int*)malloc(cc * sizeof(int));
    tmsize_t *indices = (tmsize_t*)malloc(cc * sizeof(tmsize_t));
    
    // Initialize indirect indices (e.g., reverse order access)
    for (tmsize_t j = 0; j < cc; ++j) {
        indices[j] = cc - 1 - j;
    }

    for (tmsize_t idx = i; idx < cc; idx += stride) {
        tmsize_t pos = indices[idx];  // Indirect addressing
        data[pos] += 1;
    }

    free(indices);
    free(data);
}
