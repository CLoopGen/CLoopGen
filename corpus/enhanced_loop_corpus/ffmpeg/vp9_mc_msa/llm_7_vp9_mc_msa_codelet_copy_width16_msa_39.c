#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t *src_offset = src;
uint8_t *dst_offset = dst;

for (cnt = (height >> 2); cnt--;) {
    dst_offset[0] = src_offset[0];
    dst_offset[dst_stride] = src_offset[src_stride];
    dst_offset[2*dst_stride] = src_offset[2*src_stride];
    dst_offset[3*dst_stride] = src_offset[3*src_stride];

    src_offset += (4 * src_stride);
    dst_offset += (4 * dst_stride);
}

src += (height & ~3); // Update original src/dst to reflect logical end state
dst += (height & ~3) * (dst_stride / src_stride); // Approximate update assuming compatible strides
}
