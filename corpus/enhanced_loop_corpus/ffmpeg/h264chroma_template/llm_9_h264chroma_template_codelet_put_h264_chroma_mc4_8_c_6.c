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
for (i = 0; i < h; i += 2) {
    ptrdiff_t s = stride;
    ptrdiff_t s2 = 2 * stride;
    dst[0] = ((A * src[0] + B * src[1] + C * src[s + 0] + D * src[s + 1] + 32) >> 6);
    dst[1] = ((A * src[1] + B * src[2] + C * src[s + 1] + D * src[s + 2] + 32) >> 6);
    dst[2] = ((A * src[2] + B * src[3] + C * src[s + 2] + D * src[s + 3] + 32) >> 6);
    dst[3] = ((A * src[3] + B * src[4] + C * src[s + 3] + D * src[s + 4] + 32) >> 6);

    if (i + 1 < h) {
        dst[s + 0] = ((A * src[s + 0] + B * src[s + 1] + C * src[s2 + 0] + D * src[s2 + 1] + 32) >> 6);
        dst[s + 1] = ((A * src[s + 1] + B * src[s + 2] + C * src[s2 + 1] + D * src[s2 + 2] + 32) >> 6);
        dst[s + 2] = ((A * src[s + 2] + B * src[s + 3] + C * src[s2 + 2] + D * src[s2 + 3] + 32) >> 6);
        dst[s + 3] = ((A * src[s + 3] + B * src[s + 4] + C * src[s2 + 3] + D * src[s2 + 4] + 32) >> 6);
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
