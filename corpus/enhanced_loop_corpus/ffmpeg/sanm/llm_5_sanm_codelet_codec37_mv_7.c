#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern int stride;
extern int pos;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    int within_bounds = ((pos + 0) >= 0 && (pos + 3) < height * stride);
    for (i = 0; i < 4; i++) {
        if (within_bounds) {
            dst[i] = src[i];
        } else {
            dst[i] = 0;
        }
    }
    dst += stride;
    src += stride;
    pos += stride;
}
}
