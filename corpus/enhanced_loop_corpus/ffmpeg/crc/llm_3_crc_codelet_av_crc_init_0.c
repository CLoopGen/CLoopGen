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
    // Variant 2: Strided memory access pattern with indirect indexing via pointer arithmetic
    // Use base pointers and stride through memory with fixed increments
    AVCRC *base = ctx;
    for (i = 0; i < 256; i++) {
        for (j = 0; j < 3; j++) {
            AVCRC *src_row = base + 256 * j;
            AVCRC *dst_row = base + 256 * (j + 1);
            dst_row[i] = (src_row[i] >> 8) ^ ctx[src_row[i] & 255];
        }
    }
}
