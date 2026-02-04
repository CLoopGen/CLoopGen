#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(8)))  uint8_t dither[8][8];
extern uint8_t *dst;
extern  uint16_t *src;
extern int dst_stride;
extern int src_stride;
extern int width;
extern int height;
extern int log2_scale;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    const uint8_t *d = dither[y & 7];
    for (x = 0; x < width; x += 8) {
        for (int k = 0; k < 8; ++k) {
            int idx = x + y * src_stride + k;
            int dst_idx = x + y * dst_stride + k;
            int temp = ((src[idx] << log2_scale) + d[k]) >> 8;
            if (!(temp & 256)) {
                dst[dst_idx] = temp;
            } else {
                dst[dst_idx] = ~(temp >> 31);
            }
        }
    }
}
}
