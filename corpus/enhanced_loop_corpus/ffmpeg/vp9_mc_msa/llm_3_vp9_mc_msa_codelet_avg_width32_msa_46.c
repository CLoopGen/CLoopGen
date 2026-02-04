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
    int32_t offset;
    // Change to strided access: process every 2nd row, then fill in gaps (simulated tiling effect)
    const int32_t step = 2 * src_stride;
    uint8_t *s = src;
    uint8_t *d = dst;
    uint8_t *dd = dst_dup;

    // Process even-indexed rows first (relative within block), then odd
    for (offset = 0; offset < 4 * src_stride; offset += step) {
        // Write to both output buffers with same pattern
        d[offset + 0 * dst_stride] = s[offset + 0 * src_stride];
        d[offset + 1 * dst_stride] = s[offset + 1 * src_stride];
        dd[offset + 0 * dst_stride] = s[offset + 0 * src_stride];
        dd[offset + 1 * dst_stride] = s[offset + 1 * src_stride];
    }

    // Now handle odd offsets relative to current block start
    for (offset = src_stride; offset < 5 * src_stride; offset += step) {
        d[offset + 0 * dst_stride] = s[offset + 0 * src_stride];
        d[offset + 1 * dst_stride] = s[offset + 1 * src_stride];
        dd[offset + 0 * dst_stride] = s[offset + 0 * src_stride];
        dd[offset + 1 * dst_stride] = s[offset + 1 * src_stride];
    }

    // Move all pointers forward by full block
    src += (8 * src_stride);
    dst += (8 * dst_stride);
    dst_dup += (8 * dst_stride);
}
}
