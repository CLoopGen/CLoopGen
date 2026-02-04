#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    int offset0 = 0;
    int offset1 = stride;
    dst[offset0]     = ((A * src[offset0] + B * src[offset0 + 1] + C * src[offset1] + D * src[offset1 + 1] + 28) >> 6);
    dst[offset0 + 1] = ((A * src[offset0 + 1] + B * src[offset0 + 2] + C * src[offset1 + 1] + D * src[offset1 + 2] + 28) >> 6);

    if (i + 1 < h) {
        uint8_t* dst_next = dst + stride;
        uint8_t* src_next = src + stride;
        dst_next[0] = ((A * src_next[0] + B * src_next[1] + C * src_next[stride] + D * src_next[stride + 1] + 28) >> 6);
    }
    dst += 2 * stride;
    src += 2 * stride;
}
}
