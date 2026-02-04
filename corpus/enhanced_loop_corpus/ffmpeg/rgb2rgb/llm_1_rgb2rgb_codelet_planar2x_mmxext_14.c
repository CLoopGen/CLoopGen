#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < (srcWidth - 1) / 2; x++) {
        int idx1 = 2 * x;
        int idx2 = 2 * x + 1;
        dst[2 * idx1 + 1] = (3 * src[idx1] + src[idx1 + 1]) >> 2;
        dst[2 * idx1 + 2] = (src[idx1] + 3 * src[idx1 + 1]) >> 2;
        if (idx2 < srcWidth - 1) {
            dst[2 * idx2 + 1] = (3 * src[idx2] + src[idx2 + 1]) >> 2;
            dst[2 * idx2 + 2] = (src[idx2] + 3 * src[idx2 + 1]) >> 2;
        }
    }
    if ((srcWidth - 1) % 2 == 1) {
        int x = srcWidth - 2;
        dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
        dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
    }
}
