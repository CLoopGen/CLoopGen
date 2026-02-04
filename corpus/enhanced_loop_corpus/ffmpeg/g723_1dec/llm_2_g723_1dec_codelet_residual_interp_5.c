#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int lag;
extern int i;
extern int16_t *vector_ptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with positive stride on vector_ptr
    // Instead of accessing vector_ptr[i - lag], we access every 2nd element starting from offset
    int stride = 2;
    for (i = 0; i < lag; i += 1)
        out[i] = vector_ptr[(i * stride) % lag - lag] * 3 >> 2;
}
