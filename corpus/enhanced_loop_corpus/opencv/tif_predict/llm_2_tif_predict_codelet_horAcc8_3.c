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
    // Variant 1: Consecutive memory access pattern using a local array
    int *data = (int*)malloc(cc * sizeof(int));
    for (tmsize_t idx = i; idx < cc; idx += stride) {
        data[idx] = idx;  // Writing with strided access but consecutive allocation
    }
    free(data);
}
