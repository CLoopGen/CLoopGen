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
    for (int i = 0; i < height; i += 2) {
        int limit = stride >> 2;
        for (int j = 0; j < limit; j++) {
            uint32_t temp1 = src[j];
            uint32_t temp2 = (i + 1 < height) ? src[j + (stride >> 2)] : temp1;
            dst[j] = (((temp1 >> 3) + (1061109567 & dst[j])) << 3) & 4244438268U;
            if (i + 1 < height) {
                dst[j + (stride >> 2)] = (((temp2 >> 3) + (1061109567 & dst[j + (stride >> 2)])) << 3) & 4244438268U;
            }
        }
        dst += (stride >> 2) * 2;
        src += (stride >> 2) * 2;
    }
}
