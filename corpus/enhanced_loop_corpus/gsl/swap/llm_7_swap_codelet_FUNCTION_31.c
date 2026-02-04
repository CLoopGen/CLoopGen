#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *buffer = (uint64_t*)malloc(size1 * sizeof(uint64_t));
    if (!buffer) return;
    for (i = 0; i < size1; i++) {
        buffer[i] = i * 2; // Write to buffer element (WAW safe across iterations)
        for (j = i + 1; j < size2; j++) {
            buffer[i] += j; // Introduce loop-carried WAW and RAW: each buffer[i] accumulates j values
        }
    }
    free(buffer);
}
