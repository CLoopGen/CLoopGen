#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < size; outer_i += 1) {
        for (; i <= outer_i && i < size; i++) {
            dst[i] = ((dst[i - bpp]) + (src[i]));
        }
    }
}
