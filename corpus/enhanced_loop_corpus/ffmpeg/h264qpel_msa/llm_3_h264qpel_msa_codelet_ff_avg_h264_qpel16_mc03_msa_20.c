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
    // Use consecutive memory access with fixed offsets
    for (offset = 0; offset < 4; ++offset) {
        dst[offset] = src[offset];
    }
    src += (4 * stride);
    dst += (4 * stride);
}
}
