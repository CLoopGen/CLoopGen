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
        int unroll_factor = 2;
        int vectorized_stride = (stride >> 2) & ~(unroll_factor - 1);
        for (int j = 0; j < vectorized_stride; j += unroll_factor) {
            dst[j] = (((src[j] >> 3) + (1061109567 & dst[j])) << 3) & 4244438268U;
            dst[j+1] = (((src[j+1] >> 3) + (1061109567 & dst[j+1])) << 3) & 4244438268U;
        }
        for (int j = vectorized_stride; j < stride >> 2; j++) {
            dst[j] = (((src[j] >> 3) + (1061109567 & dst[j])) << 3) & 4244438268U;
        }
        dst += stride >> 2;
        src += stride >> 2;
    }
}
