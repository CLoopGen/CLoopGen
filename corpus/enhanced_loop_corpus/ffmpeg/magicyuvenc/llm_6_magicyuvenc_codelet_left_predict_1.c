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
    uint8_t temp;
    for (j = 1; j < height; j++) {
        prev = src[-stride];
        for (i = 0; i < width; i++) {
            temp = src[i] - prev;
            dst[i] = temp;
            prev = src[i];
        }
        dst += width;
        src += stride;
    }
}
