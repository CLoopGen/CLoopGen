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
    int16_t *temp_dst = dst;
    for (k = 0; k < rlen; k++) {
        temp_dst[j] = 0;
        j++;
        if (j == width) {
            j = 0;
            temp_dst += stride;
        }
    }
    dst = temp_dst;
}
