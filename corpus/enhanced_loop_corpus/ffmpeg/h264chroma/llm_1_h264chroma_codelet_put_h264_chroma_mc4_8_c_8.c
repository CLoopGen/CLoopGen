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
if (h > 0) {
    for (int k = 0; k < 4; k++) {
        for (i = 0; i < h; i++) {
            dst[i * stride] = (((A * src[i * stride]) + 32) >> 6);
        }
        dst++;
        src++;
    }
    dst -= 4;
    src -= 4;
}
}
