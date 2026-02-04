#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t local_src[64];
ptrdiff_t offset = (8 + 8) - 2 * 8; // Precompute base offset to reduce loop-carried dependency
for (int i = 0; i < 64; i++) {
    local_src[i] = src[offset + i];
}
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        if (x - 2 * y > 0) {
            int rel_idx = x - 2 * y + 8; // Shifted index into local_src
            dst[x] = (local_src[rel_idx - 1] + local_src[rel_idx] + 1) >> 1;
        } else {
            int fallback_idx = (8) + 8 - y + (x >> 1) - offset;
            dst[x] = local_src[fallback_idx];
        }
    }
    dst += stride;
}
}
