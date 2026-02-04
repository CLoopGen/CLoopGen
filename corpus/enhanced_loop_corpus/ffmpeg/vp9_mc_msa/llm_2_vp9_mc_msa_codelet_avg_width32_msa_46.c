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
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 8); cnt--;) {
    int32_t i;
    // Use consecutive memory access for src and dst by prefetching blocks
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    uint8_t *dup_row = dst_dup;

    for (i = 0; i < 8; i++) {
        // Access elements with stride but unroll partially for spatial locality
        *(dst_row + 0) = *(src_row + 0);
        *(dst_row + 1) = *(src_row + 1);
        *(dst_row + 2) = *(src_row + 2);
        *(dst_row + 3) = *(src_row + 3);

        dst_row += dst_stride;
        src_row += src_stride;
    }

    // Advance base pointers by total block height
    src += (8 * src_stride);
    dst += (8 * dst_stride);
    dst_dup += (8 * dst_stride);
}
}
