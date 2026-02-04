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
        for (x = 0; x < width; x += 8) {
            const uint8_t *d = dither[y & 7];
            for (int offset = 0; offset < 8; offset++) {
                if (x + offset >= width) break;
                int temp = ((src[x + offset + y * src_stride] << log2_scale) + d[offset]) >> 8;
                if (temp & 256)
                    temp = ~(temp >> 31);
                dst[x + offset + y * dst_stride] = temp;
            }
        }
    }
}
