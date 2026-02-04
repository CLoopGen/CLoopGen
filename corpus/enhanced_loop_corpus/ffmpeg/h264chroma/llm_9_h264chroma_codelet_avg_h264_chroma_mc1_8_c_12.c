#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < h; i += step) {
        ptrdiff_t offset = i * stride;
        dst[0] = ((dst[0] + ((A * src[0] + B * src[1]) + 32) >> 6) + 1) >> 1;
        if (i + 1 < h) {
            dst[stride] = ((dst[stride] + ((C * src[stride] + D * src[stride + 1]) + 32) >> 6) + 1) >> 1;
        }
        dst += 2 * stride;
        src += 2 * stride;
    }
}
