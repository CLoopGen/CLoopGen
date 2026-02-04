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



void loop() {
    for (y = 0; y < height; y += 2) {
        const uint8_t *d1 = dither[y & 7];
        const uint8_t *d2 = dither[(y + 1) & 7];
        for (x = 0; x < width; x += 4) {
            int i;
            for (i = 0; i < 4; i++) {
                if (x + i < width) {
                    int temp = ((src[x + i + y * src_stride] << log2_scale) + d1[i]) >> 8;
                    if (temp & 256)
                        temp = ~(temp >> 31);
                    dst[x + i + y * dst_stride] = temp;
                }
                if (y + 1 < height && x + i < width) {
                    int temp = ((src[x + i + (y + 1) * src_stride] << log2_scale) + d2[i]) >> 8;
                    if (temp & 256)
                        temp = ~(temp >> 31);
                    dst[x + i + (y + 1) * dst_stride] = temp;
                }
            }
        }
    }
}
