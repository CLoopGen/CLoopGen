#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height >> 2); cnt--;) {
    int32_t offset_src = 0;
    int32_t offset_dst = 0;

    // Introduce WAW and WAR dependencies via temporary accumulation
    uint8_t acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;

    acc0 += src[offset_src];
    acc1 += src[offset_src + src_stride];
    acc2 += src[offset_src + 2 * src_stride];
    acc3 += src[offset_src + 3 * src_stride];

    // Modify data flow: introduce artificial dependency chain
    acc0 += 10;
    acc1 += acc0;  // RAW: acc1 depends on updated acc0
    acc2 += acc1;  // RAW: acc2 depends on acc1
    acc3 += acc2;  // RAW: acc3 depends on acc2

    // Store with derived values — introduces loop-carried dependence on computation
    dst[offset_dst] = acc0;
    dst[offset_dst + dst_stride] = acc1;
    dst[offset_dst + 2 * dst_stride] = acc2;
    dst[offset_dst + 3 * dst_stride] = acc3;

    // Update pointers after full block processing
    src += (4 * src_stride);

    // Break potential aliasing assumptions by reordering stores
    dst[offset_dst + 3 * dst_stride] = acc3 ^ 0x80;
    dst[offset_dst + 1 * dst_stride] = acc1 ^ 0x80;
    dst[offset_dst + 0 * dst_stride] = acc0 ^ 0x80;
    dst[offset_dst + 2 * dst_stride] = acc2 ^ 0x80;

    dst += (4 * dst_stride);
}
}
