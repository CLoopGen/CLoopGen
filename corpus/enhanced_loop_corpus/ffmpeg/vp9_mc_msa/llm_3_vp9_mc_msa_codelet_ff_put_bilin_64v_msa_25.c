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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    int offset;
    // Use strided memory access with increasing offsets in non-sequential order
    for (offset = 0; offset < 32; offset += 4) {
        dst[offset * dst_stride] = src[(offset + 1) * src_stride];
        dst[(offset + 1) * dst_stride] = src[offset * src_stride];
        dst[(offset + 2) * dst_stride] = src[(offset + 3) * src_stride];
        dst[(offset + 3) * dst_stride] = src[(offset + 2) * src_stride];
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
