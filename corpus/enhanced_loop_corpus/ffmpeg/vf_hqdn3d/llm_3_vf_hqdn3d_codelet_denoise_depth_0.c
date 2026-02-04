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
    // Variant 2: Strided memory access with reversed column traversal
    // Instead of left-to-right, we access columns from right to left with a fixed stride.
    // This changes spatial locality and may affect cache behavior.

    uint8_t *src_row = src;
    for (y = 0; y < h; y++, src_row += sstride, frame_ant += w) {
        const uint8_t *s = src_row;
        uint16_t *f = frame_ant;
        long x;
        if (depth == 8) {
            for (x = w - 1; x >= 0; x--) {
                f[x] = ((s[x] << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1));
            }
        } else {
            for (x = w - 1; x >= 0; x--) {
                f[x] = ((((const av_alias16 *)(s + x * 2))->u16) << (16 - depth)) + (((1 << (16 - depth)) - 1) >> 1);
            }
        }
    }
}
