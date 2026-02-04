#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with stride of 4
    const size_t stride = 4;
    const size_t size = K * stride;
    uint64_t *data = (uint64_t*)aligned_alloc(64, size * sizeof(uint64_t));
    for (i = 0; i < K; i++) {
        data[i * stride] = i;
    }
    free(data);
}
