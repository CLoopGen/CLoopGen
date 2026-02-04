#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int k;
extern unsigned int j;
extern int rlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int outer_iter = rlen / 2;
    unsigned int remainder = rlen % 2;
    for (k = 0; k < outer_iter; k++) {
        dst[j++] = 0;
        if (j == width) {
            j = 0;
            dst += stride;
        }
        dst[j++] = 0;
        if (j == width) {
            j = 0;
            dst += stride;
        }
    }
    for (k = 0; k < remainder; k++) {
        dst[j++] = 0;
        if (j == width) {
            j = 0;
            dst += stride;
        }
    }
}
