#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int width;
extern int height;
extern uint8_t prev;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height <= 1) return;
    for (j = 1; j < height; j++) {
        prev = src[-stride];
        for (i = 0; i < width; i++) {
            uint8_t temp = src[i];
            dst[i] = temp - prev;
            prev = temp;
        }
        dst += width;
        src += stride;
    }
}
