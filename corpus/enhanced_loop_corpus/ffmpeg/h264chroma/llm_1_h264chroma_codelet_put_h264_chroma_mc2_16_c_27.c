#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i0 = 0; i0 < h / 2; i0++) {
        for (int i1 = 0; i1 < 2; i1++) {
            int idx = i0 * 2 + i1;
            if (idx >= h) break;
            dst[0] = ((((A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1])) + 32) >> 6);
            dst[1] = ((((A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2])) + 32) >> 6);
            dst += stride;
            src += stride;
        }
    }
}
