#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h + 5; i++) {
        int offset = i * (tmpStride - srcStride); // Introduce loop-carried dependency via index calculation
        tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
        tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
        tmp[2] = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad;
        tmp[3] = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad;

        // Create a WAW and RAW dependency across iterations by reusing tmp values conditionally
        if (i > 0) {
            tmp[-tmpStride] += tmp[0]; // Write after write: current iteration affects prior written location
        }

        tmp += tmpStride;
        src += srcStride;
    }
}
