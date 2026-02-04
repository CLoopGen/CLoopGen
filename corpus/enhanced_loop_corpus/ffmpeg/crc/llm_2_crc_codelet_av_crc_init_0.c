#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t AVCRC;

extern AVCRC *ctx;
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorder loops to iterate over contiguous memory locations
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 256; i++) {
            uint32_t idx = 256 * j + i;
            ctx[256 * (j + 1) + i] = (ctx[idx] >> 8) ^ ctx[ctx[idx] & 255];
        }
    }
}
