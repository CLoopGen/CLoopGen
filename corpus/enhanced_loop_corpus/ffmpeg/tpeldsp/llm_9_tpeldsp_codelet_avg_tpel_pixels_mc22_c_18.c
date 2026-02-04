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
        int factor = (i % 3 == 0) ? 1 : 2;
        for (j = 0; j < width - 1; j++) {
            uint8_t temp1 = src[j];
            uint8_t temp2 = src[j + 1];
            uint8_t temp3 = src[j + stride];
            dst[j] = (dst[j] + 
                     ((factor * temp1 + (factor+1) * temp2 + (factor+2) * temp3 + 5) * 2048) >> 14
                     + 1) >> 1;
        }
        if (width > 0)
            dst[width - 1] = (dst[width - 1] + src[width - 1] + 1) >> 1;
        src += stride;
        dst += stride;
    }
}
