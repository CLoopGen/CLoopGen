#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern intptr_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth (depth 2) - splitting iteration into blocks
    const intptr_t block_size = 16;
    for (i = 0; i < len; i += block_size) {
        for (intptr_t j = i; j < len && j < i + block_size; j++) {
            dst[j] = (float)src[j];
        }
    }
}
