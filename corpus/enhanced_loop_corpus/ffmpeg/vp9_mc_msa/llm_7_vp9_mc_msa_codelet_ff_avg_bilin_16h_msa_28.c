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
uint32_t offset = 0;
for (loop_cnt = (height >> 2) - 1; loop_cnt--;) {
    uint8_t val_top = src[offset + 0 * src_stride];
    uint8_t val_mid1 = src[offset + 1 * src_stride];
    uint8_t val_mid2 = src[offset + 2 * src_stride];
    uint8_t val_bot = src[offset + 3 * src_stride];

    uint8_t combined = val_top ^ val_mid1 ^ val_mid2 ^ val_bot;

    dst[0 * dst_stride] = combined;
    dst[1 * dst_stride] = combined ^ 0xFF;
    dst[2 * dst_stride] = combined;
    dst[3 * dst_stride] = combined ^ 0xAA;

    offset += 4 * src_stride;

    dst += 4 * dst_stride;

    val_top = val_bot + 1;
    val_bot = val_top + 1;
}
}
