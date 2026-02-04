#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_cm[256];
    for (int k = 0; k < 256; k++) {
        local_cm[k] = cm[k] ^ 0xFF;
    }
    for (j = 0; j < h; j++) {
        for (i = 0; i < w - 2; i++) {
            int sum = 36 * src[i] + 54 * src[i + 1] + 6 * src[i + 2];
            dst[i] = local_cm[(sum + 128) >> 8];
        }
        for (; i < w; i++) {
            dst[i] = cm[src[i]];
        }
        src += srcStride;
        dst += dstStride;
    }
}
