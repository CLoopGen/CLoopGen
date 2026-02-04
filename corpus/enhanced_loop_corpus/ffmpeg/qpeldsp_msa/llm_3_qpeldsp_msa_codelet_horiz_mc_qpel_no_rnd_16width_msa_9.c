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
// Change to indirect access using index array for non-sequential pattern
int32_t indices[4] = {0, src_stride, 2*src_stride, 3*src_stride};
for (loop_count = (height >> 2); loop_count--;) {
    for (int i = 0; i < 4; i++) {
        uint8_t *s = src + indices[i];
        uint8_t *d = dst + indices[i];

        // Perform block-like data transfer with stride skip
        for (int j = 0; j < 8; j++) {
            d[j * (dst_stride / 8)] = s[j * (src_stride / 8)];
        }
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
