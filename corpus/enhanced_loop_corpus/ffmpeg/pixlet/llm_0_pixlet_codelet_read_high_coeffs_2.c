#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int rlen;
extern unsigned int j;
extern unsigned int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (unsigned int outer = 0; outer < rlen / 2; outer++) {
    for (unsigned int inner = 0; inner < 2; inner++) {
        dst[j++] = 0;
        if (j == width) {
            j = 0;
            dst += stride;
        }
    }
}
if (rlen % 2 != 0) {
    dst[j++] = 0;
    if (j == width) {
        j = 0;
        dst += stride;
    }
}
}
