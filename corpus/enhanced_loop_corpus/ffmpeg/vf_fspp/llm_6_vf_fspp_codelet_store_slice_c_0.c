#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32)))  uint8_t dither[8][8];
extern uint8_t *dst;
extern int16_t *src;
extern ptrdiff_t dst_stride;
extern ptrdiff_t src_stride;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern ptrdiff_t log2_scale;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    const uint8_t *d = dither[y & 7];
    for (x = 0; x < width; x += 8) {
        int temp;
        // Introduce WAR dependency by reordering store before use in next iteration
        // and create artificial loop-carried dependency via temp accumulation
        int acc = 0;
        for (int k = 0; k < 8; k++) {
            temp = (src[x + k] + (d[k] >> log2_scale)) >> (6 - log2_scale);
            acc += temp; // Accumulate to carry value across inner computations
            src[x + k] = 0;
            if (temp & 256)
                temp = ~(temp >> 31);
            dst[x + k] = temp;
        }
        // Use accumulated value to modify next row's dither influence (loop-carried dependency)
        if (y + 1 < height) {
            dither[(y + 1) & 7][0] ^= (acc & 0xFF);
        }
        // Zero out previous row in src with stride offset — now ordered after current write (WAW introduced)
        if (y > 0) {
            int16_t *prev_row = (int16_t *)((uint8_t *)src - src_stride);
            for (int k = 0; k < 8; k++)
                prev_row[x + k] = 0;
        }
    }
    src += src_stride;
    dst += dst_stride;
}
}
