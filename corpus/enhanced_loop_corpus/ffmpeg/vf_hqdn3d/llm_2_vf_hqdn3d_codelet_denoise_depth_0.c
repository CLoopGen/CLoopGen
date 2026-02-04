#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t *src;
extern int w;
extern int h;
extern int sstride;
extern int depth;
extern long x;
extern long y;
extern uint16_t *frame_ant;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes w is even for simplicity and processes two elements per iteration
    // to promote consecutive, forward access and potential vectorization.

    uint8_t *src_row = src;
    for (y = 0; y < h; y++, src_row += sstride, frame_ant += w) {
        const uint8_t *s = src_row;
        uint16_t *f = frame_ant;
        long x = 0;
        if (depth == 8) {
            for (; x <= w - 2; x += 2) {
                f[x]     = ((s[x] << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1));
                f[x + 1] = ((s[x + 1] << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1));
            }
            for (; x < w; x++) {
                f[x] = ((s[x] << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1));
            }
        } else {
            for (; x <= w - 2; x += 2) {
                f[x]     = ((((const av_alias16 *)(s + x * 2))->u16) << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1);
                f[x + 1] = ((((const av_alias16 *)(s + (x + 1) * 2))->u16) << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1);
            }
            for (; x < w; x++) {
                f[x] = ((((const av_alias16 *)(s + x * 2))->u16) << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1);
            }
        }
    }
}
