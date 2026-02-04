#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t loop_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Unroll the loop and switch to a strided access pattern across iterations
// Access every second row in source and destination, reducing effective height usage
int32_t src_skip = 2 * src_stride;
int32_t dst_skip = 2 * dst_stride;

for (loop_count = (height >> 3); loop_count--;) { // Note: divide by 8 because we process 8 rows per iteration
    uint8_t *s = src;
    uint8_t *d = dst;

    // Process 8 rows using strided access with stride of 2
    for (int i = 0; i < 8; i += 2) {
        *(d)           = *(s);
        *(d + dst_skip) = *(s + src_skip);
        s += (4 * src_stride);
        d += (4 * dst_stride);
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
