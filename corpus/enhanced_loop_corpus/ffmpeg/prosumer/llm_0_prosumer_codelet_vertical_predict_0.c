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
        for (; j < (stride >> 2) - 3; j += 4) {
            dst[j+0] = (((src[j+0] >> 3) + (1061109567 & dst[j+0])) << 3) & 4244438268U;
            dst[j+1] = (((src[j+1] >> 3) + (1061109567 & dst[j+1])) << 3) & 4244438268U;
            dst[j+2] = (((src[j+2] >> 3) + (1061109567 & dst[j+2])) << 3) & 4244438268U;
            dst[j+3] = (((src[j+3] >> 3) + (1061109567 & dst[j+3])) << 3) & 4244438268U;
        }
        for (; j < stride >> 2; j++) {
            dst[j] = (((src[j] >> 3) + (1061109567 & dst[j])) << 3) & 4244438268U;
        }
        dst += stride >> 2;
        src += stride >> 2;
    }
}
