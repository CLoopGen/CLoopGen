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
    ptrdiff_t s = stride;
    int i_local = 0;
    while (i_local < h) {
        if (!(i_local & 1)) {
            dst[0] = (((A * src[0] + B * src[1] + C * src[s + 0] + D * src[s + 1]) + 32) >> 6);
            dst[1] = (((A * src[1] + B * src[2] + C * src[s + 1] + D * src[s + 2]) + 32) >> 6);
        } else {
            dst[0] = (((C * src[s + 0] + D * src[s + 1] + A * src[0] + B * src[1]) + 32) >> 6);
            dst[1] = (((C * src[s + 1] + D * src[s + 2] + A * src[1] + B * src[2]) + 32) >> 6);
        }
        dst += s;
        src += s;
        i_local++;
    }
}
