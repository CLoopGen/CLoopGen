#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h <= 0) return;
    for (i = 0; i < h; i++) {
        int temp = A * src[0];
        if (temp > 0) {
            dst[0] = ((temp + 32) >> 6);
        } else {
            dst[0] = 0;
        }
        dst += stride;
        src += stride;
    }
}
