#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern  uint32_t *src;
extern int stride;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < height; i++) {
        int j = 0;
        int step = stride >> 2;
        for (; j < step; j++) {
            uint32_t temp = src[j];
            if (temp != 0) {
                dst[j] = (((temp >> 3) + (1061109567 & dst[j])) << 3) & 4244438268U;
            } else {
                dst[j] = 0;
                continue;
            }
        }
        dst += step;
        src += step;
    }
}
