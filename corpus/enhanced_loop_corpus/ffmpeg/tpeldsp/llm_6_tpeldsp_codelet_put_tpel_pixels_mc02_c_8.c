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
    uint8_t *temp_dst = dst;
    uint8_t *temp_src = src;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint8_t center = temp_src[j];
            uint8_t below = temp_src[j + stride];
            dst[j] = ((center + 2 * below + 1) * 683) >> 11;
        }
        temp_src += stride;
        temp_dst += stride;
    }
    dst = temp_dst;
    src = temp_src;
}
