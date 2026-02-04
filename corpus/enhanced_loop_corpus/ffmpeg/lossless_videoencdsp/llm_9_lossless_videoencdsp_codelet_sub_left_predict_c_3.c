#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern ptrdiff_t width;
extern int height;
extern int i;
extern int j;
extern uint8_t prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < height; j += 2) {
        ptrdiff_t limit = (j + 1 < height) ? width : width - (width & 1);
        for (i = 0; i < limit; i += 2) {
            *dst++ = src[i] - prev;
            prev = src[i];
            if (i + 1 < width) {
                *dst++ = src[i+1] - prev;
                prev = src[i+1];
            }
        }
        src += stride;
        if (j + 1 < height) {
            src += stride;
        }
    }
}
