#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 4; loop_cnt--;) {
    int offset;
    // Change to consecutive memory access by precomputing a flat index
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    src += (4 * stride);
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 4; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 1; offset++) {
        dst[offset] = src[offset * stride];
    }
    for (offset = 0; offset < 1; offset++) {
        dst[offset + 1] = src[(offset + 1) * stride];
    }
    for (offset = 0; offset < 2; offset++) {
        dst[offset] = src[offset * stride];
    }
    dst += (4 * stride);
}
}
