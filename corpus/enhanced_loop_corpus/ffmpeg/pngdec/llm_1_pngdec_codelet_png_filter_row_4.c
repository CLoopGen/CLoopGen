#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int bpp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_i;
    for (outer_i = 0; outer_i < size; outer_i += 16) {
        int limit = (outer_i + 16 < size) ? outer_i + 16 : size;
        for (i = outer_i; i < limit; i++) {
            dst[i] = (((((dst[i - bpp]) + (last[i])) >> 1) + (src[i])) & 255);
        }
    }
}
