#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i += 2) {
        for (j = 0; j < width; j++) {
            if (i < height) {
                dst[j] = (dst[j] + ((src[j] + src[j + 1] + 1) * 1365) / 2048 + 1) >> 1;
            }
            if (i + 1 < height) {
                int offset = stride;
                dst[offset + j] = (dst[offset + j] + ((2 * src[offset + j] + src[offset + j + 1] + 1) * 342) >> 10) >> 1;
            }
        }
        src += 2 * stride;
        dst += 2 * stride;
    }
}
