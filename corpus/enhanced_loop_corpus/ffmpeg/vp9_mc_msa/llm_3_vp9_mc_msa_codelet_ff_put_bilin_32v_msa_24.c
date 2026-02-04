#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Interleaved strided access: process multiple rows with manual stride stepping
    for (int offset = 0; offset < 4; ++offset) {
        uint8_t *s = src + offset * src_stride;
        uint8_t *d = dst + offset * dst_stride;

        // Unroll the column access partially (e.g., 4 elements at a time)
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
