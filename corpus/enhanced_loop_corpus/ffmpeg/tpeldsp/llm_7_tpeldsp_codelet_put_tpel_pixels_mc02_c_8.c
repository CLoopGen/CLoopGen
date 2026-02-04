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
    for (i = 0; i < height; i++) {
        uint8_t *local_dst = dst + i * stride;
        uint8_t *local_src = src + i * stride;
        for (j = 0; j < width; j++) {
            uint8_t val = local_src[j];
            uint8_t val_below = (i + 1 < height) ? local_src[j + stride] : val;
            local_dst[j] = ((val + 2 * val_below + 1) * 683) >> 11;
        }
    }
}
